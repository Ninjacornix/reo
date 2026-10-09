#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3E90
// Address: 0x1f3e90 - 0x1f42c0
void sub_001F3E90_0x1f3e90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3E90_0x1f3e90");
#endif

    switch (ctx->pc) {
        case 0x1f3ec8u: goto label_1f3ec8;
        case 0x1f3ee4u: goto label_1f3ee4;
        case 0x1f3ef4u: goto label_1f3ef4;
        case 0x1f3f48u: goto label_1f3f48;
        case 0x1f3f88u: goto label_1f3f88;
        case 0x1f3ff0u: goto label_1f3ff0;
        case 0x1f4024u: goto label_1f4024;
        case 0x1f4084u: goto label_1f4084;
        case 0x1f410cu: goto label_1f410c;
        case 0x1f416cu: goto label_1f416c;
        case 0x1f41f4u: goto label_1f41f4;
        case 0x1f425cu: goto label_1f425c;
        case 0x1f4274u: goto label_1f4274;
        case 0x1f42acu: goto label_1f42ac;
        default: break;
    }

    ctx->pc = 0x1f3e90u;

    // 0x1f3e90: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f3e90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f3e94: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1f3e94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1f3e98: 0xffbe0018  sd          $fp, 0x18($sp)
    ctx->pc = 0x1f3e98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 30));
    // 0x1f3e9c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1f3e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1f3ea0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f3ea0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3ea4: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f3ea4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f3ea8: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f3ea8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f3eac: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x1f3eacu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3eb0: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f3eb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3eb4: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1f3eb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1f3eb8: 0xafc30004  sw          $v1, 0x4($fp)
    ctx->pc = 0x1f3eb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 3));
    // 0x1f3ebc: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3ebcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3ec0: 0xc07cd3b  jal         func_1F34EC
    ctx->pc = 0x1F3EC0u;
    SET_GPR_U32(ctx, 31, 0x1F3EC8u);
    ctx->pc = 0x1F34ECu;
    if (runtime->hasFunction(0x1F34ECu)) {
        auto targetFn = runtime->lookupFunction(0x1F34ECu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3EC8u; }
        if (ctx->pc != 0x1F3EC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F34EC_0x1f34ec(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3EC8u; }
        if (ctx->pc != 0x1F3EC8u) { return; }
    }
    ctx->pc = 0x1F3EC8u;
label_1f3ec8:
    // 0x1f3ec8: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f3ec8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3ecc: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1f3eccu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1f3ed0: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1F3ED0u;
    {
        const bool branch_taken_0x1f3ed0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f3ed0) {
            ctx->pc = 0x1F3F10u;
            goto label_1f3f10;
        }
    }
    ctx->pc = 0x1F3ED8u;
    // 0x1f3ed8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3ed8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3edc: 0xc07cd3b  jal         func_1F34EC
    ctx->pc = 0x1F3EDCu;
    SET_GPR_U32(ctx, 31, 0x1F3EE4u);
    ctx->pc = 0x1F34ECu;
    if (runtime->hasFunction(0x1F34ECu)) {
        auto targetFn = runtime->lookupFunction(0x1F34ECu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3EE4u; }
        if (ctx->pc != 0x1F3EE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F34EC_0x1f34ec(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3EE4u; }
        if (ctx->pc != 0x1F3EE4u) { return; }
    }
    ctx->pc = 0x1F3EE4u;
label_1f3ee4:
    // 0x1f3ee4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1f3ee4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3ee8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3ee8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3eec: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1F3EECu;
    SET_GPR_U32(ctx, 31, 0x1F3EF4u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3EF4u; }
        if (ctx->pc != 0x1F3EF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3EF4u; }
        if (ctx->pc != 0x1F3EF4u) { return; }
    }
    ctx->pc = 0x1F3EF4u;
label_1f3ef4:
    // 0x1f3ef4: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1f3ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1f3ef8: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f3ef8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3efc: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1f3efcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1f3f00: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F3F00u;
    {
        const bool branch_taken_0x1f3f00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3f00) {
            ctx->pc = 0x1F3F10u;
            goto label_1f3f10;
        }
    }
    ctx->pc = 0x1F3F08u;
    // 0x1f3f08: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1F3F08u;
    {
        const bool branch_taken_0x1f3f08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3f08) {
            ctx->pc = 0x1F3F1Cu;
            goto label_1f3f1c;
        }
    }
    ctx->pc = 0x1F3F10u;
label_1f3f10:
    // 0x1f3f10: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f3f10u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3f14: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F3F14u;
    {
        const bool branch_taken_0x1f3f14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3f14) {
            ctx->pc = 0x1F3F20u;
            goto label_1f3f20;
        }
    }
    ctx->pc = 0x1F3F1Cu;
label_1f3f1c:
    // 0x1f3f1c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f3f1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
