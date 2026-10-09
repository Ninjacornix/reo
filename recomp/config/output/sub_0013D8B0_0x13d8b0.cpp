#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D8B0
// Address: 0x13d8b0 - 0x13d9b8
void sub_0013D8B0_0x13d8b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D8B0_0x13d8b0");
#endif

    switch (ctx->pc) {
        case 0x13d960u: goto label_13d960;
        case 0x13d990u: goto label_13d990;
        default: break;
    }

    ctx->pc = 0x13d8b0u;

    // 0x13d8b0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x13d8b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13d8b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13d8b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13d8b8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13d8b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d8bc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13d8bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13d8c0: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x13d8c0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d8c4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13d8c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13d8c8: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x13d8c8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d8cc: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13d8ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13d8d0: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x13d8d0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d8d4: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x13d8d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x13d8d8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13d8d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13d8dc: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x13d8dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x13d8e0: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x13d8e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13d8e4: 0x1040002a  beqz        $v0, . + 4 + (0x2A << 2)
    ctx->pc = 0x13D8E4u;
    {
        const bool branch_taken_0x13d8e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D8E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D8E4u;
            // 0x13d8e8: 0xa82d  daddu       $s5, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d8e4) {
            ctx->pc = 0x13D990u;
            goto label_13d990;
        }
    }
    ctx->pc = 0x13D8ECu;
    // 0x13d8ec: 0x82020003  lb          $v0, 0x3($s0)
    ctx->pc = 0x13d8ecu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x13d8f0: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x13d8f0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13d8f4: 0x1451000a  bne         $v0, $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x13D8F4u;
    {
        const bool branch_taken_0x13d8f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x13D8F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D8F4u;
            // 0x13d8f8: 0x92070003  lbu         $a3, 0x3($s0) (Delay Slot)
        SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d8f4) {
            ctx->pc = 0x13D920u;
            goto label_13d920;
        }
    }
    ctx->pc = 0x13D8FCu;
    // 0x13d8fc: 0x8e060020  lw          $a2, 0x20($s0)
    ctx->pc = 0x13d8fcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13d900: 0x61140  sll         $v0, $a2, 5
    ctx->pc = 0x13d900u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 5));
    // 0x13d904: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x13d904u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x13d908: 0x24420038  addiu       $v0, $v0, 0x38
    ctx->pc = 0x13d908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 56));
    // 0x13d90c: 0x8c550014  lw          $s5, 0x14($v0)
    ctx->pc = 0x13d90cu;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x13d910: 0x8c540010  lw          $s4, 0x10($v0)
    ctx->pc = 0x13d910u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x13d914: 0x8c530004  lw          $s3, 0x4($v0)
    ctx->pc = 0x13d914u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x13d918: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x13D918u;
    {
        const bool branch_taken_0x13d918 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D91Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D918u;
            // 0x13d91c: 0x8c52000c  lw          $s2, 0xC($v0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d918) {
            ctx->pc = 0x13D924u;
            goto label_13d924;
        }
    }
    ctx->pc = 0x13D920u;
label_13d920:
    // 0x13d920: 0x8e060020  lw          $a2, 0x20($s0)
    ctx->pc = 0x13d920u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
label_13d924:
    // 0x13d924: 0x24c40001  addiu       $a0, $a2, 0x1
    ctx->pc = 0x13d924u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x13d928: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13d928u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13d92c: 0x28850000  slti        $a1, $a0, 0x0
    ctx->pc = 0x13d92cu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x13d930: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x13d930u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d934: 0xc5100b  movn        $v0, $a2, $a1
    ctx->pc = 0x13d934u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x13d938: 0x8e030024  lw          $v1, 0x24($s0)
    ctx->pc = 0x13d938u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x13d93c: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x13d93cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x13d940: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x13d940u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x13d944: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x13d944u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x13d948: 0x822023  subu        $a0, $a0, $v0
    ctx->pc = 0x13d948u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13d94c: 0xae030024  sw          $v1, 0x24($s0)
    ctx->pc = 0x13d94cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 3));
    // 0x13d950: 0x1c600005  bgtz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x13D950u;
    {
        const bool branch_taken_0x13d950 = (GPR_S64(ctx, 3) > 0);
        ctx->pc = 0x13D954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D950u;
            // 0x13d954: 0xae040020  sw          $a0, 0x20($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d950) {
            ctx->pc = 0x13D968u;
            goto label_13d968;
        }
    }
    ctx->pc = 0x13D958u;
    // 0x13d958: 0xc04f50c  jal         func_13D430
    ctx->pc = 0x13D958u;
    SET_GPR_U32(ctx, 31, 0x13D960u);
    ctx->pc = 0x13D430u;
    if (runtime->hasFunction(0x13D430u)) {
        auto targetFn = runtime->lookupFunction(0x13D430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D960u; }
        if (ctx->pc != 0x13D960u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D430_0x13d430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D960u; }
        if (ctx->pc != 0x13D960u) { return; }
    }
    ctx->pc = 0x13D960u;
label_13d960:
    // 0x13d960: 0xa2110001  sb          $s1, 0x1($s0)
    ctx->pc = 0x13d960u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 17));
    // 0x13d964: 0x92070003  lbu         $a3, 0x3($s0)
    ctx->pc = 0x13d964u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
label_13d968:
    // 0x13d968: 0x71600  sll         $v0, $a3, 24
    ctx->pc = 0x13d968u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 24));
    // 0x13d96c: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x13d96cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x13d970: 0x54510008  bnel        $v0, $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x13D970u;
    {
        const bool branch_taken_0x13d970 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        if (branch_taken_0x13d970) {
            ctx->pc = 0x13D974u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D970u;
            // 0x13d974: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D994u;
            goto label_13d994;
        }
    }
    ctx->pc = 0x13D978u;
    // 0x13d978: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13d978u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d97c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x13d97cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d980: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x13d980u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d984: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x13d984u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d988: 0xc04f34e  jal         func_13CD38
    ctx->pc = 0x13D988u;
    SET_GPR_U32(ctx, 31, 0x13D990u);
    ctx->pc = 0x13D98Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D988u;
            // 0x13d98c: 0x2a0402d  daddu       $t0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CD38u;
    if (runtime->hasFunction(0x13CD38u)) {
        auto targetFn = runtime->lookupFunction(0x13CD38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D990u; }
        if (ctx->pc != 0x13D990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CD38_0x13cd38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D990u; }
        if (ctx->pc != 0x13D990u) { return; }
    }
    ctx->pc = 0x13D990u;
label_13d990:
    // 0x13d990: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13d990u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13d994:
    // 0x13d994: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13d994u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13d998: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13d998u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13d99c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13d99cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13d9a0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13d9a0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13d9a4: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x13d9a4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13d9a8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x13d9a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13d9ac: 0x3e00008  jr          $ra
    ctx->pc = 0x13D9ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D9B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D9ACu;
            // 0x13d9b0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D920u: goto label_13d920;
            case 0x13D924u: goto label_13d924;
            case 0x13D960u: goto label_13d960;
            case 0x13D968u: goto label_13d968;
            case 0x13D990u: goto label_13d990;
            case 0x13D994u: goto label_13d994;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D9B4u;
    // 0x13d9b4: 0x0  nop
    ctx->pc = 0x13d9b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
