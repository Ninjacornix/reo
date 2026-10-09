#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7B10
// Address: 0x1a7b10 - 0x1a7ba8
void sub_001A7B10_0x1a7b10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7B10_0x1a7b10");
#endif

    switch (ctx->pc) {
        case 0x1a7b50u: goto label_1a7b50;
        default: break;
    }

    ctx->pc = 0x1a7b10u;

    // 0x1a7b10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7b10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7b14: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a7b14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a7b18: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a7b18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a7b1c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7b1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7b20: 0x8c250a68  lw          $a1, 0xA68($at)
    ctx->pc = 0x1a7b20u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7b24: 0x24420a80  addiu       $v0, $v0, 0xA80
    ctx->pc = 0x1a7b24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2688));
    // 0x1a7b28: 0x51840  sll         $v1, $a1, 1
    ctx->pc = 0x1a7b28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1a7b2c: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1a7b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1a7b30: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a7b30u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a7b34: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x1a7b34u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a7b38: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1a7b38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a7b3c: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7B3Cu;
    {
        const bool branch_taken_0x1a7b3c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1A7B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7B3Cu;
            // 0x1a7b40: 0x308300ff  andi        $v1, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7b3c) {
            ctx->pc = 0x1A7B58u;
            goto label_1a7b58;
        }
    }
    ctx->pc = 0x1A7B44u;
    // 0x1a7b44: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7b44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7b48: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7B48u;
    SET_GPR_U32(ctx, 31, 0x1A7B50u);
    ctx->pc = 0x1A7B4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7B48u;
            // 0x1a7b4c: 0x24842290  addiu       $a0, $a0, 0x2290 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8848));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7B50u; }
        if (ctx->pc != 0x1A7B50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7B50u; }
        if (ctx->pc != 0x1A7B50u) { return; }
    }
    ctx->pc = 0x1A7B50u;
label_1a7b50:
    // 0x1a7b50: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1A7B50u;
    {
        const bool branch_taken_0x1a7b50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7B54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7B50u;
            // 0x1a7b54: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7b50) {
            ctx->pc = 0x1A7B9Cu;
            goto label_1a7b9c;
        }
    }
    ctx->pc = 0x1A7B58u;
label_1a7b58:
    // 0x1a7b58: 0x3c024a00  lui         $v0, 0x4A00
    ctx->pc = 0x1a7b58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)18944 << 16));
    // 0x1a7b5c: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1a7b5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1a7b60: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7b60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7b64: 0x31a3c  dsll32      $v1, $v1, 8
    ctx->pc = 0x1a7b64u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 8));
    // 0x1a7b68: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1a7b68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1a7b6c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1a7b6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a7b70: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1a7b70u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1a7b74: 0x8c220a68  lw          $v0, 0xA68($at)
    ctx->pc = 0x1a7b74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7b78: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1a7b78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a7b7c: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A7B7Cu;
    {
        const bool branch_taken_0x1a7b7c = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1A7B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7B7Cu;
            // 0x1a7b80: 0x3062001f  andi        $v0, $v1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7b7c) {
            ctx->pc = 0x1A7B90u;
            goto label_1a7b90;
        }
    }
    ctx->pc = 0x1A7B84u;
    // 0x1a7b84: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A7B84u;
    {
        const bool branch_taken_0x1a7b84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7b84) {
            ctx->pc = 0x1A7B90u;
            goto label_1a7b90;
        }
    }
    ctx->pc = 0x1A7B8Cu;
    // 0x1a7b8c: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x1a7b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_1a7b90:
    // 0x1a7b90: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7b90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7b94: 0xac220a68  sw          $v0, 0xA68($at)
    ctx->pc = 0x1a7b94u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2664), GPR_U32(ctx, 2));
    // 0x1a7b98: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a7b98u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a7b9c:
    // 0x1a7b9c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a7b9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a7ba0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7BA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7BA0u;
            // 0x1a7ba4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A7B50u: goto label_1a7b50;
            case 0x1A7B58u: goto label_1a7b58;
            case 0x1A7B90u: goto label_1a7b90;
            case 0x1A7B9Cu: goto label_1a7b9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7BA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