label_1f3f20:
    // 0x1f3f20: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3f20u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3f24: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1f3f24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f3f28: 0xdfbe0018  ld          $fp, 0x18($sp)
    ctx->pc = 0x1f3f28u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f3f2c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1f3f2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f3f30: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f3f30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f3f34: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3F34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3EC8u: goto label_1f3ec8;
            case 0x1F3EE4u: goto label_1f3ee4;
            case 0x1F3EF4u: goto label_1f3ef4;
            case 0x1F3F10u: goto label_1f3f10;
            case 0x1F3F1Cu: goto label_1f3f1c;
            case 0x1F3F20u: goto label_1f3f20;
            case 0x1F3F48u: goto label_1f3f48;
            case 0x1F3F5Cu: goto label_1f3f5c;
            case 0x1F3F64u: goto label_1f3f64;
            case 0x1F3F68u: goto label_1f3f68;
            case 0x1F3F78u: goto label_1f3f78;
            case 0x1F3F88u: goto label_1f3f88;
            case 0x1F3FA0u: goto label_1f3fa0;
            case 0x1F3FA4u: goto label_1f3fa4;
            case 0x1F3FF0u: goto label_1f3ff0;
            case 0x1F4024u: goto label_1f4024;
            case 0x1F4084u: goto label_1f4084;
            case 0x1F40B8u: goto label_1f40b8;
            case 0x1F410Cu: goto label_1f410c;
            case 0x1F416Cu: goto label_1f416c;
            case 0x1F41A0u: goto label_1f41a0;
            case 0x1F41F4u: goto label_1f41f4;
            case 0x1F425Cu: goto label_1f425c;
            case 0x1F4274u: goto label_1f4274;
            case 0x1F42ACu: goto label_1f42ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3F3Cu;
    // 0x1f3f3c: 0x0  nop
    ctx->pc = 0x1f3f3cu;
    // NOP
    // 0x1f3f40: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1F3F40u;
    {
        const bool branch_taken_0x1f3f40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F3F44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3F40u;
            // 0x1f3f44: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f3f40) {
            ctx->pc = 0x1F3F68u;
            goto label_1f3f68;
        }
    }
    ctx->pc = 0x1F3F48u;
label_1f3f48:
    // 0x1f3f48: 0x80420e0d  lb          $v0, 0xE0D($v0)
    ctx->pc = 0x1f3f48u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 3597)));
    // 0x1f3f4c: 0x4400003  bltz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F3F4Cu;
    {
        const bool branch_taken_0x1f3f4c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1F3F50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3F4Cu;
            // 0x1f3f50: 0x28410003  slti        $at, $v0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f3f4c) {
            ctx->pc = 0x1F3F5Cu;
            goto label_1f3f5c;
        }
    }
    ctx->pc = 0x1F3F54u;
    // 0x1f3f54: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F3F54u;
    {
        const bool branch_taken_0x1f3f54 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f3f54) {
            ctx->pc = 0x1F3F64u;
            goto label_1f3f64;
        }
    }
    ctx->pc = 0x1F3F5Cu;
label_1f3f5c:
    // 0x1f3f5c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1F3F5Cu;
    {
        const bool branch_taken_0x1f3f5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F3F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3F5Cu;
            // 0x1f3f60: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f3f5c) {
            ctx->pc = 0x1F3F78u;
            goto label_1f3f78;
        }
    }
    ctx->pc = 0x1F3F64u;
label_1f3f64:
    // 0x1f3f64: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1f3f64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
label_1f3f68:
    // 0x1f3f68: 0x28620010  slti        $v0, $v1, 0x10
    ctx->pc = 0x1f3f68u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1f3f6c: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1F3F6Cu;
    {
        const bool branch_taken_0x1f3f6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F3F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3F6Cu;
            // 0x1f3f70: 0x831021  addu        $v0, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f3f6c) {
            ctx->pc = 0x1F3F48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f3f48;
        }
    }
    ctx->pc = 0x1F3F74u;
    // 0x1f3f74: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f3f74u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f3f78:
    // 0x1f3f78: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3F78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3EC8u: goto label_1f3ec8;
            case 0x1F3EE4u: goto label_1f3ee4;
            case 0x1F3EF4u: goto label_1f3ef4;
            case 0x1F3F10u: goto label_1f3f10;
            case 0x1F3F1Cu: goto label_1f3f1c;
            case 0x1F3F20u: goto label_1f3f20;
            case 0x1F3F48u: goto label_1f3f48;
            case 0x1F3F5Cu: goto label_1f3f5c;
            case 0x1F3F64u: goto label_1f3f64;
            case 0x1F3F68u: goto label_1f3f68;
            case 0x1F3F78u: goto label_1f3f78;
            case 0x1F3F88u: goto label_1f3f88;
            case 0x1F3FA0u: goto label_1f3fa0;
            case 0x1F3FA4u: goto label_1f3fa4;
            case 0x1F3FF0u: goto label_1f3ff0;
            case 0x1F4024u: goto label_1f4024;
            case 0x1F4084u: goto label_1f4084;
            case 0x1F40B8u: goto label_1f40b8;
            case 0x1F410Cu: goto label_1f410c;
            case 0x1F416Cu: goto label_1f416c;
            case 0x1F41A0u: goto label_1f41a0;
            case 0x1F41F4u: goto label_1f41f4;
            case 0x1F425Cu: goto label_1f425c;
            case 0x1F4274u: goto label_1f4274;
            case 0x1F42ACu: goto label_1f42ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3F80u;
    // 0x1f3f80: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1f3f80u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3f84: 0x861821  addu        $v1, $a0, $a2
    ctx->pc = 0x1f3f84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
