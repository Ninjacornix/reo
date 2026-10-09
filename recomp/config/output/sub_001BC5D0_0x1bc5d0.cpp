#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BC5D0
// Address: 0x1bc5d0 - 0x1bc698
void sub_001BC5D0_0x1bc5d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BC5D0_0x1bc5d0");
#endif

    switch (ctx->pc) {
        case 0x1bc604u: goto label_1bc604;
        case 0x1bc618u: goto label_1bc618;
        case 0x1bc668u: goto label_1bc668;
        case 0x1bc674u: goto label_1bc674;
        case 0x1bc680u: goto label_1bc680;
        case 0x1bc688u: goto label_1bc688;
        default: break;
    }

    ctx->pc = 0x1bc5d0u;

    // 0x1bc5d0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1bc5d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1bc5d4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bc5d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bc5d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bc5d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bc5dc: 0x24030080  addiu       $v1, $zero, 0x80
    ctx->pc = 0x1bc5dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1bc5e0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bc5e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bc5e4: 0x903043f0  lbu         $s0, 0x43F0($at)
    ctx->pc = 0x1bc5e4u;
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17392)));
    // 0x1bc5e8: 0x12030027  beq         $s0, $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x1BC5E8u;
    {
        const bool branch_taken_0x1bc5e8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BC5ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC5E8u;
            // 0x1bc5ec: 0x2e010081  sltiu       $at, $s0, 0x81 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)129) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc5e8) {
            ctx->pc = 0x1BC688u;
            goto label_1bc688;
        }
    }
    ctx->pc = 0x1BC5F0u;
    // 0x1bc5f0: 0x14200007  bnez        $at, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BC5F0u;
    {
        const bool branch_taken_0x1bc5f0 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BC5F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC5F0u;
            // 0x1bc5f4: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc5f0) {
            ctx->pc = 0x1BC610u;
            goto label_1bc610;
        }
    }
    ctx->pc = 0x1BC5F8u;
    // 0x1bc5f8: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1bc5f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1bc5fc: 0xc06bc78  jal         func_1AF1E0
    ctx->pc = 0x1BC5FCu;
    SET_GPR_U32(ctx, 31, 0x1BC604u);
    ctx->pc = 0x1BC600u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC5FCu;
            // 0x1bc600: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF1E0u;
    if (runtime->hasFunction(0x1AF1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC604u; }
        if (ctx->pc != 0x1BC604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF1E0_0x1af1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC604u; }
        if (ctx->pc != 0x1BC604u) { return; }
    }
    ctx->pc = 0x1BC604u;
label_1bc604:
    // 0x1bc604: 0x2610ff80  addiu       $s0, $s0, -0x80
    ctx->pc = 0x1bc604u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967168));
    // 0x1bc608: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1BC608u;
    {
        const bool branch_taken_0x1bc608 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC60Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC608u;
            // 0x1bc60c: 0x240500ff  addiu       $a1, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc608) {
            ctx->pc = 0x1BC628u;
            goto label_1bc628;
        }
    }
    ctx->pc = 0x1BC610u;
label_1bc610:
    // 0x1bc610: 0xc06bc78  jal         func_1AF1E0
    ctx->pc = 0x1BC610u;
    SET_GPR_U32(ctx, 31, 0x1BC618u);
    ctx->pc = 0x1BC614u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC610u;
            // 0x1bc614: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF1E0u;
    if (runtime->hasFunction(0x1AF1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC618u; }
        if (ctx->pc != 0x1BC618u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF1E0_0x1af1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC618u; }
        if (ctx->pc != 0x1BC618u) { return; }
    }
    ctx->pc = 0x1BC618u;
label_1bc618:
    // 0x1bc618: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1bc618u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1bc61c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bc61cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bc620: 0x508023  subu        $s0, $v0, $s0
    ctx->pc = 0x1bc620u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1bc624: 0x108040  sll         $s0, $s0, 1
    ctx->pc = 0x1bc624u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
