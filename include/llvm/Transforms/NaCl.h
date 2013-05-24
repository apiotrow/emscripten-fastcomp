//===-- NaCl.h - NaCl Transformations ---------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TRANSFORMS_NACL_H
#define LLVM_TRANSFORMS_NACL_H

namespace llvm {

class BasicBlockPass;
class FunctionPass;
class Instruction;
class ModulePass;
class Use;
class Value;

ModulePass *createExpandByValPass();
FunctionPass *createExpandConstantExprPass();
ModulePass *createExpandCtorsPass();
BasicBlockPass *createExpandGetElementPtrPass();
ModulePass *createExpandMulWithOverflowPass();
ModulePass *createExpandTlsPass();
ModulePass *createExpandTlsConstantExprPass();
ModulePass *createExpandVarArgsPass();
ModulePass *createFlattenGlobalsPass();
ModulePass *createGlobalCleanupPass();
FunctionPass *createPromoteIntegersPass();
ModulePass *createReplacePtrsWithIntsPass();
ModulePass *createResolveAliasesPass();
ModulePass *createRewritePNaClLibraryCallsPass();
ModulePass *createStripMetadataPass();
FunctionPass *createInsertDivideCheckPass();

Instruction *PhiSafeInsertPt(Use *U);
void PhiSafeReplaceUses(Use *U, Value *NewVal);

// Copy debug information from Original to NewInst, and return NewInst.
Instruction *CopyDebug(Instruction *NewInst, Instruction *Original);

}

#endif
