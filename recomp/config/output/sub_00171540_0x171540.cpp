#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171540
// Address: 0x171540 - 0x1715f0
void sub_00171540_0x171540(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171540_0x171540");
#endif

    switch (ctx->pc) {
        case 0x17155cu: goto label_17155c;
        default: break;
    }

    ctx->pc = 0x171540u;

    // 0x171540: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x171540u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x171544: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x171544u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x171548: 0x8c43f1c0  lw          $v1, -0xE40($v0)
    ctx->pc = 0x171548u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294963648)));
    // 0x17154c: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x17154Cu;
    {
        const bool branch_taken_0x17154c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x171550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17154Cu;
            // 0x171550: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17154c) {
            ctx->pc = 0x171578u;
            goto label_171578;
        }
    }
    ctx->pc = 0x171554u;
    // 0x171554: 0xc051e8a  jal         func_147A28
    ctx->pc = 0x171554u;
    SET_GPR_U32(ctx, 31, 0x17155Cu);
    ctx->pc = 0x147A28u;
    if (runtime->hasFunction(0x147A28u)) {
        auto targetFn = runtime->lookupFunction(0x147A28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17155Cu; }
        if (ctx->pc != 0x17155Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00147A28_0x147a28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17155Cu; }
        if (ctx->pc != 0x17155Cu) { return; }
    }
    ctx->pc = 0x17155Cu;
label_17155c:
    // 0x17155c: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x17155cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x171560: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x171560u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171564: 0x248460d8  addiu       $a0, $a0, 0x60D8
    ctx->pc = 0x171564u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24792));
    // 0x171568: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x171568u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17156c: 0x24060048  addiu       $a2, $zero, 0x48
    ctx->pc = 0x17156cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x171570: 0x8055880  j           func_156200
    ctx->pc = 0x171570u;
    ctx->pc = 0x171574u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171570u;
            // 0x171574: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x156200u;
    if (runtime->hasFunction(0x156200u)) {
        auto targetFn = runtime->lookupFunction(0x156200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00156200_0x156200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x171578u;
label_171578:
    // 0x171578: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x171578u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17157c: 0x3e00008  jr          $ra
    ctx->pc = 0x17157Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17157Cu;
            // 0x171580: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17155Cu: goto label_17155c;
            case 0x171578u: goto label_171578;
            case 0x1715C8u: goto label_1715c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x171584u;
    // 0x171584: 0x0  nop
    ctx->pc = 0x171584u;
    // NOP
    // 0x171588: 0x8c891b30  lw          $t1, 0x1B30($a0)
    ctx->pc = 0x171588u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x17158c: 0x25290a48  addiu       $t1, $t1, 0xA48
    ctx->pc = 0x17158cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 2632));
    // 0x171590: 0x8d230018  lw          $v1, 0x18($t1)
    ctx->pc = 0x171590u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 24)));
    // 0x171594: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x171594u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x171598: 0x8d22000c  lw          $v0, 0xC($t1)
    ctx->pc = 0x171598u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 12)));
    // 0x17159c: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x17159cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x1715a0: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x1715a0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x1715a4: 0x8d240010  lw          $a0, 0x10($t1)
    ctx->pc = 0x1715a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x1715a8: 0x8d23000c  lw          $v1, 0xC($t1)
    ctx->pc = 0x1715a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 12)));
    // 0x1715ac: 0x8d250014  lw          $a1, 0x14($t1)
    ctx->pc = 0x1715acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 20)));
    // 0x1715b0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1715b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1715b4: 0x8d220018  lw          $v0, 0x18($t1)
    ctx->pc = 0x1715b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 24)));
    // 0x1715b8: 0x31ac0  sll         $v1, $v1, 11
    ctx->pc = 0x1715b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x1715bc: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1715bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1715c0: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1715C0u;
    {
        const bool branch_taken_0x1715c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1715c0) {
            ctx->pc = 0x1715C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1715C0u;
            // 0x1715c4: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1715C8u;
            goto label_1715c8;
        }
    }
    ctx->pc = 0x1715C8u;
label_1715c8:
    // 0x1715c8: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1715c8u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1715cc: 0x2010  mfhi        $a0
    ctx->pc = 0x1715ccu;
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0x1715d0: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x1715d0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x1715d4: 0x8d220010  lw          $v0, 0x10($t1)
    ctx->pc = 0x1715d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x1715d8: 0x8d230014  lw          $v1, 0x14($t1)
    ctx->pc = 0x1715d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 20)));
    // 0x1715dc: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x1715dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x1715e0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1715e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1715e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1715E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1715E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1715E4u;
            // 0x1715e8: 0xad020000  sw          $v0, 0x0($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17155Cu: goto label_17155c;
            case 0x171578u: goto label_171578;
            case 0x1715C8u: goto label_1715c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1715ECu;
    // 0x1715ec: 0x0  nop
    ctx->pc = 0x1715ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
