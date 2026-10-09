#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133AB8
// Address: 0x133ab8 - 0x133b44
void sub_00133AB8_0x133ab8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133AB8_0x133ab8");
#endif

    switch (ctx->pc) {
        case 0x133ae8u: goto label_133ae8;
        case 0x133b10u: goto label_133b10;
        case 0x133b20u: goto label_133b20;
        case 0x133b30u: goto label_133b30;
        default: break;
    }

    ctx->pc = 0x133ab8u;

    // 0x133ab8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x133ab8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x133abc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x133abcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x133ac0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x133ac0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133ac4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x133ac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x133ac8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x133ac8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x133acc: 0x8e110008  lw          $s1, 0x8($s0)
    ctx->pc = 0x133accu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x133ad0: 0x12200017  beqz        $s1, . + 4 + (0x17 << 2)
    ctx->pc = 0x133AD0u;
    {
        const bool branch_taken_0x133ad0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x133AD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133AD0u;
            // 0x133ad4: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133ad0) {
            ctx->pc = 0x133B30u;
            goto label_133b30;
        }
    }
    ctx->pc = 0x133AD8u;
    // 0x133ad8: 0x50800016  beql        $a0, $zero, . + 4 + (0x16 << 2)
    ctx->pc = 0x133AD8u;
    {
        const bool branch_taken_0x133ad8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x133ad8) {
            ctx->pc = 0x133ADCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x133AD8u;
            // 0x133adc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x133B34u;
            goto label_133b34;
        }
    }
    ctx->pc = 0x133AE0u;
    // 0x133ae0: 0xc04b620  jal         func_12D880
    ctx->pc = 0x133AE0u;
    SET_GPR_U32(ctx, 31, 0x133AE8u);
    ctx->pc = 0x12D880u;
    if (runtime->hasFunction(0x12D880u)) {
        auto targetFn = runtime->lookupFunction(0x12D880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133AE8u; }
        if (ctx->pc != 0x133AE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D880_0x12d880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133AE8u; }
        if (ctx->pc != 0x133AE8u) { return; }
    }
    ctx->pc = 0x133AE8u;
label_133ae8:
    // 0x133ae8: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x133ae8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x133aec: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x133aecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133af0: 0x24c207ff  addiu       $v0, $a2, 0x7FF
    ctx->pc = 0x133af0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 2047));
    // 0x133af4: 0x28c30000  slti        $v1, $a2, 0x0
    ctx->pc = 0x133af4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x133af8: 0x43300b  movn        $a2, $v0, $v1
    ctx->pc = 0x133af8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 2));
    // 0x133afc: 0x8202006c  lb          $v0, 0x6C($s0)
    ctx->pc = 0x133afcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 108)));
    // 0x133b00: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x133B00u;
    {
        const bool branch_taken_0x133b00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x133B04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133B00u;
            // 0x133b04: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133b00) {
            ctx->pc = 0x133B28u;
            goto label_133b28;
        }
    }
    ctx->pc = 0x133B08u;
    // 0x133b08: 0xc04b5d2  jal         func_12D748
    ctx->pc = 0x133B08u;
    SET_GPR_U32(ctx, 31, 0x133B10u);
    ctx->pc = 0x133B0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133B08u;
            // 0x133b0c: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D748u;
    if (runtime->hasFunction(0x12D748u)) {
        auto targetFn = runtime->lookupFunction(0x12D748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133B10u; }
        if (ctx->pc != 0x133B10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D748_0x12d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133B10u; }
        if (ctx->pc != 0x133B10u) { return; }
    }
    ctx->pc = 0x133B10u;
label_133b10:
    // 0x133b10: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x133b10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x133b14: 0x3c057fff  lui         $a1, 0x7FFF
    ctx->pc = 0x133b14u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32767 << 16));
    // 0x133b18: 0xc04c1ea  jal         func_1307A8
    ctx->pc = 0x133B18u;
    SET_GPR_U32(ctx, 31, 0x133B20u);
    ctx->pc = 0x133B1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133B18u;
            // 0x133b1c: 0x34a5ffff  ori         $a1, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1307A8u;
    if (runtime->hasFunction(0x1307A8u)) {
        auto targetFn = runtime->lookupFunction(0x1307A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133B20u; }
        if (ctx->pc != 0x133B20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001307A8_0x1307a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133B20u; }
        if (ctx->pc != 0x133B20u) { return; }
    }
    ctx->pc = 0x133B20u;
label_133b20:
    // 0x133b20: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x133B20u;
    {
        const bool branch_taken_0x133b20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x133B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133B20u;
            // 0x133b24: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133b20) {
            ctx->pc = 0x133B34u;
            goto label_133b34;
        }
    }
    ctx->pc = 0x133B28u;
label_133b28:
    // 0x133b28: 0xc04c170  jal         func_1305C0
    ctx->pc = 0x133B28u;
    SET_GPR_U32(ctx, 31, 0x133B30u);
    ctx->pc = 0x133B2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133B28u;
            // 0x133b2c: 0x62ac3  sra         $a1, $a2, 11 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 6), 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305C0u;
    if (runtime->hasFunction(0x1305C0u)) {
        auto targetFn = runtime->lookupFunction(0x1305C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133B30u; }
        if (ctx->pc != 0x133B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305C0_0x1305c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133B30u; }
        if (ctx->pc != 0x133B30u) { return; }
    }
    ctx->pc = 0x133B30u;
label_133b30:
    // 0x133b30: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x133b30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_133b34:
    // 0x133b34: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x133b34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x133b38: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x133b38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x133b3c: 0x3e00008  jr          $ra
    ctx->pc = 0x133B3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x133B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133B3Cu;
            // 0x133b40: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x133AE8u: goto label_133ae8;
            case 0x133B10u: goto label_133b10;
            case 0x133B20u: goto label_133b20;
            case 0x133B28u: goto label_133b28;
            case 0x133B30u: goto label_133b30;
            case 0x133B34u: goto label_133b34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133B44u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
