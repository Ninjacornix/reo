#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017B610
// Address: 0x17b610 - 0x17b800
void sub_0017B610_0x17b610(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017B610_0x17b610");
#endif

    switch (ctx->pc) {
        case 0x17b6b0u: goto label_17b6b0;
        case 0x17b6ecu: goto label_17b6ec;
        case 0x17b720u: goto label_17b720;
        case 0x17b750u: goto label_17b750;
        case 0x17b780u: goto label_17b780;
        case 0x17b7b0u: goto label_17b7b0;
        default: break;
    }

    ctx->pc = 0x17b610u;

    // 0x17b610: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17b610u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17b614: 0x24020041  addiu       $v0, $zero, 0x41
    ctx->pc = 0x17b614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x17b618: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17b618u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17b61c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17b61cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b620: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17b620u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17b624: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17b624u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b628: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17b628u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17b62c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17b62cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17b630: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x17b630u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17b634: 0x10620050  beq         $v1, $v0, . + 4 + (0x50 << 2)
    ctx->pc = 0x17B634u;
    {
        const bool branch_taken_0x17b634 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B634u;
            // 0x17b638: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b634) {
            ctx->pc = 0x17B778u;
            goto label_17b778;
        }
    }
    ctx->pc = 0x17B63Cu;
    // 0x17b63c: 0x28620042  slti        $v0, $v1, 0x42
    ctx->pc = 0x17b63cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)66) ? 1 : 0);
    // 0x17b640: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x17B640u;
    {
        const bool branch_taken_0x17b640 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B640u;
            // 0x17b644: 0x24020101  addiu       $v0, $zero, 0x101 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b640) {
            ctx->pc = 0x17B680u;
            goto label_17b680;
        }
    }
    ctx->pc = 0x17B648u;
    // 0x17b648: 0x24020021  addiu       $v0, $zero, 0x21
    ctx->pc = 0x17b648u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x17b64c: 0x10620056  beq         $v1, $v0, . + 4 + (0x56 << 2)
    ctx->pc = 0x17B64Cu;
    {
        const bool branch_taken_0x17b64c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B64Cu;
            // 0x17b650: 0x28620022  slti        $v0, $v1, 0x22 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)34) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b64c) {
            ctx->pc = 0x17B7A8u;
            goto label_17b7a8;
        }
    }
    ctx->pc = 0x17B654u;
    // 0x17b654: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17B654u;
    {
        const bool branch_taken_0x17b654 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B654u;
            // 0x17b658: 0x24020031  addiu       $v0, $zero, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b654) {
            ctx->pc = 0x17B670u;
            goto label_17b670;
        }
    }
    ctx->pc = 0x17B65Cu;
    // 0x17b65c: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x17b65cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x17b660: 0x10620011  beq         $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x17B660u;
    {
        const bool branch_taken_0x17b660 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17b660) {
            ctx->pc = 0x17B6A8u;
            goto label_17b6a8;
        }
    }
    ctx->pc = 0x17B668u;
    // 0x17b668: 0x1000005c  b           . + 4 + (0x5C << 2)
    ctx->pc = 0x17B668u;
    {
        const bool branch_taken_0x17b668 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B66Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B668u;
            // 0x17b66c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b668) {
            ctx->pc = 0x17B7DCu;
            goto label_17b7dc;
        }
    }
    ctx->pc = 0x17B670u;
label_17b670:
    // 0x17b670: 0x10620035  beq         $v1, $v0, . + 4 + (0x35 << 2)
    ctx->pc = 0x17B670u;
    {
        const bool branch_taken_0x17b670 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17b670) {
            ctx->pc = 0x17B748u;
            goto label_17b748;
        }
    }
    ctx->pc = 0x17B678u;
    // 0x17b678: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x17B678u;
    {
        const bool branch_taken_0x17b678 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B67Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B678u;
            // 0x17b67c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b678) {
            ctx->pc = 0x17B7DCu;
            goto label_17b7dc;
        }
    }
    ctx->pc = 0x17B680u;
