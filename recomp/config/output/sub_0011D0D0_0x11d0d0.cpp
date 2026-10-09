#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D0D0
// Address: 0x11d0d0 - 0x11d660
void sub_0011D0D0_0x11d0d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D0D0_0x11d0d0");
#endif

    switch (ctx->pc) {
        case 0x11d120u: goto label_11d120;
        case 0x11d144u: goto label_11d144;
        case 0x11d14cu: goto label_11d14c;
        case 0x11d160u: goto label_11d160;
        case 0x11d178u: goto label_11d178;
        case 0x11d1acu: goto label_11d1ac;
        case 0x11d1b4u: goto label_11d1b4;
        case 0x11d1c8u: goto label_11d1c8;
        case 0x11d1e0u: goto label_11d1e0;
        case 0x11d228u: goto label_11d228;
        case 0x11d230u: goto label_11d230;
        case 0x11d240u: goto label_11d240;
        case 0x11d258u: goto label_11d258;
        case 0x11d280u: goto label_11d280;
        case 0x11d29cu: goto label_11d29c;
        case 0x11d414u: goto label_11d414;
        case 0x11d658u: goto label_11d658;
        default: break;
    }

    ctx->pc = 0x11d0d0u;

    // 0x11d0d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11d0d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11d0d4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x11d0d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x11d0d8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11d0d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11d0dc: 0x24848bd0  addiu       $a0, $a0, -0x7430
    ctx->pc = 0x11d0dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937552));
    // 0x11d0e0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11d0e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11d0e4: 0x3c120021  lui         $s2, 0x21
    ctx->pc = 0x11d0e4u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)33 << 16));
    // 0x11d0e8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11d0e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11d0ec: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11d0ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11d0f0: 0x2650a438  addiu       $s0, $s2, -0x5BC8
    ctx->pc = 0x11d0f0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 4294943800));
    // 0x11d0f4: 0x8e45a438  lw          $a1, -0x5BC8($s2)
    ctx->pc = 0x11d0f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294943800)));
    // 0x11d0f8: 0x8e070004  lw          $a3, 0x4($s0)
    ctx->pc = 0x11d0f8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11d0fc: 0x8e090008  lw          $t1, 0x8($s0)
    ctx->pc = 0x11d0fcu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11d100: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x11d100u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d104: 0xa73821  addu        $a3, $a1, $a3
    ctx->pc = 0x11d104u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x11d108: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x11d108u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x11d10c: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x11d10cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d110: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x11d110u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x11d114: 0x2529ffff  addiu       $t1, $t1, -0x1
    ctx->pc = 0x11d114u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967295));
    // 0x11d118: 0xc045a04  jal         func_116810
    ctx->pc = 0x11D118u;
    SET_GPR_U32(ctx, 31, 0x11D120u);
    ctx->pc = 0x11D11Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D118u;
            // 0x11d11c: 0x24e7ffff  addiu       $a3, $a3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116810u;
    if (runtime->hasFunction(0x116810u)) {
        auto targetFn = runtime->lookupFunction(0x116810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D120u; }
        if (ctx->pc != 0x11D120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116810_0x116810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D120u; }
        if (ctx->pc != 0x11D120u) { return; }
    }
    ctx->pc = 0x11D120u;
label_11d120:
    // 0x11d120: 0x40803000  mtc0        $zero, Wired
    ctx->pc = 0x11d120u;
    ctx->cop0_wired = GPR_U32(ctx, 0) & 0x3F; ctx->cop0_random = 47;
    // 0x11d124: 0x40f  sync.p
    ctx->pc = 0x11d124u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d128: 0x8e51a438  lw          $s1, -0x5BC8($s2)
    ctx->pc = 0x11d128u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294943800)));
    // 0x11d12c: 0x2a220031  slti        $v0, $s1, 0x31
    ctx->pc = 0x11d12cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)49) ? 1 : 0);
    // 0x11d130: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11D130u;
    {
        const bool branch_taken_0x11d130 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11D134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D130u;
            // 0x11d134: 0xc82d  daddu       $t9, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d130) {
            ctx->pc = 0x11D14Cu;
            goto label_11d14c;
        }
    }
    ctx->pc = 0x11D138u;
    // 0x11d138: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x11d138u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x11d13c: 0xc045a04  jal         func_116810
    ctx->pc = 0x11D13Cu;
    SET_GPR_U32(ctx, 31, 0x11D144u);
    ctx->pc = 0x11D140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D13Cu;
            // 0x11d140: 0x24848c08  addiu       $a0, $a0, -0x73F8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937608));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116810u;
    if (runtime->hasFunction(0x116810u)) {
        auto targetFn = runtime->lookupFunction(0x116810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D144u; }
        if (ctx->pc != 0x11D144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116810_0x116810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D144u; }
        if (ctx->pc != 0x11D144u) { return; }
    }
    ctx->pc = 0x11D144u;
label_11d144:
    // 0x11d144: 0xc047742  jal         func_11DD08
    ctx->pc = 0x11D144u;
    SET_GPR_U32(ctx, 31, 0x11D14Cu);
    ctx->pc = 0x11D148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D144u;
            // 0x11d148: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DD08u;
    if (runtime->hasFunction(0x11DD08u)) {
        auto targetFn = runtime->lookupFunction(0x11DD08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D14Cu; }
        if (ctx->pc != 0x11D14Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD08_0x11dd08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D14Cu; }
        if (ctx->pc != 0x11D14Cu) { return; }
    }
    ctx->pc = 0x11D14Cu;
label_11d14c:
    // 0x11d14c: 0x331102a  slt         $v0, $t9, $s1
    ctx->pc = 0x11d14cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x11d150: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x11D150u;
    {
        const bool branch_taken_0x11d150 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D150u;
            // 0x11d154: 0x8e100010  lw          $s0, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d150) {
            ctx->pc = 0x11D188u;
            goto label_11d188;
        }
    }
    ctx->pc = 0x11D158u;
    // 0x11d158: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x11d158u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11d15c: 0x0  nop
    ctx->pc = 0x11d15cu;
    // NOP
label_11d160:
    // 0x11d160: 0x320202d  daddu       $a0, $t9, $zero
    ctx->pc = 0x11d160u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d164: 0x8e060004  lw          $a2, 0x4($s0)
    ctx->pc = 0x11d164u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11d168: 0x8e070008  lw          $a3, 0x8($s0)
    ctx->pc = 0x11d168u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11d16c: 0x8e08000c  lw          $t0, 0xC($s0)
    ctx->pc = 0x11d16cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x11d170: 0xc0473fc  jal         func_11CFF0
    ctx->pc = 0x11D170u;
    SET_GPR_U32(ctx, 31, 0x11D178u);
    ctx->pc = 0x11D174u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D170u;
            // 0x11d174: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11CFF0u;
    if (runtime->hasFunction(0x11CFF0u)) {
        auto targetFn = runtime->lookupFunction(0x11CFF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D178u; }
        if (ctx->pc != 0x11D178u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CFF0_0x11cff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D178u; }
        if (ctx->pc != 0x11D178u) { return; }
    }
    ctx->pc = 0x11D178u;
label_11d178:
    // 0x11d178: 0x27390001  addiu       $t9, $t9, 0x1
    ctx->pc = 0x11d178u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 25), 1));
    // 0x11d17c: 0x331102a  slt         $v0, $t9, $s1
    ctx->pc = 0x11d17cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x11d180: 0x5440fff7  bnel        $v0, $zero, . + 4 + (-0x9 << 2)
    ctx->pc = 0x11D180u;
    {
        const bool branch_taken_0x11d180 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11d180) {
            ctx->pc = 0x11D184u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11D180u;
            // 0x11d184: 0x8e050000  lw          $a1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11D160u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11d160;
        }
    }
    ctx->pc = 0x11D188u;
