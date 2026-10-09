#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182CA0
// Address: 0x182ca0 - 0x182de8
void sub_00182CA0_0x182ca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182CA0_0x182ca0");
#endif

    switch (ctx->pc) {
        case 0x182d00u: goto label_182d00;
        case 0x182d3cu: goto label_182d3c;
        case 0x182d60u: goto label_182d60;
        default: break;
    }

    ctx->pc = 0x182ca0u;

    // 0x182ca0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x182ca0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x182ca4: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x182ca4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182ca8: 0x246800ff  addiu       $t0, $v1, 0xFF
    ctx->pc = 0x182ca8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), 255));
    // 0x182cac: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x182cacu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182cb0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x182cb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x182cb4: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x182cb4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182cb8: 0x28670000  slti        $a3, $v1, 0x0
    ctx->pc = 0x182cb8u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x182cbc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x182cbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x182cc0: 0x107100b  movn        $v0, $t0, $a3
    ctx->pc = 0x182cc0u;
    if (GPR_U64(ctx, 7) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 8));
    // 0x182cc4: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x182cc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x182cc8: 0x29a03  sra         $s3, $v0, 8
    ctx->pc = 0x182cc8u;
    SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 2), 8));
    // 0x182ccc: 0xc0f02d  daddu       $fp, $a2, $zero
    ctx->pc = 0x182cccu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182cd0: 0x131200  sll         $v0, $s3, 8
    ctx->pc = 0x182cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 8));
    // 0x182cd4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x182cd4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182cd8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x182cd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x182cdc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x182cdcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182ce0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x182ce0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x182ce4: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x182ce4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x182ce8: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x182ce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x182cec: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x182cecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x182cf0: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x182cf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x182cf4: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x182cf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x182cf8: 0xc060a3a  jal         func_1828E8
    ctx->pc = 0x182CF8u;
    SET_GPR_U32(ctx, 31, 0x182D00u);
    ctx->pc = 0x182CFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182CF8u;
            // 0x182cfc: 0x629823  subu        $s3, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1828E8u;
    if (runtime->hasFunction(0x1828E8u)) {
        auto targetFn = runtime->lookupFunction(0x1828E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182D00u; }
        if (ctx->pc != 0x182D00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001828E8_0x1828e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182D00u; }
        if (ctx->pc != 0x182D00u) { return; }
    }
    ctx->pc = 0x182D00u;
label_182d00:
    // 0x182d00: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x182d00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x182d04: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x182d04u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182d08: 0x24020898  addiu       $v0, $zero, 0x898
    ctx->pc = 0x182d08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x182d0c: 0x202a818  mult        $s5, $s0, $v0
    ctx->pc = 0x182d0cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 21, (int32_t)result); }
    // 0x182d10: 0x14600028  bnez        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x182D10u;
    {
        const bool branch_taken_0x182d10 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x182D14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182D10u;
            // 0x182d14: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182d10) {
            ctx->pc = 0x182DB4u;
            goto label_182db4;
        }
    }
    ctx->pc = 0x182D18u;
    // 0x182d18: 0x3c170028  lui         $s7, 0x28
    ctx->pc = 0x182d18u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)40 << 16));
    // 0x182d1c: 0x26a30800  addiu       $v1, $s5, 0x800
    ctx->pc = 0x182d1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 2048));
    // 0x182d20: 0x26f45b48  addiu       $s4, $s7, 0x5B48
    ctx->pc = 0x182d20u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 23), 23368));
    // 0x182d24: 0x74b021  addu        $s6, $v1, $s4
    ctx->pc = 0x182d24u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
    // 0x182d28: 0x8ec20000  lw          $v0, 0x0($s6)
    ctx->pc = 0x182d28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x182d2c: 0x10510014  beq         $v0, $s1, . + 4 + (0x14 << 2)
    ctx->pc = 0x182D2Cu;
    {
        const bool branch_taken_0x182d2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x182D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182D2Cu;
            // 0x182d30: 0x24040898  addiu       $a0, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182d2c) {
            ctx->pc = 0x182D80u;
            goto label_182d80;
        }
    }
    ctx->pc = 0x182D34u;
    // 0x182d34: 0xc060a84  jal         func_182A10
    ctx->pc = 0x182D34u;
    SET_GPR_U32(ctx, 31, 0x182D3Cu);
    ctx->pc = 0x182D38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182D34u;
            // 0x182d38: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182A10u;
    if (runtime->hasFunction(0x182A10u)) {
        auto targetFn = runtime->lookupFunction(0x182A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182D3Cu; }
        if (ctx->pc != 0x182D3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182A10_0x182a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182D3Cu; }
        if (ctx->pc != 0x182D3Cu) { return; }
    }
    ctx->pc = 0x182D3Cu;
