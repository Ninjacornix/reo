#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001249A0
// Address: 0x1249a0 - 0x124cd8
void sub_001249A0_0x1249a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001249A0_0x1249a0");
#endif

    switch (ctx->pc) {
        case 0x1249c0u: goto label_1249c0;
        case 0x1249d0u: goto label_1249d0;
        case 0x124a74u: goto label_124a74;
        case 0x124aacu: goto label_124aac;
        case 0x124b18u: goto label_124b18;
        case 0x124b40u: goto label_124b40;
        case 0x124b64u: goto label_124b64;
        case 0x124b80u: goto label_124b80;
        case 0x124ba4u: goto label_124ba4;
        case 0x124bc0u: goto label_124bc0;
        case 0x124bd0u: goto label_124bd0;
        case 0x124becu: goto label_124bec;
        case 0x124c10u: goto label_124c10;
        case 0x124c20u: goto label_124c20;
        case 0x124c4cu: goto label_124c4c;
        case 0x124c68u: goto label_124c68;
        default: break;
    }

    ctx->pc = 0x1249a0u;

    // 0x1249a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1249a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1249a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1249a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1249a8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1249a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1249ac: 0x12000009  beqz        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1249ACu;
    {
        const bool branch_taken_0x1249ac = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1249B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1249ACu;
            // 0x1249b0: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1249ac) {
            ctx->pc = 0x1249D4u;
            goto label_1249d4;
        }
    }
    ctx->pc = 0x1249B4u;
    // 0x1249b4: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x1249b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1249b8: 0xc04d3d6  jal         func_134F58
    ctx->pc = 0x1249B8u;
    SET_GPR_U32(ctx, 31, 0x1249C0u);
    ctx->pc = 0x1249BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1249B8u;
            // 0x1249bc: 0xae000008  sw          $zero, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F58u;
    if (runtime->hasFunction(0x134F58u)) {
        auto targetFn = runtime->lookupFunction(0x134F58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1249C0u; }
        if (ctx->pc != 0x1249C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F58_0x134f58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1249C0u; }
        if (ctx->pc != 0x1249C0u) { return; }
    }
    ctx->pc = 0x1249C0u;
label_1249c0:
    // 0x1249c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1249c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1249c4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1249c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1249c8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1249C8u;
    SET_GPR_U32(ctx, 31, 0x1249D0u);
    ctx->pc = 0x1249CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1249C8u;
            // 0x1249cc: 0x240600e4  addiu       $a2, $zero, 0xE4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 228));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1249D0u; }
        if (ctx->pc != 0x1249D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1249D0u; }
        if (ctx->pc != 0x1249D0u) { return; }
    }
    ctx->pc = 0x1249D0u;
label_1249d0:
    // 0x1249d0: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1249d0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
