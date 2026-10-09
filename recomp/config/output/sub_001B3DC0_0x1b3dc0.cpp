#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B3DC0
// Address: 0x1b3dc0 - 0x1b3fa0
void sub_001B3DC0_0x1b3dc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B3DC0_0x1b3dc0");
#endif

    switch (ctx->pc) {
        case 0x1b3dd0u: goto label_1b3dd0;
        case 0x1b3ddcu: goto label_1b3ddc;
        case 0x1b3e50u: goto label_1b3e50;
        case 0x1b3e5cu: goto label_1b3e5c;
        case 0x1b3e6cu: goto label_1b3e6c;
        case 0x1b3e7cu: goto label_1b3e7c;
        case 0x1b3ed0u: goto label_1b3ed0;
        default: break;
    }

    ctx->pc = 0x1b3dc0u;

    // 0x1b3dc0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b3dc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b3dc4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b3dc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b3dc8: 0xc06d298  jal         func_1B4A60
    ctx->pc = 0x1B3DC8u;
    SET_GPR_U32(ctx, 31, 0x1B3DD0u);
    ctx->pc = 0x1B4A60u;
    if (runtime->hasFunction(0x1B4A60u)) {
        auto targetFn = runtime->lookupFunction(0x1B4A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3DD0u; }
        if (ctx->pc != 0x1B3DD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4A60_0x1b4a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3DD0u; }
        if (ctx->pc != 0x1B3DD0u) { return; }
    }
    ctx->pc = 0x1B3DD0u;
label_1b3dd0:
    // 0x1b3dd0: 0x3c04001b  lui         $a0, 0x1B
    ctx->pc = 0x1b3dd0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)27 << 16));
    // 0x1b3dd4: 0xc06be9c  jal         func_1AFA70
    ctx->pc = 0x1B3DD4u;
    SET_GPR_U32(ctx, 31, 0x1B3DDCu);
    ctx->pc = 0x1B3DD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3DD4u;
            // 0x1b3dd8: 0x24844500  addiu       $a0, $a0, 0x4500 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17664));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AFA70u;
    if (runtime->hasFunction(0x1AFA70u)) {
        auto targetFn = runtime->lookupFunction(0x1AFA70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3DDCu; }
        if (ctx->pc != 0x1B3DDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AFA70_0x1afa70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3DDCu; }
        if (ctx->pc != 0x1B3DDCu) { return; }
    }
    ctx->pc = 0x1B3DDCu;
label_1b3ddc:
    // 0x1b3ddc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b3ddcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b3de0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b3de0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b3de4: 0x902443ea  lbu         $a0, 0x43EA($at)
    ctx->pc = 0x1b3de4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17386)));
    // 0x1b3de8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b3de8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b3dec: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3DECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B3DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3DECu;
            // 0x1b3df0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B3DD0u: goto label_1b3dd0;
            case 0x1B3DDCu: goto label_1b3ddc;
            case 0x1B3E38u: goto label_1b3e38;
            case 0x1B3E50u: goto label_1b3e50;
            case 0x1B3E5Cu: goto label_1b3e5c;
            case 0x1B3E64u: goto label_1b3e64;
            case 0x1B3E6Cu: goto label_1b3e6c;
            case 0x1B3E7Cu: goto label_1b3e7c;
            case 0x1B3EA8u: goto label_1b3ea8;
            case 0x1B3ED0u: goto label_1b3ed0;
            case 0x1B3ED8u: goto label_1b3ed8;
            case 0x1B3F00u: goto label_1b3f00;
            case 0x1B3F1Cu: goto label_1b3f1c;
            case 0x1B3F24u: goto label_1b3f24;
            case 0x1B3F44u: goto label_1b3f44;
            case 0x1B3F70u: goto label_1b3f70;
            case 0x1B3F74u: goto label_1b3f74;
            case 0x1B3F78u: goto label_1b3f78;
            case 0x1B3F84u: goto label_1b3f84;
            case 0x1B3F88u: goto label_1b3f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B3DF4u;
    // 0x1b3df4: 0x0  nop
    ctx->pc = 0x1b3df4u;
    // NOP
    // 0x1b3df8: 0x0  nop
    ctx->pc = 0x1b3df8u;
    // NOP
    // 0x1b3dfc: 0x0  nop
    ctx->pc = 0x1b3dfcu;
    // NOP
    // 0x1b3e00: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b3e00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b3e04: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b3e04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b3e08: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b3e08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b3e0c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b3e0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b3e10: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b3e10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b3e14: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b3e14u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b3e18: 0x9023ae94  lbu         $v1, -0x516C($at)
    ctx->pc = 0x1b3e18u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946452)));
    // 0x1b3e1c: 0x14600059  bnez        $v1, . + 4 + (0x59 << 2)
    ctx->pc = 0x1B3E1Cu;
    {
        const bool branch_taken_0x1b3e1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B3E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3E1Cu;
            // 0x1b3e20: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3e1c) {
            ctx->pc = 0x1B3F84u;
            goto label_1b3f84;
        }
    }
    ctx->pc = 0x1B3E24u;
    // 0x1b3e24: 0x902243c0  lbu         $v0, 0x43C0($at)
    ctx->pc = 0x1b3e24u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17344)));
    // 0x1b3e28: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B3E28u;
    {
        const bool branch_taken_0x1b3e28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3E28u;
            // 0x1b3e2c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3e28) {
            ctx->pc = 0x1B3E38u;
            goto label_1b3e38;
        }
    }
    ctx->pc = 0x1B3E30u;
    // 0x1b3e30: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b3e30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b3e34: 0xa022ae8c  sb          $v0, -0x5174($at)
    ctx->pc = 0x1b3e34u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946444), (uint8_t)GPR_U32(ctx, 2));
