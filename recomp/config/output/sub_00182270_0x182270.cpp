#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182270
// Address: 0x182270 - 0x182398
void sub_00182270_0x182270(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182270_0x182270");
#endif

    switch (ctx->pc) {
        case 0x182288u: goto label_182288;
        case 0x1822e0u: goto label_1822e0;
        case 0x1822f4u: goto label_1822f4;
        case 0x1822fcu: goto label_1822fc;
        case 0x182318u: goto label_182318;
        case 0x182324u: goto label_182324;
        case 0x182338u: goto label_182338;
        case 0x182354u: goto label_182354;
        case 0x182364u: goto label_182364;
        case 0x18237cu: goto label_18237c;
        default: break;
    }

    ctx->pc = 0x182270u;

    // 0x182270: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x182270u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x182274: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x182274u;
    {
        const bool branch_taken_0x182274 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x182278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182274u;
            // 0x182278: 0x90830000  lbu         $v1, 0x0($a0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182274) {
            ctx->pc = 0x1822BCu;
            goto label_1822bc;
        }
    }
    ctx->pc = 0x18227Cu;
    // 0x18227c: 0x2406003f  addiu       $a2, $zero, 0x3F
    ctx->pc = 0x18227cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x182280: 0x2405002a  addiu       $a1, $zero, 0x2A
    ctx->pc = 0x182280u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 42));
    // 0x182284: 0x0  nop
    ctx->pc = 0x182284u;
    // NOP
label_182288:
    // 0x182288: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x182288u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x18228c: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x18228cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x182290: 0x10460005  beq         $v0, $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x182290u;
    {
        const bool branch_taken_0x182290 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 6));
        ctx->pc = 0x182294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182290u;
            // 0x182294: 0x28430020  slti        $v1, $v0, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x182290) {
            ctx->pc = 0x1822A8u;
            goto label_1822a8;
        }
    }
    ctx->pc = 0x182298u;
    // 0x182298: 0x10450003  beq         $v0, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x182298u;
    {
        const bool branch_taken_0x182298 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        if (branch_taken_0x182298) {
            ctx->pc = 0x1822A8u;
            goto label_1822a8;
        }
    }
    ctx->pc = 0x1822A0u;
    // 0x1822a0: 0x50600003  beql        $v1, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x1822A0u;
    {
        const bool branch_taken_0x1822a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1822a0) {
            ctx->pc = 0x1822A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1822A0u;
            // 0x1822a4: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1822B0u;
            goto label_1822b0;
        }
    }
    ctx->pc = 0x1822A8u;
label_1822a8:
    // 0x1822a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1822A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1822ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1822A8u;
            // 0x1822ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182288u: goto label_182288;
            case 0x1822A8u: goto label_1822a8;
            case 0x1822B0u: goto label_1822b0;
            case 0x1822BCu: goto label_1822bc;
            case 0x1822E0u: goto label_1822e0;
            case 0x1822F4u: goto label_1822f4;
            case 0x1822FCu: goto label_1822fc;
            case 0x182318u: goto label_182318;
            case 0x182324u: goto label_182324;
            case 0x182330u: goto label_182330;
            case 0x182338u: goto label_182338;
            case 0x182354u: goto label_182354;
            case 0x182358u: goto label_182358;
            case 0x182364u: goto label_182364;
            case 0x18237Cu: goto label_18237c;
            case 0x182384u: goto label_182384;
            case 0x182388u: goto label_182388;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1822B0u;
label_1822b0:
    // 0x1822b0: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x1822b0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1822b4: 0x1440fff4  bnez        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1822B4u;
    {
        const bool branch_taken_0x1822b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1822B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1822B4u;
            // 0x1822b8: 0x90830000  lbu         $v1, 0x0($a0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1822b4) {
            ctx->pc = 0x182288u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_182288;
        }
    }
    ctx->pc = 0x1822BCu;
