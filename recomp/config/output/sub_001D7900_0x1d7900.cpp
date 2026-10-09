#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7900
// Address: 0x1d7900 - 0x1d7990
void sub_001D7900_0x1d7900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7900_0x1d7900");
#endif

    switch (ctx->pc) {
        case 0x1d7978u: goto label_1d7978;
        default: break;
    }

    ctx->pc = 0x1d7900u;

    // 0x1d7900: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d7900u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d7904: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1d7904u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7908: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d7908u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d790c: 0x30c4000f  andi        $a0, $a2, 0xF
    ctx->pc = 0x1d790cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
    // 0x1d7910: 0x4c10004  bgez        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D7910u;
    {
        const bool branch_taken_0x1d7910 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1D7914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7910u;
            // 0x1d7914: 0xffa00000  sd          $zero, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7910) {
            ctx->pc = 0x1D7924u;
            goto label_1d7924;
        }
    }
    ctx->pc = 0x1D7918u;
    // 0x1d7918: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D7918u;
    {
        const bool branch_taken_0x1d7918 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D791Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7918u;
            // 0x1d791c: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7918) {
            ctx->pc = 0x1D7928u;
            goto label_1d7928;
        }
    }
    ctx->pc = 0x1D7920u;
    // 0x1d7920: 0x2484fff0  addiu       $a0, $a0, -0x10
    ctx->pc = 0x1d7920u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967280));
label_1d7924:
    // 0x1d7924: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1d7924u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_1d7928:
    // 0x1d7928: 0x3103000f  andi        $v1, $t0, 0xF
    ctx->pc = 0x1d7928u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)15);
    // 0x1d792c: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x1d792cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1d7930: 0x5010004  bgez        $t0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D7930u;
    {
        const bool branch_taken_0x1d7930 = (GPR_S64(ctx, 8) >= 0);
        ctx->pc = 0x1D7934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7930u;
            // 0x1d7934: 0x464821  addu        $t1, $v0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7930) {
            ctx->pc = 0x1D7944u;
            goto label_1d7944;
        }
    }
    ctx->pc = 0x1D7938u;
    // 0x1d7938: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D7938u;
    {
        const bool branch_taken_0x1d7938 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D793Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7938u;
            // 0x1d793c: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7938) {
            ctx->pc = 0x1D7948u;
            goto label_1d7948;
        }
    }
    ctx->pc = 0x1D7940u;
    // 0x1d7940: 0x2463fff0  addiu       $v1, $v1, -0x10
    ctx->pc = 0x1d7940u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967280));
label_1d7944:
    // 0x1d7944: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1d7944u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_1d7948:
    // 0x1d7948: 0x3c040035  lui         $a0, 0x35
    ctx->pc = 0x1d7948u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)53 << 16));
    // 0x1d794c: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1d794cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d7950: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d7950u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d7954: 0x485021  addu        $t2, $v0, $t0
    ctx->pc = 0x1d7954u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1d7958: 0x24848290  addiu       $a0, $a0, -0x7D70
    ctx->pc = 0x1d7958u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294935184));
    // 0x1d795c: 0x120402d  daddu       $t0, $t1, $zero
    ctx->pc = 0x1d795cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7960: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1d7960u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7964: 0x3c090034  lui         $t1, 0x34
    ctx->pc = 0x1d7964u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)52 << 16));
    // 0x1d7968: 0x24e77280  addiu       $a3, $a3, 0x7280
    ctx->pc = 0x1d7968u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 29312));
    // 0x1d796c: 0x25296280  addiu       $t1, $t1, 0x6280
    ctx->pc = 0x1d796cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 25216));
    // 0x1d7970: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1D7970u;
    SET_GPR_U32(ctx, 31, 0x1D7978u);
    ctx->pc = 0x1D7974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7970u;
            // 0x1d7974: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7978u; }
        if (ctx->pc != 0x1D7978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7978u; }
        if (ctx->pc != 0x1D7978u) { return; }
    }
    ctx->pc = 0x1D7978u;
label_1d7978:
    // 0x1d7978: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d7978u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d797c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D797Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D797Cu;
            // 0x1d7980: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7924u: goto label_1d7924;
            case 0x1D7928u: goto label_1d7928;
            case 0x1D7944u: goto label_1d7944;
            case 0x1D7948u: goto label_1d7948;
            case 0x1D7978u: goto label_1d7978;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7984u;
    // 0x1d7984: 0x0  nop
    ctx->pc = 0x1d7984u;
    // NOP
    // 0x1d7988: 0x0  nop
    ctx->pc = 0x1d7988u;
    // NOP
    // 0x1d798c: 0x0  nop
    ctx->pc = 0x1d798cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
