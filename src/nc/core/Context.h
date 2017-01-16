/* The file is part of Snowman decompiler. */
/* See doc/licenses.asciidoc for the licensing information. */

/* * SmartDec decompiler - SmartDec is a native code to C/C++ decompiler
 * Copyright (C) 2015 Alexander Chernov, Katerina Troshina, Yegor Derevenets,
 * Alexander Fokin, Sergey Levin, Leonid Tsvetkov
 *
 * This file is part of SmartDec decompiler.
 *
 * SmartDec decompiler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SmartDec decompiler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SmartDec decompiler.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

//#include <nc/config.h>

#include <memory> /* For std::unique_ptr. */

//#include <QObject>

#include <nc/common/CancellationToken.h>
//#include <nc/common/LogToken.h>

namespace nc {
namespace core {

namespace arch {
    class Instructions;
}

namespace image {
    class Image;
}

namespace ir {
    class Function;
    class Functions;
    class Program;

    namespace calling {
        class Conventions;
        class Hooks;
        class Signatures;
    }
    namespace cflow {
        class Graphs;
    }
    namespace dflow {
        class Dataflows;
    }
    namespace types {
        class Types;
    }
    namespace liveness {
        class Livenesses;
    }
    namespace vars {
        class Variables;
    }
}

namespace likec {
    class Tree;
}

/**
 * This class stores all the information that is required and produced during decompilation.
 */
class Context /*: public QObject*/ {
    //Q_OBJECT

    std::shared_ptr<image::Image> image_; ///< Executable image being decompiled.
    std::shared_ptr<const arch::Instructions> instructions_; ///< Instructions being decompiled.
/*    std::unique_ptr<ir::Program> program_; ///< Program.
    std::unique_ptr<ir::Functions> functions_; ///< Functions.
    std::unique_ptr<ir::calling::Conventions> conventions_; ///< Assigned calling conventions.
    std::unique_ptr<ir::calling::Hooks> hooks_; ///< Hooks manager.
    std::unique_ptr<ir::calling::Signatures> signatures_; ///< Signatures.
    std::unique_ptr<ir::dflow::Dataflows> dataflows_; ///< Dataflows.
    std::unique_ptr<ir::vars::Variables> variables_; ///< Reconstructed variables.
    std::unique_ptr<ir::cflow::Graphs> graphs_; ///< Structured graphs.
    std::unique_ptr<ir::liveness::Livenesses> livenesses_; ///< Liveness information.
    std::unique_ptr<ir::types::Types> types_; ///< Information about types.
    std::unique_ptr<likec::Tree> tree_; ///< Abstract syntax tree of the LikeC program.
    LogToken logToken_; ///< Log token. */
    CancellationToken cancellationToken_; ///< Cancellation token.

public:
    /**
     * Class constructor.
     */
    Context();

    /**
     * Class destructor.
     */
    ~Context();

    /**
     * Sets the executable image being decompiled.
     *
     * \param image Pointer to the image. Can be nullptr.
     */
    void setImage(const std::shared_ptr<image::Image> &image);

    /**
     * \return Pointer to the executable image being decompiled. Can be nullptr.
     */
    std::shared_ptr<image::Image> image() const { return image_; }

    /**
     * Sets the set instructions being decompiled.
     *
     * \param instructions Pointer to the new set of instructions. Can be nullptr.
     */
    void setInstructions(const std::shared_ptr<const arch::Instructions> &instructions);

    /**
     * \returns Pointer to the instructions being decompiled. Can be nullptr.
     */
    const std::shared_ptr<const arch::Instructions> &instructions() const { return instructions_; }


    /**
     * Sets the information about types.
     *
     * \param[in] types Pointer to the information about types. Can be nullptr.
     */
    //void setTypes(std::unique_ptr<ir::types::Types> types);

    /**
     * \return Pointer to the information about types. Can be nullptr.
     */
    //const ir::types::Types *types() const { return types_.get(); }

    /**
     * Sets the LikeC tree.
     *
     * \param tree Valid pointer to the LikeC tree.
     */
    //void setTree(std::unique_ptr<likec::Tree> tree);

    /**
     * \return The LikeC tree. Can be nullptr.
     */
    //likec::Tree *tree() const { return tree_.get(); }

    /**
     * Sets cancellation token.
     *
     * \param token Cancellation token.
     */
    void setCancellationToken(const CancellationToken &token) { cancellationToken_ = token; }

    /**
     * \return Cancellation token.
     */
    const CancellationToken &cancellationToken() const { return cancellationToken_; }

    /**
     * Sets the log token.
     *
     * \param token log token.
     */
    //void setLogToken(const LogToken &token) { logToken_ = token; }

    /**
     * \return Log token.
     */
    //const LogToken &logToken() const { return logToken_; }

    //Q_SIGNALS:

    /**
     * Signal emitted when the set of instructions is changed.
     */
    void instructionsChanged();

    /**
     * Signal emitted when LikeC tree is computed.
     */
    //void treeChanged();
};

} // namespace core
} // namespace nc

/* vim:set et sts=4 sw=4: */
