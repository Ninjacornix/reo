#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A558
// Address: 0x17a558 - 0x17a598
void sub_0017A558_0x17a558(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A558_0x17a558");
#endif

    switch (ctx->pc) {
        case 0x17a56cu: goto label_17a56c;
        default: break;
    }

    ctx->pc = 0x17a558u;

    // 0x17a558: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17a558u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17a55c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a55cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a560: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x17a560u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17a564: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x17A564u;
    SET_GPR_U32(ctx, 31, 0x17A56Cu);
    ctx->pc = 0x17A568u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A564u;
            // 0x17a568: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A56Cu; }
        if (ctx->pc != 0x17A56Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A56Cu; }
        if (ctx->pc != 0x17A56Cu) { return; }
    }
    ctx->pc = 0x17A56Cu;
label_17a56c:
    // 0x17a56c: 0x240300c0  addiu       $v1, $zero, 0xC0
    ctx->pc = 0x17a56cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x17a570: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x17A570u;
    {
        const bool branch_taken_0x17a570 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17A574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A570u;
            // 0x17a574: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a570) {
            ctx->pc = 0x17A588u;
            goto label_17a588;
        }
    }
    ctx->pc = 0x17A578u;
    // 0x17a578: 0x92030020  lbu         $v1, 0x20($s0)
    ctx->pc = 0x17a578u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x17a57c: 0x3102b  sltu        $v0, $zero, $v1
    ctx->pc = 0x17a57cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x17a580: 0x2c630002  sltiu       $v1, $v1, 0x2
    ctx->pc = 0x17a580u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x17a584: 0x3100a  movz        $v0, $zero, $v1
    ctx->pc = 0x17a584u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
label_17a588:
    // 0x17a588: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a588u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a58c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17a58cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a590: 0x3e00008  jr          $ra
    ctx->pc = 0x17A590u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A590u;
            // 0x17a594: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A56Cu: goto label_17a56c;
            case 0x17A588u: goto label_17a588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A598u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