label_1822bc:
    // 0x1822bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1822BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1822C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1822BCu;
            // 0x1822c0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182288u: goto label_182288;
            case 0x1822A8u: goto label_1822a8;
            case 0x1822B0u: goto label_1822b0;
            case 0x1822BCu: goto label_1822bc;
            case 0x1822E0u: goto label_1822e0;
            case 0x1822F4u: goto label_1822f4;
            case 0x1822FCu: goto label_1822fc;
            case 0x182318u: goto label_182318;
            case 0x182324u: goto label_182324;
            case 0x182330u: goto label_182330;
            case 0x182338u: goto label_182338;
            case 0x182354u: goto label_182354;
            case 0x182358u: goto label_182358;
            case 0x182364u: goto label_182364;
            case 0x18237Cu: goto label_18237c;
            case 0x182384u: goto label_182384;
            case 0x182388u: goto label_182388;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1822C4u;
    // 0x1822c4: 0x0  nop
    ctx->pc = 0x1822c4u;
    // NOP
    // 0x1822c8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1822c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1822cc: 0x2405002f  addiu       $a1, $zero, 0x2F
    ctx->pc = 0x1822ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x1822d0: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x1822d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1822d4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1822d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1822d8: 0xc042b3a  jal         func_10ACE8
    ctx->pc = 0x1822D8u;
    SET_GPR_U32(ctx, 31, 0x1822E0u);
    ctx->pc = 0x1822DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1822D8u;
            // 0x1822dc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ACE8u;
    if (runtime->hasFunction(0x10ACE8u)) {
        auto targetFn = runtime->lookupFunction(0x10ACE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1822E0u; }
        if (ctx->pc != 0x1822E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ACE8_0x10ace8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1822E0u; }
        if (ctx->pc != 0x1822E0u) { return; }
    }
    ctx->pc = 0x1822E0u;
label_1822e0:
    // 0x1822e0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1822e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1822e4: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1822E4u;
    {
        const bool branch_taken_0x1822e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1822E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1822E4u;
            // 0x1822e8: 0x2405002f  addiu       $a1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1822e4) {
            ctx->pc = 0x182330u;
            goto label_182330;
        }
    }
    ctx->pc = 0x1822ECu;
    // 0x1822ec: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1822ECu;
    SET_GPR_U32(ctx, 31, 0x1822F4u);
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1822F4u; }
        if (ctx->pc != 0x1822F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1822F4u; }
        if (ctx->pc != 0x1822F4u) { return; }
    }
    ctx->pc = 0x1822F4u;
label_1822f4:
    // 0x1822f4: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1822F4u;
    SET_GPR_U32(ctx, 31, 0x1822FCu);
    ctx->pc = 0x1822F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1822F4u;
            // 0x1822f8: 0x24440001  addiu       $a0, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1822FCu; }
        if (ctx->pc != 0x1822FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1822FCu; }
        if (ctx->pc != 0x1822FCu) { return; }
    }
    ctx->pc = 0x1822FCu;
label_1822fc:
    // 0x1822fc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1822fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182300: 0x2c430020  sltiu       $v1, $v0, 0x20
    ctx->pc = 0x182300u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x182304: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x182304u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182308: 0x1060001f  beqz        $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x182308u;
    {
        const bool branch_taken_0x182308 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x18230Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182308u;
            // 0x18230c: 0x2405002f  addiu       $a1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182308) {
            ctx->pc = 0x182388u;
            goto label_182388;
        }
    }
    ctx->pc = 0x182310u;
    // 0x182310: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x182310u;
    SET_GPR_U32(ctx, 31, 0x182318u);
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182318u; }
        if (ctx->pc != 0x182318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182318u; }
        if (ctx->pc != 0x182318u) { return; }
    }
    ctx->pc = 0x182318u;
label_182318:
    // 0x182318: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x182318u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18231c: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x18231Cu;
    SET_GPR_U32(ctx, 31, 0x182324u);
    ctx->pc = 0x182320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18231Cu;
            // 0x182320: 0x24450001  addiu       $a1, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182324u; }
        if (ctx->pc != 0x182324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182324u; }
        if (ctx->pc != 0x182324u) { return; }
    }
    ctx->pc = 0x182324u;