label_1f3f88:
    // 0x1f3f88: 0x24650e0d  addiu       $a1, $v1, 0xE0D
    ctx->pc = 0x1f3f88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 3597));
    // 0x1f3f8c: 0x80630e0d  lb          $v1, 0xE0D($v1)
    ctx->pc = 0x1f3f8cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 3597)));
    // 0x1f3f90: 0x4600003  bltz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F3F90u;
    {
        const bool branch_taken_0x1f3f90 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1F3F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3F90u;
            // 0x1f3f94: 0x28610003  slti        $at, $v1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f3f90) {
            ctx->pc = 0x1F3FA0u;
            goto label_1f3fa0;
        }
    }
    ctx->pc = 0x1F3F98u;
    // 0x1f3f98: 0x14200002  bnez        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1F3F98u;
    {
        const bool branch_taken_0x1f3f98 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f3f98) {
            ctx->pc = 0x1F3FA4u;
            goto label_1f3fa4;
        }
    }
    ctx->pc = 0x1F3FA0u;
label_1f3fa0:
    // 0x1f3fa0: 0xa0a00000  sb          $zero, 0x0($a1)
    ctx->pc = 0x1f3fa0u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 0));
label_1f3fa4:
    // 0x1f3fa4: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1f3fa4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1f3fa8: 0x28c30010  slti        $v1, $a2, 0x10
    ctx->pc = 0x1f3fa8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1f3fac: 0x1460fff6  bnez        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1F3FACu;
    {
        const bool branch_taken_0x1f3fac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F3FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3FACu;
            // 0x1f3fb0: 0x861821  addu        $v1, $a0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f3fac) {
            ctx->pc = 0x1F3F88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f3f88;
        }
    }
    ctx->pc = 0x1F3FB4u;
    // 0x1f3fb4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3FB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3EC8u: goto label_1f3ec8;
            case 0x1F3EE4u: goto label_1f3ee4;
            case 0x1F3EF4u: goto label_1f3ef4;
            case 0x1F3F10u: goto label_1f3f10;
            case 0x1F3F1Cu: goto label_1f3f1c;
            case 0x1F3F20u: goto label_1f3f20;
            case 0x1F3F48u: goto label_1f3f48;
            case 0x1F3F5Cu: goto label_1f3f5c;
            case 0x1F3F64u: goto label_1f3f64;
            case 0x1F3F68u: goto label_1f3f68;
            case 0x1F3F78u: goto label_1f3f78;
            case 0x1F3F88u: goto label_1f3f88;
            case 0x1F3FA0u: goto label_1f3fa0;
            case 0x1F3FA4u: goto label_1f3fa4;
            case 0x1F3FF0u: goto label_1f3ff0;
            case 0x1F4024u: goto label_1f4024;
            case 0x1F4084u: goto label_1f4084;
            case 0x1F40B8u: goto label_1f40b8;
            case 0x1F410Cu: goto label_1f410c;
            case 0x1F416Cu: goto label_1f416c;
            case 0x1F41A0u: goto label_1f41a0;
            case 0x1F41F4u: goto label_1f41f4;
            case 0x1F425Cu: goto label_1f425c;
            case 0x1F4274u: goto label_1f4274;
            case 0x1F42ACu: goto label_1f42ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3FBCu;
    // 0x1f3fbc: 0x0  nop
    ctx->pc = 0x1f3fbcu;
    // NOP
    // 0x1f3fc0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f3fc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f3fc4: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f3fc4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f3fc8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1f3fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1f3fcc: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f3fccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f3fd0: 0xac2057c0  sw          $zero, 0x57C0($at)
    ctx->pc = 0x1f3fd0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 22464), GPR_U32(ctx, 0));
    // 0x1f3fd4: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f3fd4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f3fd8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f3fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f3fdc: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f3fdcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f3fe0: 0x2484ead0  addiu       $a0, $a0, -0x1530
    ctx->pc = 0x1f3fe0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961872));
    // 0x1f3fe4: 0xac22eaf0  sw          $v0, -0x1510($at)
    ctx->pc = 0x1f3fe4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961904), GPR_U32(ctx, 2));
    // 0x1f3fe8: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1F3FE8u;
    SET_GPR_U32(ctx, 31, 0x1F3FF0u);
    ctx->pc = 0x1F3FECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3FE8u;
            // 0x1f3fec: 0x24a59b20  addiu       $a1, $a1, -0x64E0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941472));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3FF0u; }
        if (ctx->pc != 0x1F3FF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3FF0u; }
        if (ctx->pc != 0x1F3FF0u) { return; }
    }
    ctx->pc = 0x1F3FF0u;
