#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BD7B0
// Address: 0x1bd7b0 - 0x1bd910
void sub_001BD7B0_0x1bd7b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BD7B0_0x1bd7b0");
#endif

    switch (ctx->pc) {
        case 0x1bd7d4u: goto label_1bd7d4;
        case 0x1bd804u: goto label_1bd804;
        default: break;
    }

    ctx->pc = 0x1bd7b0u;

    // 0x1bd7b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bd7b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bd7b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd7b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd7b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bd7b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bd7bc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bd7bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd7c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bd7c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bd7c4: 0x24060044  addiu       $a2, $zero, 0x44
    ctx->pc = 0x1bd7c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
    // 0x1bd7c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1bd7c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd7cc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1BD7CCu;
    SET_GPR_U32(ctx, 31, 0x1BD7D4u);
    ctx->pc = 0x1BD7D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD7CCu;
            // 0x1bd7d0: 0xac3044f0  sw          $s0, 0x44F0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 17648), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD7D4u; }
        if (ctx->pc != 0x1BD7D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD7D4u; }
        if (ctx->pc != 0x1BD7D4u) { return; }
    }
    ctx->pc = 0x1BD7D4u;
label_1bd7d4:
    // 0x1bd7d4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1bd7d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bd7d8: 0x26030100  addiu       $v1, $s0, 0x100
    ctx->pc = 0x1bd7d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 256));
    // 0x1bd7dc: 0xae040008  sw          $a0, 0x8($s0)
    ctx->pc = 0x1bd7dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 4));
    // 0x1bd7e0: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1bd7e0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1bd7e4: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x1bd7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
    // 0x1bd7e8: 0x24844f30  addiu       $a0, $a0, 0x4F30
    ctx->pc = 0x1bd7e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20272));
    // 0x1bd7ec: 0x3c030002  lui         $v1, 0x2
    ctx->pc = 0x1bd7ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)2 << 16));
    // 0x1bd7f0: 0xae040018  sw          $a0, 0x18($s0)
    ctx->pc = 0x1bd7f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 4));
    // 0x1bd7f4: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x1bd7f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x1bd7f8: 0xae030014  sw          $v1, 0x14($s0)
    ctx->pc = 0x1bd7f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x1bd7fc: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1BD7FCu;
    {
        const bool branch_taken_0x1bd7fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD7FCu;
            // 0x1bd800: 0x8e050018  lw          $a1, 0x18($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd7fc) {
            ctx->pc = 0x1BD874u;
            goto label_1bd874;
        }
    }
    ctx->pc = 0x1BD804u;
label_1bd804:
    // 0x1bd804: 0x8e03001c  lw          $v1, 0x1C($s0)
    ctx->pc = 0x1bd804u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1bd808: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bd808u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bd80c: 0xae03001c  sw          $v1, 0x1C($s0)
    ctx->pc = 0x1bd80cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 3));
    // 0x1bd810: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1bd810u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bd814: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD814u;
    {
        const bool branch_taken_0x1bd814 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BD818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD814u;
            // 0x1bd818: 0x32243  sra         $a0, $v1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd814) {
            ctx->pc = 0x1BD824u;
            goto label_1bd824;
        }
    }
    ctx->pc = 0x1BD81Cu;
    // 0x1bd81c: 0x246301ff  addiu       $v1, $v1, 0x1FF
    ctx->pc = 0x1bd81cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x1bd820: 0x32243  sra         $a0, $v1, 9
    ctx->pc = 0x1bd820u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
label_1bd824:
    // 0x1bd824: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1bd824u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bd828: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd828u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd82c: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1bd82cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1bd830: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1bd830u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bd834: 0x8ca30004  lw          $v1, 0x4($a1)
    ctx->pc = 0x1bd834u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1bd838: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd838u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd83c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1bd83cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1bd840: 0x64001a  div         $zero, $v1, $a0
    ctx->pc = 0x1bd840u;
    { int32_t divisor = GPR_S32(ctx, 4);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1bd844: 0x0  nop
    ctx->pc = 0x1bd844u;
    // NOP
    // 0x1bd848: 0x0  nop
    ctx->pc = 0x1bd848u;
    // NOP
    // 0x1bd84c: 0x1812  mflo        $v1
    ctx->pc = 0x1bd84cu;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1bd850: 0x831818  mult        $v1, $a0, $v1
    ctx->pc = 0x1bd850u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1bd854: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD854u;
    {
        const bool branch_taken_0x1bd854 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BD858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD854u;
            // 0x1bd858: 0x32243  sra         $a0, $v1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd854) {
            ctx->pc = 0x1BD864u;
            goto label_1bd864;
        }
    }
    ctx->pc = 0x1BD85Cu;
    // 0x1bd85c: 0x246301ff  addiu       $v1, $v1, 0x1FF
    ctx->pc = 0x1bd85cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x1bd860: 0x32243  sra         $a0, $v1, 9
    ctx->pc = 0x1bd860u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
