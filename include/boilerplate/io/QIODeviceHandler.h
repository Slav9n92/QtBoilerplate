/*
 * \file QIODeviceHandler.h
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 11.07.2025
 * \time : 13:12
 */

#pragma once

#include <QtCore>
#include <QIODevice>
#include <QUuid>
#include <boilerplate/expected/Expected.h>
#include <QString>
#include <type_traits>

namespace qt {
namespace boilerplate {

template< typename HeaderTypeT = quint64, QDataStream::ByteOrder byteOrder = QDataStream::ByteOrder::BigEndian >
class QIODeviceHandler final
{
    static_assert( std::is_integral< HeaderTypeT >::value && !std::is_same< bool, HeaderTypeT >::value, "Not an integer" );

public:
    enum class Error : quint8
    {
        InvalidDevice = 0,
        HeaderOverflow
    };

public:
    explicit QIODeviceHandler( QPointer< QIODevice > device ) noexcept
            : QIODeviceHandler( std::move( device ), QUuid::createUuid() )
    {
    }

    QIODeviceHandler( QPointer< QIODevice > device, QUuid id ) noexcept
            : id( id )
            , device( std::move( device ) )
            , packageSize( 0 )
    {
    }

public:
    boilerplate::Expected< qint64, Error > write( const QByteArray& bytes ) noexcept
    {
        if( !device ) { return boilerplate::make_unexpected_type( Error::InvalidDevice ); }
        if( bytes.size() > std::numeric_limits< HeaderTypeT >::max() ) { return boilerplate::make_unexpected_type( Error::HeaderOverflow ); }

        QByteArray package;
        QDataStream stream( &package, QIODevice::OpenModeFlag::WriteOnly );
        stream.setByteOrder( byteOrder );
        stream << static_cast< HeaderTypeT >( bytes.size() );
        package.append( bytes );
        return { device->write( package ) };
    }

    boilerplate::Expected< std::list< QByteArray >, Error > read() noexcept
    {
        if( !device ) { return boilerplate::make_unexpected_type( Error::InvalidDevice ); }

        const auto headerSize = getHeaderSize();
        std::list< QByteArray > incoming;
        do
        {
            if( 0 < device->bytesAvailable() ) { buffer.append( device->readAll() ); }
            if( 0 == packageSize )
            {
                if( headerSize <= buffer.size() )
                {
                    auto&& header = buffer.mid( 0, headerSize );
                    buffer.remove( 0, headerSize );
                    QDataStream stream( &header, QIODevice::OpenModeFlag::ReadOnly );
                    stream.setByteOrder( byteOrder );
                    stream >> packageSize;
                }
                else { break; }
            }
            if( packageSize > buffer.size() ) { break; }

            incoming.push_back( buffer.mid( 0, packageSize ) );
            buffer.remove( 0, packageSize );
            packageSize = 0;
        } while( !buffer.isEmpty() );
        return { incoming };
    }

public:
    QUuid getId() const noexcept
    {
        return id;
    }

    QPointer< QIODevice > getDevice() const noexcept
    {
        return device;
    }

    size_t getHeaderSize() const noexcept
    {
        return sizeof( HeaderTypeT );
    }

private:
    QUuid id;
    QPointer< QIODevice > device;
    HeaderTypeT packageSize;
    QByteArray buffer;
};

}
}