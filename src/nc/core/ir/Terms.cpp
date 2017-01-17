/* The file is part of Snowman decompiler. */
/* See doc/licenses.asciidoc for the licensing information. */

//
// SmartDec decompiler - SmartDec is a native code to C/C++ decompiler
// Copyright (C) 2015 Alexander Chernov, Katerina Troshina, Yegor Derevenets,
// Alexander Fokin, Sergey Levin, Leonid Tsvetkov
//
// This file is part of SmartDec decompiler.
//
// SmartDec decompiler is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SmartDec decompiler is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SmartDec decompiler.  If not, see <http://www.gnu.org/licenses/>.
//

#include "Terms.h"

#include <folly/FBString.h>

#include <nc/common/Unreachable.h>
#include <nc/common/make_unique.h>

namespace nc {
namespace core {
namespace ir {

std::unique_ptr<Term> Constant::doClone() const {
    return std::make_unique<Constant>(value());
}

void Constant::doCallOnChildren(const std::function<void(Term *)> &) {}

void Constant::print(folly::fbstring &out) const {
    //out << QString(QLatin1String("0x%1")).arg(value().value(), 0, 16);
}

std::unique_ptr<Term> Intrinsic::doClone() const {
    return std::make_unique<Intrinsic>(intrinsicKind(), size());
}

void Intrinsic::doCallOnChildren(const std::function<void(Term *)> &) {}

void Intrinsic::print(folly::fbstring &out) const {
    //out << "intrinsic(" << intrinsicKind() << ")";
}

MemoryLocationAccess::MemoryLocationAccess(const MemoryLocation &memoryLocation):
    Term(MEMORY_LOCATION_ACCESS, memoryLocation.size<SmallBitSize>()), memoryLocation_(memoryLocation)
{}

std::unique_ptr<Term> MemoryLocationAccess::doClone() const {
    return std::make_unique<MemoryLocationAccess>(memoryLocation());
}

void MemoryLocationAccess::doCallOnChildren(const std::function<void(Term *)> &) {}

void MemoryLocationAccess::print(folly::fbstring &out) const {
    //out << memoryLocation_;
}

Dereference::Dereference(std::unique_ptr<Term> address, Domain domain, SmallBitSize size):
    Term(DEREFERENCE, size), domain_(domain), address_(std::move(address))
{}

std::unique_ptr<Term> Dereference::doClone() const {
    return std::make_unique<Dereference>(address()->clone(), domain(), size());
}

void Dereference::doCallOnChildren(const std::function<void(Term *)> &fun) {
    fun(address());
}

void Dereference::print(folly::fbstring &out) const {
    //out << "[" << *address() << "]";
}

UnaryOperator::UnaryOperator(int operatorKind, std::unique_ptr<Term> operand, SmallBitSize size):
    Term(UNARY_OPERATOR, size), 
    operatorKind_(operatorKind), 
    operand_(std::move(operand))
{
    assert(operand_ != nullptr);

    switch (operatorKind) {
        case NOT: case NEGATION:
            assert(size == operand_->size());
            break;
        case SIGN_EXTEND: case ZERO_EXTEND:
            assert(size > operand_->size());
            break;
        case TRUNCATE:
            assert(size < operand_->size());
            break;
    }
}

std::unique_ptr<Term> UnaryOperator::doClone() const {
    return std::make_unique<UnaryOperator>(operatorKind(), operand()->clone(), size());
}

void UnaryOperator::doCallOnChildren(const std::function<void(Term *)> &fun) {
    fun(operand());
}

void UnaryOperator::print(folly::fbstring &out) const {
    switch (operatorKind()) {
        case NOT:
            out.append("~");
            break;
        case NEGATION:
            out.append("-");
            break;
        case SIGN_EXTEND:
            out.append("sign_extend ");
            break;
        case ZERO_EXTEND:
            out.append("zero_extend ");
            break;
        case TRUNCATE:
            out.append("truncate ");
            break;
        default:
            unreachable();
            break;
    }
    //out << *operand();
}

BinaryOperator::BinaryOperator(int operatorKind, std::unique_ptr<Term> left, std::unique_ptr<Term> right, SmallBitSize size):
    Term(BINARY_OPERATOR, size), operatorKind_(operatorKind), left_(std::move(left)), right_(std::move(right))
{
    assert(left_ != nullptr);
    assert(right_ != nullptr);

    switch (operatorKind) {
        case AND: case OR: case XOR:
        case ADD: case SUB: case MUL:
        case SIGNED_DIV: case SIGNED_REM:
        case UNSIGNED_DIV: case UNSIGNED_REM:
            assert(left_->size() == right_->size());
            assert(size == left_->size());
            break;

        case SHL: case SHR: case SAR:
            assert(size == left_->size());
            break;

        case EQUAL:
        case SIGNED_LESS: case SIGNED_LESS_OR_EQUAL:
        case UNSIGNED_LESS: case UNSIGNED_LESS_OR_EQUAL:
            assert(left_->size() == right_->size());
            assert(size == 1);
            break;
    }
}

std::unique_ptr<Term> BinaryOperator::doClone() const {
    return std::make_unique<BinaryOperator>(operatorKind(), left()->clone(), right()->clone(), size());
}

void BinaryOperator::doCallOnChildren(const std::function<void(Term *)> &fun) {
    fun(left());
    fun(right());
}

void BinaryOperator::print(folly::fbstring &out) const {
    std::ostringstream leftStr;
    leftStr << left();
    out.append(folly::fbstring("(")).append(leftStr.str()).append(folly::fbstring(" "));
    switch (operatorKind()) {
        case AND:
            out.append(folly::fbstring("&"));
            break;
        case OR:
            out.append(folly::fbstring("|"));
            break;
        case XOR:
            //out << '^';
            out.append(folly::fbstring("^"));
            break;
        case SHL:
            //out << "<<";
            out.append(folly::fbstring("<<"));
            break;
        case SHR:
            //out << ">>>";
            out.append(folly::fbstring(">>>"));
            break;
        case SAR:
            //out << ">>";
            out.append(folly::fbstring(">>"));
            break;
        case ADD:
            //out << '+';
            out.append(folly::fbstring("+"));
            break;
        case SUB:
            //out << '-';
            out.append(folly::fbstring("-"));
            break;
        case MUL:
            //out << '*';
            out.append(folly::fbstring("*"));
            break;
        case SIGNED_DIV:
            //out << "(signed)/";
            out.append(folly::fbstring("(signed)/"));
            break;
        case SIGNED_REM:
            //out << "(signed)%";
            out.append(folly::fbstring("(signed)%"));
            break;
        case UNSIGNED_DIV:
            out.append(folly::fbstring("(unsigned)/"));
            //out << "(unsigned)/";
            break;
        case UNSIGNED_REM:
            //out << "(unsigned)%";
             out.append(folly::fbstring("(unsigned)%"));
            break;
        case EQUAL:
            //out << "==";
             out.append(folly::fbstring("=="));
            break;
        case SIGNED_LESS:
            out.append(folly::fbstring("(signed)<"));
            //out << "(signed)<";
            break;
        case SIGNED_LESS_OR_EQUAL:
             out.append(folly::fbstring("(signed)<="));
            //out << "(signed)<=";
            break;
        case UNSIGNED_LESS:
            out.append(folly::fbstring("(unsigned)<"));
            //out << "(unsigned)<";
            break;
        case UNSIGNED_LESS_OR_EQUAL:
            //out << "(unsigned)<=";
            out.append(folly::fbstring("(unsigned)<="));
            break;
        default:
            unreachable();
            break;
    }
    std::ostringstream rightStr;
    rightStr << right();
    out.append(" ").append(rightStr.str()).append(")");
}

} // namespace ir
} // namespace core
} // namespace nc

/* vim:set et sts=4 sw=4: */