label_1b3e38:
    // 0x1b3e38: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b3e38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b3e3c: 0x902243eb  lbu         $v0, 0x43EB($at)
    ctx->pc = 0x1b3e3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17387)));
    // 0x1b3e40: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B3E40u;
    {
        const bool branch_taken_0x1b3e40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B3E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3E40u;
            // 0x1b3e44: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3e40) {
            ctx->pc = 0x1B3E64u;
            goto label_1b3e64;
        }
    }
    ctx->pc = 0x1B3E48u;
    // 0x1b3e48: 0xc06d298  jal         func_1B4A60
    ctx->pc = 0x1B3E48u;
    SET_GPR_U32(ctx, 31, 0x1B3E50u);
    ctx->pc = 0x1B4A60u;
    if (runtime->hasFunction(0x1B4A60u)) {
        auto targetFn = runtime->lookupFunction(0x1B4A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3E50u; }
        if (ctx->pc != 0x1B3E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4A60_0x1b4a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3E50u; }
        if (ctx->pc != 0x1B3E50u) { return; }
    }
    ctx->pc = 0x1B3E50u;
label_1b3e50:
    // 0x1b3e50: 0x3c04001b  lui         $a0, 0x1B
    ctx->pc = 0x1b3e50u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)27 << 16));
    // 0x1b3e54: 0xc06be9c  jal         func_1AFA70
    ctx->pc = 0x1B3E54u;
    SET_GPR_U32(ctx, 31, 0x1B3E5Cu);
    ctx->pc = 0x1B3E58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3E54u;
            // 0x1b3e58: 0x24844500  addiu       $a0, $a0, 0x4500 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17664));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AFA70u;
    if (runtime->hasFunction(0x1AFA70u)) {
        auto targetFn = runtime->lookupFunction(0x1AFA70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3E5Cu; }
        if (ctx->pc != 0x1B3E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AFA70_0x1afa70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3E5Cu; }
        if (ctx->pc != 0x1B3E5Cu) { return; }
    }
    ctx->pc = 0x1B3E5Cu;
label_1b3e5c:
    // 0x1b3e5c: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x1B3E5Cu;
    {
        const bool branch_taken_0x1b3e5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3E5Cu;
            // 0x1b3e60: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3e5c) {
            ctx->pc = 0x1B3F88u;
            goto label_1b3f88;
        }
    }
    ctx->pc = 0x1B3E64u;