label_11d188:
    // 0x11d188: 0x2650a438  addiu       $s0, $s2, -0x5BC8
    ctx->pc = 0x11d188u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 4294943800));
    // 0x11d18c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x11d18cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11d190: 0x3228821  addu        $s1, $t9, $v0
    ctx->pc = 0x11d190u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 25), GPR_U32(ctx, 2)));
    // 0x11d194: 0x2a230031  slti        $v1, $s1, 0x31
    ctx->pc = 0x11d194u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)49) ? 1 : 0);
    // 0x11d198: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x11D198u;
    {
        const bool branch_taken_0x11d198 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x11D19Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D198u;
            // 0x11d19c: 0x331102a  slt         $v0, $t9, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d198) {
            ctx->pc = 0x11D1B8u;
            goto label_11d1b8;
        }
    }
    ctx->pc = 0x11D1A0u;
    // 0x11d1a0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x11d1a0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x11d1a4: 0xc045a04  jal         func_116810
    ctx->pc = 0x11D1A4u;
    SET_GPR_U32(ctx, 31, 0x11D1ACu);
    ctx->pc = 0x11D1A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D1A4u;
            // 0x11d1a8: 0x24848c20  addiu       $a0, $a0, -0x73E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116810u;
    if (runtime->hasFunction(0x116810u)) {
        auto targetFn = runtime->lookupFunction(0x116810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D1ACu; }
        if (ctx->pc != 0x11D1ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116810_0x116810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D1ACu; }
        if (ctx->pc != 0x11D1ACu) { return; }
    }
    ctx->pc = 0x11D1ACu;
label_11d1ac:
    // 0x11d1ac: 0xc047742  jal         func_11DD08
    ctx->pc = 0x11D1ACu;
    SET_GPR_U32(ctx, 31, 0x11D1B4u);
    ctx->pc = 0x11D1B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D1ACu;
            // 0x11d1b0: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DD08u;
    if (runtime->hasFunction(0x11DD08u)) {
        auto targetFn = runtime->lookupFunction(0x11DD08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D1B4u; }
        if (ctx->pc != 0x11D1B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD08_0x11dd08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D1B4u; }
        if (ctx->pc != 0x11D1B4u) { return; }
    }
    ctx->pc = 0x11D1B4u;
label_11d1b4:
    // 0x11d1b4: 0x331102a  slt         $v0, $t9, $s1
    ctx->pc = 0x11d1b4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
label_11d1b8:
    // 0x11d1b8: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x11D1B8u;
    {
        const bool branch_taken_0x11d1b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D1BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D1B8u;
            // 0x11d1bc: 0x8e100014  lw          $s0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d1b8) {
            ctx->pc = 0x11D1F0u;
            goto label_11d1f0;
        }
    }
    ctx->pc = 0x11D1C0u;
    // 0x11d1c0: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x11d1c0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11d1c4: 0x0  nop
    ctx->pc = 0x11d1c4u;
    // NOP
label_11d1c8:
    // 0x11d1c8: 0x320202d  daddu       $a0, $t9, $zero
    ctx->pc = 0x11d1c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d1cc: 0x8e060004  lw          $a2, 0x4($s0)
    ctx->pc = 0x11d1ccu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11d1d0: 0x8e070008  lw          $a3, 0x8($s0)
    ctx->pc = 0x11d1d0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11d1d4: 0x8e08000c  lw          $t0, 0xC($s0)
    ctx->pc = 0x11d1d4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x11d1d8: 0xc0473fc  jal         func_11CFF0
    ctx->pc = 0x11D1D8u;
    SET_GPR_U32(ctx, 31, 0x11D1E0u);
    ctx->pc = 0x11D1DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D1D8u;
            // 0x11d1dc: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11CFF0u;
    if (runtime->hasFunction(0x11CFF0u)) {
        auto targetFn = runtime->lookupFunction(0x11CFF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D1E0u; }
        if (ctx->pc != 0x11D1E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CFF0_0x11cff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D1E0u; }
        if (ctx->pc != 0x11D1E0u) { return; }
    }
    ctx->pc = 0x11D1E0u;
label_11d1e0:
    // 0x11d1e0: 0x27390001  addiu       $t9, $t9, 0x1
    ctx->pc = 0x11d1e0u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 25), 1));
    // 0x11d1e4: 0x331102a  slt         $v0, $t9, $s1
    ctx->pc = 0x11d1e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x11d1e8: 0x5440fff7  bnel        $v0, $zero, . + 4 + (-0x9 << 2)
    ctx->pc = 0x11D1E8u;
    {
        const bool branch_taken_0x11d1e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11d1e8) {
            ctx->pc = 0x11D1ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11D1E8u;
            // 0x11d1ec: 0x8e050000  lw          $a1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11D1C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11d1c8;
        }
    }
    ctx->pc = 0x11D1F0u;
label_11d1f0:
    // 0x11d1f0: 0x2650a438  addiu       $s0, $s2, -0x5BC8
    ctx->pc = 0x11d1f0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 4294943800));
    // 0x11d1f4: 0xae19000c  sw          $t9, 0xC($s0)
    ctx->pc = 0x11d1f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 25));
    // 0x11d1f8: 0x40993000  mtc0        $t9, Wired
    ctx->pc = 0x11d1f8u;
    ctx->cop0_wired = GPR_U32(ctx, 25) & 0x3F; ctx->cop0_random = 47;
    // 0x11d1fc: 0x40f  sync.p
    ctx->pc = 0x11d1fcu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d200: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x11d200u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11d204: 0x58400019  blezl       $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x11D204u;
    {
        const bool branch_taken_0x11d204 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x11d204) {
            ctx->pc = 0x11D208u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11D204u;
            // 0x11d208: 0x320802d  daddu       $s0, $t9, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11D26Cu;
            goto label_11d26c;
        }
    }
    ctx->pc = 0x11D20Cu;
    // 0x11d20c: 0x3228821  addu        $s1, $t9, $v0
    ctx->pc = 0x11d20cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 25), GPR_U32(ctx, 2)));
    // 0x11d210: 0x2a220031  slti        $v0, $s1, 0x31
    ctx->pc = 0x11d210u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)49) ? 1 : 0);
    // 0x11d214: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11D214u;
    {
        const bool branch_taken_0x11d214 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11D218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D214u;
            // 0x11d218: 0x331102a  slt         $v0, $t9, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d214) {
            ctx->pc = 0x11D234u;
            goto label_11d234;
        }
    }
    ctx->pc = 0x11D21Cu;
    // 0x11d21c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x11d21cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x11d220: 0xc045a04  jal         func_116810
    ctx->pc = 0x11D220u;
    SET_GPR_U32(ctx, 31, 0x11D228u);
    ctx->pc = 0x11D224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D220u;
            // 0x11d224: 0x24848c38  addiu       $a0, $a0, -0x73C8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937656));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116810u;
    if (runtime->hasFunction(0x116810u)) {
        auto targetFn = runtime->lookupFunction(0x116810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D228u; }
        if (ctx->pc != 0x11D228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116810_0x116810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D228u; }
        if (ctx->pc != 0x11D228u) { return; }
    }
    ctx->pc = 0x11D228u;