label_1249d4:
    // 0x1249d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1249d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1249d8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1249d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1249dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1249DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1249E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1249DCu;
            // 0x1249e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1249C0u: goto label_1249c0;
            case 0x1249D0u: goto label_1249d0;
            case 0x1249D4u: goto label_1249d4;
            case 0x124A74u: goto label_124a74;
            case 0x124AACu: goto label_124aac;
            case 0x124AB8u: goto label_124ab8;
            case 0x124B18u: goto label_124b18;
            case 0x124B40u: goto label_124b40;
            case 0x124B64u: goto label_124b64;
            case 0x124B70u: goto label_124b70;
            case 0x124B80u: goto label_124b80;
            case 0x124BA4u: goto label_124ba4;
            case 0x124BC0u: goto label_124bc0;
            case 0x124BD0u: goto label_124bd0;
            case 0x124BECu: goto label_124bec;
            case 0x124BF4u: goto label_124bf4;
            case 0x124C00u: goto label_124c00;
            case 0x124C10u: goto label_124c10;
            case 0x124C20u: goto label_124c20;
            case 0x124C4Cu: goto label_124c4c;
            case 0x124C68u: goto label_124c68;
            case 0x124C70u: goto label_124c70;
            case 0x124CA4u: goto label_124ca4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1249E4u;
    // 0x1249e4: 0x0  nop
    ctx->pc = 0x1249e4u;
    // NOP
    // 0x1249e8: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1249e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1249ec: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1249ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1249f0: 0xffb00050  sd          $s0, 0x50($sp)
    ctx->pc = 0x1249f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x1249f4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1249f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1249f8: 0xffb10058  sd          $s1, 0x58($sp)
    ctx->pc = 0x1249f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 17));
    // 0x1249fc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1249fcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124a00: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x124a00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x124a04: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x124a04u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124a08: 0xffb30068  sd          $s3, 0x68($sp)
    ctx->pc = 0x124a08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 19));
    // 0x124a0c: 0x2613000c  addiu       $s3, $s0, 0xC
    ctx->pc = 0x124a0cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x124a10: 0xffb40070  sd          $s4, 0x70($sp)
    ctx->pc = 0x124a10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 20));
    // 0x124a14: 0x26140018  addiu       $s4, $s0, 0x18
    ctx->pc = 0x124a14u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x124a18: 0xffb50078  sd          $s5, 0x78($sp)
    ctx->pc = 0x124a18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 21));
    // 0x124a1c: 0x2615000d  addiu       $s5, $s0, 0xD
    ctx->pc = 0x124a1cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 16), 13));
    // 0x124a20: 0xffb60080  sd          $s6, 0x80($sp)
    ctx->pc = 0x124a20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x124a24: 0x2616000e  addiu       $s6, $s0, 0xE
    ctx->pc = 0x124a24u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 16), 14));
    // 0x124a28: 0xffb70088  sd          $s7, 0x88($sp)
    ctx->pc = 0x124a28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 23));
    // 0x124a2c: 0x26170010  addiu       $s7, $s0, 0x10
    ctx->pc = 0x124a2cu;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x124a30: 0xffbe0090  sd          $fp, 0x90($sp)
    ctx->pc = 0x124a30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 30));
    // 0x124a34: 0x261e000f  addiu       $fp, $s0, 0xF
    ctx->pc = 0x124a34u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 16), 15));
    // 0x124a38: 0xffbf0098  sd          $ra, 0x98($sp)
    ctx->pc = 0x124a38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 31));
    // 0x124a3c: 0x27a60040  addiu       $a2, $sp, 0x40
    ctx->pc = 0x124a3cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x124a40: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x124a40u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x124a44: 0x26020014  addiu       $v0, $s0, 0x14
    ctx->pc = 0x124a44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x124a48: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x124a48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124a4c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x124a4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124a50: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x124a50u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124a54: 0x2a0402d  daddu       $t0, $s5, $zero
    ctx->pc = 0x124a54u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124a58: 0x3c0482d  daddu       $t1, $fp, $zero
    ctx->pc = 0x124a58u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124a5c: 0x2c0502d  daddu       $t2, $s6, $zero
    ctx->pc = 0x124a5cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124a60: 0x40582d  daddu       $t3, $v0, $zero
    ctx->pc = 0x124a60u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124a64: 0xafa2004c  sw          $v0, 0x4C($sp)
    ctx->pc = 0x124a64u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 2));
    // 0x124a68: 0xafb40000  sw          $s4, 0x0($sp)
    ctx->pc = 0x124a68u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 20));
    // 0x124a6c: 0xc0499e6  jal         func_126798
    ctx->pc = 0x124A6Cu;
    SET_GPR_U32(ctx, 31, 0x124A74u);
    ctx->pc = 0x124A70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124A6Cu;
            // 0x124a70: 0xafb70008  sw          $s7, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 23));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126798u;
    if (runtime->hasFunction(0x126798u)) {
        auto targetFn = runtime->lookupFunction(0x126798u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124A74u; }
        if (ctx->pc != 0x124A74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126798_0x126798(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124A74u; }
        if (ctx->pc != 0x124A74u) { return; }
    }
    ctx->pc = 0x124A74u;
label_124a74:
    // 0x124a74: 0x440008b  bltz        $v0, . + 4 + (0x8B << 2)
    ctx->pc = 0x124A74u;
    {
        const bool branch_taken_0x124a74 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x124A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124A74u;
            // 0x124a78: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124a74) {
            ctx->pc = 0x124CA4u;
            goto label_124ca4;
        }
    }
    ctx->pc = 0x124A7Cu;
    // 0x124a7c: 0x82620000  lb          $v0, 0x0($s3)
    ctx->pc = 0x124a7cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x124a80: 0x28420005  slti        $v0, $v0, 0x5
    ctx->pc = 0x124a80u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x124a84: 0x1440003a  bnez        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x124A84u;
    {
        const bool branch_taken_0x124a84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x124A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124A84u;
            // 0x124a88: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124a84) {
            ctx->pc = 0x124B70u;
            goto label_124b70;
        }
    }
    ctx->pc = 0x124A8Cu;
    // 0x124a8c: 0x8e0200b0  lw          $v0, 0xB0($s0)
    ctx->pc = 0x124a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 176)));
    // 0x124a90: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x124A90u;
    {
        const bool branch_taken_0x124a90 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x124a90) {
            ctx->pc = 0x124A94u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x124A90u;
            // 0x124a94: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x124AB8u;
            goto label_124ab8;
        }
    }
    ctx->pc = 0x124A98u;
    // 0x124a98: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x124a98u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x124a9c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x124a9cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x124aa0: 0x24849b68  addiu       $a0, $a0, -0x6498
    ctx->pc = 0x124aa0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294941544));
    // 0x124aa4: 0xc04a04a  jal         func_128128
    ctx->pc = 0x124AA4u;
    SET_GPR_U32(ctx, 31, 0x124AACu);
    ctx->pc = 0x124AA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124AA4u;
            // 0x124aa8: 0x24a59b88  addiu       $a1, $a1, -0x6478 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941576));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128128u;
    if (runtime->hasFunction(0x128128u)) {
        auto targetFn = runtime->lookupFunction(0x128128u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124AACu; }
        if (ctx->pc != 0x124AACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128128_0x128128(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124AACu; }
        if (ctx->pc != 0x124AACu) { return; }
    }
    ctx->pc = 0x124AACu;
label_124aac:
    // 0x124aac: 0x1000007d  b           . + 4 + (0x7D << 2)
    ctx->pc = 0x124AACu;
    {
        const bool branch_taken_0x124aac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x124AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124AACu;
            // 0x124ab0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124aac) {
            ctx->pc = 0x124CA4u;
            goto label_124ca4;
        }
    }
    ctx->pc = 0x124AB4u;
    // 0x124ab4: 0x0  nop
    ctx->pc = 0x124ab4u;
    // NOP