label_1b3e64:
    // 0x1b3e64: 0xc06a5d4  jal         func_1A9750
    ctx->pc = 0x1B3E64u;
    SET_GPR_U32(ctx, 31, 0x1B3E6Cu);
    ctx->pc = 0x1B3E68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3E64u;
            // 0x1b3e68: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9750u;
    if (runtime->hasFunction(0x1A9750u)) {
        auto targetFn = runtime->lookupFunction(0x1A9750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3E6Cu; }
        if (ctx->pc != 0x1B3E6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9750_0x1a9750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3E6Cu; }
        if (ctx->pc != 0x1B3E6Cu) { return; }
    }
    ctx->pc = 0x1B3E6Cu;
label_1b3e6c:
    // 0x1b3e6c: 0x3c120031  lui         $s2, 0x31
    ctx->pc = 0x1b3e6cu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)49 << 16));
    // 0x1b3e70: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1b3e70u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b3e74: 0x265251d0  addiu       $s2, $s2, 0x51D0
    ctx->pc = 0x1b3e74u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 20944));
    // 0x1b3e78: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b3e78u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b3e7c:
    // 0x1b3e7c: 0x86430000  lh          $v1, 0x0($s2)
    ctx->pc = 0x1b3e7cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1b3e80: 0x1060003c  beqz        $v1, . + 4 + (0x3C << 2)
    ctx->pc = 0x1B3E80u;
    {
        const bool branch_taken_0x1b3e80 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3e80) {
            ctx->pc = 0x1B3F74u;
            goto label_1b3f74;
        }
    }
    ctx->pc = 0x1B3E88u;
    // 0x1b3e88: 0x86430006  lh          $v1, 0x6($s2)
    ctx->pc = 0x1b3e88u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 6)));
    // 0x1b3e8c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1b3e8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1b3e90: 0xa6430006  sh          $v1, 0x6($s2)
    ctx->pc = 0x1b3e90u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 6), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b3e94: 0x86430006  lh          $v1, 0x6($s2)
    ctx->pc = 0x1b3e94u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 6)));
    // 0x1b3e98: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B3E98u;
    {
        const bool branch_taken_0x1b3e98 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b3e98) {
            ctx->pc = 0x1B3EA8u;
            goto label_1b3ea8;
        }
    }
    ctx->pc = 0x1B3EA0u;
    // 0x1b3ea0: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1B3EA0u;
    {
        const bool branch_taken_0x1b3ea0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3EA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3EA0u;
            // 0x1b3ea4: 0xa6400000  sh          $zero, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3ea0) {
            ctx->pc = 0x1B3F74u;
            goto label_1b3f74;
        }
    }
    ctx->pc = 0x1B3EA8u;
label_1b3ea8:
    // 0x1b3ea8: 0x1200000b  beqz        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x1B3EA8u;
    {
        const bool branch_taken_0x1b3ea8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3EACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3EA8u;
            // 0x1b3eac: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3ea8) {
            ctx->pc = 0x1B3ED8u;
            goto label_1b3ed8;
        }
    }
    ctx->pc = 0x1B3EB0u;
    // 0x1b3eb0: 0x902343c0  lbu         $v1, 0x43C0($at)
    ctx->pc = 0x1b3eb0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17344)));
    // 0x1b3eb4: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B3EB4u;
    {
        const bool branch_taken_0x1b3eb4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3eb4) {
            ctx->pc = 0x1B3ED8u;
            goto label_1b3ed8;
        }
    }
    ctx->pc = 0x1B3EBCu;
    // 0x1b3ebc: 0x9243000b  lbu         $v1, 0xB($s2)
    ctx->pc = 0x1b3ebcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 11)));
    // 0x1b3ec0: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B3EC0u;
    {
        const bool branch_taken_0x1b3ec0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b3ec0) {
            ctx->pc = 0x1B3ED8u;
            goto label_1b3ed8;
        }
    }
    ctx->pc = 0x1B3EC8u;
    // 0x1b3ec8: 0xc1b850c  jal         func_6E1430
    ctx->pc = 0x1B3EC8u;
    SET_GPR_U32(ctx, 31, 0x1B3ED0u);
    ctx->pc = 0x6E1430u;
    {
        auto targetFn = runtime->lookupFunction(0x6E1430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3ED0u; }
        if (ctx->pc != 0x1B3ED0u) { return; }
    }
    ctx->pc = 0x1B3ED0u;