label_11d228:
    // 0x11d228: 0xc047742  jal         func_11DD08
    ctx->pc = 0x11D228u;
    SET_GPR_U32(ctx, 31, 0x11D230u);
    ctx->pc = 0x11D22Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D228u;
            // 0x11d22c: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DD08u;
    if (runtime->hasFunction(0x11DD08u)) {
        auto targetFn = runtime->lookupFunction(0x11DD08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D230u; }
        if (ctx->pc != 0x11D230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD08_0x11dd08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D230u; }
        if (ctx->pc != 0x11D230u) { return; }
    }
    ctx->pc = 0x11D230u;
label_11d230:
    // 0x11d230: 0x331102a  slt         $v0, $t9, $s1
    ctx->pc = 0x11d230u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
label_11d234:
    // 0x11d234: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x11D234u;
    {
        const bool branch_taken_0x11d234 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D234u;
            // 0x11d238: 0x8e100018  lw          $s0, 0x18($s0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d234) {
            ctx->pc = 0x11D268u;
            goto label_11d268;
        }
    }
    ctx->pc = 0x11D23Cu;
    // 0x11d23c: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x11d23cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_11d240:
    // 0x11d240: 0x320202d  daddu       $a0, $t9, $zero
    ctx->pc = 0x11d240u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d244: 0x8e060004  lw          $a2, 0x4($s0)
    ctx->pc = 0x11d244u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11d248: 0x8e070008  lw          $a3, 0x8($s0)
    ctx->pc = 0x11d248u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11d24c: 0x8e08000c  lw          $t0, 0xC($s0)
    ctx->pc = 0x11d24cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x11d250: 0xc0473fc  jal         func_11CFF0
    ctx->pc = 0x11D250u;
    SET_GPR_U32(ctx, 31, 0x11D258u);
    ctx->pc = 0x11D254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D250u;
            // 0x11d254: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11CFF0u;
    if (runtime->hasFunction(0x11CFF0u)) {
        auto targetFn = runtime->lookupFunction(0x11CFF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D258u; }
        if (ctx->pc != 0x11D258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CFF0_0x11cff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D258u; }
        if (ctx->pc != 0x11D258u) { return; }
    }
    ctx->pc = 0x11D258u;
label_11d258:
    // 0x11d258: 0x27390001  addiu       $t9, $t9, 0x1
    ctx->pc = 0x11d258u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 25), 1));
    // 0x11d25c: 0x331102a  slt         $v0, $t9, $s1
    ctx->pc = 0x11d25cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x11d260: 0x5440fff7  bnel        $v0, $zero, . + 4 + (-0x9 << 2)
    ctx->pc = 0x11D260u;
    {
        const bool branch_taken_0x11d260 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11d260) {
            ctx->pc = 0x11D264u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11D260u;
            // 0x11d264: 0x8e050000  lw          $a1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11D240u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11d240;
        }
    }
    ctx->pc = 0x11D268u;
label_11d268:
    // 0x11d268: 0x320802d  daddu       $s0, $t9, $zero
    ctx->pc = 0x11d268u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
label_11d26c:
    // 0x11d26c: 0x2a020030  slti        $v0, $s0, 0x30
    ctx->pc = 0x11d26cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)48) ? 1 : 0);
    // 0x11d270: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x11D270u;
    {
        const bool branch_taken_0x11d270 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D270u;
            // 0x11d274: 0x19cb40  sll         $t9, $t9, 13 (Delay Slot)
        SET_GPR_S32(ctx, 25, (int32_t)SLL32(GPR_U32(ctx, 25), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d270) {
            ctx->pc = 0x11D2A8u;
            goto label_11d2a8;
        }
    }
    ctx->pc = 0x11D278u;
    // 0x11d278: 0x3c02e000  lui         $v0, 0xE000
    ctx->pc = 0x11d278u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)57344 << 16));
    // 0x11d27c: 0x3228821  addu        $s1, $t9, $v0
    ctx->pc = 0x11d27cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 25), GPR_U32(ctx, 2)));
label_11d280:
    // 0x11d280: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11d280u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d284: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x11d284u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d288: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11d288u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d28c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x11d28cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d290: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x11d290u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d294: 0xc0473fc  jal         func_11CFF0
    ctx->pc = 0x11D294u;
    SET_GPR_U32(ctx, 31, 0x11D29Cu);
    ctx->pc = 0x11D298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D294u;
            // 0x11d298: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11CFF0u;
    if (runtime->hasFunction(0x11CFF0u)) {
        auto targetFn = runtime->lookupFunction(0x11CFF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D29Cu; }
        if (ctx->pc != 0x11D29Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CFF0_0x11cff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D29Cu; }
        if (ctx->pc != 0x11D29Cu) { return; }
    }
    ctx->pc = 0x11D29Cu;
label_11d29c:
    // 0x11d29c: 0x2a020030  slti        $v0, $s0, 0x30
    ctx->pc = 0x11d29cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)48) ? 1 : 0);
    // 0x11d2a0: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x11D2A0u;
    {
        const bool branch_taken_0x11d2a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11D2A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D2A0u;
            // 0x11d2a4: 0x26312000  addiu       $s1, $s1, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d2a0) {
            ctx->pc = 0x11D280u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11d280;
        }
    }
    ctx->pc = 0x11D2A8u;
