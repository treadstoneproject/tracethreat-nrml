/* The file is part of Snowman decompiler. */
/* See doc/licenses.asciidoc for the licensing information. */

#include "Driver.h"

#include <nc/common/Foreach.h>
#include <nc/common/Exception.h>

#include <nc/core/arch/Architecture.h>
#include <nc/core/arch/Disassembler.h>
#include <nc/core/arch/Instructions.h>
#include <nc/core/image/Image.h>
#include <nc/core/image/Section.h>
#include <nc/core/input/Parser.h>
#include <nc/core/input/ParserRepository.h>

#include "Context.h"


#include <fstream>

namespace nc {
namespace core {

void Driver::parse(Context &context, const folly::fbstring &filename) {
    //QFile source(filename);
    std::ofstream source;
    source.open(filename.c_str());
    if (source.is_open()) {
        //throw nc::Exception(tr("Could not open file \"%1\" for reading.").arg(filename));
        LOG(INFO)<<"Open file";
    }else{
        LOG(INFO)<<"Could not open file";
    }

    //context.logToken().info(tr("Choosing a parser for %1...").arg(filename));
    LOG(INFO)<<"Choosing a parser for ... : " << filename ;

    const input::Parser *suitableParser = nullptr;

    foreach(const input::Parser *parser, input::ParserRepository::instance()->parsers()) {

        //context.logToken().info(tr("Trying %1 parser...").arg(parser->name()));

        LOG(INFO)<<"Trying :  "<< parser->name() <<" parser... : ";

        if (parser->canParse(&source)) {
            suitableParser = parser;
            break;
        }
    }

    if (!suitableParser) {
        LOG(INFO)<<"No suitable parser found";

//        context.logToken().error(tr("No suitable parser found."));
        //throw nc::Exception(tr("File %1 has unknown format.").arg(filename));
    }

//    context.logToken().info(tr("Parsing using %1 parser...").arg(suitableParser->name()));
    LOG(INFO)<<"Parsing using %1 parser... : "<<suitableParser->name();

    suitableParser->parse(&source, context.image().get());//, context.logToken());

//    context.logToken().info(tr("Parsing completed."));
    LOG(INFO)<<"Parsing completed.";
}

void Driver::disassemble(Context &context) {
//    context.logToken().info(tr("Disassemble code sections."));
    LOG(INFO)<<"Disassemble code sections.";
    foreach (auto section, context.image()->sections()) {
        if (section->isCode()) {
            disassemble(context, section);
        }
    }
}

void Driver::disassemble(Context &context, const image::Section *section) {
    assert(section != nullptr);

    //context.logToken().info(tr("Disassemble section %1...").arg(section->name()));
    LOG(INFO)<<"Disassemble section %1... : "<<section->name();
    disassemble(context, section, section->addr(), section->endAddr());
}

void Driver::disassemble(Context &context, const image::ByteSource *source, ByteAddr begin, ByteAddr end) {
    assert(source != nullptr);

    //context.logToken().info(tr("Disassemble addresses from 0x%2 to 0x%3...").arg(begin, 0, 16).arg(end, 0, 16));
    //LOG(INFO)<<"Disassemble addresses from 0x%2 to 0x%3... : " << 
    //try {
        auto newInstructions = std::make_shared<arch::Instructions>(*context.instructions());

        context.image()->platform().architecture()->createDisassembler()->disassemble(
            context.image().get(),
            source,
            begin,
            end,
            [&](std::shared_ptr<arch::Instruction> instr){ newInstructions->add(std::move(instr)); },
            context.cancellationToken());

        context.setInstructions(newInstructions);

        //context.logToken().info(tr("Disassembly completed."));
        LOG(INFO)<<"Disassembly completed.";
    //} catch (const CancellationException &) {
        //context.logToken().info(tr("Disassembly canceled."));
        //LOG(INFO)<<"Disassembly canceled.";
    //}
}
/*
void Driver::decompile(Context &context) {
    try {
        context.image()->platform().architecture()->masterAnalyzer()->decompile(context);
    } catch (const CancellationException &) {
        //context.logToken().info(tr("Decompilation canceled."));
        LOG(INFO)<<"Decompilation canceled.";
        throw;
    }
}
*/
} // namespace core
} // namespace nc

/* vim:set et sts=4 sw=4: */
