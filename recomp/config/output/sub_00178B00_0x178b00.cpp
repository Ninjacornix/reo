#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178B00
// Address: 0x178b00 - 0x178b80
void sub_00178B00_0x178b00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178B00_0x178b00");
#endif

    switch (ctx->pc) {
        case 0x178b20u: goto label_178b20;
        case 0x178b30u: goto label_178b30;
        case 0x178b40u: goto label_178b40;
        default: break;
    }

    ctx->pc = 0x178b00u;

    // 0x178b00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x178b00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x178b04: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x178b04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x178b08: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x178b08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x178b0c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x178b0cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178b10: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x178b10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x178b14: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x178b14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x178b18: 0xc05df12  jal         func_177C48
    ctx->pc = 0x178B18u;
    SET_GPR_U32(ctx, 31, 0x178B20u);
    ctx->pc = 0x178B1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178B18u;
            // 0x178b1c: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C48u;
    if (runtime->hasFunction(0x177C48u)) {
        auto targetFn = runtime->lookupFunction(0x177C48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178B20u; }
        if (ctx->pc != 0x178B20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C48_0x177c48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178B20u; }
        if (ctx->pc != 0x178B20u) { return; }
    }
    ctx->pc = 0x178B20u;
label_178b20:
    // 0x178b20: 0x10510011  beq         $v0, $s1, . + 4 + (0x11 << 2)
    ctx->pc = 0x178B20u;
    {
        const bool branch_taken_0x178b20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x178B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178B20u;
            // 0x178b24: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178b20) {
            ctx->pc = 0x178B68u;
            goto label_178b68;
        }
    }
    ctx->pc = 0x178B28u;
    // 0x178b28: 0xc059f30  jal         func_167CC0
    ctx->pc = 0x178B28u;
    SET_GPR_U32(ctx, 31, 0x178B30u);
    ctx->pc = 0x178B2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178B28u;
            // 0x178b2c: 0x8e051cd0  lw          $a1, 0x1CD0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7376)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CC0u;
    if (runtime->hasFunction(0x167CC0u)) {
        auto targetFn = runtime->lookupFunction(0x167CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178B30u; }
        if (ctx->pc != 0x178B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CC0_0x167cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178B30u; }
        if (ctx->pc != 0x178B30u) { return; }
    }
    ctx->pc = 0x178B30u;
label_178b30:
    // 0x178b30: 0x1451000d  bne         $v0, $s1, . + 4 + (0xD << 2)
    ctx->pc = 0x178B30u;
    {
        const bool branch_taken_0x178b30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x178B34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178B30u;
            // 0x178b34: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178b30) {
            ctx->pc = 0x178B68u;
            goto label_178b68;
        }
    }
    ctx->pc = 0x178B38u;
    // 0x178b38: 0xc05e2e0  jal         func_178B80
    ctx->pc = 0x178B38u;
    SET_GPR_U32(ctx, 31, 0x178B40u);
    ctx->pc = 0x178B80u;
    if (runtime->hasFunction(0x178B80u)) {
        auto targetFn = runtime->lookupFunction(0x178B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178B40u; }
        if (ctx->pc != 0x178B40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178B80_0x178b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178B40u; }
        if (ctx->pc != 0x178B40u) { return; }
    }
    ctx->pc = 0x178B40u;
label_178b40:
    // 0x178b40: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x178B40u;
    {
        const bool branch_taken_0x178b40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x178B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178B40u;
            // 0x178b44: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178b40) {
            ctx->pc = 0x178B68u;
            goto label_178b68;
        }
    }
    ctx->pc = 0x178B48u;
    // 0x178b48: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178b48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178b4c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178b4cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178b50: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x178b50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x178b54: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x178b54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178b58: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x178b58u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x178b5c: 0x805df0c  j           func_177C30
    ctx->pc = 0x178B5Cu;
    ctx->pc = 0x178B60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178B5Cu;
            // 0x178b60: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C30u;
    if (runtime->hasFunction(0x177C30u)) {
        auto targetFn = runtime->lookupFunction(0x177C30u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177C30_0x177c30(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x178B64u;
    // 0x178b64: 0x0  nop
    ctx->pc = 0x178b64u;
    // NOP
label_178b68:
    // 0x178b68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178b68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178b6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x178b6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178b70: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x178b70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178b74: 0x3e00008  jr          $ra
    ctx->pc = 0x178B74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178B74u;
            // 0x178b78: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178B20u: goto label_178b20;
            case 0x178B30u: goto label_178b30;
            case 0x178B40u: goto label_178b40;
            case 0x178B68u: goto label_178b68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178B7Cu;
    // 0x178b7c: 0x0  nop
    ctx->pc = 0x178b7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