label_11d2a8:
    // 0x11d2a8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11d2a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11d2ac: 0x320102d  daddu       $v0, $t9, $zero
    ctx->pc = 0x11d2acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d2b0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11d2b0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11d2b4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11d2b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11d2b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11d2b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11d2bc: 0x3e00008  jr          $ra
    ctx->pc = 0x11D2BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D2C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D2BCu;
            // 0x11d2c0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D120u: goto label_11d120;
            case 0x11D144u: goto label_11d144;
            case 0x11D14Cu: goto label_11d14c;
            case 0x11D160u: goto label_11d160;
            case 0x11D178u: goto label_11d178;
            case 0x11D188u: goto label_11d188;
            case 0x11D1ACu: goto label_11d1ac;
            case 0x11D1B4u: goto label_11d1b4;
            case 0x11D1B8u: goto label_11d1b8;
            case 0x11D1C8u: goto label_11d1c8;
            case 0x11D1E0u: goto label_11d1e0;
            case 0x11D1F0u: goto label_11d1f0;
            case 0x11D228u: goto label_11d228;
            case 0x11D230u: goto label_11d230;
            case 0x11D234u: goto label_11d234;
            case 0x11D240u: goto label_11d240;
            case 0x11D258u: goto label_11d258;
            case 0x11D268u: goto label_11d268;
            case 0x11D26Cu: goto label_11d26c;
            case 0x11D280u: goto label_11d280;
            case 0x11D29Cu: goto label_11d29c;
            case 0x11D2A8u: goto label_11d2a8;
            case 0x11D414u: goto label_11d414;
            case 0x11D658u: goto label_11d658;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D2C4u;
    // 0x11d2c4: 0x0  nop
    ctx->pc = 0x11d2c4u;
    // NOP
    // 0x11d2c8: 0x0  nop
    ctx->pc = 0x11d2c8u;
    // NOP
    // 0x11d2cc: 0x0  nop
    ctx->pc = 0x11d2ccu;
    // NOP
    // 0x11d2d0: 0x0  nop
    ctx->pc = 0x11d2d0u;
    // NOP
    // 0x11d2d4: 0x0  nop
    ctx->pc = 0x11d2d4u;
    // NOP
    // 0x11d2d8: 0x0  nop
    ctx->pc = 0x11d2d8u;
    // NOP
    // 0x11d2dc: 0x0  nop
    ctx->pc = 0x11d2dcu;
    // NOP
    // 0x11d2e0: 0x0  nop
    ctx->pc = 0x11d2e0u;
    // NOP
    // 0x11d2e4: 0x0  nop
    ctx->pc = 0x11d2e4u;
    // NOP
    // 0x11d2e8: 0x0  nop
    ctx->pc = 0x11d2e8u;
    // NOP
    // 0x11d2ec: 0x0  nop
    ctx->pc = 0x11d2ecu;
    // NOP
    // 0x11d2f0: 0x0  nop
    ctx->pc = 0x11d2f0u;
    // NOP
    // 0x11d2f4: 0x0  nop
    ctx->pc = 0x11d2f4u;
    // NOP
    // 0x11d2f8: 0x0  nop
    ctx->pc = 0x11d2f8u;
    // NOP
    // 0x11d2fc: 0x0  nop
    ctx->pc = 0x11d2fcu;
    // NOP
    // 0x11d300: 0x3c1a0026  lui         $k0, 0x26
    ctx->pc = 0x11d300u;
    SET_GPR_S32(ctx, 26, (int32_t)((uint32_t)38 << 16));
    // 0x11d304: 0x275af6c0  addiu       $k0, $k0, -0x940
    ctx->pc = 0x11d304u;
    SET_GPR_S32(ctx, 26, (int32_t)ADD32(GPR_U32(ctx, 26), 4294964928));
    // 0x11d308: 0x7f410010  sq          $at, 0x10($k0)
    ctx->pc = 0x11d308u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 16), GPR_VEC(ctx, 1));
    // 0x11d30c: 0x7f420020  sq          $v0, 0x20($k0)
    ctx->pc = 0x11d30cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 32), GPR_VEC(ctx, 2));
    // 0x11d310: 0x7f430030  sq          $v1, 0x30($k0)
    ctx->pc = 0x11d310u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 48), GPR_VEC(ctx, 3));
    // 0x11d314: 0x7f440040  sq          $a0, 0x40($k0)
    ctx->pc = 0x11d314u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 64), GPR_VEC(ctx, 4));
    // 0x11d318: 0x7f450050  sq          $a1, 0x50($k0)
    ctx->pc = 0x11d318u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 80), GPR_VEC(ctx, 5));
    // 0x11d31c: 0x7f460060  sq          $a2, 0x60($k0)
    ctx->pc = 0x11d31cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 96), GPR_VEC(ctx, 6));
    // 0x11d320: 0x7f470070  sq          $a3, 0x70($k0)
    ctx->pc = 0x11d320u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 112), GPR_VEC(ctx, 7));
    // 0x11d324: 0x7f480080  sq          $t0, 0x80($k0)
    ctx->pc = 0x11d324u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 128), GPR_VEC(ctx, 8));
    // 0x11d328: 0x7f490090  sq          $t1, 0x90($k0)
    ctx->pc = 0x11d328u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 144), GPR_VEC(ctx, 9));
    // 0x11d32c: 0x7f4a00a0  sq          $t2, 0xA0($k0)
    ctx->pc = 0x11d32cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 160), GPR_VEC(ctx, 10));
    // 0x11d330: 0x7f4b00b0  sq          $t3, 0xB0($k0)
    ctx->pc = 0x11d330u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 176), GPR_VEC(ctx, 11));
    // 0x11d334: 0x7f4c00c0  sq          $t4, 0xC0($k0)
    ctx->pc = 0x11d334u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 192), GPR_VEC(ctx, 12));
    // 0x11d338: 0x7f4d00d0  sq          $t5, 0xD0($k0)
    ctx->pc = 0x11d338u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 208), GPR_VEC(ctx, 13));
    // 0x11d33c: 0x7f4e00e0  sq          $t6, 0xE0($k0)
    ctx->pc = 0x11d33cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 224), GPR_VEC(ctx, 14));
    // 0x11d340: 0x7f4f00f0  sq          $t7, 0xF0($k0)
    ctx->pc = 0x11d340u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 240), GPR_VEC(ctx, 15));
    // 0x11d344: 0x7f500100  sq          $s0, 0x100($k0)
    ctx->pc = 0x11d344u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 256), GPR_VEC(ctx, 16));
    // 0x11d348: 0x7f510110  sq          $s1, 0x110($k0)
    ctx->pc = 0x11d348u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 272), GPR_VEC(ctx, 17));
    // 0x11d34c: 0x7f520120  sq          $s2, 0x120($k0)
    ctx->pc = 0x11d34cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 288), GPR_VEC(ctx, 18));
    // 0x11d350: 0x7f530130  sq          $s3, 0x130($k0)
    ctx->pc = 0x11d350u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 304), GPR_VEC(ctx, 19));
    // 0x11d354: 0x7f540140  sq          $s4, 0x140($k0)
    ctx->pc = 0x11d354u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 320), GPR_VEC(ctx, 20));
    // 0x11d358: 0x7f550150  sq          $s5, 0x150($k0)
    ctx->pc = 0x11d358u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 336), GPR_VEC(ctx, 21));
    // 0x11d35c: 0x7f560160  sq          $s6, 0x160($k0)
    ctx->pc = 0x11d35cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 352), GPR_VEC(ctx, 22));
    // 0x11d360: 0x7f570170  sq          $s7, 0x170($k0)
    ctx->pc = 0x11d360u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 368), GPR_VEC(ctx, 23));
    // 0x11d364: 0x7f580180  sq          $t8, 0x180($k0)
    ctx->pc = 0x11d364u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 384), GPR_VEC(ctx, 24));
    // 0x11d368: 0x7f590190  sq          $t9, 0x190($k0)
    ctx->pc = 0x11d368u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 400), GPR_VEC(ctx, 25));
    // 0x11d36c: 0x7f5c01c0  sq          $gp, 0x1C0($k0)
    ctx->pc = 0x11d36cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 448), GPR_VEC(ctx, 28));
    // 0x11d370: 0x7f5d01d0  sq          $sp, 0x1D0($k0)
    ctx->pc = 0x11d370u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 464), GPR_VEC(ctx, 29));
    // 0x11d374: 0x7f5e01e0  sq          $fp, 0x1E0($k0)
    ctx->pc = 0x11d374u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 480), GPR_VEC(ctx, 30));
    // 0x11d378: 0x7f5f01f0  sq          $ra, 0x1F0($k0)
    ctx->pc = 0x11d378u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 496), GPR_VEC(ctx, 31));
    // 0x11d37c: 0x1010  mfhi        $v0
    ctx->pc = 0x11d37cu;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x11d380: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d380u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d384: 0xfc22f8c0  sd          $v0, -0x740($at)
    ctx->pc = 0x11d384u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965440), GPR_U64(ctx, 2));
    // 0x11d388: 0x70001010  mfhi1       $v0
    ctx->pc = 0x11d388u;
    SET_GPR_U64(ctx, 2, ctx->hi1);
    // 0x11d38c: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d38cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d390: 0xfc22f8c8  sd          $v0, -0x738($at)
    ctx->pc = 0x11d390u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965448), GPR_U64(ctx, 2));
    // 0x11d394: 0x1012  mflo        $v0
    ctx->pc = 0x11d394u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x11d398: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d398u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d39c: 0xfc22f8d0  sd          $v0, -0x730($at)
    ctx->pc = 0x11d39cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965456), GPR_U64(ctx, 2));
    // 0x11d3a0: 0x70001012  mflo1       $v0
    ctx->pc = 0x11d3a0u;
    SET_GPR_U64(ctx, 2, ctx->lo1);
    // 0x11d3a4: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d3a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d3a8: 0xfc22f8d8  sd          $v0, -0x728($at)
    ctx->pc = 0x11d3a8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965464), GPR_U64(ctx, 2));
    // 0x11d3ac: 0x1028  mfsa        $v0
    ctx->pc = 0x11d3acu;
    SET_GPR_U32(ctx, 2, ctx->sa);
    // 0x11d3b0: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d3b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d3b4: 0xfc22f8e0  sd          $v0, -0x720($at)
    ctx->pc = 0x11d3b4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965472), GPR_U64(ctx, 2));
    // 0x11d3b8: 0x40046000  mfc0        $a0, Status
    ctx->pc = 0x11d3b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ctx->cop0_status);
    // 0x11d3bc: 0x40056800  mfc0        $a1, Cause
    ctx->pc = 0x11d3bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ctx->cop0_cause);
    // 0x11d3c0: 0x40067000  mfc0        $a2, EPC
    ctx->pc = 0x11d3c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ctx->cop0_epc);
    // 0x11d3c4: 0x40074000  mfc0        $a3, BadVaddr
    ctx->pc = 0x11d3c4u;
    SET_GPR_S32(ctx, 7, (int32_t)ctx->cop0_badvaddr);
    // 0x11d3c8: 0x3c080026  lui         $t0, 0x26
    ctx->pc = 0x11d3c8u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)38 << 16));
    // 0x11d3cc: 0x2508f6c0  addiu       $t0, $t0, -0x940
    ctx->pc = 0x11d3ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294964928));
    // 0x11d3d0: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d3d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d3d4: 0xac26f8e8  sw          $a2, -0x718($at)
    ctx->pc = 0x11d3d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965480), GPR_U32(ctx, 6));
    // 0x11d3d8: 0x3c010012  lui         $at, 0x12
    ctx->pc = 0x11d3d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)18 << 16));
    // 0x11d3dc: 0x2421d400  addiu       $at, $at, -0x2C00
    ctx->pc = 0x11d3dcu;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 4294956032));
    // 0x11d3e0: 0x40817000  mtc0        $at, EPC
    ctx->pc = 0x11d3e0u;
    ctx->cop0_epc = GPR_U32(ctx, 1);
    // 0x11d3e4: 0x40f  sync.p
    ctx->pc = 0x11d3e4u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d3e8: 0x40016000  mfc0        $at, Status
    ctx->pc = 0x11d3e8u;
    SET_GPR_S32(ctx, 1, (int32_t)ctx->cop0_status);
    // 0x11d3ec: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x11d3ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x11d3f0: 0x220824  and         $at, $at, $v0
    ctx->pc = 0x11d3f0u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) & GPR_U64(ctx, 2));
    // 0x11d3f4: 0x40816000  mtc0        $at, Status
    ctx->pc = 0x11d3f4u;
    ctx->cop0_status = GPR_U32(ctx, 1) & 0xFF57FFFF;
    // 0x11d3f8: 0x40f  sync.p
    ctx->pc = 0x11d3f8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d3fc: 0x42000018  eret
    ctx->pc = 0x11d3fcu;
    if (ctx->cop0_status & 0x4) { 
    ctx->pc = ctx->cop0_errorepc; 
    ctx->cop0_status &= ~0x4; 
} else { 
    ctx->pc = ctx->cop0_epc; 
    ctx->cop0_status &= ~0x2; 
} 
runtime->clearLLBit(ctx); 
return;
    // 0x11d400: 0x3c010021  lui         $at, 0x21
    ctx->pc = 0x11d400u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)33 << 16));
    // 0x11d404: 0x8c21a138  lw          $at, -0x5EC8($at)
    ctx->pc = 0x11d404u;
    SET_GPR_S32(ctx, 1, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294943032)));
    // 0x11d408: 0x3c1d0026  lui         $sp, 0x26
    ctx->pc = 0x11d408u;
    SET_GPR_S32(ctx, 29, (int32_t)((uint32_t)38 << 16));
    // 0x11d40c: 0x20f809  jalr        $at
    ctx->pc = 0x11D40Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 1);
        SET_GPR_U32(ctx, 31, 0x11D414u);
        ctx->pc = 0x11D410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D40Cu;
            // 0x11d410: 0x27bdf6c0  addiu       $sp, $sp, -0x940 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294964928));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x11D414u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D120u: goto label_11d120;
            case 0x11D144u: goto label_11d144;
            case 0x11D14Cu: goto label_11d14c;
            case 0x11D160u: goto label_11d160;
            case 0x11D178u: goto label_11d178;
            case 0x11D188u: goto label_11d188;
            case 0x11D1ACu: goto label_11d1ac;
            case 0x11D1B4u: goto label_11d1b4;
            case 0x11D1B8u: goto label_11d1b8;
            case 0x11D1C8u: goto label_11d1c8;
            case 0x11D1E0u: goto label_11d1e0;
            case 0x11D1F0u: goto label_11d1f0;
            case 0x11D228u: goto label_11d228;
            case 0x11D230u: goto label_11d230;
            case 0x11D234u: goto label_11d234;
            case 0x11D240u: goto label_11d240;
            case 0x11D258u: goto label_11d258;
            case 0x11D268u: goto label_11d268;
            case 0x11D26Cu: goto label_11d26c;
            case 0x11D280u: goto label_11d280;
            case 0x11D29Cu: goto label_11d29c;
            case 0x11D2A8u: goto label_11d2a8;
            case 0x11D414u: goto label_11d414;
            case 0x11D658u: goto label_11d658;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x11D414u; }
            if (ctx->pc != 0x11D414u) { return; }
        }
        }
    }
    ctx->pc = 0x11D414u;