label_124ab8:
    // 0x124ab8: 0x24090060  addiu       $t1, $zero, 0x60
    ctx->pc = 0x124ab8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x124abc: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x124abcu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x124ac0: 0x2408000a  addiu       $t0, $zero, 0xA
    ctx->pc = 0x124ac0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x124ac4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x124ac4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124ac8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x124ac8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124acc: 0x82c30000  lb          $v1, 0x0($s6)
    ctx->pc = 0x124accu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x124ad0: 0x27a60042  addiu       $a2, $sp, 0x42
    ctx->pc = 0x124ad0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 66));
    // 0x124ad4: 0x27a70043  addiu       $a3, $sp, 0x43
    ctx->pc = 0x124ad4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 67));
    // 0x124ad8: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x124ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x124adc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x124adcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x124ae0: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x124ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x124ae4: 0xa3c20000  sb          $v0, 0x0($fp)
    ctx->pc = 0x124ae4u;
    WRITE8(ADD32(GPR_U32(ctx, 30), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x124ae8: 0xaee90000  sw          $t1, 0x0($s7)
    ctx->pc = 0x124ae8u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 0), GPR_U32(ctx, 9));
    // 0x124aec: 0xa6080098  sh          $t0, 0x98($s0)
    ctx->pc = 0x124aecu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 152), (uint16_t)GPR_U32(ctx, 8));
    // 0x124af0: 0xa600001c  sh          $zero, 0x1C($s0)
    ctx->pc = 0x124af0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 28), (uint16_t)GPR_U32(ctx, 0));
    // 0x124af4: 0xa6000024  sh          $zero, 0x24($s0)
    ctx->pc = 0x124af4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x124af8: 0xa6000026  sh          $zero, 0x26($s0)
    ctx->pc = 0x124af8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x124afc: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x124afcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x124b00: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x124b00u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x124b04: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x124b04u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x124b08: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x124b08u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x124b0c: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x124b0cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x124b10: 0xc049a46  jal         func_126918
    ctx->pc = 0x124B10u;
    SET_GPR_U32(ctx, 31, 0x124B18u);
    ctx->pc = 0x124B14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124B10u;
            // 0x124b14: 0xae000088  sw          $zero, 0x88($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126918u;
    if (runtime->hasFunction(0x126918u)) {
        auto targetFn = runtime->lookupFunction(0x126918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124B18u; }
        if (ctx->pc != 0x124B18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126918_0x126918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124B18u; }
        if (ctx->pc != 0x124B18u) { return; }
    }
    ctx->pc = 0x124B18u;
