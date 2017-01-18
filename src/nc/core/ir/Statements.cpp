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

#include "Statements.h"

//#include <folly::fbstring>

#include <folly/FBString.h>
#include <folly/Conv.h>

#include <nc/common/Unreachable.h>
#include <nc/common/make_unique.h>

#include <nc/core/arch/Instruction.h>

namespace nc {
namespace core {
namespace ir {

std::unique_ptr<Statement> InlineAssembly::doClone() const {
    return std::make_unique<InlineAssembly>();
}

void InlineAssembly::print(folly::fbstring &out) const {
    out.append( "asm { ");
    if (instruction()) {
        std::ostringstream ostr;
        ostr<<instruction();
        out.append(ostr.str());
        //out.append(folly::to<folly::fbstring>(*instruction()));
    }
    out.append(" }");
}

Assignment::Assignment(std::unique_ptr<Term> left, std::unique_ptr<Term> right):
    Statement(ASSIGNMENT), left_(std::move(left)), right_(std::move(right))
{
    assert(left_);
    assert(right_);
    assert(left_->size() == right_->size());

    left_->setStatement(this);
    right_->setStatement(this);
}

std::unique_ptr<Statement> Assignment::doClone() const {
    return std::make_unique<Assignment>(left()->clone(), right()->clone());
}

void Assignment::print(folly::fbstring &out) const {
     std::ostringstream leftStr_;
     leftStr_ << &left_;
     std::ostringstream rightStr_;
     rightStr_ << &right_;
    out.append(folly::to<folly::fbstring>(leftStr_.str())).append( " = ").append(folly::to<folly::fbstring>(rightStr_.str()));
}

Touch::Touch(std::unique_ptr<Term> term, Term::AccessType accessType):
    Statement(TOUCH), term_(std::move(term)), accessType_(accessType)
{
    assert(term_);

    term_->setStatement(this);
}

std::unique_ptr<Statement> Touch::doClone() const {
    return std::make_unique<Touch>(term()->clone(), term()->accessType());
}

void Touch::print(folly::fbstring &out) const {
    switch (term()->accessType()) {
        case Term::READ:
            out.append( "read");
            break;
        case Term::WRITE:
            out.append("write");
            break;
        default:
            unreachable();
    }
    std::ostringstream termStr_;
    termStr_ << &term_;
    out.append( "(" ).append(folly::to<folly::fbstring>(termStr_.str())).append( ")"); //<< endl;
}

Call::Call(std::unique_ptr<Term> target):
    Statement(CALL), 
    target_(std::move(target))
{
    assert(target_ != nullptr);

    target_->setStatement(this);
}

std::unique_ptr<Statement> Call::doClone() const {
    return std::make_unique<Call>(target()->clone());
}

void Call::print(folly::fbstring &out) const {
    //out << "call " << *target_ << endl;
     std::ostringstream  targetStr_;
    targetStr_ << &target_;
    out.append("call ").append(folly::to<folly::fbstring>(targetStr_.str()));
}

std::unique_ptr<Statement> Halt::doClone() const {
    return std::make_unique<Halt>();
}

void Halt::print(folly::fbstring &out) const {
    //out << "halt" << endl;
    out.append("halt");
}

std::unique_ptr<Statement> Callback::doClone() const {
    return std::make_unique<Callback>(function());
}

void Callback::print(folly::fbstring &out) const {
    //out << "callback" << endl;
    out.append("callback");
}

std::unique_ptr<Statement> RememberReachingDefinitions::doClone() const {
    return std::make_unique<RememberReachingDefinitions>();
}

void RememberReachingDefinitions::print(folly::fbstring &out) const {
    //out << "remember_reaching_definitions" << endl;
    out.append("remember_reaching_definitions");
}

} // namespace ir
} // namespace core
} // namespace nc

/* vim:set et sts=4 sw=4: */