label_1f3ff0:
    // 0x1f3ff0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f3ff0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f3ff4: 0x3c020036  lui         $v0, 0x36
    ctx->pc = 0x1f3ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)54 << 16));
    // 0x1f3ff8: 0xac20ec70  sw          $zero, -0x1390($at)
    ctx->pc = 0x1f3ff8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962288), GPR_U32(ctx, 0));
    // 0x1f3ffc: 0x2442ead0  addiu       $v0, $v0, -0x1530
    ctx->pc = 0x1f3ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294961872));
    // 0x1f4000: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f4000u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f4004: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1f4004u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4008: 0xac2257c8  sw          $v0, 0x57C8($at)
    ctx->pc = 0x1f4008u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 22472), GPR_U32(ctx, 2));
    // 0x1f400c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f400cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4010: 0xac20ec40  sw          $zero, -0x13C0($at)
    ctx->pc = 0x1f4010u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962240), GPR_U32(ctx, 0));
    // 0x1f4014: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x1f4014u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x1f4018: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f4018u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f401c: 0x24c67310  addiu       $a2, $a2, 0x7310
    ctx->pc = 0x1f401cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 29456));
    // 0x1f4020: 0x2484ec50  addiu       $a0, $a0, -0x13B0
    ctx->pc = 0x1f4020u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962256));
label_1f4024:
    // 0x1f4024: 0x71e3c  dsll32      $v1, $a3, 24
    ctx->pc = 0x1f4024u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 24));
    // 0x1f4028: 0x24e20001  addiu       $v0, $a3, 0x1
    ctx->pc = 0x1f4028u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1f402c: 0x31e3f  dsra32      $v1, $v1, 24
    ctx->pc = 0x1f402cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 24));
    // 0x1f4030: 0x23e3c  dsll32      $a3, $v0, 24
    ctx->pc = 0x1f4030u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 24));
    // 0x1f4034: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1f4034u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1f4038: 0x73e3f  dsra32      $a3, $a3, 24
    ctx->pc = 0x1f4038u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 24));
    // 0x1f403c: 0xc31021  addu        $v0, $a2, $v1
    ctx->pc = 0x1f403cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1f4040: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1f4040u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f4044: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1f4044u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1f4048: 0x28e20005  slti        $v0, $a3, 0x5
    ctx->pc = 0x1f4048u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)5) ? 1 : 0);
    // 0x1f404c: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1F404Cu;
    {
        const bool branch_taken_0x1f404c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F4050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F404Cu;
            // 0x1f4050: 0xac650000  sw          $a1, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f404c) {
            ctx->pc = 0x1F4024u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f4024;
        }
    }
    ctx->pc = 0x1F4054u;
    // 0x1f4054: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4054u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4058: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f4058u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f405c: 0xa020ebd4  sb          $zero, -0x142C($at)
    ctx->pc = 0x1f405cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294962132), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f4060: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1f4060u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1f4064: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4064u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4068: 0x2484eb00  addiu       $a0, $a0, -0x1500
    ctx->pc = 0x1f4068u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961920));
    // 0x1f406c: 0xa422ebb0  sh          $v0, -0x1450($at)
    ctx->pc = 0x1f406cu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294962096), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f4070: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f4070u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4074: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4074u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4078: 0x24060094  addiu       $a2, $zero, 0x94
    ctx->pc = 0x1f4078u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 148));
    // 0x1f407c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F407Cu;
    SET_GPR_U32(ctx, 31, 0x1F4084u);
    ctx->pc = 0x1F4080u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F407Cu;
            // 0x1f4080: 0xac20ebd8  sw          $zero, -0x1428($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294962136), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4084u; }
        if (ctx->pc != 0x1F4084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4084u; }
        if (ctx->pc != 0x1F4084u) { return; }
    }
    ctx->pc = 0x1F4084u;
label_1f4084:
    // 0x1f4084: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1f4084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1f4088: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4088u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f408c: 0xac22eb14  sw          $v0, -0x14EC($at)
    ctx->pc = 0x1f408cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961940), GPR_U32(ctx, 2));
    // 0x1f4090: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4090u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4094: 0x8c22eb14  lw          $v0, -0x14EC($at)
    ctx->pc = 0x1f4094u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961940)));
    // 0x1f4098: 0x3c010001  lui         $at, 0x1
    ctx->pc = 0x1f4098u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1f409c: 0x41082a  slt         $at, $v0, $at
    ctx->pc = 0x1f409cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1f40a0: 0x14200005  bnez        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F40A0u;
    {
        const bool branch_taken_0x1f40a0 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F40A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F40A0u;
            // 0x1f40a4: 0x24020300  addiu       $v0, $zero, 0x300 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f40a0) {
            ctx->pc = 0x1F40B8u;
            goto label_1f40b8;
        }
    }
    ctx->pc = 0x1F40A8u;
    // 0x1f40a8: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1f40a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1f40ac: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40b0: 0xac22eb14  sw          $v0, -0x14EC($at)
    ctx->pc = 0x1f40b0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961940), GPR_U32(ctx, 2));
    // 0x1f40b4: 0x24020300  addiu       $v0, $zero, 0x300
    ctx->pc = 0x1f40b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