label_124b18:
    // 0x124b18: 0x4400036  bltz        $v0, . + 4 + (0x36 << 2)
    ctx->pc = 0x124B18u;
    {
        const bool branch_taken_0x124b18 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x124B1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124B18u;
            // 0x124b1c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124b18) {
            ctx->pc = 0x124BF4u;
            goto label_124bf4;
        }
    }
    ctx->pc = 0x124B20u;
    // 0x124b20: 0x8e870000  lw          $a3, 0x0($s4)
    ctx->pc = 0x124b20u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x124b24: 0x93a50042  lbu         $a1, 0x42($sp)
    ctx->pc = 0x124b24u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 66)));
    // 0x124b28: 0x27a80032  addiu       $t0, $sp, 0x32
    ctx->pc = 0x124b28u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 50));
    // 0x124b2c: 0x93a60043  lbu         $a2, 0x43($sp)
    ctx->pc = 0x124b2cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 67)));
    // 0x124b30: 0x27a90034  addiu       $t1, $sp, 0x34
    ctx->pc = 0x124b30u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 52));
    // 0x124b34: 0x27aa0036  addiu       $t2, $sp, 0x36
    ctx->pc = 0x124b34u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 29), 54));
    // 0x124b38: 0xc049428  jal         func_1250A0
    ctx->pc = 0x124B38u;
    SET_GPR_U32(ctx, 31, 0x124B40u);
    ctx->pc = 0x124B3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124B38u;
            // 0x124b3c: 0xa7a00030  sh          $zero, 0x30($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 48), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1250A0u;
    if (runtime->hasFunction(0x1250A0u)) {
        auto targetFn = runtime->lookupFunction(0x1250A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124B40u; }
        if (ctx->pc != 0x124B40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001250A0_0x1250a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124B40u; }
        if (ctx->pc != 0x124B40u) { return; }
    }
    ctx->pc = 0x124B40u;
label_124b40:
    // 0x124b40: 0x4400058  bltz        $v0, . + 4 + (0x58 << 2)
    ctx->pc = 0x124B40u;
    {
        const bool branch_taken_0x124b40 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x124B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124B40u;
            // 0x124b44: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124b40) {
            ctx->pc = 0x124CA4u;
            goto label_124ca4;
        }
    }
    ctx->pc = 0x124B48u;
    // 0x124b48: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x124b48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x124b4c: 0x8c42b948  lw          $v0, -0x46B8($v0)
    ctx->pc = 0x124b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949192)));
    // 0x124b50: 0x50400047  beql        $v0, $zero, . + 4 + (0x47 << 2)
    ctx->pc = 0x124B50u;
    {
        const bool branch_taken_0x124b50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x124b50) {
            ctx->pc = 0x124B54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x124B50u;
            // 0x124b54: 0x8202000e  lb          $v0, 0xE($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x124C70u;
            goto label_124c70;
        }
    }
    ctx->pc = 0x124B58u;
    // 0x124b58: 0x8e0400b0  lw          $a0, 0xB0($s0)
    ctx->pc = 0x124b58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 176)));
    // 0x124b5c: 0x40f809  jalr        $v0
    ctx->pc = 0x124B5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x124B64u);
        ctx->pc = 0x124B60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124B5Cu;
            // 0x124b60: 0x27a50030  addiu       $a1, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x124B64u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1249C0u: goto label_1249c0;
            case 0x1249D0u: goto label_1249d0;
            case 0x1249D4u: goto label_1249d4;
            case 0x124A74u: goto label_124a74;
            case 0x124AACu: goto label_124aac;
            case 0x124AB8u: goto label_124ab8;
            case 0x124B18u: goto label_124b18;
            case 0x124B40u: goto label_124b40;
            case 0x124B64u: goto label_124b64;
            case 0x124B70u: goto label_124b70;
            case 0x124B80u: goto label_124b80;
            case 0x124BA4u: goto label_124ba4;
            case 0x124BC0u: goto label_124bc0;
            case 0x124BD0u: goto label_124bd0;
            case 0x124BECu: goto label_124bec;
            case 0x124BF4u: goto label_124bf4;
            case 0x124C00u: goto label_124c00;
            case 0x124C10u: goto label_124c10;
            case 0x124C20u: goto label_124c20;
            case 0x124C4Cu: goto label_124c4c;
            case 0x124C68u: goto label_124c68;
            case 0x124C70u: goto label_124c70;
            case 0x124CA4u: goto label_124ca4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124B64u; }
            if (ctx->pc != 0x124B64u) { return; }
        }
        }
    }
    ctx->pc = 0x124B64u;
