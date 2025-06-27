/*
 * \file Tst_Expected.cpp
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 27.06.2025
 * \time : 13:48
 */

#include "Tst_Expected.h"

#include <QtTest/QtTest>
#include <memory>
#include <tst/mocs/ExpectedMoc.h>

namespace qt {
namespace boilerplate {
namespace testing {

Tst_Expected::Tst_Expected( QObject* parent ) noexcept
        : QObject( parent )
{
}

void Tst_Expected::cleanup() noexcept
{
    ExpectedMoc::reset();
}

void Tst_Expected::constructByValueIntQStringRValue() noexcept
{
    boilerplate::Expected< int, QString > expected( 2 );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueIntQStringLValue() noexcept
{
    int i = 2;
    boilerplate::Expected< int, QString > expected( i );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueDoubleQStringRValue() noexcept
{
    boilerplate::Expected< double, QString > expected( 2.4 );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueDoubleQStringLValue() noexcept
{
    double d = 2.4;
    boilerplate::Expected< double, QString > expected( d );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueVectorQStringRValue() noexcept
{
    boilerplate::Expected< QVector< QString >, QString > expected( QVector< QString >{} );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueVectorQStringLValue() noexcept
{
    QVector< QString > vec;
    boilerplate::Expected< decltype( vec ), QString > expected( vec );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueVectorQStringMove() noexcept
{
    QVector< QString > vec;
    boilerplate::Expected< decltype( vec ), QString > expected( std::move( vec ) );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueRefWrapperQStringLValue() noexcept
{
    QString s;
    std::reference_wrapper< QString > ref( s );
    boilerplate::Expected< decltype( ref ), QString > expected( ref );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueIntIntRValue() noexcept
{
    boilerplate::Expected< int, int > expected( 2 );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueIntIntLValue() noexcept
{
    int i = 2;
    boilerplate::Expected< int, int > expected( i );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueDoubleDoubleRValue() noexcept
{
    boilerplate::Expected< double, double > expected( 2.4 );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueDoubleDoubleLValue() noexcept
{
    double d = 2.4;
    boilerplate::Expected< double, double > expected( d );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueQStringQStringRValue() noexcept
{
    boilerplate::Expected< QString, QString > expected( "test" );
    QCOMPARE( expected.operator bool(), true );
}

void Tst_Expected::constructByValueQStringQStringLValue() noexcept
{
    QString s = "test";
    boilerplate::Expected< QString, QString > expected( s );
    QCOMPARE( static_cast< bool >( expected ), true );
}

void Tst_Expected::constructByValueUniquePtrUniquePtrRValue() noexcept
{
    boilerplate::Expected< std::unique_ptr< QString >, std::unique_ptr< QString > > expected( std::make_unique< QString >( "test" ) );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueUniquePtrUniquePtrMove() noexcept
{
    auto ptr = std::make_unique< QString >( "test" );
    boilerplate::Expected< std::unique_ptr< QString >, std::unique_ptr< QString > > expected( std::move( ptr ) );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByValueRefWrapperRefWrapperLValue() noexcept
{
    QString s;
    std::reference_wrapper< QString > ref( s );
    boilerplate::Expected< decltype( ref ), decltype( ref ) > expected( ref );
    QCOMPARE( expected.hasValue(), true );
}

void Tst_Expected::constructByErrorQStringIntRValue() noexcept
{
    boilerplate::Expected< QString, int > expected( boilerplate::make_unexpected_type( 2 ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorQStringIntLValue() noexcept
{
    int i = 2;
    boilerplate::Expected< QString, int > expected( boilerplate::make_unexpected_type( i ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorQStringDoubleRValue() noexcept
{
    boilerplate::Expected< QString, double > expected( boilerplate::make_unexpected_type( 2.4 ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorQStringDoubleLValue() noexcept
{
    double d = 2.4;
    boilerplate::Expected< QString, double > expected( boilerplate::make_unexpected_type( d ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorQStringVectorRValue() noexcept
{
    boilerplate::Expected< QString, QVector< QString > > expected( boilerplate::make_unexpected_type( QVector< QString >{} ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorQStringVectorLValue() noexcept
{
    QVector< QString > vec;
    boilerplate::Expected< QString, decltype( vec ) > expected( boilerplate::make_unexpected_type( vec ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorQStringVectorMove() noexcept
{
    QVector< QString > vec;
    boilerplate::Expected< QString, decltype( vec ) > expected( boilerplate::make_unexpected_type( std::move( vec ) ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorQStringRefWrapperLValue() noexcept
{
    QString s;
    std::reference_wrapper< QString > ref( s );
    boilerplate::Expected< QString, decltype( ref ) > expected( boilerplate::make_unexpected_type( ref ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorIntIntRValue() noexcept
{
    boilerplate::Expected< int, int > expected( boilerplate::make_unexpected_type( 2 ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorIntIntLValue() noexcept
{
    int i = 2;
    boilerplate::Expected< int, int > expected( boilerplate::make_unexpected_type( i ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorDoubleDoubleRValue() noexcept
{
    boilerplate::Expected< double, double > expected( boilerplate::make_unexpected_type( 2.4 ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorDoubleDoubleLValue() noexcept
{
    double d;
    boilerplate::Expected< double, double > expected( boilerplate::make_unexpected_type( d ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorQStringQStringRValue() noexcept
{
    boilerplate::Expected< QString, QString > expected( boilerplate::make_unexpected_type( QString( "test" ) ) );
    QCOMPARE( expected.operator bool(), false );
}

void Tst_Expected::constructByErrorQStringQStringLValue() noexcept
{
    QString s = "test";
    boilerplate::Expected< QString, QString > expected( boilerplate::make_unexpected_type( s ) );
    QCOMPARE( static_cast< bool >( expected ), false );
}

void Tst_Expected::constructByErrorUniquePtrUniqueRValue() noexcept
{
    boilerplate::Expected< std::unique_ptr< QString >, std::unique_ptr< QString > > expected( boilerplate::make_unexpected_type( std::make_unique< QString >( "test" ) ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorUniquePtrUniqueMove() noexcept
{
    auto ptr = std::make_unique< QString >( "test" );
    boilerplate::Expected< std::unique_ptr< QString >, std::unique_ptr< QString > > expected( boilerplate::make_unexpected_type( std::move( ptr ) ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::constructByErrorRefWrapperRefWrapperLValue() noexcept
{
    QString s;
    std::reference_wrapper< QString > ref( s );
    boilerplate::Expected< decltype( ref ), decltype( ref ) > expected( boilerplate::make_unexpected_type( ref ) );
    QCOMPARE( expected.hasValue(), false );
}

void Tst_Expected::ctorAndDtorCountValueCtorMocQStringLValue() noexcept
{
    {
        ExpectedMoc moc;
        boilerplate::Expected< ExpectedMoc, QString > expected( moc );
        QCOMPARE( ExpectedMoc::getCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getCopyCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getMoveCtorCount(), 0 );
    }
    QCOMPARE( 2, ExpectedMoc::getDtorCount() );
}

void Tst_Expected::ctorAndDtorCountValueCtorMocQStringRValue() noexcept
{
    {
        boilerplate::Expected< ExpectedMoc, QString > expected( ExpectedMoc{} );
        QCOMPARE( ExpectedMoc::getCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getCopyCtorCount(), 0 );
        QCOMPARE( ExpectedMoc::getMoveCtorCount(), 1 );
    }
    QCOMPARE( 2, ExpectedMoc::getDtorCount() );
}

void Tst_Expected::ctorAndDtorCountValueCtorMocQStringMove() noexcept
{
    {
        ExpectedMoc moc;
        boilerplate::Expected< ExpectedMoc, QString > expected( std::move( moc ) );
        QCOMPARE( ExpectedMoc::getCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getCopyCtorCount(), 0 );
        QCOMPARE( ExpectedMoc::getMoveCtorCount(), 1 );
    }
    QCOMPARE( 2, ExpectedMoc::getDtorCount() );
}

void Tst_Expected::ctorAndDtorCountErrorCtorQStringMocLValue() noexcept
{
    {
        ExpectedMoc moc;
        boilerplate::Expected< QString, ExpectedMoc > expected( boilerplate::make_unexpected_type( moc ) );
        QCOMPARE( ExpectedMoc::getCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getCopyCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getMoveCtorCount(), 1 );
    }
    QCOMPARE( 3, ExpectedMoc::getDtorCount() );
}

void Tst_Expected::ctorAndDtorCountErrorCtorQStringMocRValue() noexcept
{
    {
        boilerplate::Expected< QString, ExpectedMoc > expected( boilerplate::make_unexpected_type( ExpectedMoc{} ) );
        QCOMPARE( ExpectedMoc::getCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getCopyCtorCount(), 0 );
        QCOMPARE( ExpectedMoc::getMoveCtorCount(), 2 );
    }
    QCOMPARE( 3, ExpectedMoc::getDtorCount() );
}

void Tst_Expected::ctorAndDtorCountErrorCtorQStringMocMove() noexcept
{
    {
        ExpectedMoc moc;
        boilerplate::Expected< QString, ExpectedMoc > expected( boilerplate::make_unexpected_type( std::move( moc ) ) );
        QCOMPARE( ExpectedMoc::getCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getCopyCtorCount(), 0 );
        QCOMPARE( ExpectedMoc::getMoveCtorCount(), 2 );
    }
    QCOMPARE( 3, ExpectedMoc::getDtorCount() );
}

void Tst_Expected::assigmentAndDtorCountValueCtorCopy() noexcept
{
    {
        ExpectedMoc moc1;
        boilerplate::Expected< ExpectedMoc, QString > expected1( moc1 );

        ExpectedMoc moc2;
        boilerplate::Expected< ExpectedMoc, QString > expected2( moc2 );

        expected1 = expected2;

        QCOMPARE( ExpectedMoc::getCtorCount(), 2 );
        QCOMPARE( ExpectedMoc::getCopyCtorCount(), 3 );
        QCOMPARE( ExpectedMoc::getMoveCtorCount(), 0 );
    }
    QCOMPARE( 5, ExpectedMoc::getDtorCount() );
}

void Tst_Expected::assigmentAndDtorCountValueCtorMove() noexcept
{
    {
        ExpectedMoc moc1;
        boilerplate::Expected< ExpectedMoc, QString > expected1( moc1 );

        ExpectedMoc moc2;
        boilerplate::Expected< ExpectedMoc, QString > expected2( moc2 );

        expected1 = std::move( expected2 );

        QCOMPARE( ExpectedMoc::getCtorCount(), 2 );
        QCOMPARE( ExpectedMoc::getCopyCtorCount(), 2 );
        QCOMPARE( ExpectedMoc::getMoveCtorCount(), 1 );
    }
    QCOMPARE( 5, ExpectedMoc::getDtorCount() );
}

void Tst_Expected::assigmentAndDtorCountErrorCtorCopy() noexcept
{
    {
        ExpectedMoc moc1;
        boilerplate::Expected< ExpectedMoc, QString > expected1( moc1 );

        QString s;
        boilerplate::Expected< ExpectedMoc, QString > expected2( boilerplate::make_unexpected_type( s ) );

        expected1 = expected2;

        QCOMPARE( ExpectedMoc::getCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getCopyCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getMoveCtorCount(), 0 );
    }
    QCOMPARE( 2, ExpectedMoc::getDtorCount() );
}

void Tst_Expected::assigmentAndDtorCountErrorCtorMove() noexcept
{
    {
        ExpectedMoc moc1;
        boilerplate::Expected< ExpectedMoc, QString > expected1( moc1 );

        QString s;
        boilerplate::Expected< ExpectedMoc, QString > expected2( boilerplate::make_unexpected_type( s ) );

        expected1 = std::move( expected2 );

        QCOMPARE( ExpectedMoc::getCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getCopyCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getMoveCtorCount(), 0 );
    }
    QCOMPARE( 2, ExpectedMoc::getDtorCount() );
}

void Tst_Expected::copyInvalidExpected() noexcept
{
    int i = 23;
    boilerplate::Expected< int, QString > expected1( i );
    QCOMPARE( expected1.hasValue(), true );

    QString s;
    boilerplate::Expected< int, QString > expected2( boilerplate::make_unexpected_type( s ) );
    QCOMPARE( expected2.hasValue(), false );

    expected1 = expected2;
    QCOMPARE( expected1.hasValue(), false );
}

void Tst_Expected::moveInvalidExpected() noexcept
{
    QString s1;
    boilerplate::Expected< QString, QString > expected1( s1 );
    QCOMPARE( expected1.hasValue(), true );

    QString s2;
    boilerplate::Expected< QString, QString > expected2( boilerplate::make_unexpected_type( s2 ) );
    QCOMPARE( expected2.hasValue(), false );

    expected1 = std::move( expected2 );
    QCOMPARE( expected1.hasValue(), false );
}

void Tst_Expected::copyValidExpected() noexcept
{
    int i = 23;
    boilerplate::Expected< int, QString > expected1( i );
    QCOMPARE( expected1.hasValue(), true );

    QString s;
    boilerplate::Expected< int, QString > expected2( boilerplate::make_unexpected_type( s ) );
    QCOMPARE( expected2.hasValue(), false );

    expected2 = expected1;
    QCOMPARE( expected2.hasValue(), true );
}

void Tst_Expected::moveValidExpected() noexcept
{
    QString s1;
    boilerplate::Expected< QString, QString > expected1( s1 );
    QCOMPARE( expected1.hasValue(), true );

    QString s2;
    boilerplate::Expected< QString, QString > expected2( boilerplate::make_unexpected_type( s2 ) );
    QCOMPARE( expected2.hasValue(), false );

    expected2 = std::move( expected1 );
    QCOMPARE( expected2.hasValue(), true );
}

void Tst_Expected::valueCheckQStringIntLValue() noexcept
{
    QString s = "test";
    boilerplate::Expected< QString, int > expected( s );
    QCOMPARE( expected.getValue(), s );
}

void Tst_Expected::valueCheckQStringIntRValue() noexcept
{
    boilerplate::Expected< QString, int > expected( QString( "test" ) );
    QCOMPARE( *expected, "test" );
}

void Tst_Expected::valueCheckQStringQStringLValue() noexcept
{
    QString s = "test";
    boilerplate::Expected< QString, QString > expected( s );
    QCOMPARE( expected.getValue(), s );
}

void Tst_Expected::valueCheckByGetValueRefWrapperQStringLValue() noexcept
{
    QString s = "test";
    std::reference_wrapper< QString > ref( s );
    boilerplate::Expected< std::reference_wrapper< QString >, QString > expected( ref );
    QCOMPARE( expected.getValue(), s );
    expected.getValue().get() = "changed";
    QCOMPARE( s, "changed" );
}

void Tst_Expected::valueCheckByDereferencingRefWrapperQStringLValue() noexcept
{
    QString s = "test";
    std::reference_wrapper< QString > ref( s );
    boilerplate::Expected< std::reference_wrapper< QString >, QString > expected( ref );
    QCOMPARE( expected.getValue(), s );
    ( *expected ).get() = "changed";
    QCOMPARE( s, "changed" );
}

void Tst_Expected::valueCheckRefWrapperRefWrapperLValue() noexcept
{
    QString s = "test";
    std::reference_wrapper< QString > ref( s );
    boilerplate::Expected< std::reference_wrapper< QString >, std::reference_wrapper< QString > > expected( ref );
    QCOMPARE( expected.getValue(), s );
    ( *expected ).get() = "changed";
    QCOMPARE( s, "changed" );
}

void Tst_Expected::valueCheckAfterMoveExpectedQStringIntLValue() noexcept
{
    QString s = "test";
    boilerplate::Expected< QString, int > expected1( s );

    int i = 23;
    boilerplate::Expected< QString, int > expected2( boilerplate::make_unexpected_type( i ) );
    QCOMPARE( expected2.hasValue(), false );

    expected2 = std::move( expected1 );
    QCOMPARE( expected2.getValue(), s );
}

void Tst_Expected::valueCheckAfterMoveExpectedQStringQStringLValue() noexcept
{
    QString s1 = "value";
    boilerplate::Expected< QString, QString > expected1( s1 );

    QString s2 = "error";
    boilerplate::Expected< QString, QString > expected2( boilerplate::make_unexpected_type( s2 ) );
    QCOMPARE( expected2.hasValue(), false );

    expected2 = std::move( expected1 );
    QCOMPARE( expected2.getValue(), s1 );
}

void Tst_Expected::valueCheckAfterMoveExpectedQStringRefWrapperLValue() noexcept
{
    QString s1 = "value";
    boilerplate::Expected< QString, std::reference_wrapper< QString > > expected1( s1 );

    QString s2 = "error";
    std::reference_wrapper< QString > ref( s2 );
    boilerplate::Expected< QString, std::reference_wrapper< QString > > expected2( boilerplate::make_unexpected_type( ref ) );
    QCOMPARE( expected2.hasValue(), false );

    expected2 = std::move( expected1 );
    QCOMPARE( expected2.getValue(), s1 );
}

void Tst_Expected::valueCheckAfterMoveExpectedQStringMocLValue() noexcept
{
    QString s1 = "value";
    boilerplate::Expected< QString, ExpectedMoc > expected1( s1 );

    boilerplate::Expected< QString, ExpectedMoc > expected2( boilerplate::make_unexpected_type( ExpectedMoc{} ) );
    QCOMPARE( expected2.hasValue(), false );

    expected2 = std::move( expected1 );
    QCOMPARE( expected2.getValue(), s1 );
    QCOMPARE( ExpectedMoc::getCtorCount(), 1 );
    QCOMPARE( ExpectedMoc::getCopyCtorCount(), 0 );
    QCOMPARE( ExpectedMoc::getMoveCtorCount(), 2 );
    QCOMPARE( ExpectedMoc::getDtorCount(), 3 );
}

void Tst_Expected::errorCheckQStringIntLValue() noexcept
{
    int i = 23;
    boilerplate::Expected< QString, int > expected( boilerplate::make_unexpected_type( i ) );
    QCOMPARE( expected.getError(), 23 );
}

void Tst_Expected::errorCheckQStringIntRValue() noexcept
{
    boilerplate::Expected< QString, int > expected( boilerplate::make_unexpected_type( 23 ) );
    QCOMPARE( expected.getError(), 23 );
}

void Tst_Expected::errorCheckQStringQStringLValue() noexcept
{
    QString s = "test";
    boilerplate::Expected< QString, QString > expected( boilerplate::make_unexpected_type( s ) );
    QCOMPARE( expected.getError(), s );
}

void Tst_Expected::errorCheckQStringRefWrapperLValue() noexcept
{
    QString s = "test";
    std::reference_wrapper< QString > ref( s );
    boilerplate::Expected< QString, std::reference_wrapper< QString > > expected( boilerplate::make_unexpected_type( ref ) );
    QCOMPARE( expected.getError(), s );
    expected.getError().get() = "changed";
    QCOMPARE( s, "changed" );
}

void Tst_Expected::errorCheckRefWrapperRefWrapperLValue() noexcept
{
    QString s = "test";
    std::reference_wrapper< QString > ref( s );
    boilerplate::Expected< std::reference_wrapper< QString >, std::reference_wrapper< QString > > expected( boilerplate::make_unexpected_type( ref ) );
    QCOMPARE( expected.getError(), s );
    expected.getError().get() = "changed";
    QCOMPARE( s, "changed" );
}

void Tst_Expected::errorCheckAfterMoveExpectedQStringIntLValue() noexcept
{
    QString s = "test";
    boilerplate::Expected< QString, int > expected1( s );
    QCOMPARE( expected1.hasValue(), true );

    int i = 23;
    boilerplate::Expected< QString, int > expected2( boilerplate::make_unexpected_type( i ) );

    expected1 = std::move( expected2 );
    QCOMPARE( expected1.getError(), 23 );
}

void Tst_Expected::errorCheckAfterMoveExpectedQStringQStringLValue() noexcept
{
    QString s1 = "value";
    boilerplate::Expected< QString, QString > expected1( s1 );
    QCOMPARE( expected1.hasValue(), true );

    QString s2 = "error";
    boilerplate::Expected< QString, QString > expected2( boilerplate::make_unexpected_type( s2 ) );

    expected1 = std::move( expected2 );
    QCOMPARE( expected1.getError(), s2 );
}

void Tst_Expected::errorCheckAfterMoveExpectedQStringRefWrapperLValue() noexcept
{
    QString s1 = "value";
    boilerplate::Expected< QString, std::reference_wrapper< QString > > expected1( s1 );
    QCOMPARE( expected1.hasValue(), true );

    QString s2 = "error";
    std::reference_wrapper< QString > ref( s2 );
    boilerplate::Expected< QString, std::reference_wrapper< QString > > expected2( boilerplate::make_unexpected_type( ref ) );

    expected1 = std::move( expected2 );
    QCOMPARE( expected1.getError(), s2 );
}

void Tst_Expected::errorCheckAfterMoveExpectedQStringMocRValue() noexcept
{
    {
        QString s1 = "value";
        boilerplate::Expected< QString, ExpectedMoc > expected1( s1 );
        QCOMPARE( expected1.hasValue(), true );

        boilerplate::Expected< QString, ExpectedMoc > expected2( boilerplate::make_unexpected_type( ExpectedMoc{} ) );

        expected1 = std::move( expected2 );
        QCOMPARE( expected1.hasValue(), false );
        QCOMPARE( ExpectedMoc::getCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getCopyCtorCount(), 0 );
        QCOMPARE( ExpectedMoc::getMoveCtorCount(), 3 );
    }
    QCOMPARE( ExpectedMoc::getDtorCount(), 4 );
}

void Tst_Expected::errorCheckAfterCopyExpectedQStringMocRValue() noexcept
{
    {
        QString s1 = "value";
        boilerplate::Expected< QString, ExpectedMoc > expected1( s1 );
        QCOMPARE( expected1.hasValue(), true );

        boilerplate::Expected< QString, ExpectedMoc > expected2( boilerplate::make_unexpected_type( ExpectedMoc{} ) );

        expected1 = expected2;
        QCOMPARE( expected1.hasValue(), false );
        QCOMPARE( ExpectedMoc::getCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getCopyCtorCount(), 1 );
        QCOMPARE( ExpectedMoc::getMoveCtorCount(), 2 );
    }
    QCOMPARE( ExpectedMoc::getDtorCount(), 4 );
}

}
}
}