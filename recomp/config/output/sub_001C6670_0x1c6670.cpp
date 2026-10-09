#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6670
// Address: 0x1c6670 - 0x1c67b0
void sub_001C6670_0x1c6670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6670_0x1c6670");
#endif

    switch (ctx->pc) {
        case 0x1c6680u: goto label_1c6680;
        case 0x1c66a0u: goto label_1c66a0;
        case 0x1c6754u: goto label_1c6754;
        case 0x1c6780u: goto label_1c6780;
        default: break;
    }

    ctx->pc = 0x1c6670u;

    // 0x1c6670: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c6670u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c6674: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c6674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c6678: 0xc072204  jal         func_1C8810
    ctx->pc = 0x1C6678u;
    SET_GPR_U32(ctx, 31, 0x1C6680u);
    ctx->pc = 0x1C667Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6678u;
            // 0x1c667c: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8810u;
    if (runtime->hasFunction(0x1C8810u)) {
        auto targetFn = runtime->lookupFunction(0x1C8810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6680u; }
        if (ctx->pc != 0x1C6680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8810_0x1c8810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6680u; }
        if (ctx->pc != 0x1C6680u) { return; }
    }
    ctx->pc = 0x1C6680u;
label_1c6680:
    // 0x1c6680: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c6680u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c6684: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1c6684u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c6688: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6688u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C668Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6688u;
            // 0x1c668c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6680u: goto label_1c6680;
            case 0x1C66A0u: goto label_1c66a0;
            case 0x1C6754u: goto label_1c6754;
            case 0x1C6780u: goto label_1c6780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6690u;
    // 0x1c6690: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c6690u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c6694: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c6694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c6698: 0xc072208  jal         func_1C8820
    ctx->pc = 0x1C6698u;
    SET_GPR_U32(ctx, 31, 0x1C66A0u);
    ctx->pc = 0x1C669Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6698u;
            // 0x1c669c: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8820u;
    if (runtime->hasFunction(0x1C8820u)) {
        auto targetFn = runtime->lookupFunction(0x1C8820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C66A0u; }
        if (ctx->pc != 0x1C66A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8820_0x1c8820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C66A0u; }
        if (ctx->pc != 0x1C66A0u) { return; }
    }
    ctx->pc = 0x1C66A0u;
label_1c66a0:
    // 0x1c66a0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c66a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c66a4: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1c66a4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c66a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C66A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C66ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C66A8u;
            // 0x1c66ac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6680u: goto label_1c6680;
            case 0x1C66A0u: goto label_1c66a0;
            case 0x1C6754u: goto label_1c6754;
            case 0x1C6780u: goto label_1c6780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C66B0u;
    // 0x1c66b0: 0x948501b0  lhu         $a1, 0x1B0($a0)
    ctx->pc = 0x1c66b0u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 432)));
    // 0x1c66b4: 0x8c8301a8  lw          $v1, 0x1A8($a0)
    ctx->pc = 0x1c66b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 424)));
    // 0x1c66b8: 0x8c8201ac  lw          $v0, 0x1AC($a0)
    ctx->pc = 0x1c66b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 428)));
    // 0x1c66bc: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1c66bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1c66c0: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1c66c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1c66c4: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x1c66c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c66c8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c66c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c66cc: 0x45001a  div         $zero, $v0, $a1
    ctx->pc = 0x1c66ccu;
    { int32_t divisor = GPR_S32(ctx, 5);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1c66d0: 0x0  nop
    ctx->pc = 0x1c66d0u;
    // NOP
    // 0x1c66d4: 0x0  nop
    ctx->pc = 0x1c66d4u;
    // NOP
    // 0x1c66d8: 0x1012  mflo        $v0
    ctx->pc = 0x1c66d8u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1c66dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1C66DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C66E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C66DCu;
            // 0x1c66e0: 0x304200ff  andi        $v0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6680u: goto label_1c6680;
            case 0x1C66A0u: goto label_1c66a0;
            case 0x1C6754u: goto label_1c6754;
            case 0x1C6780u: goto label_1c6780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C66E4u;
    // 0x1c66e4: 0x0  nop
    ctx->pc = 0x1c66e4u;
    // NOP
    // 0x1c66e8: 0x0  nop
    ctx->pc = 0x1c66e8u;
    // NOP
    // 0x1c66ec: 0x0  nop
    ctx->pc = 0x1c66ecu;
    // NOP
    // 0x1c66f0: 0xac8501a8  sw          $a1, 0x1A8($a0)
    ctx->pc = 0x1c66f0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 424), GPR_U32(ctx, 5));
    // 0x1c66f4: 0x30e200ff  andi        $v0, $a3, 0xFF
    ctx->pc = 0x1c66f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x1c66f8: 0xac8501ac  sw          $a1, 0x1AC($a0)
    ctx->pc = 0x1c66f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 428), GPR_U32(ctx, 5));
    // 0x1c66fc: 0xa48601b0  sh          $a2, 0x1B0($a0)
    ctx->pc = 0x1c66fcu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 432), (uint16_t)GPR_U32(ctx, 6));
    // 0x1c6700: 0xa48201b4  sh          $v0, 0x1B4($a0)
    ctx->pc = 0x1c6700u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 436), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c6704: 0x948601b0  lhu         $a2, 0x1B0($a0)
    ctx->pc = 0x1c6704u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 432)));
    // 0x1c6708: 0x8c8401a8  lw          $a0, 0x1A8($a0)
    ctx->pc = 0x1c6708u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 424)));
    // 0x1c670c: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1C670Cu;
    ctx->pc = 0x1C6710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C670Cu;
            // 0x1c6710: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6714u;
    // 0x1c6714: 0x0  nop
    ctx->pc = 0x1c6714u;
    // NOP
    // 0x1c6718: 0x0  nop
    ctx->pc = 0x1c6718u;
    // NOP
    // 0x1c671c: 0x0  nop
    ctx->pc = 0x1c671cu;
    // NOP
    // 0x1c6720: 0xac8501b8  sw          $a1, 0x1B8($a0)
    ctx->pc = 0x1c6720u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 440), GPR_U32(ctx, 5));
    // 0x1c6724: 0xac8501bc  sw          $a1, 0x1BC($a0)
    ctx->pc = 0x1c6724u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 444), GPR_U32(ctx, 5));
    // 0x1c6728: 0xa48601c0  sh          $a2, 0x1C0($a0)
    ctx->pc = 0x1c6728u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 448), (uint16_t)GPR_U32(ctx, 6));
    // 0x1c672c: 0x948601c0  lhu         $a2, 0x1C0($a0)
    ctx->pc = 0x1c672cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 448)));
    // 0x1c6730: 0x8c8401b8  lw          $a0, 0x1B8($a0)
    ctx->pc = 0x1c6730u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 440)));
    // 0x1c6734: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1C6734u;
    ctx->pc = 0x1C6738u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6734u;
            // 0x1c6738: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C673Cu;
    // 0x1c673c: 0x0  nop
    ctx->pc = 0x1c673cu;
    // NOP
    // 0x1c6740: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c6740u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c6744: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C6744u;
    {
        const bool branch_taken_0x1c6744 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6744u;
            // 0x1c6748: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c6744) {
            ctx->pc = 0x1C6754u;
            goto label_1c6754;
        }
    }
    ctx->pc = 0x1C674Cu;
    // 0x1c674c: 0xc07220c  jal         func_1C8830
    ctx->pc = 0x1C674Cu;
    SET_GPR_U32(ctx, 31, 0x1C6754u);
    ctx->pc = 0x1C6750u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C674Cu;
            // 0x1c6750: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8830u;
    {
        auto targetFn = runtime->lookupFunction(0x1C8830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6754u; }
        if (ctx->pc != 0x1C6754u) { return; }
    }
    ctx->pc = 0x1C6754u;