label_124b64:
    // 0x124b64: 0x10000042  b           . + 4 + (0x42 << 2)
    ctx->pc = 0x124B64u;
    {
        const bool branch_taken_0x124b64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x124B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124B64u;
            // 0x124b68: 0x8202000e  lb          $v0, 0xE($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124b64) {
            ctx->pc = 0x124C70u;
            goto label_124c70;
        }
    }
    ctx->pc = 0x124B6Cu;
    // 0x124b6c: 0x0  nop
    ctx->pc = 0x124b6cu;
    // NOP
label_124b70:
    // 0x124b70: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x124b70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124b74: 0x27a60042  addiu       $a2, $sp, 0x42
    ctx->pc = 0x124b74u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 66));
    // 0x124b78: 0xc049a46  jal         func_126918
    ctx->pc = 0x124B78u;
    SET_GPR_U32(ctx, 31, 0x124B80u);
    ctx->pc = 0x124B7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124B78u;
            // 0x124b7c: 0x27a70043  addiu       $a3, $sp, 0x43 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 67));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126918u;
    if (runtime->hasFunction(0x126918u)) {
        auto targetFn = runtime->lookupFunction(0x126918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124B80u; }
        if (ctx->pc != 0x124B80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126918_0x126918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124B80u; }
        if (ctx->pc != 0x124B80u) { return; }
    }
    ctx->pc = 0x124B80u;
label_124b80:
    // 0x124b80: 0x440001c  bltz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x124B80u;
    {
        const bool branch_taken_0x124b80 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x124B84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124B80u;
            // 0x124b84: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124b80) {
            ctx->pc = 0x124BF4u;
            goto label_124bf4;
        }
    }
    ctx->pc = 0x124B88u;
    // 0x124b88: 0x8e870000  lw          $a3, 0x0($s4)
    ctx->pc = 0x124b88u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x124b8c: 0x93a50042  lbu         $a1, 0x42($sp)
    ctx->pc = 0x124b8cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 66)));
    // 0x124b90: 0x27a80044  addiu       $t0, $sp, 0x44
    ctx->pc = 0x124b90u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 68));
    // 0x124b94: 0x93a60043  lbu         $a2, 0x43($sp)
    ctx->pc = 0x124b94u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 67)));
    // 0x124b98: 0x27a90046  addiu       $t1, $sp, 0x46
    ctx->pc = 0x124b98u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 70));
    // 0x124b9c: 0xc049428  jal         func_1250A0
    ctx->pc = 0x124B9Cu;
    SET_GPR_U32(ctx, 31, 0x124BA4u);
    ctx->pc = 0x124BA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124B9Cu;
            // 0x124ba0: 0x27aa0048  addiu       $t2, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1250A0u;
    if (runtime->hasFunction(0x1250A0u)) {
        auto targetFn = runtime->lookupFunction(0x1250A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124BA4u; }
        if (ctx->pc != 0x124BA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001250A0_0x1250a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124BA4u; }
        if (ctx->pc != 0x124BA4u) { return; }
    }
    ctx->pc = 0x124BA4u;