label_182d3c:
    // 0x182d3c: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x182d3cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x182d40: 0x26840400  addiu       $a0, $s4, 0x400
    ctx->pc = 0x182d40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 1024));
    // 0x182d44: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x182D44u;
    {
        const bool branch_taken_0x182d44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x182D48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182D44u;
            // 0x182d48: 0x3463006f  ori         $v1, $v1, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x182d44) {
            ctx->pc = 0x182D6Cu;
            goto label_182d6c;
        }
    }
    ctx->pc = 0x182D4Cu;
    // 0x182d4c: 0x2a42821  addu        $a1, $s5, $a0
    ctx->pc = 0x182d4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 4)));
    // 0x182d50: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x182d50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182d54: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x182d54u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182d58: 0xc061b98  jal         func_186E60
    ctx->pc = 0x182D58u;
    SET_GPR_U32(ctx, 31, 0x182D60u);
    ctx->pc = 0x182D5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182D58u;
            // 0x182d5c: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186E60u;
    if (runtime->hasFunction(0x186E60u)) {
        auto targetFn = runtime->lookupFunction(0x186E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182D60u; }
        if (ctx->pc != 0x182D60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186E60_0x186e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182D60u; }
        if (ctx->pc != 0x182D60u) { return; }
    }
    ctx->pc = 0x182D60u;
label_182d60:
    // 0x182d60: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x182d60u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x182d64: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x182D64u;
    {
        const bool branch_taken_0x182d64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x182D68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182D64u;
            // 0x182d68: 0x3463006f  ori         $v1, $v1, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x182d64) {
            ctx->pc = 0x182D78u;
            goto label_182d78;
        }
    }
    ctx->pc = 0x182D6Cu;
label_182d6c:
    // 0x182d6c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x182D6Cu;
    {
        const bool branch_taken_0x182d6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x182D70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182D6Cu;
            // 0x182d70: 0xae430000  sw          $v1, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182d6c) {
            ctx->pc = 0x182DB4u;
            goto label_182db4;
        }
    }
    ctx->pc = 0x182D74u;
    // 0x182d74: 0x0  nop
    ctx->pc = 0x182d74u;
    // NOP
label_182d78:
    // 0x182d78: 0xaed10000  sw          $s1, 0x0($s6)
    ctx->pc = 0x182d78u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 17));
    // 0x182d7c: 0x24040898  addiu       $a0, $zero, 0x898
    ctx->pc = 0x182d7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
label_182d80:
    // 0x182d80: 0x24030226  addiu       $v1, $zero, 0x226
    ctx->pc = 0x182d80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 550));
    // 0x182d84: 0x2043818  mult        $a3, $s0, $a0
    ctx->pc = 0x182d84u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x182d88: 0x26e55b48  addiu       $a1, $s7, 0x5B48
    ctx->pc = 0x182d88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), 23368));
    // 0x182d8c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x182d8cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x182d90: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x182d90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x182d94: 0xe52021  addu        $a0, $a3, $a1
    ctx->pc = 0x182d94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x182d98: 0x2033818  mult        $a3, $s0, $v1
    ctx->pc = 0x182d98u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x182d9c: 0xf31821  addu        $v1, $a3, $s3
    ctx->pc = 0x182d9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 19)));
    // 0x182da0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x182da0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x182da4: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x182da4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x182da8: 0xac7e0400  sw          $fp, 0x400($v1)
    ctx->pc = 0x182da8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1024), GPR_U32(ctx, 30));
    // 0x182dac: 0xac860894  sw          $a2, 0x894($a0)
    ctx->pc = 0x182dacu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 2196), GPR_U32(ctx, 6));
    // 0x182db0: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x182db0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
label_182db4:
    // 0x182db4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x182db4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x182db8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x182db8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x182dbc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x182dbcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x182dc0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x182dc0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x182dc4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x182dc4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x182dc8: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x182dc8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x182dcc: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x182dccu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x182dd0: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x182dd0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x182dd4: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x182dd4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x182dd8: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x182dd8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x182ddc: 0x3e00008  jr          $ra
    ctx->pc = 0x182DDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182DDCu;
            // 0x182de0: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182D00u: goto label_182d00;
            case 0x182D3Cu: goto label_182d3c;
            case 0x182D60u: goto label_182d60;
            case 0x182D6Cu: goto label_182d6c;
            case 0x182D78u: goto label_182d78;
            case 0x182D80u: goto label_182d80;
            case 0x182DB4u: goto label_182db4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182DE4u;
    // 0x182de4: 0x0  nop
    ctx->pc = 0x182de4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