label_1f40b8:
    // 0x1f40b8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40bc: 0xac22eb18  sw          $v0, -0x14E8($at)
    ctx->pc = 0x1f40bcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961944), GPR_U32(ctx, 2));
    // 0x1f40c0: 0x3c030036  lui         $v1, 0x36
    ctx->pc = 0x1f40c0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)54 << 16));
    // 0x1f40c4: 0x2463efa0  addiu       $v1, $v1, -0x1060
    ctx->pc = 0x1f40c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963104));
    // 0x1f40c8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40cc: 0x3c020036  lui         $v0, 0x36
    ctx->pc = 0x1f40ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)54 << 16));
    // 0x1f40d0: 0xac23eb1c  sw          $v1, -0x14E4($at)
    ctx->pc = 0x1f40d0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961948), GPR_U32(ctx, 3));
    // 0x1f40d4: 0x2442ec90  addiu       $v0, $v0, -0x1370
    ctx->pc = 0x1f40d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962320));
    // 0x1f40d8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40dc: 0xac22eb24  sw          $v0, -0x14DC($at)
    ctx->pc = 0x1f40dcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961956), GPR_U32(ctx, 2));
    // 0x1f40e0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40e4: 0x8c23eb1c  lw          $v1, -0x14E4($at)
    ctx->pc = 0x1f40e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961948)));
    // 0x1f40e8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40ec: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1f40ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1f40f0: 0x8c22eb24  lw          $v0, -0x14DC($at)
    ctx->pc = 0x1f40f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961956)));
    // 0x1f40f4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f40f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f40f8: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1f40f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1f40fc: 0xac23eb20  sw          $v1, -0x14E0($at)
    ctx->pc = 0x1f40fcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961952), GPR_U32(ctx, 3));
    // 0x1f4100: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4100u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4104: 0xc042652  jal         func_109948
    ctx->pc = 0x1F4104u;
    SET_GPR_U32(ctx, 31, 0x1F410Cu);
    ctx->pc = 0x1F4108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4104u;
            // 0x1f4108: 0xac22eb28  sw          $v0, -0x14D8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294961960), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x109948u;
    if (runtime->hasFunction(0x109948u)) {
        auto targetFn = runtime->lookupFunction(0x109948u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F410Cu; }
        if (ctx->pc != 0x1F410Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00109948_0x109948(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F410Cu; }
        if (ctx->pc != 0x1F410Cu) { return; }
    }
    ctx->pc = 0x1F410Cu;
label_1f410c:
    // 0x1f410c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f410cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4110: 0xa022eb31  sb          $v0, -0x14CF($at)
    ctx->pc = 0x1f4110u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294961969), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f4114: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f4114u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f4118: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4118u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f411c: 0xa022eb38  sb          $v0, -0x14C8($at)
    ctx->pc = 0x1f411cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294961976), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f4120: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4120u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4124: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f4124u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4128: 0xac20eb90  sw          $zero, -0x1470($at)
    ctx->pc = 0x1f4128u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962064), GPR_U32(ctx, 0));
    // 0x1f412c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1f412cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f4130: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4130u;
            // 0x1f4134: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3EC8u: goto label_1f3ec8;
            case 0x1F3EE4u: goto label_1f3ee4;
            case 0x1F3EF4u: goto label_1f3ef4;
            case 0x1F3F10u: goto label_1f3f10;
            case 0x1F3F1Cu: goto label_1f3f1c;
            case 0x1F3F20u: goto label_1f3f20;
            case 0x1F3F48u: goto label_1f3f48;
            case 0x1F3F5Cu: goto label_1f3f5c;
            case 0x1F3F64u: goto label_1f3f64;
            case 0x1F3F68u: goto label_1f3f68;
            case 0x1F3F78u: goto label_1f3f78;
            case 0x1F3F88u: goto label_1f3f88;
            case 0x1F3FA0u: goto label_1f3fa0;
            case 0x1F3FA4u: goto label_1f3fa4;
            case 0x1F3FF0u: goto label_1f3ff0;
            case 0x1F4024u: goto label_1f4024;
            case 0x1F4084u: goto label_1f4084;
            case 0x1F40B8u: goto label_1f40b8;
            case 0x1F410Cu: goto label_1f410c;
            case 0x1F416Cu: goto label_1f416c;
            case 0x1F41A0u: goto label_1f41a0;
            case 0x1F41F4u: goto label_1f41f4;
            case 0x1F425Cu: goto label_1f425c;
            case 0x1F4274u: goto label_1f4274;
            case 0x1F42ACu: goto label_1f42ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F4138u;
    // 0x1f4138: 0x0  nop
    ctx->pc = 0x1f4138u;
    // NOP
    // 0x1f413c: 0x0  nop
    ctx->pc = 0x1f413cu;
    // NOP
    // 0x1f4140: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f4140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f4144: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f4144u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f4148: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1f4148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1f414c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f414cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4150: 0xac20eaf0  sw          $zero, -0x1510($at)
    ctx->pc = 0x1f4150u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961904), GPR_U32(ctx, 0));
    // 0x1f4154: 0x2484eb00  addiu       $a0, $a0, -0x1500
    ctx->pc = 0x1f4154u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961920));
    // 0x1f4158: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4158u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f415c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f415cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4160: 0x24060094  addiu       $a2, $zero, 0x94
    ctx->pc = 0x1f4160u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 148));
    // 0x1f4164: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F4164u;
    SET_GPR_U32(ctx, 31, 0x1F416Cu);
    ctx->pc = 0x1F4168u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4164u;
            // 0x1f4168: 0xac20ec70  sw          $zero, -0x1390($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294962288), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F416Cu; }
        if (ctx->pc != 0x1F416Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F416Cu; }
        if (ctx->pc != 0x1F416Cu) { return; }
    }
    ctx->pc = 0x1F416Cu;
