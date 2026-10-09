#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E4B8
// Address: 0x12e4b8 - 0x12e550
void sub_0012E4B8_0x12e4b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E4B8_0x12e4b8");
#endif

    switch (ctx->pc) {
        case 0x12e528u: goto label_12e528;
        case 0x12e538u: goto label_12e538;
        default: break;
    }

    ctx->pc = 0x12e4b8u;

    // 0x12e4b8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12e4b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12e4bc: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x12e4bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x12e4c0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12e4c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12e4c4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12e4c4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e4c8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12e4c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12e4cc: 0x50a00001  beql        $a1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x12E4CCu;
    {
        const bool branch_taken_0x12e4cc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x12e4cc) {
            ctx->pc = 0x12E4D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12E4CCu;
            // 0x12e4d0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x12E4D4u;
            goto label_12e4d4;
        }
    }
    ctx->pc = 0x12E4D4u;
label_12e4d4:
    // 0x12e4d4: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x12e4d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x12e4d8: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x12e4d8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12e4dc: 0x8e070078  lw          $a3, 0x78($s0)
    ctx->pc = 0x12e4dcu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x12e4e0: 0x8c838758  lw          $v1, -0x78A8($a0)
    ctx->pc = 0x12e4e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294936408)));
    // 0x12e4e4: 0x24e2ffff  addiu       $v0, $a3, -0x1
    ctx->pc = 0x12e4e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x12e4e8: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x12e4e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e4ec: 0x45001a  div         $zero, $v0, $a1
    ctx->pc = 0x12e4ecu;
    { int32_t divisor = GPR_S32(ctx, 5);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x12e4f0: 0x1012  mflo        $v0
    ctx->pc = 0x12e4f0u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x12e4f4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x12e4f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12e4f8: 0x43282a  slt         $a1, $v0, $v1
    ctx->pc = 0x12e4f8u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12e4fc: 0x45180b  movn        $v1, $v0, $a1
    ctx->pc = 0x12e4fcu;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 2));
    // 0x12e500: 0x28660001  slti        $a2, $v1, 0x1
    ctx->pc = 0x12e500u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)1) ? 1 : 0);
    // 0x12e504: 0x106180b  movn        $v1, $t0, $a2
    ctx->pc = 0x12e504u;
    if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 8));
    // 0x12e508: 0x14e00005  bnez        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x12E508u;
    {
        const bool branch_taken_0x12e508 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x12E50Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E508u;
            // 0x12e50c: 0xa603007c  sh          $v1, 0x7C($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 124), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e508) {
            ctx->pc = 0x12E520u;
            goto label_12e520;
        }
    }
    ctx->pc = 0x12E510u;
    // 0x12e510: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x12e510u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x12e514: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x12E514u;
    {
        const bool branch_taken_0x12e514 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E514u;
            // 0x12e518: 0xdc22adf8  ld          $v0, -0x5208($at) (Delay Slot)
        SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294946296)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e514) {
            ctx->pc = 0x12E538u;
            goto label_12e538;
        }
    }
    ctx->pc = 0x12E51Cu;
    // 0x12e51c: 0x0  nop
    ctx->pc = 0x12e51cu;
    // NOP
label_12e520:
    // 0x12e520: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x12E520u;
    SET_GPR_U32(ctx, 31, 0x12E528u);
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E528u; }
        if (ctx->pc != 0x12E528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E528u; }
        if (ctx->pc != 0x12E528u) { return; }
    }
    ctx->pc = 0x12E528u;
label_12e528:
    // 0x12e528: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x12e528u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x12e52c: 0xdc24ae00  ld          $a0, -0x5200($at)
    ctx->pc = 0x12e52cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 1), 4294946304)));
    // 0x12e530: 0xc04480e  jal         func_112038
    ctx->pc = 0x12E530u;
    SET_GPR_U32(ctx, 31, 0x12E538u);
    ctx->pc = 0x12E534u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12E530u;
            // 0x12e534: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E538u; }
        if (ctx->pc != 0x12E538u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E538u; }
        if (ctx->pc != 0x12E538u) { return; }
    }
    ctx->pc = 0x12E538u;
label_12e538:
    // 0x12e538: 0xfe020080  sd          $v0, 0x80($s0)
    ctx->pc = 0x12e538u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 128), GPR_U64(ctx, 2));
    // 0x12e53c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12e53cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e540: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12e540u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12e544: 0x3e00008  jr          $ra
    ctx->pc = 0x12E544u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E544u;
            // 0x12e548: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E4D4u: goto label_12e4d4;
            case 0x12E520u: goto label_12e520;
            case 0x12E528u: goto label_12e528;
            case 0x12E538u: goto label_12e538;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12E54Cu;
    // 0x12e54c: 0x0  nop
    ctx->pc = 0x12e54cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
