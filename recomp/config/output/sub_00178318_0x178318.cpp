#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178318
// Address: 0x178318 - 0x178378
void sub_00178318_0x178318(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178318_0x178318");
#endif

    switch (ctx->pc) {
        case 0x17835cu: goto label_17835c;
        default: break;
    }

    ctx->pc = 0x178318u;

    // 0x178318: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x178318u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17831c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17831cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x178320: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x178320u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178324: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x178324u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x178328: 0x26070014  addiu       $a3, $s0, 0x14
    ctx->pc = 0x178328u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x17832c: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x17832cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x178330: 0x8ce60000  lw          $a2, 0x0($a3)
    ctx->pc = 0x178330u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x178334: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x178334u;
    {
        const bool branch_taken_0x178334 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x178334) {
            ctx->pc = 0x178338u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x178334u;
            // 0x178338: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x17833Cu;
            goto label_17833c;
        }
    }
    ctx->pc = 0x17833Cu;
label_17833c:
    // 0x17833c: 0xc3001a  div         $zero, $a2, $v1
    ctx->pc = 0x17833cu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 6);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x178340: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x178340u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x178344: 0x1010  mfhi        $v0
    ctx->pc = 0x178344u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x178348: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x178348u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x17834c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x17834cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x178350: 0xac450018  sw          $a1, 0x18($v0)
    ctx->pc = 0x178350u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 5));
    // 0x178354: 0xc05e0f6  jal         func_1783D8
    ctx->pc = 0x178354u;
    SET_GPR_U32(ctx, 31, 0x17835Cu);
    ctx->pc = 0x178358u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178354u;
            // 0x178358: 0xace60000  sw          $a2, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1783D8u;
    if (runtime->hasFunction(0x1783D8u)) {
        auto targetFn = runtime->lookupFunction(0x1783D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17835Cu; }
        if (ctx->pc != 0x17835Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001783D8_0x1783d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17835Cu; }
        if (ctx->pc != 0x17835Cu) { return; }
    }
    ctx->pc = 0x17835Cu;
label_17835c:
    // 0x17835c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x17835cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178360: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x178360u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178364: 0xae0301a8  sw          $v1, 0x1A8($s0)
    ctx->pc = 0x178364u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 424), GPR_U32(ctx, 3));
    // 0x178368: 0xae0301a4  sw          $v1, 0x1A4($s0)
    ctx->pc = 0x178368u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 420), GPR_U32(ctx, 3));
    // 0x17836c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17836cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178370: 0x3e00008  jr          $ra
    ctx->pc = 0x178370u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178370u;
            // 0x178374: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17833Cu: goto label_17833c;
            case 0x17835Cu: goto label_17835c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178378u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
