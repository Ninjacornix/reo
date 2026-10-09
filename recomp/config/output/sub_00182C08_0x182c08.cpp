#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182C08
// Address: 0x182c08 - 0x182c48
void sub_00182C08_0x182c08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182C08_0x182c08");
#endif

    switch (ctx->pc) {
        case 0x182c1cu: goto label_182c1c;
        default: break;
    }

    ctx->pc = 0x182c08u;

    // 0x182c08: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x182c08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x182c0c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x182c0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x182c10: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x182c10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x182c14: 0xc060aa6  jal         func_182A98
    ctx->pc = 0x182C14u;
    SET_GPR_U32(ctx, 31, 0x182C1Cu);
    ctx->pc = 0x182C18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182C14u;
            // 0x182c18: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182A98u;
    if (runtime->hasFunction(0x182A98u)) {
        auto targetFn = runtime->lookupFunction(0x182A98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182C1Cu; }
        if (ctx->pc != 0x182C1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182A98_0x182a98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182C1Cu; }
        if (ctx->pc != 0x182C1Cu) { return; }
    }
    ctx->pc = 0x182C1Cu;
label_182c1c:
    // 0x182c1c: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x182c1cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x182c20: 0x3c048101  lui         $a0, 0x8101
    ctx->pc = 0x182c20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33025 << 16));
    // 0x182c24: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x182c24u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x182c28: 0x14430002  bne         $v0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x182C28u;
    {
        const bool branch_taken_0x182c28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x182C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182C28u;
            // 0x182c2c: 0x34849002  ori         $a0, $a0, 0x9002 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)36866);
        ctx->in_delay_slot = false;
        if (branch_taken_0x182c28) {
            ctx->pc = 0x182C34u;
            goto label_182c34;
        }
    }
    ctx->pc = 0x182C30u;
    // 0x182c30: 0xae040000  sw          $a0, 0x0($s0)
    ctx->pc = 0x182c30u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 4));
label_182c34:
    // 0x182c34: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x182c34u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x182c38: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x182c38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x182c3c: 0x3e00008  jr          $ra
    ctx->pc = 0x182C3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182C3Cu;
            // 0x182c40: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182C1Cu: goto label_182c1c;
            case 0x182C34u: goto label_182c34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182C44u;
    // 0x182c44: 0x0  nop
    ctx->pc = 0x182c44u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