label_1b3ed0:
    // 0x1b3ed0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b3ed0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b3ed4: 0xa020ae8c  sb          $zero, -0x5174($at)
    ctx->pc = 0x1b3ed4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946444), (uint8_t)GPR_U32(ctx, 0));
label_1b3ed8:
    // 0x1b3ed8: 0x82440009  lb          $a0, 0x9($s2)
    ctx->pc = 0x1b3ed8u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 9)));
    // 0x1b3edc: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1b3edcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b3ee0: 0x10830018  beq         $a0, $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1B3EE0u;
    {
        const bool branch_taken_0x1b3ee0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B3EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3EE0u;
            // 0x1b3ee4: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3ee0) {
            ctx->pc = 0x1B3F44u;
            goto label_1b3f44;
        }
    }
    ctx->pc = 0x1B3EE8u;
    // 0x1b3ee8: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B3EE8u;
    {
        const bool branch_taken_0x1b3ee8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b3ee8) {
            ctx->pc = 0x1B3F00u;
            goto label_1b3f00;
        }
    }
    ctx->pc = 0x1B3EF0u;
    // 0x1b3ef0: 0x10800020  beqz        $a0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1B3EF0u;
    {
        const bool branch_taken_0x1b3ef0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3ef0) {
            ctx->pc = 0x1B3F74u;
            goto label_1b3f74;
        }
    }
    ctx->pc = 0x1B3EF8u;
    // 0x1b3ef8: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1B3EF8u;
    {
        const bool branch_taken_0x1b3ef8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3EF8u;
            // 0x1b3efc: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3ef8) {
            ctx->pc = 0x1B3F78u;
            goto label_1b3f78;
        }
    }
    ctx->pc = 0x1B3F00u;
label_1b3f00:
    // 0x1b3f00: 0x9243000a  lbu         $v1, 0xA($s2)
    ctx->pc = 0x1b3f00u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 10)));
    // 0x1b3f04: 0x28610064  slti        $at, $v1, 0x64
    ctx->pc = 0x1b3f04u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)100) ? 1 : 0);
    // 0x1b3f08: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B3F08u;
    {
        const bool branch_taken_0x1b3f08 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3f08) {
            ctx->pc = 0x1B3F1Cu;
            goto label_1b3f1c;
        }
    }
    ctx->pc = 0x1B3F10u;
    // 0x1b3f10: 0x24630005  addiu       $v1, $v1, 0x5
    ctx->pc = 0x1b3f10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5));
    // 0x1b3f14: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1B3F14u;
    {
        const bool branch_taken_0x1b3f14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3F14u;
            // 0x1b3f18: 0xa243000a  sb          $v1, 0xA($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 10), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3f14) {
            ctx->pc = 0x1B3F24u;
            goto label_1b3f24;
        }
    }
    ctx->pc = 0x1B3F1Cu;
label_1b3f1c:
    // 0x1b3f1c: 0x24630003  addiu       $v1, $v1, 0x3
    ctx->pc = 0x1b3f1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x1b3f20: 0xa243000a  sb          $v1, 0xA($s2)
    ctx->pc = 0x1b3f20u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 10), (uint8_t)GPR_U32(ctx, 3));
label_1b3f24:
    // 0x1b3f24: 0x9243000a  lbu         $v1, 0xA($s2)
    ctx->pc = 0x1b3f24u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 10)));
    // 0x1b3f28: 0x28630080  slti        $v1, $v1, 0x80
    ctx->pc = 0x1b3f28u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)128) ? 1 : 0);
    // 0x1b3f2c: 0x14600011  bnez        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1B3F2Cu;
    {
        const bool branch_taken_0x1b3f2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B3F30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3F2Cu;
            // 0x1b3f30: 0x24040080  addiu       $a0, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3f2c) {
            ctx->pc = 0x1B3F74u;
            goto label_1b3f74;
        }
    }
    ctx->pc = 0x1B3F34u;
    // 0x1b3f34: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1b3f34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b3f38: 0xa244000a  sb          $a0, 0xA($s2)
    ctx->pc = 0x1b3f38u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 10), (uint8_t)GPR_U32(ctx, 4));
    // 0x1b3f3c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1B3F3Cu;
    {
        const bool branch_taken_0x1b3f3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3F3Cu;
            // 0x1b3f40: 0xa2430009  sb          $v1, 0x9($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 9), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3f3c) {
            ctx->pc = 0x1B3F74u;
            goto label_1b3f74;
        }
    }
    ctx->pc = 0x1B3F44u;
