#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B3920
// Address: 0x1b3920 - 0x1b39b0
void sub_001B3920_0x1b3920(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B3920_0x1b3920");
#endif

    switch (ctx->pc) {
        case 0x1b3984u: goto label_1b3984;
        case 0x1b3994u: goto label_1b3994;
        default: break;
    }

    ctx->pc = 0x1b3920u;

    // 0x1b3920: 0x27bdff10  addiu       $sp, $sp, -0xF0
    ctx->pc = 0x1b3920u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967056));
    // 0x1b3924: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b3924u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b3928: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b3928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b392c: 0x28620008  slti        $v0, $v1, 0x8
    ctx->pc = 0x1b392cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1b3930: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b3930u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b3934: 0xafa400a8  sw          $a0, 0xA8($sp)
    ctx->pc = 0x1b3934u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 168), GPR_U32(ctx, 4));
    // 0x1b3938: 0xffa500b8  sd          $a1, 0xB8($sp)
    ctx->pc = 0x1b3938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 5));
    // 0x1b393c: 0xffa600c0  sd          $a2, 0xC0($sp)
    ctx->pc = 0x1b393cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 6));
    // 0x1b3940: 0xffa700c8  sd          $a3, 0xC8($sp)
    ctx->pc = 0x1b3940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 200), GPR_U64(ctx, 7));
    // 0x1b3944: 0xffa800d0  sd          $t0, 0xD0($sp)
    ctx->pc = 0x1b3944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 8));
    // 0x1b3948: 0xffa900d8  sd          $t1, 0xD8($sp)
    ctx->pc = 0x1b3948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 216), GPR_U64(ctx, 9));
    // 0x1b394c: 0xffaa00e0  sd          $t2, 0xE0($sp)
    ctx->pc = 0x1b394cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 224), GPR_U64(ctx, 10));
    // 0x1b3950: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B3950u;
    {
        const bool branch_taken_0x1b3950 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B3954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3950u;
            // 0x1b3954: 0xffab00e8  sd          $t3, 0xE8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 232), GPR_U64(ctx, 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3950) {
            ctx->pc = 0x1B3960u;
            goto label_1b3960;
        }
    }
    ctx->pc = 0x1B3958u;
    // 0x1b3958: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B3958u;
    {
        const bool branch_taken_0x1b3958 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B395Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3958u;
            // 0x1b395c: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3958) {
            ctx->pc = 0x1B396Cu;
            goto label_1b396c;
        }
    }
    ctx->pc = 0x1B3960u;
label_1b3960:
    // 0x1b3960: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1b3960u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1b3964: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1b3964u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b3968: 0x218c0  sll         $v1, $v0, 3
    ctx->pc = 0x1b3968u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_1b396c:
    // 0x1b396c: 0x8fa500a8  lw          $a1, 0xA8($sp)
    ctx->pc = 0x1b396cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1b3970: 0x27a200f0  addiu       $v0, $sp, 0xF0
    ctx->pc = 0x1b3970u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1b3974: 0x27b00020  addiu       $s0, $sp, 0x20
    ctx->pc = 0x1b3974u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1b3978: 0x433023  subu        $a2, $v0, $v1
    ctx->pc = 0x1b3978u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b397c: 0xc043e20  jal         func_10F880
    ctx->pc = 0x1B397Cu;
    SET_GPR_U32(ctx, 31, 0x1B3984u);
    ctx->pc = 0x1B3980u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B397Cu;
            // 0x1b3980: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10F880u;
    if (runtime->hasFunction(0x10F880u)) {
        auto targetFn = runtime->lookupFunction(0x10F880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3984u; }
        if (ctx->pc != 0x1B3984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F880_0x10f880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3984u; }
        if (ctx->pc != 0x1B3984u) { return; }
    }
    ctx->pc = 0x1B3984u;
label_1b3984:
    // 0x1b3984: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x1b3984u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1b3988: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1b3988u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1b398c: 0xc06ce6c  jal         func_1B39B0
    ctx->pc = 0x1B398Cu;
    SET_GPR_U32(ctx, 31, 0x1B3994u);
    ctx->pc = 0x1B3990u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B398Cu;
            // 0x1b3990: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B39B0u;
    if (runtime->hasFunction(0x1B39B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B39B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3994u; }
        if (ctx->pc != 0x1B3994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B39B0_0x1b39b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B3994u; }
        if (ctx->pc != 0x1B3994u) { return; }
    }
    ctx->pc = 0x1B3994u;
label_1b3994:
    // 0x1b3994: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b3994u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b3998: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b3998u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b399c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B399Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B39A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B399Cu;
            // 0x1b39a0: 0x27bd00f0  addiu       $sp, $sp, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B3960u: goto label_1b3960;
            case 0x1B396Cu: goto label_1b396c;
            case 0x1B3984u: goto label_1b3984;
            case 0x1B3994u: goto label_1b3994;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B39A4u;
    // 0x1b39a4: 0x0  nop
    ctx->pc = 0x1b39a4u;
    // NOP
    // 0x1b39a8: 0x0  nop
    ctx->pc = 0x1b39a8u;
    // NOP
    // 0x1b39ac: 0x0  nop
    ctx->pc = 0x1b39acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