label_17b680:
    // 0x17b680: 0x10620055  beq         $v1, $v0, . + 4 + (0x55 << 2)
    ctx->pc = 0x17B680u;
    {
        const bool branch_taken_0x17b680 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B680u;
            // 0x17b684: 0x28620102  slti        $v0, $v1, 0x102 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)258) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b680) {
            ctx->pc = 0x17B7D8u;
            goto label_17b7d8;
        }
    }
    ctx->pc = 0x17B688u;
    // 0x17b688: 0x54400054  bnel        $v0, $zero, . + 4 + (0x54 << 2)
    ctx->pc = 0x17B688u;
    {
        const bool branch_taken_0x17b688 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17b688) {
            ctx->pc = 0x17B68Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17B688u;
            // 0x17b68c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17B7DCu;
            goto label_17b7dc;
        }
    }
    ctx->pc = 0x17B690u;
    // 0x17b690: 0x24021001  addiu       $v0, $zero, 0x1001
    ctx->pc = 0x17b690u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4097));
    // 0x17b694: 0x10620020  beq         $v1, $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x17B694u;
    {
        const bool branch_taken_0x17b694 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17b694) {
            ctx->pc = 0x17B718u;
            goto label_17b718;
        }
    }
    ctx->pc = 0x17B69Cu;
    // 0x17b69c: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x17B69Cu;
    {
        const bool branch_taken_0x17b69c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B6A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B69Cu;
            // 0x17b6a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b69c) {
            ctx->pc = 0x17B7DCu;
            goto label_17b7dc;
        }
    }
    ctx->pc = 0x17B6A4u;
    // 0x17b6a4: 0x0  nop
    ctx->pc = 0x17b6a4u;
    // NOP