label_124ba4:
    // 0x124ba4: 0x440ffc1  bltz        $v0, . + 4 + (-0x3F << 2)
    ctx->pc = 0x124BA4u;
    {
        const bool branch_taken_0x124ba4 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x124BA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124BA4u;
            // 0x124ba8: 0x2613001c  addiu       $s3, $s0, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124ba4) {
            ctx->pc = 0x124AACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_124aac;
        }
    }
    ctx->pc = 0x124BACu;
    // 0x124bac: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x124bacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x124bb0: 0x87a50044  lh          $a1, 0x44($sp)
    ctx->pc = 0x124bb0u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x124bb4: 0x87a60046  lh          $a2, 0x46($sp)
    ctx->pc = 0x124bb4u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 70)));
    // 0x124bb8: 0xc04d3ca  jal         func_134F28
    ctx->pc = 0x124BB8u;
    SET_GPR_U32(ctx, 31, 0x124BC0u);
    ctx->pc = 0x124BBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124BB8u;
            // 0x124bbc: 0x87a70048  lh          $a3, 0x48($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 72)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F28u;
    if (runtime->hasFunction(0x134F28u)) {
        auto targetFn = runtime->lookupFunction(0x134F28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124BC0u; }
        if (ctx->pc != 0x124BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F28_0x134f28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124BC0u; }
        if (ctx->pc != 0x124BC0u) { return; }
    }
    ctx->pc = 0x124BC0u;
label_124bc0:
    // 0x124bc0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x124bc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124bc4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x124bc4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124bc8: 0xc049a26  jal         func_126898
    ctx->pc = 0x124BC8u;
    SET_GPR_U32(ctx, 31, 0x124BD0u);
    ctx->pc = 0x124BCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124BC8u;
            // 0x124bcc: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126898u;
    if (runtime->hasFunction(0x126898u)) {
        auto targetFn = runtime->lookupFunction(0x126898u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124BD0u; }
        if (ctx->pc != 0x124BD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126898_0x126898(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124BD0u; }
        if (ctx->pc != 0x124BD0u) { return; }
    }
    ctx->pc = 0x124BD0u;
label_124bd0:
    // 0x124bd0: 0x4400008  bltz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x124BD0u;
    {
        const bool branch_taken_0x124bd0 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x124BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124BD0u;
            // 0x124bd4: 0x27b40020  addiu       $s4, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124bd0) {
            ctx->pc = 0x124BF4u;
            goto label_124bf4;
        }
    }
    ctx->pc = 0x124BD8u;
    // 0x124bd8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x124bd8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124bdc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x124bdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124be0: 0x27a60010  addiu       $a2, $sp, 0x10
    ctx->pc = 0x124be0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x124be4: 0xc049a64  jal         func_126990
    ctx->pc = 0x124BE4u;
    SET_GPR_U32(ctx, 31, 0x124BECu);
    ctx->pc = 0x124BE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124BE4u;
            // 0x124be8: 0x280382d  daddu       $a3, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126990u;
    if (runtime->hasFunction(0x126990u)) {
        auto targetFn = runtime->lookupFunction(0x126990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124BECu; }
        if (ctx->pc != 0x124BECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126990_0x126990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124BECu; }
        if (ctx->pc != 0x124BECu) { return; }
    }
    ctx->pc = 0x124BECu;
label_124bec:
    // 0x124bec: 0x4430004  bgezl       $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x124BECu;
    {
        const bool branch_taken_0x124bec = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x124bec) {
            ctx->pc = 0x124BF0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x124BECu;
            // 0x124bf0: 0x8fa2004c  lw          $v0, 0x4C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x124C00u;
            goto label_124c00;
        }
    }
    ctx->pc = 0x124BF4u;
label_124bf4:
    // 0x124bf4: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x124BF4u;
    {
        const bool branch_taken_0x124bf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x124BF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124BF4u;
            // 0x124bf8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124bf4) {
            ctx->pc = 0x124CA4u;
            goto label_124ca4;
        }
    }
    ctx->pc = 0x124BFCu;
    // 0x124bfc: 0x0  nop
    ctx->pc = 0x124bfcu;
    // NOP