label_1bc628:
    // 0x1bc628: 0x24020280  addiu       $v0, $zero, 0x280
    ctx->pc = 0x1bc628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1bc62c: 0x101e00  sll         $v1, $s0, 24
    ctx->pc = 0x1bc62cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 24));
    // 0x1bc630: 0xa7a20024  sh          $v0, 0x24($sp)
    ctx->pc = 0x1bc630u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 36), (uint16_t)GPR_U32(ctx, 2));
    // 0x1bc634: 0x2404005f  addiu       $a0, $zero, 0x5F
    ctx->pc = 0x1bc634u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
    // 0x1bc638: 0x240201c0  addiu       $v0, $zero, 0x1C0
    ctx->pc = 0x1bc638u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 448));
    // 0x1bc63c: 0xa7a00022  sh          $zero, 0x22($sp)
    ctx->pc = 0x1bc63cu;
    WRITE16(ADD32(GPR_U32(ctx, 29), 34), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bc640: 0xa7a20026  sh          $v0, 0x26($sp)
    ctx->pc = 0x1bc640u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 38), (uint16_t)GPR_U32(ctx, 2));
    // 0x1bc644: 0x51400  sll         $v0, $a1, 16
    ctx->pc = 0x1bc644u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x1bc648: 0xa7a00020  sh          $zero, 0x20($sp)
    ctx->pc = 0x1bc648u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 32), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bc64c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1bc64cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1bc650: 0x51200  sll         $v0, $a1, 8
    ctx->pc = 0x1bc650u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x1bc654: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1bc654u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1bc658: 0xa21025  or          $v0, $a1, $v0
    ctx->pc = 0x1bc658u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x1bc65c: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1bc65cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1bc660: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BC660u;
    SET_GPR_U32(ctx, 31, 0x1BC668u);
    ctx->pc = 0x1BC664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC660u;
            // 0x1bc664: 0xafa20028  sw          $v0, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC668u; }
        if (ctx->pc != 0x1BC668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC668u; }
        if (ctx->pc != 0x1BC668u) { return; }
    }
    ctx->pc = 0x1BC668u;
label_1bc668:
    // 0x1bc668: 0x24040060  addiu       $a0, $zero, 0x60
    ctx->pc = 0x1bc668u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x1bc66c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BC66Cu;
    SET_GPR_U32(ctx, 31, 0x1BC674u);
    ctx->pc = 0x1BC670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC66Cu;
            // 0x1bc670: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC674u; }
        if (ctx->pc != 0x1BC674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC674u; }
        if (ctx->pc != 0x1BC674u) { return; }
    }
    ctx->pc = 0x1BC674u;
label_1bc674:
    // 0x1bc674: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x1bc674u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1bc678: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BC678u;
    SET_GPR_U32(ctx, 31, 0x1BC680u);
    ctx->pc = 0x1BC67Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC678u;
            // 0x1bc67c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC680u; }
        if (ctx->pc != 0x1BC680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC680u; }
        if (ctx->pc != 0x1BC680u) { return; }
    }
    ctx->pc = 0x1BC680u;
label_1bc680:
    // 0x1bc680: 0xc06aed8  jal         func_1ABB60
    ctx->pc = 0x1BC680u;
    SET_GPR_U32(ctx, 31, 0x1BC688u);
    ctx->pc = 0x1BC684u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC680u;
            // 0x1bc684: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ABB60u;
    if (runtime->hasFunction(0x1ABB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ABB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC688u; }
        if (ctx->pc != 0x1BC688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ABB60_0x1abb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC688u; }
        if (ctx->pc != 0x1BC688u) { return; }
    }
    ctx->pc = 0x1BC688u;
label_1bc688:
    // 0x1bc688: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bc688u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bc68c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bc68cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bc690: 0x3e00008  jr          $ra
    ctx->pc = 0x1BC690u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BC694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC690u;
            // 0x1bc694: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BC604u: goto label_1bc604;
            case 0x1BC610u: goto label_1bc610;
            case 0x1BC618u: goto label_1bc618;
            case 0x1BC628u: goto label_1bc628;
            case 0x1BC668u: goto label_1bc668;
            case 0x1BC674u: goto label_1bc674;
            case 0x1BC680u: goto label_1bc680;
            case 0x1BC688u: goto label_1bc688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BC698u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