label_17b6a8:
    // 0x17b6a8: 0xc05f51a  jal         func_17D468
    ctx->pc = 0x17B6A8u;
    SET_GPR_U32(ctx, 31, 0x17B6B0u);
    ctx->pc = 0x17D468u;
    if (runtime->hasFunction(0x17D468u)) {
        auto targetFn = runtime->lookupFunction(0x17D468u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B6B0u; }
        if (ctx->pc != 0x17B6B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D468_0x17d468(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B6B0u; }
        if (ctx->pc != 0x17B6B0u) { return; }
    }
    ctx->pc = 0x17B6B0u;
label_17b6b0:
    // 0x17b6b0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17b6b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b6b4: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x17B6B4u;
    {
        const bool branch_taken_0x17b6b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17B6B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B6B4u;
            // 0x17b6b8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b6b4) {
            ctx->pc = 0x17B6E0u;
            goto label_17b6e0;
        }
    }
    ctx->pc = 0x17B6BCu;
    // 0x17b6bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b6bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b6c0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b6c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b6c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b6c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b6c8: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b6c8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b6cc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b6ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b6d0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b6d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b6d4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17b6d4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b6d8: 0x805ee22  j           func_17B888
    ctx->pc = 0x17B6D8u;
    ctx->pc = 0x17B6DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B6D8u;
            // 0x17b6dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B888u;
    if (runtime->hasFunction(0x17B888u)) {
        auto targetFn = runtime->lookupFunction(0x17B888u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B888_0x17b888(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B6E0u;
label_17b6e0:
    // 0x17b6e0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b6e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b6e4: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B6E4u;
    SET_GPR_U32(ctx, 31, 0x17B6ECu);
    ctx->pc = 0x17B6E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B6E4u;
            // 0x17b6e8: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B6ECu; }
        if (ctx->pc != 0x17B6ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B6ECu; }
        if (ctx->pc != 0x17B6ECu) { return; }
    }
    ctx->pc = 0x17B6ECu;
label_17b6ec:
    // 0x17b6ec: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b6ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b6f0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b6f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b6f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b6f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b6f8: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b6f8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b6fc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b6fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b700: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b700u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b704: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17b704u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b708: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b708u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b70c: 0x805ee22  j           func_17B888
    ctx->pc = 0x17B70Cu;
    ctx->pc = 0x17B710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B70Cu;
            // 0x17b710: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B888u;
    if (runtime->hasFunction(0x17B888u)) {
        auto targetFn = runtime->lookupFunction(0x17B888u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B888_0x17b888(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B714u;
    // 0x17b714: 0x0  nop
    ctx->pc = 0x17b714u;
    // NOP
label_17b718:
    // 0x17b718: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B718u;
    SET_GPR_U32(ctx, 31, 0x17B720u);
    ctx->pc = 0x17B71Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B718u;
            // 0x17b71c: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B720u; }
        if (ctx->pc != 0x17B720u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B720u; }
        if (ctx->pc != 0x17B720u) { return; }
    }
    ctx->pc = 0x17B720u;
label_17b720:
    // 0x17b720: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b720u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b724: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b724u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b728: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b728u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b72c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b72cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b730: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b730u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b734: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b734u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b738: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17b738u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b73c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b73cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b740: 0x805ee22  j           func_17B888
    ctx->pc = 0x17B740u;
    ctx->pc = 0x17B744u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B740u;
            // 0x17b744: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B888u;
    if (runtime->hasFunction(0x17B888u)) {
        auto targetFn = runtime->lookupFunction(0x17B888u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B888_0x17b888(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B748u;
label_17b748:
    // 0x17b748: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B748u;
    SET_GPR_U32(ctx, 31, 0x17B750u);
    ctx->pc = 0x17B74Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B748u;
            // 0x17b74c: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B750u; }
        if (ctx->pc != 0x17B750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B750u; }
        if (ctx->pc != 0x17B750u) { return; }
    }
    ctx->pc = 0x17B750u;
label_17b750:
    // 0x17b750: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b750u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b754: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b754u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b758: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b758u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b75c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b75cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b760: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b760u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b764: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b764u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b768: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17b768u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b76c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b76cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b770: 0x805ee22  j           func_17B888
    ctx->pc = 0x17B770u;
    ctx->pc = 0x17B774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B770u;
            // 0x17b774: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B888u;
    if (runtime->hasFunction(0x17B888u)) {
        auto targetFn = runtime->lookupFunction(0x17B888u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B888_0x17b888(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B778u;
label_17b778:
    // 0x17b778: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B778u;
    SET_GPR_U32(ctx, 31, 0x17B780u);
    ctx->pc = 0x17B77Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B778u;
            // 0x17b77c: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B780u; }
        if (ctx->pc != 0x17B780u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B780u; }
        if (ctx->pc != 0x17B780u) { return; }
    }
    ctx->pc = 0x17B780u;
label_17b780:
    // 0x17b780: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b780u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b784: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b784u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b788: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b788u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b78c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b78cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b790: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b790u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b794: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b794u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b798: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17b798u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b79c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b79cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b7a0: 0x805ee22  j           func_17B888
    ctx->pc = 0x17B7A0u;
    ctx->pc = 0x17B7A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B7A0u;
            // 0x17b7a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B888u;
    if (runtime->hasFunction(0x17B888u)) {
        auto targetFn = runtime->lookupFunction(0x17B888u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B888_0x17b888(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B7A8u;
label_17b7a8:
    // 0x17b7a8: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B7A8u;
    SET_GPR_U32(ctx, 31, 0x17B7B0u);
    ctx->pc = 0x17B7ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B7A8u;
            // 0x17b7ac: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B7B0u; }
        if (ctx->pc != 0x17B7B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B7B0u; }
        if (ctx->pc != 0x17B7B0u) { return; }
    }
    ctx->pc = 0x17B7B0u;
label_17b7b0:
    // 0x17b7b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b7b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b7b4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b7b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b7b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b7b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b7bc: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b7bcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b7c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b7c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b7c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b7c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b7c8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b7c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b7cc: 0x805ee58  j           func_17B960
    ctx->pc = 0x17B7CCu;
    ctx->pc = 0x17B7D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B7CCu;
            // 0x17b7d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B960u;
    if (runtime->hasFunction(0x17B960u)) {
        auto targetFn = runtime->lookupFunction(0x17B960u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B960_0x17b960(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B7D4u;
    // 0x17b7d4: 0x0  nop
    ctx->pc = 0x17b7d4u;
    // NOP
label_17b7d8:
    // 0x17b7d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b7d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_17b7dc:
    // 0x17b7dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b7dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b7e0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b7e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b7e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b7e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b7e8: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17b7e8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17b7ec: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b7ecu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b7f0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b7f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b7f4: 0x24c60f08  addiu       $a2, $a2, 0xF08
    ctx->pc = 0x17b7f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 3848));
    // 0x17b7f8: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17B7F8u;
    ctx->pc = 0x17B7FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B7F8u;
            // 0x17b7fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B800u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