label_1c6754:
    // 0x1c6754: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c6754u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c6758: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6758u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C675Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6758u;
            // 0x1c675c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6680u: goto label_1c6680;
            case 0x1C66A0u: goto label_1c66a0;
            case 0x1C6754u: goto label_1c6754;
            case 0x1C6780u: goto label_1c6780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6760u;
    // 0x1c6760: 0xa48501e8  sh          $a1, 0x1E8($a0)
    ctx->pc = 0x1c6760u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 488), (uint16_t)GPR_U32(ctx, 5));
    // 0x1c6764: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6764u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6764u;
            // 0x1c6768: 0xa48001e0  sh          $zero, 0x1E0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 480), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6680u: goto label_1c6680;
            case 0x1C66A0u: goto label_1c66a0;
            case 0x1C6754u: goto label_1c6754;
            case 0x1C6780u: goto label_1c6780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C676Cu;
    // 0x1c676c: 0x0  nop
    ctx->pc = 0x1c676cu;
    // NOP
    // 0x1c6770: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c6770u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c6774: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c6774u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c6778: 0xc072210  jal         func_1C8840
    ctx->pc = 0x1C6778u;
    SET_GPR_U32(ctx, 31, 0x1C6780u);
    ctx->pc = 0x1C677Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6778u;
            // 0x1c677c: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8840u;
    if (runtime->hasFunction(0x1C8840u)) {
        auto targetFn = runtime->lookupFunction(0x1C8840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6780u; }
        if (ctx->pc != 0x1C6780u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8840_0x1c8840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6780u; }
        if (ctx->pc != 0x1C6780u) { return; }
    }
    ctx->pc = 0x1C6780u;
label_1c6780:
    // 0x1c6780: 0x3c02447a  lui         $v0, 0x447A
    ctx->pc = 0x1c6780u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17530 << 16));
    // 0x1c6784: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c6784u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c6788: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1c6788u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1c678c: 0x0  nop
    ctx->pc = 0x1c678cu;
    // NOP
    // 0x1c6790: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x1c6790u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1c6794: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6794u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6794u;
            // 0x1c6798: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6680u: goto label_1c6680;
            case 0x1C66A0u: goto label_1c66a0;
            case 0x1C6754u: goto label_1c6754;
            case 0x1C6780u: goto label_1c6780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C679Cu;
    // 0x1c679c: 0x0  nop
    ctx->pc = 0x1c679cu;
    // NOP
    // 0x1c67a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C67A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C67A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C67A0u;
            // 0x1c67a4: 0x908201ce  lbu         $v0, 0x1CE($a0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 462)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6680u: goto label_1c6680;
            case 0x1C66A0u: goto label_1c66a0;
            case 0x1C6754u: goto label_1c6754;
            case 0x1C6780u: goto label_1c6780;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C67A8u;
    // 0x1c67a8: 0x0  nop
    ctx->pc = 0x1c67a8u;
    // NOP
    // 0x1c67ac: 0x0  nop
    ctx->pc = 0x1c67acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
