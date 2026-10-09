#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141D18
// Address: 0x141d18 - 0x141df0
void sub_00141D18_0x141d18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141D18_0x141d18");
#endif

    switch (ctx->pc) {
        case 0x141d3cu: goto label_141d3c;
        case 0x141da0u: goto label_141da0;
        case 0x141dccu: goto label_141dcc;
        default: break;
    }

    ctx->pc = 0x141d18u;

    // 0x141d18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x141d18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x141d1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141d1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141d20: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x141d20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141d24: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x141d24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x141d28: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x141d28u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141d2c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x141d2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x141d30: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x141d30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x141d34: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x141D34u;
    SET_GPR_U32(ctx, 31, 0x141D3Cu);
    ctx->pc = 0x141D38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141D34u;
            // 0x141d38: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141D3Cu; }
        if (ctx->pc != 0x141D3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141D3Cu; }
        if (ctx->pc != 0x141D3Cu) { return; }
    }
    ctx->pc = 0x141D3Cu;
label_141d3c:
    // 0x141d3c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x141d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x141d40: 0x1080c0  sll         $s0, $s0, 3
    ctx->pc = 0x141d40u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x141d44: 0x244249a0  addiu       $v0, $v0, 0x49A0
    ctx->pc = 0x141d44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18848));
    // 0x141d48: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x141d48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x141d4c: 0x501821  addu        $v1, $v0, $s0
    ctx->pc = 0x141d4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x141d50: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x141d50u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x141d54: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x141d54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x141d58: 0xac720004  sw          $s2, 0x4($v1)
    ctx->pc = 0x141d58u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 18));
    // 0x141d5c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141d5cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141d60: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x141d60u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x141d64: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x141d64u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141d68: 0x80505ba  j           func_1416E8
    ctx->pc = 0x141D68u;
    ctx->pc = 0x141D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141D68u;
            // 0x141d6c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001416E8_0x1416e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141D70u;
    // 0x141d70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x141d70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x141d74: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x141d74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x141d78: 0x244249a0  addiu       $v0, $v0, 0x49A0
    ctx->pc = 0x141d78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18848));
    // 0x141d7c: 0x420c0  sll         $a0, $a0, 3
    ctx->pc = 0x141d7cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x141d80: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x141d80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x141d84: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x141d84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x141d88: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x141d88u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x141d8c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x141d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x141d90: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x141D90u;
    {
        const bool branch_taken_0x141d90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x141d90) {
            ctx->pc = 0x141D94u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141D90u;
            // 0x141d94: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141DA4u;
            goto label_141da4;
        }
    }
    ctx->pc = 0x141D98u;
    // 0x141d98: 0x40f809  jalr        $v0
    ctx->pc = 0x141D98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x141DA0u);
        ctx->pc = 0x141D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141D98u;
            // 0x141d9c: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141DA0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141D3Cu: goto label_141d3c;
            case 0x141DA0u: goto label_141da0;
            case 0x141DA4u: goto label_141da4;
            case 0x141DCCu: goto label_141dcc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141DA0u; }
            if (ctx->pc != 0x141DA0u) { return; }
        }
        }
    }
    ctx->pc = 0x141DA0u;
label_141da0:
    // 0x141da0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x141da0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_141da4:
    // 0x141da4: 0x3e00008  jr          $ra
    ctx->pc = 0x141DA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x141DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141DA4u;
            // 0x141da8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x141D3Cu: goto label_141d3c;
            case 0x141DA0u: goto label_141da0;
            case 0x141DA4u: goto label_141da4;
            case 0x141DCCu: goto label_141dcc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141DACu;
    // 0x141dac: 0x0  nop
    ctx->pc = 0x141dacu;
    // NOP
    // 0x141db0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x141db0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x141db4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141db8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x141db8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141dbc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x141dbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x141dc0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x141dc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x141dc4: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x141DC4u;
    SET_GPR_U32(ctx, 31, 0x141DCCu);
    ctx->pc = 0x141DC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141DC4u;
            // 0x141dc8: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141DCCu; }
        if (ctx->pc != 0x141DCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141DCCu; }
        if (ctx->pc != 0x141DCCu) { return; }
    }
    ctx->pc = 0x141DCCu;
label_141dcc:
    // 0x141dcc: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x141dccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x141dd0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x141dd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141dd4: 0x244249f0  addiu       $v0, $v0, 0x49F0
    ctx->pc = 0x141dd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18928));
    // 0x141dd8: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x141dd8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x141ddc: 0xac510000  sw          $s1, 0x0($v0)
    ctx->pc = 0x141ddcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 17));
    // 0x141de0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141de0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141de4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x141de4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x141de8: 0x80505ba  j           func_1416E8
    ctx->pc = 0x141DE8u;
    ctx->pc = 0x141DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141DE8u;
            // 0x141dec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001416E8_0x1416e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141DF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