label_1f416c:
    // 0x1f416c: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1f416cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1f4170: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4170u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4174: 0xac22eb14  sw          $v0, -0x14EC($at)
    ctx->pc = 0x1f4174u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961940), GPR_U32(ctx, 2));
    // 0x1f4178: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4178u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f417c: 0x8c22eb14  lw          $v0, -0x14EC($at)
    ctx->pc = 0x1f417cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961940)));
    // 0x1f4180: 0x3c010001  lui         $at, 0x1
    ctx->pc = 0x1f4180u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)1 << 16));
    // 0x1f4184: 0x41082a  slt         $at, $v0, $at
    ctx->pc = 0x1f4184u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1f4188: 0x14200005  bnez        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F4188u;
    {
        const bool branch_taken_0x1f4188 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F418Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4188u;
            // 0x1f418c: 0x24020300  addiu       $v0, $zero, 0x300 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4188) {
            ctx->pc = 0x1F41A0u;
            goto label_1f41a0;
        }
    }
    ctx->pc = 0x1F4190u;
    // 0x1f4190: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1f4190u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1f4194: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4194u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4198: 0xac22eb14  sw          $v0, -0x14EC($at)
    ctx->pc = 0x1f4198u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961940), GPR_U32(ctx, 2));
    // 0x1f419c: 0x24020300  addiu       $v0, $zero, 0x300
    ctx->pc = 0x1f419cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
