#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108108
// Address: 0x108108 - 0x108188
void sub_00108108_0x108108(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108108_0x108108");
#endif

    ctx->pc = 0x108108u;

    // 0x108108: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x108108u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x10810c: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x10810cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x108110: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x108110u;
    {
        const bool branch_taken_0x108110 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x108114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108110u;
            // 0x108114: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108110) {
            ctx->pc = 0x108120u;
            goto label_108120;
        }
    }
    ctx->pc = 0x108118u;
    // 0x108118: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x108118u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10811c: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x10811cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
label_108120:
    // 0x108120: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x108120u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x108124: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x108124u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x108128: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x108128u;
    {
        const bool branch_taken_0x108128 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10812Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108128u;
            // 0x10812c: 0x3c02f000  lui         $v0, 0xF000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)61440 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108128) {
            ctx->pc = 0x108138u;
            goto label_108138;
        }
    }
    ctx->pc = 0x108130u;
    // 0x108130: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x108130u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x108134: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x108134u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
label_108138:
    // 0x108138: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x108138u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x10813c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10813Cu;
    {
        const bool branch_taken_0x10813c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x108140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10813Cu;
            // 0x108140: 0x3c02c000  lui         $v0, 0xC000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49152 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10813c) {
            ctx->pc = 0x10814Cu;
            goto label_10814c;
        }
    }
    ctx->pc = 0x108144u;
    // 0x108144: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x108144u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x108148: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x108148u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
label_10814c:
    // 0x10814c: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x10814cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x108150: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x108150u;
    {
        const bool branch_taken_0x108150 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x108150) {
            ctx->pc = 0x108160u;
            goto label_108160;
        }
    }
    ctx->pc = 0x108158u;
    // 0x108158: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x108158u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
    // 0x10815c: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x10815cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
label_108160:
    // 0x108160: 0x4800007  bltz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x108160u;
    {
        const bool branch_taken_0x108160 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x108164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108160u;
            // 0x108164: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108160) {
            ctx->pc = 0x108180u;
            goto label_108180;
        }
    }
    ctx->pc = 0x108168u;
    // 0x108168: 0x3c034000  lui         $v1, 0x4000
    ctx->pc = 0x108168u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16384 << 16));
    // 0x10816c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x10816cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x108170: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x108170u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x108174: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x108174u;
    {
        const bool branch_taken_0x108174 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x108178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108174u;
            // 0x108178: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108174) {
            ctx->pc = 0x108180u;
            goto label_108180;
        }
    }
    ctx->pc = 0x10817Cu;
    // 0x10817c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x10817cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_108180:
    // 0x108180: 0x3e00008  jr          $ra
    ctx->pc = 0x108180u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108120u: goto label_108120;
            case 0x108138u: goto label_108138;
            case 0x10814Cu: goto label_10814c;
            case 0x108160u: goto label_108160;
            case 0x108180u: goto label_108180;
            default: break;
        }
        return;
    }
    ctx->pc = 0x108188u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