label_124c00:
    // 0x124c00: 0x86660000  lh          $a2, 0x0($s3)
    ctx->pc = 0x124c00u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x124c04: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x124c04u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x124c08: 0xc04d3ac  jal         func_134EB0
    ctx->pc = 0x124C08u;
    SET_GPR_U32(ctx, 31, 0x124C10u);
    ctx->pc = 0x124C0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124C08u;
            // 0x124c0c: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134EB0u;
    if (runtime->hasFunction(0x134EB0u)) {
        auto targetFn = runtime->lookupFunction(0x134EB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124C10u; }
        if (ctx->pc != 0x124C10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134EB0_0x134eb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124C10u; }
        if (ctx->pc != 0x124C10u) { return; }
    }
    ctx->pc = 0x124C10u;
label_124c10:
    // 0x124c10: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x124c10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x124c14: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x124c14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x124c18: 0xc04d3b6  jal         func_134ED8
    ctx->pc = 0x124C18u;
    SET_GPR_U32(ctx, 31, 0x124C20u);
    ctx->pc = 0x124C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124C18u;
            // 0x124c1c: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134ED8u;
    if (runtime->hasFunction(0x134ED8u)) {
        auto targetFn = runtime->lookupFunction(0x134ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124C20u; }
        if (ctx->pc != 0x124C20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134ED8_0x134ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124C20u; }
        if (ctx->pc != 0x124C20u) { return; }
    }
    ctx->pc = 0x124C20u;
label_124c20:
    // 0x124c20: 0x26020034  addiu       $v0, $s0, 0x34
    ctx->pc = 0x124c20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 52));
    // 0x124c24: 0x26060020  addiu       $a2, $s0, 0x20
    ctx->pc = 0x124c24u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
    // 0x124c28: 0x26070024  addiu       $a3, $s0, 0x24
    ctx->pc = 0x124c28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 36));
    // 0x124c2c: 0x26080026  addiu       $t0, $s0, 0x26
    ctx->pc = 0x124c2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 38));
    // 0x124c30: 0x26090028  addiu       $t1, $s0, 0x28
    ctx->pc = 0x124c30u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
    // 0x124c34: 0x260a002c  addiu       $t2, $s0, 0x2C
    ctx->pc = 0x124c34u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 16), 44));
    // 0x124c38: 0x260b0030  addiu       $t3, $s0, 0x30
    ctx->pc = 0x124c38u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x124c3c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x124c3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124c40: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x124c40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124c44: 0xc049ab2  jal         func_126AC8
    ctx->pc = 0x124C44u;
    SET_GPR_U32(ctx, 31, 0x124C4Cu);
    ctx->pc = 0x124C48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124C44u;
            // 0x124c48: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126AC8u;
    if (runtime->hasFunction(0x126AC8u)) {
        auto targetFn = runtime->lookupFunction(0x126AC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124C4Cu; }
        if (ctx->pc != 0x124C4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126AC8_0x126ac8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124C4Cu; }
        if (ctx->pc != 0x124C4Cu) { return; }
    }
    ctx->pc = 0x124C4Cu;
label_124c4c:
    // 0x124c4c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x124c4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124c50: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x124c50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124c54: 0x260600c8  addiu       $a2, $s0, 0xC8
    ctx->pc = 0x124c54u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 200));
    // 0x124c58: 0x260700cc  addiu       $a3, $s0, 0xCC
    ctx->pc = 0x124c58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 204));
    // 0x124c5c: 0x260800dc  addiu       $t0, $s0, 0xDC
    ctx->pc = 0x124c5cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 220));
    // 0x124c60: 0xc049b4a  jal         func_126D28
    ctx->pc = 0x124C60u;
    SET_GPR_U32(ctx, 31, 0x124C68u);
    ctx->pc = 0x124C64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124C60u;
            // 0x124c64: 0x260900de  addiu       $t1, $s0, 0xDE (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 222));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126D28u;
    if (runtime->hasFunction(0x126D28u)) {
        auto targetFn = runtime->lookupFunction(0x126D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124C68u; }
        if (ctx->pc != 0x124C68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126D28_0x126d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124C68u; }
        if (ctx->pc != 0x124C68u) { return; }
    }
    ctx->pc = 0x124C68u;