label_11d414:
    // 0x11d414: 0x2403ffac  addiu       $v1, $zero, -0x54
    ctx->pc = 0x11d414u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967212));
    // 0x11d418: 0xc  syscall     0
    ctx->pc = 0x11d418u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11d41c: 0x0  nop
    ctx->pc = 0x11d41cu;
    // NOP
    // 0x11d420: 0x0  nop
    ctx->pc = 0x11d420u;
    // NOP
    // 0x11d424: 0x0  nop
    ctx->pc = 0x11d424u;
    // NOP
    // 0x11d428: 0x0  nop
    ctx->pc = 0x11d428u;
    // NOP
    // 0x11d42c: 0x0  nop
    ctx->pc = 0x11d42cu;
    // NOP
    // 0x11d430: 0x0  nop
    ctx->pc = 0x11d430u;
    // NOP
    // 0x11d434: 0x0  nop
    ctx->pc = 0x11d434u;
    // NOP
    // 0x11d438: 0x0  nop
    ctx->pc = 0x11d438u;
    // NOP
    // 0x11d43c: 0x0  nop
    ctx->pc = 0x11d43cu;
    // NOP
    // 0x11d440: 0x40016000  mfc0        $at, Status
    ctx->pc = 0x11d440u;
    SET_GPR_S32(ctx, 1, (int32_t)ctx->cop0_status);
    // 0x11d444: 0x241affe4  addiu       $k0, $zero, -0x1C
    ctx->pc = 0x11d444u;
    SET_GPR_S32(ctx, 26, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967268));
    // 0x11d448: 0x3a0824  and         $at, $at, $k0
    ctx->pc = 0x11d448u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) & GPR_U64(ctx, 26));
    // 0x11d44c: 0x40816000  mtc0        $at, Status
    ctx->pc = 0x11d44cu;
    ctx->cop0_status = GPR_U32(ctx, 1) & 0xFF57FFFF;
    // 0x11d450: 0x40f  sync.p
    ctx->pc = 0x11d450u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d454: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11d454u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11d458: 0x8c42f8e8  lw          $v0, -0x718($v0)
    ctx->pc = 0x11d458u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294965480)));
    // 0x11d45c: 0x40827000  mtc0        $v0, EPC
    ctx->pc = 0x11d45cu;
    ctx->cop0_epc = GPR_U32(ctx, 2);
    // 0x11d460: 0x40f  sync.p
    ctx->pc = 0x11d460u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d464: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11d464u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11d468: 0xdc42f8c0  ld          $v0, -0x740($v0)
    ctx->pc = 0x11d468u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 4294965440)));
    // 0x11d46c: 0x400011  mthi        $v0
    ctx->pc = 0x11d46cu;
    ctx->hi = GPR_U64(ctx, 2);
    // 0x11d470: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11d470u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11d474: 0xdc42f8c8  ld          $v0, -0x738($v0)
    ctx->pc = 0x11d474u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 4294965448)));
    // 0x11d478: 0x70400011  mthi1       $v0
    ctx->pc = 0x11d478u;
    ctx->hi1 = GPR_U64(ctx, 2);
    // 0x11d47c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11d47cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11d480: 0xdc42f8d0  ld          $v0, -0x730($v0)
    ctx->pc = 0x11d480u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 4294965456)));
    // 0x11d484: 0x400013  mtlo        $v0
    ctx->pc = 0x11d484u;
    ctx->lo = GPR_U64(ctx, 2);
    // 0x11d488: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11d488u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11d48c: 0xdc42f8d8  ld          $v0, -0x728($v0)
    ctx->pc = 0x11d48cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 4294965464)));
    // 0x11d490: 0x70400013  mtlo1       $v0
    ctx->pc = 0x11d490u;
    ctx->lo1 = GPR_U64(ctx, 2);
    // 0x11d494: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11d494u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11d498: 0xdc42f8e0  ld          $v0, -0x720($v0)
    ctx->pc = 0x11d498u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 4294965472)));
    // 0x11d49c: 0x400029  mtsa        $v0
    ctx->pc = 0x11d49cu;
    ctx->sa = GPR_U32(ctx, 2) & 0x7F;
    // 0x11d4a0: 0x40f  sync.p
    ctx->pc = 0x11d4a0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d4a4: 0x3c1a0026  lui         $k0, 0x26
    ctx->pc = 0x11d4a4u;
    SET_GPR_S32(ctx, 26, (int32_t)((uint32_t)38 << 16));
    // 0x11d4a8: 0x275af6c0  addiu       $k0, $k0, -0x940
    ctx->pc = 0x11d4a8u;
    SET_GPR_S32(ctx, 26, (int32_t)ADD32(GPR_U32(ctx, 26), 4294964928));
    // 0x11d4ac: 0x7b410010  lq          $at, 0x10($k0)
    ctx->pc = 0x11d4acu;
    SET_GPR_VEC(ctx, 1, READ128(ADD32(GPR_U32(ctx, 26), 16)));
    // 0x11d4b0: 0x7b420020  lq          $v0, 0x20($k0)
    ctx->pc = 0x11d4b0u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 26), 32)));
    // 0x11d4b4: 0x7b430030  lq          $v1, 0x30($k0)
    ctx->pc = 0x11d4b4u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 26), 48)));
    // 0x11d4b8: 0x7b440040  lq          $a0, 0x40($k0)
    ctx->pc = 0x11d4b8u;
    SET_GPR_VEC(ctx, 4, READ128(ADD32(GPR_U32(ctx, 26), 64)));
    // 0x11d4bc: 0x7b450050  lq          $a1, 0x50($k0)
    ctx->pc = 0x11d4bcu;
    SET_GPR_VEC(ctx, 5, READ128(ADD32(GPR_U32(ctx, 26), 80)));
    // 0x11d4c0: 0x7b460060  lq          $a2, 0x60($k0)
    ctx->pc = 0x11d4c0u;
    SET_GPR_VEC(ctx, 6, READ128(ADD32(GPR_U32(ctx, 26), 96)));
    // 0x11d4c4: 0x7b470070  lq          $a3, 0x70($k0)
    ctx->pc = 0x11d4c4u;
    SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 26), 112)));
    // 0x11d4c8: 0x7b480080  lq          $t0, 0x80($k0)
    ctx->pc = 0x11d4c8u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 26), 128)));
    // 0x11d4cc: 0x7b490090  lq          $t1, 0x90($k0)
    ctx->pc = 0x11d4ccu;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 26), 144)));
    // 0x11d4d0: 0x7b4a00a0  lq          $t2, 0xA0($k0)
    ctx->pc = 0x11d4d0u;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 26), 160)));
    // 0x11d4d4: 0x7b4b00b0  lq          $t3, 0xB0($k0)
    ctx->pc = 0x11d4d4u;
    SET_GPR_VEC(ctx, 11, READ128(ADD32(GPR_U32(ctx, 26), 176)));
    // 0x11d4d8: 0x7b4c00c0  lq          $t4, 0xC0($k0)
    ctx->pc = 0x11d4d8u;
    SET_GPR_VEC(ctx, 12, READ128(ADD32(GPR_U32(ctx, 26), 192)));
    // 0x11d4dc: 0x7b4d00d0  lq          $t5, 0xD0($k0)
    ctx->pc = 0x11d4dcu;
    SET_GPR_VEC(ctx, 13, READ128(ADD32(GPR_U32(ctx, 26), 208)));
    // 0x11d4e0: 0x7b4e00e0  lq          $t6, 0xE0($k0)
    ctx->pc = 0x11d4e0u;
    SET_GPR_VEC(ctx, 14, READ128(ADD32(GPR_U32(ctx, 26), 224)));
    // 0x11d4e4: 0x7b4f00f0  lq          $t7, 0xF0($k0)
    ctx->pc = 0x11d4e4u;
    SET_GPR_VEC(ctx, 15, READ128(ADD32(GPR_U32(ctx, 26), 240)));
    // 0x11d4e8: 0x7b500100  lq          $s0, 0x100($k0)
    ctx->pc = 0x11d4e8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 26), 256)));
    // 0x11d4ec: 0x7b510110  lq          $s1, 0x110($k0)
    ctx->pc = 0x11d4ecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 26), 272)));
    // 0x11d4f0: 0x7b520120  lq          $s2, 0x120($k0)
    ctx->pc = 0x11d4f0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 26), 288)));
    // 0x11d4f4: 0x7b530130  lq          $s3, 0x130($k0)
    ctx->pc = 0x11d4f4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 26), 304)));
    // 0x11d4f8: 0x7b540140  lq          $s4, 0x140($k0)
    ctx->pc = 0x11d4f8u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 26), 320)));
    // 0x11d4fc: 0x7b550150  lq          $s5, 0x150($k0)
    ctx->pc = 0x11d4fcu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 26), 336)));
    // 0x11d500: 0x7b560160  lq          $s6, 0x160($k0)
    ctx->pc = 0x11d500u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 26), 352)));
    // 0x11d504: 0x7b570170  lq          $s7, 0x170($k0)
    ctx->pc = 0x11d504u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 26), 368)));
    // 0x11d508: 0x7b580180  lq          $t8, 0x180($k0)
    ctx->pc = 0x11d508u;
    SET_GPR_VEC(ctx, 24, READ128(ADD32(GPR_U32(ctx, 26), 384)));
    // 0x11d50c: 0x7b590190  lq          $t9, 0x190($k0)
    ctx->pc = 0x11d50cu;
    SET_GPR_VEC(ctx, 25, READ128(ADD32(GPR_U32(ctx, 26), 400)));
    // 0x11d510: 0x7b5c01c0  lq          $gp, 0x1C0($k0)
    ctx->pc = 0x11d510u;
    SET_GPR_VEC(ctx, 28, READ128(ADD32(GPR_U32(ctx, 26), 448)));
    // 0x11d514: 0x7b5d01d0  lq          $sp, 0x1D0($k0)
    ctx->pc = 0x11d514u;
    SET_GPR_VEC(ctx, 29, READ128(ADD32(GPR_U32(ctx, 26), 464)));
    // 0x11d518: 0x7b5e01e0  lq          $fp, 0x1E0($k0)
    ctx->pc = 0x11d518u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 26), 480)));
    // 0x11d51c: 0x7b5f01f0  lq          $ra, 0x1F0($k0)
    ctx->pc = 0x11d51cu;
    SET_GPR_VEC(ctx, 31, READ128(ADD32(GPR_U32(ctx, 26), 496)));
    // 0x11d520: 0x401a6000  mfc0        $k0, Status
    ctx->pc = 0x11d520u;
    SET_GPR_S32(ctx, 26, (int32_t)ctx->cop0_status);
    // 0x11d524: 0x375a0013  ori         $k0, $k0, 0x13
    ctx->pc = 0x11d524u;
    SET_GPR_U64(ctx, 26, GPR_U64(ctx, 26) | (uint64_t)(uint16_t)19);
    // 0x11d528: 0x409a6000  mtc0        $k0, Status
    ctx->pc = 0x11d528u;
    ctx->cop0_status = GPR_U32(ctx, 26) & 0xFF57FFFF;
    // 0x11d52c: 0x40f  sync.p
    ctx->pc = 0x11d52cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d530: 0x42000018  eret
    ctx->pc = 0x11d530u;
    if (ctx->cop0_status & 0x4) { 
    ctx->pc = ctx->cop0_errorepc; 
    ctx->cop0_status &= ~0x4; 
} else { 
    ctx->pc = ctx->cop0_epc; 
    ctx->cop0_status &= ~0x2; 
} 
runtime->clearLLBit(ctx); 
return;
    // 0x11d534: 0x0  nop
    ctx->pc = 0x11d534u;
    // NOP
    // 0x11d538: 0x0  nop
    ctx->pc = 0x11d538u;
    // NOP
    // 0x11d53c: 0x0  nop
    ctx->pc = 0x11d53cu;
    // NOP
    // 0x11d540: 0x3c1a0026  lui         $k0, 0x26
    ctx->pc = 0x11d540u;
    SET_GPR_S32(ctx, 26, (int32_t)((uint32_t)38 << 16));
    // 0x11d544: 0x275af6c0  addiu       $k0, $k0, -0x940
    ctx->pc = 0x11d544u;
    SET_GPR_S32(ctx, 26, (int32_t)ADD32(GPR_U32(ctx, 26), 4294964928));
    // 0x11d548: 0x7f410010  sq          $at, 0x10($k0)
    ctx->pc = 0x11d548u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 16), GPR_VEC(ctx, 1));
    // 0x11d54c: 0x7f420020  sq          $v0, 0x20($k0)
    ctx->pc = 0x11d54cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 32), GPR_VEC(ctx, 2));
    // 0x11d550: 0x7f430030  sq          $v1, 0x30($k0)
    ctx->pc = 0x11d550u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 48), GPR_VEC(ctx, 3));
    // 0x11d554: 0x7f440040  sq          $a0, 0x40($k0)
    ctx->pc = 0x11d554u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 64), GPR_VEC(ctx, 4));
    // 0x11d558: 0x7f450050  sq          $a1, 0x50($k0)
    ctx->pc = 0x11d558u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 80), GPR_VEC(ctx, 5));
    // 0x11d55c: 0x7f460060  sq          $a2, 0x60($k0)
    ctx->pc = 0x11d55cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 96), GPR_VEC(ctx, 6));
    // 0x11d560: 0x7f470070  sq          $a3, 0x70($k0)
    ctx->pc = 0x11d560u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 112), GPR_VEC(ctx, 7));
    // 0x11d564: 0x7f480080  sq          $t0, 0x80($k0)
    ctx->pc = 0x11d564u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 128), GPR_VEC(ctx, 8));
    // 0x11d568: 0x7f490090  sq          $t1, 0x90($k0)
    ctx->pc = 0x11d568u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 144), GPR_VEC(ctx, 9));
    // 0x11d56c: 0x7f4a00a0  sq          $t2, 0xA0($k0)
    ctx->pc = 0x11d56cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 160), GPR_VEC(ctx, 10));
    // 0x11d570: 0x7f4b00b0  sq          $t3, 0xB0($k0)
    ctx->pc = 0x11d570u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 176), GPR_VEC(ctx, 11));
    // 0x11d574: 0x7f4c00c0  sq          $t4, 0xC0($k0)
    ctx->pc = 0x11d574u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 192), GPR_VEC(ctx, 12));
    // 0x11d578: 0x7f4d00d0  sq          $t5, 0xD0($k0)
    ctx->pc = 0x11d578u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 208), GPR_VEC(ctx, 13));
    // 0x11d57c: 0x7f4e00e0  sq          $t6, 0xE0($k0)
    ctx->pc = 0x11d57cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 224), GPR_VEC(ctx, 14));
    // 0x11d580: 0x7f4f00f0  sq          $t7, 0xF0($k0)
    ctx->pc = 0x11d580u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 240), GPR_VEC(ctx, 15));
    // 0x11d584: 0x7f500100  sq          $s0, 0x100($k0)
    ctx->pc = 0x11d584u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 256), GPR_VEC(ctx, 16));
    // 0x11d588: 0x7f510110  sq          $s1, 0x110($k0)
    ctx->pc = 0x11d588u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 272), GPR_VEC(ctx, 17));
    // 0x11d58c: 0x7f520120  sq          $s2, 0x120($k0)
    ctx->pc = 0x11d58cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 288), GPR_VEC(ctx, 18));
    // 0x11d590: 0x7f530130  sq          $s3, 0x130($k0)
    ctx->pc = 0x11d590u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 304), GPR_VEC(ctx, 19));
    // 0x11d594: 0x7f540140  sq          $s4, 0x140($k0)
    ctx->pc = 0x11d594u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 320), GPR_VEC(ctx, 20));
    // 0x11d598: 0x7f550150  sq          $s5, 0x150($k0)
    ctx->pc = 0x11d598u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 336), GPR_VEC(ctx, 21));
    // 0x11d59c: 0x7f560160  sq          $s6, 0x160($k0)
    ctx->pc = 0x11d59cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 352), GPR_VEC(ctx, 22));
    // 0x11d5a0: 0x7f570170  sq          $s7, 0x170($k0)
    ctx->pc = 0x11d5a0u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 368), GPR_VEC(ctx, 23));
    // 0x11d5a4: 0x7f580180  sq          $t8, 0x180($k0)
    ctx->pc = 0x11d5a4u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 384), GPR_VEC(ctx, 24));
    // 0x11d5a8: 0x7f590190  sq          $t9, 0x190($k0)
    ctx->pc = 0x11d5a8u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 400), GPR_VEC(ctx, 25));
    // 0x11d5ac: 0x7f5c01c0  sq          $gp, 0x1C0($k0)
    ctx->pc = 0x11d5acu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 448), GPR_VEC(ctx, 28));
    // 0x11d5b0: 0x7f5d01d0  sq          $sp, 0x1D0($k0)
    ctx->pc = 0x11d5b0u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 464), GPR_VEC(ctx, 29));
    // 0x11d5b4: 0x7f5e01e0  sq          $fp, 0x1E0($k0)
    ctx->pc = 0x11d5b4u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 480), GPR_VEC(ctx, 30));
    // 0x11d5b8: 0x7f5f01f0  sq          $ra, 0x1F0($k0)
    ctx->pc = 0x11d5b8u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 496), GPR_VEC(ctx, 31));
    // 0x11d5bc: 0x1010  mfhi        $v0
    ctx->pc = 0x11d5bcu;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x11d5c0: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d5c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d5c4: 0xfc22f8c0  sd          $v0, -0x740($at)
    ctx->pc = 0x11d5c4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965440), GPR_U64(ctx, 2));
    // 0x11d5c8: 0x70001010  mfhi1       $v0
    ctx->pc = 0x11d5c8u;
    SET_GPR_U64(ctx, 2, ctx->hi1);
    // 0x11d5cc: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d5ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d5d0: 0xfc22f8c8  sd          $v0, -0x738($at)
    ctx->pc = 0x11d5d0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965448), GPR_U64(ctx, 2));
    // 0x11d5d4: 0x1012  mflo        $v0
    ctx->pc = 0x11d5d4u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x11d5d8: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d5d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d5dc: 0xfc22f8d0  sd          $v0, -0x730($at)
    ctx->pc = 0x11d5dcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965456), GPR_U64(ctx, 2));
    // 0x11d5e0: 0x70001012  mflo1       $v0
    ctx->pc = 0x11d5e0u;
    SET_GPR_U64(ctx, 2, ctx->lo1);
    // 0x11d5e4: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d5e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d5e8: 0xfc22f8d8  sd          $v0, -0x728($at)
    ctx->pc = 0x11d5e8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965464), GPR_U64(ctx, 2));
    // 0x11d5ec: 0x1028  mfsa        $v0
    ctx->pc = 0x11d5ecu;
    SET_GPR_U32(ctx, 2, ctx->sa);
    // 0x11d5f0: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d5f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d5f4: 0xfc22f8e0  sd          $v0, -0x720($at)
    ctx->pc = 0x11d5f4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965472), GPR_U64(ctx, 2));
    // 0x11d5f8: 0x40046000  mfc0        $a0, Status
    ctx->pc = 0x11d5f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ctx->cop0_status);
    // 0x11d5fc: 0x40056800  mfc0        $a1, Cause
    ctx->pc = 0x11d5fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ctx->cop0_cause);
    // 0x11d600: 0x40067000  mfc0        $a2, EPC
    ctx->pc = 0x11d600u;
    SET_GPR_S32(ctx, 6, (int32_t)ctx->cop0_epc);
    // 0x11d604: 0x40074000  mfc0        $a3, BadVaddr
    ctx->pc = 0x11d604u;
    SET_GPR_S32(ctx, 7, (int32_t)ctx->cop0_badvaddr);
    // 0x11d608: 0x4008b800  mfc0        $t0, Reserved23
    ctx->pc = 0x11d608u;
    SET_GPR_S32(ctx, 8, (int32_t)ctx->cop0_badpaddr);
    // 0x11d60c: 0x3c090026  lui         $t1, 0x26
    ctx->pc = 0x11d60cu;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)38 << 16));
    // 0x11d610: 0x2529f6c0  addiu       $t1, $t1, -0x940
    ctx->pc = 0x11d610u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294964928));
    // 0x11d614: 0x3c010012  lui         $at, 0x12
    ctx->pc = 0x11d614u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)18 << 16));
    // 0x11d618: 0x2421d63c  addiu       $at, $at, -0x29C4
    ctx->pc = 0x11d618u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 4294956604));
    // 0x11d61c: 0x40817000  mtc0        $at, EPC
    ctx->pc = 0x11d61cu;
    ctx->cop0_epc = GPR_U32(ctx, 1);
    // 0x11d620: 0x40f  sync.p
    ctx->pc = 0x11d620u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d624: 0x40016000  mfc0        $at, Status
    ctx->pc = 0x11d624u;
    SET_GPR_S32(ctx, 1, (int32_t)ctx->cop0_status);
    // 0x11d628: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x11d628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x11d62c: 0x220824  and         $at, $at, $v0
    ctx->pc = 0x11d62cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) & GPR_U64(ctx, 2));
    // 0x11d630: 0x40816000  mtc0        $at, Status
    ctx->pc = 0x11d630u;
    ctx->cop0_status = GPR_U32(ctx, 1) & 0xFF57FFFF;
    // 0x11d634: 0x40f  sync.p
    ctx->pc = 0x11d634u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d638: 0x42000018  eret
    ctx->pc = 0x11d638u;
    if (ctx->cop0_status & 0x4) { 
    ctx->pc = ctx->cop0_errorepc; 
    ctx->cop0_status &= ~0x4; 
} else { 
    ctx->pc = ctx->cop0_epc; 
    ctx->cop0_status &= ~0x2; 
} 
runtime->clearLLBit(ctx); 
return;
    // 0x11d63c: 0x30a2007c  andi        $v0, $a1, 0x7C
    ctx->pc = 0x11d63cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)124);
    // 0x11d640: 0x3c010021  lui         $at, 0x21
    ctx->pc = 0x11d640u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)33 << 16));
    // 0x11d644: 0x220821  addu        $at, $at, $v0
    ctx->pc = 0x11d644u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x11d648: 0x8c21a140  lw          $at, -0x5EC0($at)
    ctx->pc = 0x11d648u;
    SET_GPR_S32(ctx, 1, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294943040)));
    // 0x11d64c: 0x3c1d0026  lui         $sp, 0x26
    ctx->pc = 0x11d64cu;
    SET_GPR_S32(ctx, 29, (int32_t)((uint32_t)38 << 16));
    // 0x11d650: 0x20f809  jalr        $at
    ctx->pc = 0x11D650u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 1);
        SET_GPR_U32(ctx, 31, 0x11D658u);
        ctx->pc = 0x11D654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D650u;
            // 0x11d654: 0x27bdf6c0  addiu       $sp, $sp, -0x940 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294964928));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x11D658u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D120u: goto label_11d120;
            case 0x11D144u: goto label_11d144;
            case 0x11D14Cu: goto label_11d14c;
            case 0x11D160u: goto label_11d160;
            case 0x11D178u: goto label_11d178;
            case 0x11D188u: goto label_11d188;
            case 0x11D1ACu: goto label_11d1ac;
            case 0x11D1B4u: goto label_11d1b4;
            case 0x11D1B8u: goto label_11d1b8;
            case 0x11D1C8u: goto label_11d1c8;
            case 0x11D1E0u: goto label_11d1e0;
            case 0x11D1F0u: goto label_11d1f0;
            case 0x11D228u: goto label_11d228;
            case 0x11D230u: goto label_11d230;
            case 0x11D234u: goto label_11d234;
            case 0x11D240u: goto label_11d240;
            case 0x11D258u: goto label_11d258;
            case 0x11D268u: goto label_11d268;
            case 0x11D26Cu: goto label_11d26c;
            case 0x11D280u: goto label_11d280;
            case 0x11D29Cu: goto label_11d29c;
            case 0x11D2A8u: goto label_11d2a8;
            case 0x11D414u: goto label_11d414;
            case 0x11D658u: goto label_11d658;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x11D658u; }
            if (ctx->pc != 0x11D658u) { return; }
        }
        }
    }
    ctx->pc = 0x11D658u;
label_11d658:
    // 0x11d658: 0x3ffffcd  break       1023, 1023
    ctx->pc = 0x11d658u;
    runtime->handleBreak(rdram, ctx);
    // 0x11d65c: 0x0  nop
    ctx->pc = 0x11d65cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