label_1f41a0:
    // 0x1f41a0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41a4: 0xac22eb18  sw          $v0, -0x14E8($at)
    ctx->pc = 0x1f41a4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961944), GPR_U32(ctx, 2));
    // 0x1f41a8: 0x3c030036  lui         $v1, 0x36
    ctx->pc = 0x1f41a8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)54 << 16));
    // 0x1f41ac: 0x2463efa0  addiu       $v1, $v1, -0x1060
    ctx->pc = 0x1f41acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963104));
    // 0x1f41b0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41b4: 0x3c020036  lui         $v0, 0x36
    ctx->pc = 0x1f41b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)54 << 16));
    // 0x1f41b8: 0xac23eb1c  sw          $v1, -0x14E4($at)
    ctx->pc = 0x1f41b8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961948), GPR_U32(ctx, 3));
    // 0x1f41bc: 0x2442ec90  addiu       $v0, $v0, -0x1370
    ctx->pc = 0x1f41bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962320));
    // 0x1f41c0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41c4: 0xac22eb24  sw          $v0, -0x14DC($at)
    ctx->pc = 0x1f41c4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961956), GPR_U32(ctx, 2));
    // 0x1f41c8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41cc: 0x8c23eb1c  lw          $v1, -0x14E4($at)
    ctx->pc = 0x1f41ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961948)));
    // 0x1f41d0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41d4: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1f41d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1f41d8: 0x8c22eb24  lw          $v0, -0x14DC($at)
    ctx->pc = 0x1f41d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961956)));
    // 0x1f41dc: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41e0: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1f41e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1f41e4: 0xac23eb20  sw          $v1, -0x14E0($at)
    ctx->pc = 0x1f41e4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961952), GPR_U32(ctx, 3));
    // 0x1f41e8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41ec: 0xc042652  jal         func_109948
    ctx->pc = 0x1F41ECu;
    SET_GPR_U32(ctx, 31, 0x1F41F4u);
    ctx->pc = 0x1F41F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F41ECu;
            // 0x1f41f0: 0xac22eb28  sw          $v0, -0x14D8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294961960), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x109948u;
    if (runtime->hasFunction(0x109948u)) {
        auto targetFn = runtime->lookupFunction(0x109948u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F41F4u; }
        if (ctx->pc != 0x1F41F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00109948_0x109948(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F41F4u; }
        if (ctx->pc != 0x1F41F4u) { return; }
    }
    ctx->pc = 0x1F41F4u;
label_1f41f4:
    // 0x1f41f4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f41f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f41f8: 0xa022eb31  sb          $v0, -0x14CF($at)
    ctx->pc = 0x1f41f8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294961969), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f41fc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f41fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f4200: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f4200u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4204: 0xa022eb38  sb          $v0, -0x14C8($at)
    ctx->pc = 0x1f4204u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294961976), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f4208: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1f4208u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f420c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f420cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4210: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4210u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4210u;
            // 0x1f4214: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3EC8u: goto label_1f3ec8;
            case 0x1F3EE4u: goto label_1f3ee4;
            case 0x1F3EF4u: goto label_1f3ef4;
            case 0x1F3F10u: goto label_1f3f10;
            case 0x1F3F1Cu: goto label_1f3f1c;
            case 0x1F3F20u: goto label_1f3f20;
            case 0x1F3F48u: goto label_1f3f48;
            case 0x1F3F5Cu: goto label_1f3f5c;
            case 0x1F3F64u: goto label_1f3f64;
            case 0x1F3F68u: goto label_1f3f68;
            case 0x1F3F78u: goto label_1f3f78;
            case 0x1F3F88u: goto label_1f3f88;
            case 0x1F3FA0u: goto label_1f3fa0;
            case 0x1F3FA4u: goto label_1f3fa4;
            case 0x1F3FF0u: goto label_1f3ff0;
            case 0x1F4024u: goto label_1f4024;
            case 0x1F4084u: goto label_1f4084;
            case 0x1F40B8u: goto label_1f40b8;
            case 0x1F410Cu: goto label_1f410c;
            case 0x1F416Cu: goto label_1f416c;
            case 0x1F41A0u: goto label_1f41a0;
            case 0x1F41F4u: goto label_1f41f4;
            case 0x1F425Cu: goto label_1f425c;
            case 0x1F4274u: goto label_1f4274;
            case 0x1F42ACu: goto label_1f42ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F4218u;
    // 0x1f4218: 0x0  nop
    ctx->pc = 0x1f4218u;
    // NOP
    // 0x1f421c: 0x0  nop
    ctx->pc = 0x1f421cu;
    // NOP
    // 0x1f4220: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f4220u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f4224: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1f4224u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1f4228: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1f4228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1f422c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f422cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f4230: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f4230u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f4234: 0x24427440  addiu       $v0, $v0, 0x7440
    ctx->pc = 0x1f4234u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 29760));
    // 0x1f4238: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f4238u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f423c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1f423cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4240: 0x8023eb00  lb          $v1, -0x1500($at)
    ctx->pc = 0x1f4240u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294961920)));
    // 0x1f4244: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f4244u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f4248: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1f4248u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1f424c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1f424cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f4250: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f4250u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f4254: 0x40f809  jalr        $v0
    ctx->pc = 0x1F4254u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1F425Cu);
        ctx->pc = 0x1F4258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4254u;
            // 0x1f4258: 0x2484eb00  addiu       $a0, $a0, -0x1500 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961920));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1F425Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3EC8u: goto label_1f3ec8;
            case 0x1F3EE4u: goto label_1f3ee4;
            case 0x1F3EF4u: goto label_1f3ef4;
            case 0x1F3F10u: goto label_1f3f10;
            case 0x1F3F1Cu: goto label_1f3f1c;
            case 0x1F3F20u: goto label_1f3f20;
            case 0x1F3F48u: goto label_1f3f48;
            case 0x1F3F5Cu: goto label_1f3f5c;
            case 0x1F3F64u: goto label_1f3f64;
            case 0x1F3F68u: goto label_1f3f68;
            case 0x1F3F78u: goto label_1f3f78;
            case 0x1F3F88u: goto label_1f3f88;
            case 0x1F3FA0u: goto label_1f3fa0;
            case 0x1F3FA4u: goto label_1f3fa4;
            case 0x1F3FF0u: goto label_1f3ff0;
            case 0x1F4024u: goto label_1f4024;
            case 0x1F4084u: goto label_1f4084;
            case 0x1F40B8u: goto label_1f40b8;
            case 0x1F410Cu: goto label_1f410c;
            case 0x1F416Cu: goto label_1f416c;
            case 0x1F41A0u: goto label_1f41a0;
            case 0x1F41F4u: goto label_1f41f4;
            case 0x1F425Cu: goto label_1f425c;
            case 0x1F4274u: goto label_1f4274;
            case 0x1F42ACu: goto label_1f42ac;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1F425Cu; }
            if (ctx->pc != 0x1F425Cu) { return; }
        }
        }
    }
    ctx->pc = 0x1F425Cu;
