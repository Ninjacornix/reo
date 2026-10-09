#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172AC8
// Address: 0x172ac8 - 0x172b68
void sub_00172AC8_0x172ac8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172AC8_0x172ac8");
#endif

    switch (ctx->pc) {
        case 0x172b40u: goto label_172b40;
        case 0x172b50u: goto label_172b50;
        default: break;
    }

    ctx->pc = 0x172ac8u;

    // 0x172ac8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x172ac8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x172acc: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x172accu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x172ad0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x172ad0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172ad4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x172ad4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172ad8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x172ad8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x172adc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x172adcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x172ae0: 0x8e03004c  lw          $v1, 0x4C($s0)
    ctx->pc = 0x172ae0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x172ae4: 0x10620012  beq         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x172AE4u;
    {
        const bool branch_taken_0x172ae4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x172AE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172AE4u;
            // 0x172ae8: 0x8e110048  lw          $s1, 0x48($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172ae4) {
            ctx->pc = 0x172B30u;
            goto label_172b30;
        }
    }
    ctx->pc = 0x172AECu;
    // 0x172aec: 0x28620004  slti        $v0, $v1, 0x4
    ctx->pc = 0x172aecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x172af0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x172AF0u;
    {
        const bool branch_taken_0x172af0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x172AF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172AF0u;
            // 0x172af4: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172af0) {
            ctx->pc = 0x172B10u;
            goto label_172b10;
        }
    }
    ctx->pc = 0x172AF8u;
    // 0x172af8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x172af8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x172afc: 0x1062000a  beq         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x172AFCu;
    {
        const bool branch_taken_0x172afc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x172B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172AFCu;
            // 0x172b00: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172afc) {
            ctx->pc = 0x172B28u;
            goto label_172b28;
        }
    }
    ctx->pc = 0x172B04u;
    // 0x172b04: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x172B04u;
    {
        const bool branch_taken_0x172b04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172B04u;
            // 0x172b08: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172b04) {
            ctx->pc = 0x172B58u;
            goto label_172b58;
        }
    }
    ctx->pc = 0x172B0Cu;
    // 0x172b0c: 0x0  nop
    ctx->pc = 0x172b0cu;
    // NOP
label_172b10:
    // 0x172b10: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x172B10u;
    {
        const bool branch_taken_0x172b10 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x172B14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172B10u;
            // 0x172b14: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172b10) {
            ctx->pc = 0x172B38u;
            goto label_172b38;
        }
    }
    ctx->pc = 0x172B18u;
    // 0x172b18: 0x10620007  beq         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x172B18u;
    {
        const bool branch_taken_0x172b18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x172B1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172B18u;
            // 0x172b1c: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172b18) {
            ctx->pc = 0x172B38u;
            goto label_172b38;
        }
    }
    ctx->pc = 0x172B20u;
    // 0x172b20: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x172B20u;
    {
        const bool branch_taken_0x172b20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172B20u;
            // 0x172b24: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172b20) {
            ctx->pc = 0x172B58u;
            goto label_172b58;
        }
    }
    ctx->pc = 0x172B28u;
label_172b28:
    // 0x172b28: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x172B28u;
    {
        const bool branch_taken_0x172b28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172B2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172B28u;
            // 0x172b2c: 0x24110002  addiu       $s1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172b28) {
            ctx->pc = 0x172B50u;
            goto label_172b50;
        }
    }
    ctx->pc = 0x172B30u;
label_172b30:
    // 0x172b30: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x172B30u;
    {
        const bool branch_taken_0x172b30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x172B34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172B30u;
            // 0x172b34: 0x24110003  addiu       $s1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172b30) {
            ctx->pc = 0x172B50u;
            goto label_172b50;
        }
    }
    ctx->pc = 0x172B38u;
label_172b38:
    // 0x172b38: 0xc05caf8  jal         func_172BE0
    ctx->pc = 0x172B38u;
    SET_GPR_U32(ctx, 31, 0x172B40u);
    ctx->pc = 0x172B3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172B38u;
            // 0x172b3c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x172BE0u;
    if (runtime->hasFunction(0x172BE0u)) {
        auto targetFn = runtime->lookupFunction(0x172BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172B40u; }
        if (ctx->pc != 0x172B40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00172BE0_0x172be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172B40u; }
        if (ctx->pc != 0x172B40u) { return; }
    }
    ctx->pc = 0x172B40u;
label_172b40:
    // 0x172b40: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x172B40u;
    {
        const bool branch_taken_0x172b40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x172B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172B40u;
            // 0x172b44: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172b40) {
            ctx->pc = 0x172B50u;
            goto label_172b50;
        }
    }
    ctx->pc = 0x172B48u;
    // 0x172b48: 0xc05cec0  jal         func_173B00
    ctx->pc = 0x172B48u;
    SET_GPR_U32(ctx, 31, 0x172B50u);
    ctx->pc = 0x172B4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172B48u;
            // 0x172b4c: 0x24110004  addiu       $s1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173B00u;
    if (runtime->hasFunction(0x173B00u)) {
        auto targetFn = runtime->lookupFunction(0x173B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172B50u; }
        if (ctx->pc != 0x172B50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173B00_0x173b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172B50u; }
        if (ctx->pc != 0x172B50u) { return; }
    }
    ctx->pc = 0x172B50u;
label_172b50:
    // 0x172b50: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x172b50u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172b54: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172b54u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_172b58:
    // 0x172b58: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x172b58u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172b5c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x172b5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x172b60: 0x3e00008  jr          $ra
    ctx->pc = 0x172B60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172B64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172B60u;
            // 0x172b64: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x172B10u: goto label_172b10;
            case 0x172B28u: goto label_172b28;
            case 0x172B30u: goto label_172b30;
            case 0x172B38u: goto label_172b38;
            case 0x172B40u: goto label_172b40;
            case 0x172B50u: goto label_172b50;
            case 0x172B58u: goto label_172b58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x172B68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