label_1b3f44:
    // 0x1b3f44: 0x86430006  lh          $v1, 0x6($s2)
    ctx->pc = 0x1b3f44u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 6)));
    // 0x1b3f48: 0x2861001f  slti        $at, $v1, 0x1F
    ctx->pc = 0x1b3f48u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1b3f4c: 0x10200009  beqz        $at, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B3F4Cu;
    {
        const bool branch_taken_0x1b3f4c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3f4c) {
            ctx->pc = 0x1B3F74u;
            goto label_1b3f74;
        }
    }
    ctx->pc = 0x1B3F54u;
    // 0x1b3f54: 0x9243000a  lbu         $v1, 0xA($s2)
    ctx->pc = 0x1b3f54u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 10)));
    // 0x1b3f58: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B3F58u;
    {
        const bool branch_taken_0x1b3f58 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b3f58) {
            ctx->pc = 0x1B3F74u;
            goto label_1b3f74;
        }
    }
    ctx->pc = 0x1B3F60u;
    // 0x1b3f60: 0x2463fffc  addiu       $v1, $v1, -0x4
    ctx->pc = 0x1b3f60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
    // 0x1b3f64: 0x4610002  bgez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B3F64u;
    {
        const bool branch_taken_0x1b3f64 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x1b3f64) {
            ctx->pc = 0x1B3F70u;
            goto label_1b3f70;
        }
    }
    ctx->pc = 0x1B3F6Cu;
    // 0x1b3f6c: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x1b3f6cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b3f70:
    // 0x1b3f70: 0xa243000a  sb          $v1, 0xA($s2)
    ctx->pc = 0x1b3f70u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 10), (uint8_t)GPR_U32(ctx, 3));
label_1b3f74:
    // 0x1b3f74: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b3f74u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1b3f78:
    // 0x1b3f78: 0x2a230020  slti        $v1, $s1, 0x20
    ctx->pc = 0x1b3f78u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1b3f7c: 0x1460ffbf  bnez        $v1, . + 4 + (-0x41 << 2)
    ctx->pc = 0x1B3F7Cu;
    {
        const bool branch_taken_0x1b3f7c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B3F80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3F7Cu;
            // 0x1b3f80: 0x2652008c  addiu       $s2, $s2, 0x8C (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 140));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3f7c) {
            ctx->pc = 0x1B3E7Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b3e7c;
        }
    }
    ctx->pc = 0x1B3F84u;
label_1b3f84:
    // 0x1b3f84: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b3f84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1b3f88:
    // 0x1b3f88: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b3f88u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b3f8c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b3f8cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b3f90: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b3f90u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b3f94: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3F94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B3F98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3F94u;
            // 0x1b3f98: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B3DD0u: goto label_1b3dd0;
            case 0x1B3DDCu: goto label_1b3ddc;
            case 0x1B3E38u: goto label_1b3e38;
            case 0x1B3E50u: goto label_1b3e50;
            case 0x1B3E5Cu: goto label_1b3e5c;
            case 0x1B3E64u: goto label_1b3e64;
            case 0x1B3E6Cu: goto label_1b3e6c;
            case 0x1B3E7Cu: goto label_1b3e7c;
            case 0x1B3EA8u: goto label_1b3ea8;
            case 0x1B3ED0u: goto label_1b3ed0;
            case 0x1B3ED8u: goto label_1b3ed8;
            case 0x1B3F00u: goto label_1b3f00;
            case 0x1B3F1Cu: goto label_1b3f1c;
            case 0x1B3F24u: goto label_1b3f24;
            case 0x1B3F44u: goto label_1b3f44;
            case 0x1B3F70u: goto label_1b3f70;
            case 0x1B3F74u: goto label_1b3f74;
            case 0x1B3F78u: goto label_1b3f78;
            case 0x1B3F84u: goto label_1b3f84;
            case 0x1B3F88u: goto label_1b3f88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B3F9Cu;
    // 0x1b3f9c: 0x0  nop
    ctx->pc = 0x1b3f9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