label_1f425c:
    // 0x1f425c: 0x3c050036  lui         $a1, 0x36
    ctx->pc = 0x1f425cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)54 << 16));
    // 0x1f4260: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1f4260u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4264: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f4264u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4268: 0x24a5eb88  addiu       $a1, $a1, -0x1478
    ctx->pc = 0x1f4268u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294962056));
    // 0x1f426c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F426Cu;
    SET_GPR_U32(ctx, 31, 0x1F4274u);
    ctx->pc = 0x1F4270u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F426Cu;
            // 0x1f4270: 0x2406000c  addiu       $a2, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4274u; }
        if (ctx->pc != 0x1F4274u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4274u; }
        if (ctx->pc != 0x1F4274u) { return; }
    }
    ctx->pc = 0x1F4274u;
label_1f4274:
    // 0x1f4274: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1f4274u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4278: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1f4278u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f427c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f427cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f4280: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f4280u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f4284: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4284u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4288u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4284u;
            // 0x1f4288: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3EC8u: goto label_1f3ec8;
            case 0x1F3EE4u: goto label_1f3ee4;
            case 0x1F3EF4u: goto label_1f3ef4;
            case 0x1F3F10u: goto label_1f3f10;
            case 0x1F3F1Cu: goto label_1f3f1c;
            case 0x1F3F20u: goto label_1f3f20;
            case 0x1F3F48u: goto label_1f3f48;
            case 0x1F3F5Cu: goto label_1f3f5c;
            case 0x1F3F64u: goto label_1f3f64;
            case 0x1F3F68u: goto label_1f3f68;
            case 0x1F3F78u: goto label_1f3f78;
            case 0x1F3F88u: goto label_1f3f88;
            case 0x1F3FA0u: goto label_1f3fa0;
            case 0x1F3FA4u: goto label_1f3fa4;
            case 0x1F3FF0u: goto label_1f3ff0;
            case 0x1F4024u: goto label_1f4024;
            case 0x1F4084u: goto label_1f4084;
            case 0x1F40B8u: goto label_1f40b8;
            case 0x1F410Cu: goto label_1f410c;
            case 0x1F416Cu: goto label_1f416c;
            case 0x1F41A0u: goto label_1f41a0;
            case 0x1F41F4u: goto label_1f41f4;
            case 0x1F425Cu: goto label_1f425c;
            case 0x1F4274u: goto label_1f4274;
            case 0x1F42ACu: goto label_1f42ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F428Cu;
    // 0x1f428c: 0x0  nop
    ctx->pc = 0x1f428cu;
    // NOP
    // 0x1f4290: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f4290u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f4294: 0x3c040036  lui         $a0, 0x36
    ctx->pc = 0x1f4294u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)54 << 16));
    // 0x1f4298: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1f4298u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1f429c: 0x2484eb00  addiu       $a0, $a0, -0x1500
    ctx->pc = 0x1f429cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961920));
    // 0x1f42a0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f42a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f42a4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F42A4u;
    SET_GPR_U32(ctx, 31, 0x1F42ACu);
    ctx->pc = 0x1F42A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F42A4u;
            // 0x1f42a8: 0x24060094  addiu       $a2, $zero, 0x94 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 148));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F42ACu; }
        if (ctx->pc != 0x1F42ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F42ACu; }
        if (ctx->pc != 0x1F42ACu) { return; }
    }
    ctx->pc = 0x1F42ACu;
label_1f42ac:
    // 0x1f42ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1f42acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f42b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f42b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f42b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F42B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F42B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F42B4u;
            // 0x1f42b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3EC8u: goto label_1f3ec8;
            case 0x1F3EE4u: goto label_1f3ee4;
            case 0x1F3EF4u: goto label_1f3ef4;
            case 0x1F3F10u: goto label_1f3f10;
            case 0x1F3F1Cu: goto label_1f3f1c;
            case 0x1F3F20u: goto label_1f3f20;
            case 0x1F3F48u: goto label_1f3f48;
            case 0x1F3F5Cu: goto label_1f3f5c;
            case 0x1F3F64u: goto label_1f3f64;
            case 0x1F3F68u: goto label_1f3f68;
            case 0x1F3F78u: goto label_1f3f78;
            case 0x1F3F88u: goto label_1f3f88;
            case 0x1F3FA0u: goto label_1f3fa0;
            case 0x1F3FA4u: goto label_1f3fa4;
            case 0x1F3FF0u: goto label_1f3ff0;
            case 0x1F4024u: goto label_1f4024;
            case 0x1F4084u: goto label_1f4084;
            case 0x1F40B8u: goto label_1f40b8;
            case 0x1F410Cu: goto label_1f410c;
            case 0x1F416Cu: goto label_1f416c;
            case 0x1F41A0u: goto label_1f41a0;
            case 0x1F41F4u: goto label_1f41f4;
            case 0x1F425Cu: goto label_1f425c;
            case 0x1F4274u: goto label_1f4274;
            case 0x1F42ACu: goto label_1f42ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F42BCu;
    // 0x1f42bc: 0x0  nop
    ctx->pc = 0x1f42bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