label_124c68:
    // 0x124c68: 0xa6000098  sh          $zero, 0x98($s0)
    ctx->pc = 0x124c68u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 152), (uint16_t)GPR_U32(ctx, 0));
    // 0x124c6c: 0x8202000e  lb          $v0, 0xE($s0)
    ctx->pc = 0x124c6cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_124c70:
    // 0x124c70: 0x8203000f  lb          $v1, 0xF($s0)
    ctx->pc = 0x124c70u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 15)));
    // 0x124c74: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x124c74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x124c78: 0x8e05003c  lw          $a1, 0x3C($s0)
    ctx->pc = 0x124c78u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x124c7c: 0x8e060040  lw          $a2, 0x40($s0)
    ctx->pc = 0x124c7cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x124c80: 0x8e070044  lw          $a3, 0x44($s0)
    ctx->pc = 0x124c80u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x124c84: 0xae020050  sw          $v0, 0x50($s0)
    ctx->pc = 0x124c84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 2));
    // 0x124c88: 0xae030054  sw          $v1, 0x54($s0)
    ctx->pc = 0x124c88u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 3));
    // 0x124c8c: 0xae040058  sw          $a0, 0x58($s0)
    ctx->pc = 0x124c8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 4));
    // 0x124c90: 0xae05005c  sw          $a1, 0x5C($s0)
    ctx->pc = 0x124c90u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 5));
    // 0x124c94: 0xae060060  sw          $a2, 0x60($s0)
    ctx->pc = 0x124c94u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 96), GPR_U32(ctx, 6));
    // 0x124c98: 0xae070064  sw          $a3, 0x64($s0)
    ctx->pc = 0x124c98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 7));
    // 0x124c9c: 0xae00008c  sw          $zero, 0x8C($s0)
    ctx->pc = 0x124c9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 0));
    // 0x124ca0: 0x87a20040  lh          $v0, 0x40($sp)
    ctx->pc = 0x124ca0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 64)));
label_124ca4:
    // 0x124ca4: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x124ca4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x124ca8: 0xdfb10058  ld          $s1, 0x58($sp)
    ctx->pc = 0x124ca8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x124cac: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x124cacu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x124cb0: 0xdfb30068  ld          $s3, 0x68($sp)
    ctx->pc = 0x124cb0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x124cb4: 0xdfb40070  ld          $s4, 0x70($sp)
    ctx->pc = 0x124cb4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x124cb8: 0xdfb50078  ld          $s5, 0x78($sp)
    ctx->pc = 0x124cb8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x124cbc: 0xdfb60080  ld          $s6, 0x80($sp)
    ctx->pc = 0x124cbcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x124cc0: 0xdfb70088  ld          $s7, 0x88($sp)
    ctx->pc = 0x124cc0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x124cc4: 0xdfbe0090  ld          $fp, 0x90($sp)
    ctx->pc = 0x124cc4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x124cc8: 0xdfbf0098  ld          $ra, 0x98($sp)
    ctx->pc = 0x124cc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x124ccc: 0x3e00008  jr          $ra
    ctx->pc = 0x124CCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124CD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124CCCu;
            // 0x124cd0: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1249C0u: goto label_1249c0;
            case 0x1249D0u: goto label_1249d0;
            case 0x1249D4u: goto label_1249d4;
            case 0x124A74u: goto label_124a74;
            case 0x124AACu: goto label_124aac;
            case 0x124AB8u: goto label_124ab8;
            case 0x124B18u: goto label_124b18;
            case 0x124B40u: goto label_124b40;
            case 0x124B64u: goto label_124b64;
            case 0x124B70u: goto label_124b70;
            case 0x124B80u: goto label_124b80;
            case 0x124BA4u: goto label_124ba4;
            case 0x124BC0u: goto label_124bc0;
            case 0x124BD0u: goto label_124bd0;
            case 0x124BECu: goto label_124bec;
            case 0x124BF4u: goto label_124bf4;
            case 0x124C00u: goto label_124c00;
            case 0x124C10u: goto label_124c10;
            case 0x124C20u: goto label_124c20;
            case 0x124C4Cu: goto label_124c4c;
            case 0x124C68u: goto label_124c68;
            case 0x124C70u: goto label_124c70;
            case 0x124CA4u: goto label_124ca4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124CD4u;
    // 0x124cd4: 0x0  nop
    ctx->pc = 0x124cd4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
