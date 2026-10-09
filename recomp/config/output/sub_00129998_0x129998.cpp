#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129998
// Address: 0x129998 - 0x129a60
void sub_00129998_0x129998(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129998_0x129998");
#endif

    switch (ctx->pc) {
        case 0x1299c8u: goto label_1299c8;
        case 0x1299d4u: goto label_1299d4;
        case 0x129a00u: goto label_129a00;
        case 0x129a18u: goto label_129a18;
        case 0x129a2cu: goto label_129a2c;
        case 0x129a40u: goto label_129a40;
        default: break;
    }

    ctx->pc = 0x129998u;

    // 0x129998: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x129998u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12999c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x12999cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1299a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1299a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1299a4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1299a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1299a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1299a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1299ac: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1299acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1299b0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1299b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1299b4: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1299b4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1299b8: 0x54430012  bnel        $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1299B8u;
    {
        const bool branch_taken_0x1299b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1299b8) {
            ctx->pc = 0x1299BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1299B8u;
            // 0x1299bc: 0x82110003  lb          $s1, 0x3($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129A04u;
            goto label_129a04;
        }
    }
    ctx->pc = 0x1299C0u;
    // 0x1299c0: 0xc04c16e  jal         func_1305B8
    ctx->pc = 0x1299C0u;
    SET_GPR_U32(ctx, 31, 0x1299C8u);
    ctx->pc = 0x1299C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1299C0u;
            // 0x1299c4: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1299C8u; }
        if (ctx->pc != 0x1299C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305B8_0x1305b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1299C8u; }
        if (ctx->pc != 0x1299C8u) { return; }
    }
    ctx->pc = 0x1299C8u;
label_1299c8:
    // 0x1299c8: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x1299c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1299cc: 0xc04c182  jal         func_130608
    ctx->pc = 0x1299CCu;
    SET_GPR_U32(ctx, 31, 0x1299D4u);
    ctx->pc = 0x1299D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1299CCu;
            // 0x1299d0: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130608u;
    if (runtime->hasFunction(0x130608u)) {
        auto targetFn = runtime->lookupFunction(0x130608u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1299D4u; }
        if (ctx->pc != 0x1299D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130608_0x130608(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1299D4u; }
        if (ctx->pc != 0x1299D4u) { return; }
    }
    ctx->pc = 0x1299D4u;
label_1299d4:
    // 0x1299d4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1299d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1299d8: 0x92030001  lbu         $v1, 0x1($s0)
    ctx->pc = 0x1299d8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1299dc: 0x8e050014  lw          $a1, 0x14($s0)
    ctx->pc = 0x1299dcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1299e0: 0x2463fffd  addiu       $v1, $v1, -0x3
    ctx->pc = 0x1299e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967293));
    // 0x1299e4: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x1299e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1299e8: 0x2c630002  sltiu       $v1, $v1, 0x2
    ctx->pc = 0x1299e8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x1299ec: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x1299ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1299f0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1299F0u;
    {
        const bool branch_taken_0x1299f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1299F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1299F0u;
            // 0x1299f4: 0xae020020  sw          $v0, 0x20($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1299f0) {
            ctx->pc = 0x129A00u;
            goto label_129a00;
        }
    }
    ctx->pc = 0x1299F8u;
    // 0x1299f8: 0xc04a4b8  jal         func_1292E0
    ctx->pc = 0x1299F8u;
    SET_GPR_U32(ctx, 31, 0x129A00u);
    ctx->pc = 0x1299FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1299F8u;
            // 0x1299fc: 0xae050014  sw          $a1, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1292E0u;
    if (runtime->hasFunction(0x1292E0u)) {
        auto targetFn = runtime->lookupFunction(0x1292E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129A00u; }
        if (ctx->pc != 0x129A00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001292E0_0x1292e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129A00u; }
        if (ctx->pc != 0x129A00u) { return; }
    }
    ctx->pc = 0x129A00u;
label_129a00:
    // 0x129a00: 0x82110003  lb          $s1, 0x3($s0)
    ctx->pc = 0x129a00u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
label_129a04:
    // 0x129a04: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x129a04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x129a08: 0x56220010  bnel        $s1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x129A08u;
    {
        const bool branch_taken_0x129a08 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x129a08) {
            ctx->pc = 0x129A0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129A08u;
            // 0x129a0c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129A4Cu;
            goto label_129a4c;
        }
    }
    ctx->pc = 0x129A10u;
    // 0x129a10: 0xc04c16e  jal         func_1305B8
    ctx->pc = 0x129A10u;
    SET_GPR_U32(ctx, 31, 0x129A18u);
    ctx->pc = 0x129A14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129A10u;
            // 0x129a14: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129A18u; }
        if (ctx->pc != 0x129A18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305B8_0x1305b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129A18u; }
        if (ctx->pc != 0x129A18u) { return; }
    }
    ctx->pc = 0x129A18u;
label_129a18:
    // 0x129a18: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x129a18u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129a1c: 0x5651000b  bnel        $s2, $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x129A1Cu;
    {
        const bool branch_taken_0x129a1c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 17));
        if (branch_taken_0x129a1c) {
            ctx->pc = 0x129A20u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129A1Cu;
            // 0x129a20: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129A4Cu;
            goto label_129a4c;
        }
    }
    ctx->pc = 0x129A24u;
    // 0x129a24: 0xc04c182  jal         func_130608
    ctx->pc = 0x129A24u;
    SET_GPR_U32(ctx, 31, 0x129A2Cu);
    ctx->pc = 0x129A28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129A24u;
            // 0x129a28: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130608u;
    if (runtime->hasFunction(0x130608u)) {
        auto targetFn = runtime->lookupFunction(0x130608u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129A2Cu; }
        if (ctx->pc != 0x129A2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130608_0x130608(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129A2Cu; }
        if (ctx->pc != 0x129A2Cu) { return; }
    }
    ctx->pc = 0x129A2Cu;
label_129a2c:
    // 0x129a2c: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x129a2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x129a30: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x129a30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129a34: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x129a34u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x129a38: 0xc04a4b8  jal         func_1292E0
    ctx->pc = 0x129A38u;
    SET_GPR_U32(ctx, 31, 0x129A40u);
    ctx->pc = 0x129A3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129A38u;
            // 0x129a3c: 0xae020020  sw          $v0, 0x20($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1292E0u;
    if (runtime->hasFunction(0x1292E0u)) {
        auto targetFn = runtime->lookupFunction(0x1292E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129A40u; }
        if (ctx->pc != 0x129A40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001292E0_0x1292e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129A40u; }
        if (ctx->pc != 0x129A40u) { return; }
    }
    ctx->pc = 0x129A40u;
label_129a40:
    // 0x129a40: 0xa2120001  sb          $s2, 0x1($s0)
    ctx->pc = 0x129a40u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 18));
    // 0x129a44: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x129a44u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x129a48: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x129a48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_129a4c:
    // 0x129a4c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x129a4cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129a50: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x129a50u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x129a54: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x129a54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x129a58: 0x3e00008  jr          $ra
    ctx->pc = 0x129A58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129A58u;
            // 0x129a5c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1299C8u: goto label_1299c8;
            case 0x1299D4u: goto label_1299d4;
            case 0x129A00u: goto label_129a00;
            case 0x129A04u: goto label_129a04;
            case 0x129A18u: goto label_129a18;
            case 0x129A2Cu: goto label_129a2c;
            case 0x129A40u: goto label_129a40;
            case 0x129A4Cu: goto label_129a4c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129A60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
