#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162950
// Address: 0x162950 - 0x1629f4
void sub_00162950_0x162950(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162950_0x162950");
#endif

    switch (ctx->pc) {
        case 0x16296cu: goto label_16296c;
        case 0x162980u: goto label_162980;
        case 0x162990u: goto label_162990;
        case 0x1629b0u: goto label_1629b0;
        case 0x1629c0u: goto label_1629c0;
        default: break;
    }

    ctx->pc = 0x162950u;

    // 0x162950: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x162950u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x162954: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162954u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162958: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x162958u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16295c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16295cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x162960: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x162960u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x162964: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x162964u;
    SET_GPR_U32(ctx, 31, 0x16296Cu);
    ctx->pc = 0x162968u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162964u;
            // 0x162968: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16296Cu; }
        if (ctx->pc != 0x16296Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16296Cu; }
        if (ctx->pc != 0x16296Cu) { return; }
    }
    ctx->pc = 0x16296Cu;
label_16296c:
    // 0x16296c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16296Cu;
    {
        const bool branch_taken_0x16296c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x162970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16296Cu;
            // 0x162970: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16296c) {
            ctx->pc = 0x162988u;
            goto label_162988;
        }
    }
    ctx->pc = 0x162974u;
    // 0x162974: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x162974u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162978: 0xc058dd4  jal         func_163750
    ctx->pc = 0x162978u;
    SET_GPR_U32(ctx, 31, 0x162980u);
    ctx->pc = 0x16297Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162978u;
            // 0x16297c: 0x24840360  addiu       $a0, $a0, 0x360 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 864));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162980u; }
        if (ctx->pc != 0x162980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162980u; }
        if (ctx->pc != 0x162980u) { return; }
    }
    ctx->pc = 0x162980u;
label_162980:
    // 0x162980: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x162980u;
    {
        const bool branch_taken_0x162980 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x162984u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162980u;
            // 0x162984: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162980) {
            ctx->pc = 0x1629E0u;
            goto label_1629e0;
        }
    }
    ctx->pc = 0x162988u;
label_162988:
    // 0x162988: 0xc0589fc  jal         func_1627F0
    ctx->pc = 0x162988u;
    SET_GPR_U32(ctx, 31, 0x162990u);
    ctx->pc = 0x1627F0u;
    if (runtime->hasFunction(0x1627F0u)) {
        auto targetFn = runtime->lookupFunction(0x1627F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162990u; }
        if (ctx->pc != 0x162990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001627F0_0x1627f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162990u; }
        if (ctx->pc != 0x162990u) { return; }
    }
    ctx->pc = 0x162990u;
label_162990:
    // 0x162990: 0x202182a  slt         $v1, $s0, $v0
    ctx->pc = 0x162990u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x162994: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x162994u;
    {
        const bool branch_taken_0x162994 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x162998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162994u;
            // 0x162998: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162994) {
            ctx->pc = 0x1629E0u;
            goto label_1629e0;
        }
    }
    ctx->pc = 0x16299Cu;
    // 0x16299c: 0x6010006  bgez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16299Cu;
    {
        const bool branch_taken_0x16299c = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x1629A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16299Cu;
            // 0x1629a0: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16299c) {
            ctx->pc = 0x1629B8u;
            goto label_1629b8;
        }
    }
    ctx->pc = 0x1629A4u;
    // 0x1629a4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1629a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1629a8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1629A8u;
    SET_GPR_U32(ctx, 31, 0x1629B0u);
    ctx->pc = 0x1629ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1629A8u;
            // 0x1629ac: 0x24840390  addiu       $a0, $a0, 0x390 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 912));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1629B0u; }
        if (ctx->pc != 0x1629B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1629B0u; }
        if (ctx->pc != 0x1629B0u) { return; }
    }
    ctx->pc = 0x1629B0u;
label_1629b0:
    // 0x1629b0: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1629B0u;
    {
        const bool branch_taken_0x1629b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1629B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1629B0u;
            // 0x1629b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1629b0) {
            ctx->pc = 0x1629E0u;
            goto label_1629e0;
        }
    }
    ctx->pc = 0x1629B8u;
label_1629b8:
    // 0x1629b8: 0xc058a84  jal         func_162A10
    ctx->pc = 0x1629B8u;
    SET_GPR_U32(ctx, 31, 0x1629C0u);
    ctx->pc = 0x1629BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1629B8u;
            // 0x1629bc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162A10u;
    if (runtime->hasFunction(0x162A10u)) {
        auto targetFn = runtime->lookupFunction(0x162A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1629C0u; }
        if (ctx->pc != 0x1629C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162A10_0x162a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1629C0u; }
        if (ctx->pc != 0x1629C0u) { return; }
    }
    ctx->pc = 0x1629C0u;
label_1629c0:
    // 0x1629c0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1629c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1629c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1629c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1629c8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1629c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1629cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1629ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1629d0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1629d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1629d4: 0x8058a8a  j           func_162A28
    ctx->pc = 0x1629D4u;
    ctx->pc = 0x1629D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1629D4u;
            // 0x1629d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162A28u;
    if (runtime->hasFunction(0x162A28u)) {
        auto targetFn = runtime->lookupFunction(0x162A28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00162A28_0x162a28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1629DCu;
    // 0x1629dc: 0x0  nop
    ctx->pc = 0x1629dcu;
    // NOP
label_1629e0:
    // 0x1629e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1629e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1629e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1629e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1629e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1629e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1629ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1629ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1629F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1629ECu;
            // 0x1629f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16296Cu: goto label_16296c;
            case 0x162980u: goto label_162980;
            case 0x162988u: goto label_162988;
            case 0x162990u: goto label_162990;
            case 0x1629B0u: goto label_1629b0;
            case 0x1629B8u: goto label_1629b8;
            case 0x1629C0u: goto label_1629c0;
            case 0x1629E0u: goto label_1629e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1629F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