label_182324:
    // 0x182324: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x182324u;
    {
        const bool branch_taken_0x182324 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x182328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182324u;
            // 0x182328: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182324) {
            ctx->pc = 0x182358u;
            goto label_182358;
        }
    }
    ctx->pc = 0x18232Cu;
    // 0x18232c: 0x0  nop
    ctx->pc = 0x18232cu;
    // NOP
label_182330:
    // 0x182330: 0xc042c56  jal         func_10B158
    ctx->pc = 0x182330u;
    SET_GPR_U32(ctx, 31, 0x182338u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182338u; }
        if (ctx->pc != 0x182338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182338u; }
        if (ctx->pc != 0x182338u) { return; }
    }
    ctx->pc = 0x182338u;
label_182338:
    // 0x182338: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x182338u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18233c: 0x2c430020  sltiu       $v1, $v0, 0x20
    ctx->pc = 0x18233cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x182340: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x182340u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182344: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x182344u;
    {
        const bool branch_taken_0x182344 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x182348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182344u;
            // 0x182348: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182344) {
            ctx->pc = 0x182388u;
            goto label_182388;
        }
    }
    ctx->pc = 0x18234Cu;
    // 0x18234c: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x18234Cu;
    SET_GPR_U32(ctx, 31, 0x182354u);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182354u; }
        if (ctx->pc != 0x182354u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182354u; }
        if (ctx->pc != 0x182354u) { return; }
    }
    ctx->pc = 0x182354u;
label_182354:
    // 0x182354: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x182354u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
label_182358:
    // 0x182358: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x182358u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18235c: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x18235Cu;
    SET_GPR_U32(ctx, 31, 0x182364u);
    ctx->pc = 0x182360u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18235Cu;
            // 0x182360: 0x24a517b0  addiu       $a1, $a1, 0x17B0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182364u; }
        if (ctx->pc != 0x182364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182364u; }
        if (ctx->pc != 0x182364u) { return; }
    }
    ctx->pc = 0x182364u;
label_182364:
    // 0x182364: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x182364u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x182368: 0x24a517b8  addiu       $a1, $a1, 0x17B8
    ctx->pc = 0x182368u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6072));
    // 0x18236c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18236Cu;
    {
        const bool branch_taken_0x18236c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x182370u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18236Cu;
            // 0x182370: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18236c) {
            ctx->pc = 0x182384u;
            goto label_182384;
        }
    }
    ctx->pc = 0x182374u;
    // 0x182374: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x182374u;
    SET_GPR_U32(ctx, 31, 0x18237Cu);
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18237Cu; }
        if (ctx->pc != 0x18237Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18237Cu; }
        if (ctx->pc != 0x18237Cu) { return; }
    }
    ctx->pc = 0x18237Cu;
label_18237c:
    // 0x18237c: 0x54400002  bnel        $v0, $zero, . + 4 + (0x2 << 2)
    ctx->pc = 0x18237Cu;
    {
        const bool branch_taken_0x18237c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18237c) {
            ctx->pc = 0x182380u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18237Cu;
            // 0x182380: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x182388u;
            goto label_182388;
        }
    }
    ctx->pc = 0x182384u;
label_182384:
    // 0x182384: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x182384u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_182388:
    // 0x182388: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x182388u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18238c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x18238cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x182390: 0x3e00008  jr          $ra
    ctx->pc = 0x182390u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182390u;
            // 0x182394: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182288u: goto label_182288;
            case 0x1822A8u: goto label_1822a8;
            case 0x1822B0u: goto label_1822b0;
            case 0x1822BCu: goto label_1822bc;
            case 0x1822E0u: goto label_1822e0;
            case 0x1822F4u: goto label_1822f4;
            case 0x1822FCu: goto label_1822fc;
            case 0x182318u: goto label_182318;
            case 0x182324u: goto label_182324;
            case 0x182330u: goto label_182330;
            case 0x182338u: goto label_182338;
            case 0x182354u: goto label_182354;
            case 0x182358u: goto label_182358;
            case 0x182364u: goto label_182364;
            case 0x18237Cu: goto label_18237c;
            case 0x182384u: goto label_182384;
            case 0x182388u: goto label_182388;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182398u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
