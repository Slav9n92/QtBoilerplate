/*
 * \file Tst_Expected.h
 * \copyright :
 * \author : Bubnov V.V.
 * \date : 27.06.2025
 * \time : 13:48
 */

#pragma once

#include <QtCore>
#include <boilerplate/expected/Expected.h>

namespace qt {
namespace boilerplate {
namespace testing {

class Tst_Expected : public QObject
{
//@formatter:off
    Q_OBJECT
//@formatter:on

public:
    explicit Tst_Expected( QObject* parent = nullptr ) noexcept;

private slots:
            void cleanup() noexcept;

    void constructByValueIntQStringRValue() noexcept;
    void constructByValueIntQStringLValue() noexcept;
    void constructByValueDoubleQStringRValue() noexcept;
    void constructByValueDoubleQStringLValue() noexcept;
    void constructByValueVectorQStringRValue() noexcept;
    void constructByValueVectorQStringLValue() noexcept;
    void constructByValueVectorQStringMove() noexcept;
    void constructByValueRefWrapperQStringLValue() noexcept;

    void constructByValueIntIntRValue() noexcept;
    void constructByValueIntIntLValue() noexcept;
    void constructByValueDoubleDoubleRValue() noexcept;
    void constructByValueDoubleDoubleLValue() noexcept;
    void constructByValueQStringQStringRValue() noexcept;
    void constructByValueQStringQStringLValue() noexcept;
    void constructByValueUniquePtrUniquePtrRValue() noexcept;
    void constructByValueUniquePtrUniquePtrMove() noexcept;
    void constructByValueRefWrapperRefWrapperLValue() noexcept;

    void constructByErrorQStringIntRValue() noexcept;
    void constructByErrorQStringIntLValue() noexcept;
    void constructByErrorQStringDoubleRValue() noexcept;
    void constructByErrorQStringDoubleLValue() noexcept;
    void constructByErrorQStringVectorRValue() noexcept;
    void constructByErrorQStringVectorLValue() noexcept;
    void constructByErrorQStringVectorMove() noexcept;
    void constructByErrorQStringRefWrapperLValue() noexcept;

    void constructByErrorIntIntRValue() noexcept;
    void constructByErrorIntIntLValue() noexcept;
    void constructByErrorDoubleDoubleRValue() noexcept;
    void constructByErrorDoubleDoubleLValue() noexcept;
    void constructByErrorQStringQStringRValue() noexcept;
    void constructByErrorQStringQStringLValue() noexcept;
    void constructByErrorUniquePtrUniqueRValue() noexcept;
    void constructByErrorUniquePtrUniqueMove() noexcept;
    void constructByErrorRefWrapperRefWrapperLValue() noexcept;

    void ctorAndDtorCountValueCtorMocQStringLValue() noexcept;
    void ctorAndDtorCountValueCtorMocQStringRValue() noexcept;
    void ctorAndDtorCountValueCtorMocQStringMove() noexcept;
    void ctorAndDtorCountErrorCtorQStringMocLValue() noexcept;
    void ctorAndDtorCountErrorCtorQStringMocRValue() noexcept;
    void ctorAndDtorCountErrorCtorQStringMocMove() noexcept;

    void assigmentAndDtorCountValueCtorCopy() noexcept;
    void assigmentAndDtorCountValueCtorMove() noexcept;
    void assigmentAndDtorCountErrorCtorCopy() noexcept;
    void assigmentAndDtorCountErrorCtorMove() noexcept;

    void copyInvalidExpected() noexcept;
    void moveInvalidExpected() noexcept;
    void copyValidExpected() noexcept;
    void moveValidExpected() noexcept;

    void valueCheckQStringIntLValue() noexcept;
    void valueCheckQStringIntRValue() noexcept;
    void valueCheckQStringQStringLValue() noexcept;
    void valueCheckByGetValueRefWrapperQStringLValue() noexcept;
    void valueCheckByDereferencingRefWrapperQStringLValue() noexcept;
    void valueCheckRefWrapperRefWrapperLValue() noexcept;
    void valueCheckAfterMoveExpectedQStringIntLValue() noexcept;
    void valueCheckAfterMoveExpectedQStringQStringLValue() noexcept;
    void valueCheckAfterMoveExpectedQStringRefWrapperLValue() noexcept;
    void valueCheckAfterMoveExpectedQStringMocLValue() noexcept;

    void errorCheckQStringIntLValue() noexcept;
    void errorCheckQStringIntRValue() noexcept;
    void errorCheckQStringQStringLValue() noexcept;
    void errorCheckQStringRefWrapperLValue() noexcept;
    void errorCheckRefWrapperRefWrapperLValue() noexcept;
    void errorCheckAfterMoveExpectedQStringIntLValue() noexcept;
    void errorCheckAfterMoveExpectedQStringQStringLValue() noexcept;
    void errorCheckAfterMoveExpectedQStringRefWrapperLValue() noexcept;
    void errorCheckAfterMoveExpectedQStringMocRValue() noexcept;
    void errorCheckAfterCopyExpectedQStringMocRValue() noexcept;
};

}
}
}