label_1bd864:
    // 0x1bd864: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1bd864u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bd868: 0x24a5000c  addiu       $a1, $a1, 0xC
    ctx->pc = 0x1bd868u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 12));
    // 0x1bd86c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd86cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd870: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1bd870u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
label_1bd874:
    // 0x1bd874: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1bd874u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1bd878: 0x1460ffe2  bnez        $v1, . + 4 + (-0x1E << 2)
    ctx->pc = 0x1BD878u;
    {
        const bool branch_taken_0x1bd878 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bd878) {
            ctx->pc = 0x1BD804u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd804;
        }
    }
    ctx->pc = 0x1BD880u;
    // 0x1bd880: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1bd880u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bd884: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD884u;
    {
        const bool branch_taken_0x1bd884 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BD888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD884u;
            // 0x1bd888: 0x32243  sra         $a0, $v1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd884) {
            ctx->pc = 0x1BD894u;
            goto label_1bd894;
        }
    }
    ctx->pc = 0x1BD88Cu;
    // 0x1bd88c: 0x246301ff  addiu       $v1, $v1, 0x1FF
    ctx->pc = 0x1bd88cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x1bd890: 0x32243  sra         $a0, $v1, 9
    ctx->pc = 0x1bd890u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
label_1bd894:
    // 0x1bd894: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1bd894u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bd898: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd898u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd89c: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1bd89cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1bd8a0: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1bd8a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bd8a4: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD8A4u;
    {
        const bool branch_taken_0x1bd8a4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BD8A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD8A4u;
            // 0x1bd8a8: 0x32243  sra         $a0, $v1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd8a4) {
            ctx->pc = 0x1BD8B4u;
            goto label_1bd8b4;
        }
    }
    ctx->pc = 0x1BD8ACu;
    // 0x1bd8ac: 0x246301ff  addiu       $v1, $v1, 0x1FF
    ctx->pc = 0x1bd8acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x1bd8b0: 0x32243  sra         $a0, $v1, 9
    ctx->pc = 0x1bd8b0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
label_1bd8b4:
    // 0x1bd8b4: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1bd8b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bd8b8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd8b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd8bc: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1bd8bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1bd8c0: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1bd8c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bd8c4: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD8C4u;
    {
        const bool branch_taken_0x1bd8c4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BD8C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD8C4u;
            // 0x1bd8c8: 0x32243  sra         $a0, $v1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd8c4) {
            ctx->pc = 0x1BD8D4u;
            goto label_1bd8d4;
        }
    }
    ctx->pc = 0x1BD8CCu;
    // 0x1bd8cc: 0x246301ff  addiu       $v1, $v1, 0x1FF
    ctx->pc = 0x1bd8ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x1bd8d0: 0x32243  sra         $a0, $v1, 9
    ctx->pc = 0x1bd8d0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
label_1bd8d4:
    // 0x1bd8d4: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1bd8d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bd8d8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd8d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd8dc: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1bd8dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1bd8e0: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1bd8e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bd8e4: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD8E4u;
    {
        const bool branch_taken_0x1bd8e4 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1BD8E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD8E4u;
            // 0x1bd8e8: 0x32243  sra         $a0, $v1, 9 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd8e4) {
            ctx->pc = 0x1BD8F4u;
            goto label_1bd8f4;
        }
    }
    ctx->pc = 0x1BD8ECu;
    // 0x1bd8ec: 0x246301ff  addiu       $v1, $v1, 0x1FF
    ctx->pc = 0x1bd8ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 511));
    // 0x1bd8f0: 0x32243  sra         $a0, $v1, 9
    ctx->pc = 0x1bd8f0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 9));
label_1bd8f4:
    // 0x1bd8f4: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x1bd8f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1bd8f8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1bd8f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1bd8fc: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x1bd8fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x1bd900: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bd900u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bd904: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bd904u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bd908: 0x3e00008  jr          $ra
    ctx->pc = 0x1BD908u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BD90Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD908u;
            // 0x1bd90c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BD7D4u: goto label_1bd7d4;
            case 0x1BD804u: goto label_1bd804;
            case 0x1BD824u: goto label_1bd824;
            case 0x1BD864u: goto label_1bd864;
            case 0x1BD874u: goto label_1bd874;
            case 0x1BD894u: goto label_1bd894;
            case 0x1BD8B4u: goto label_1bd8b4;
            case 0x1BD8D4u: goto label_1bd8d4;
            case 0x1BD8F4u: goto label_1bd8f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BD910u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
