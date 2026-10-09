#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161C18
// Address: 0x161c18 - 0x161c74
void sub_00161C18_0x161c18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161C18_0x161c18");
#endif

    switch (ctx->pc) {
        case 0x161c54u: goto label_161c54;
        default: break;
    }

    ctx->pc = 0x161c18u;

    // 0x161c18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x161c18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x161c1c: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x161c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x161c20: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x161c20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x161c24: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x161c24u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161c28: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x161c28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x161c2c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x161c2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161c30: 0x51102a  slt         $v0, $v0, $s1
    ctx->pc = 0x161c30u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x161c34: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x161c34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x161c38: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x161c38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x161c3c: 0x249000f4  addiu       $s0, $a0, 0xF4
    ctx->pc = 0x161c3cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 244));
    // 0x161c40: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x161C40u;
    {
        const bool branch_taken_0x161c40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161C40u;
            // 0x161c44: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161c40) {
            ctx->pc = 0x161C54u;
            goto label_161c54;
        }
    }
    ctx->pc = 0x161C48u;
    // 0x161c48: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161c48u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161c4c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161C4Cu;
    SET_GPR_U32(ctx, 31, 0x161C54u);
    ctx->pc = 0x161C50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161C4Cu;
            // 0x161c50: 0x2484fec0  addiu       $a0, $a0, -0x140 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161C54u; }
        if (ctx->pc != 0x161C54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161C54u; }
        if (ctx->pc != 0x161C54u) { return; }
    }
    ctx->pc = 0x161C54u;
label_161c54:
    // 0x161c54: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x161c54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x161c58: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x161c58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x161c5c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x161c5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161c60: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161c60u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161c64: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x161c64u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161c68: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x161c68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x161c6c: 0x3e00008  jr          $ra
    ctx->pc = 0x161C6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161C6Cu;
            // 0x161c70: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161C54u: goto label_161c54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161C74u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
