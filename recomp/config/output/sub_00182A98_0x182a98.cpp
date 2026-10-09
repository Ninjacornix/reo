#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182A98
// Address: 0x182a98 - 0x182c08
void sub_00182A98_0x182a98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182A98_0x182a98");
#endif

    switch (ctx->pc) {
        case 0x182aecu: goto label_182aec;
        case 0x182b28u: goto label_182b28;
        case 0x182b68u: goto label_182b68;
        case 0x182b94u: goto label_182b94;
        default: break;
    }

    ctx->pc = 0x182a98u;

    // 0x182a98: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x182a98u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182a9c: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x182a9cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x182aa0: 0x28e30000  slti        $v1, $a3, 0x0
    ctx->pc = 0x182aa0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x182aa4: 0x24e800ff  addiu       $t0, $a3, 0xFF
    ctx->pc = 0x182aa4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), 255));
    // 0x182aa8: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x182aa8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182aac: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x182aacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x182ab0: 0x103100b  movn        $v0, $t0, $v1
    ctx->pc = 0x182ab0u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 8));
    // 0x182ab4: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x182ab4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x182ab8: 0x2b203  sra         $s6, $v0, 8
    ctx->pc = 0x182ab8u;
    SET_GPR_S32(ctx, 22, SRA32(GPR_S32(ctx, 2), 8));
    // 0x182abc: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x182abcu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182ac0: 0x161a00  sll         $v1, $s6, 8
    ctx->pc = 0x182ac0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 22), 8));
    // 0x182ac4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x182ac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x182ac8: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x182ac8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x182acc: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x182accu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182ad0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x182ad0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x182ad4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x182ad4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x182ad8: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x182ad8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x182adc: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x182adcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x182ae0: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x182ae0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x182ae4: 0xc060a3a  jal         func_1828E8
    ctx->pc = 0x182AE4u;
    SET_GPR_U32(ctx, 31, 0x182AECu);
    ctx->pc = 0x182AE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182AE4u;
            // 0x182ae8: 0xe3b023  subu        $s6, $a3, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1828E8u;
    if (runtime->hasFunction(0x1828E8u)) {
        auto targetFn = runtime->lookupFunction(0x1828E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182AECu; }
        if (ctx->pc != 0x182AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001828E8_0x1828e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182AECu; }
        if (ctx->pc != 0x182AECu) { return; }
    }
    ctx->pc = 0x182AECu;
label_182aec:
    // 0x182aec: 0x8ea30000  lw          $v1, 0x0($s5)
    ctx->pc = 0x182aecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x182af0: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x182af0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182af4: 0x14600038  bnez        $v1, . + 4 + (0x38 << 2)
    ctx->pc = 0x182AF4u;
    {
        const bool branch_taken_0x182af4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x182AF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182AF4u;
            // 0x182af8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182af4) {
            ctx->pc = 0x182BD8u;
            goto label_182bd8;
        }
    }
    ctx->pc = 0x182AFCu;
    // 0x182afc: 0x24020898  addiu       $v0, $zero, 0x898
    ctx->pc = 0x182afcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x182b00: 0x3c170028  lui         $s7, 0x28
    ctx->pc = 0x182b00u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)40 << 16));
    // 0x182b04: 0x2628018  mult        $s0, $s3, $v0
    ctx->pc = 0x182b04u;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 16, (int32_t)result); }
    // 0x182b08: 0x26f45b48  addiu       $s4, $s7, 0x5B48
    ctx->pc = 0x182b08u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 23), 23368));
    // 0x182b0c: 0x26020800  addiu       $v0, $s0, 0x800
    ctx->pc = 0x182b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 2048));
    // 0x182b10: 0x548821  addu        $s1, $v0, $s4
    ctx->pc = 0x182b10u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x182b14: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x182b14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x182b18: 0x10720027  beq         $v1, $s2, . + 4 + (0x27 << 2)
    ctx->pc = 0x182B18u;
    {
        const bool branch_taken_0x182b18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 18));
        ctx->pc = 0x182B1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182B18u;
            // 0x182b1c: 0x24020226  addiu       $v0, $zero, 0x226 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 550));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182b18) {
            ctx->pc = 0x182BB8u;
            goto label_182bb8;
        }
    }
    ctx->pc = 0x182B20u;
    // 0x182b20: 0xc060a84  jal         func_182A10
    ctx->pc = 0x182B20u;
    SET_GPR_U32(ctx, 31, 0x182B28u);
    ctx->pc = 0x182B24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182B20u;
            // 0x182b24: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182A10u;
    if (runtime->hasFunction(0x182A10u)) {
        auto targetFn = runtime->lookupFunction(0x182A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182B28u; }
        if (ctx->pc != 0x182B28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182A10_0x182a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182B28u; }
        if (ctx->pc != 0x182B28u) { return; }
    }
    ctx->pc = 0x182B28u;
label_182b28:
    // 0x182b28: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x182B28u;
    {
        const bool branch_taken_0x182b28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x182b28) {
            ctx->pc = 0x182B9Cu;
            goto label_182b9c;
        }
    }
    ctx->pc = 0x182B30u;
    // 0x182b30: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x182b30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x182b34: 0x1840000f  blez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x182B34u;
    {
        const bool branch_taken_0x182b34 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x182B38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182B34u;
            // 0x182b38: 0x24020898  addiu       $v0, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182b34) {
            ctx->pc = 0x182B74u;
            goto label_182b74;
        }
    }
    ctx->pc = 0x182B3Cu;
    // 0x182b3c: 0x2141021  addu        $v0, $s0, $s4
    ctx->pc = 0x182b3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 20)));
    // 0x182b40: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x182b40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x182b44: 0x8c430894  lw          $v1, 0x894($v0)
    ctx->pc = 0x182b44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 2196)));
    // 0x182b48: 0x5464000a  bnel        $v1, $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x182B48u;
    {
        const bool branch_taken_0x182b48 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x182b48) {
            ctx->pc = 0x182B4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x182B48u;
            // 0x182b4c: 0x24020898  addiu       $v0, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
            ctx->pc = 0x182B74u;
            goto label_182b74;
        }
    }
    ctx->pc = 0x182B50u;
    // 0x182b50: 0x26850400  addiu       $a1, $s4, 0x400
    ctx->pc = 0x182b50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), 1024));
    // 0x182b54: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x182b54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182b58: 0x2052821  addu        $a1, $s0, $a1
    ctx->pc = 0x182b58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x182b5c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x182b5cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182b60: 0xc061baa  jal         func_186EA8
    ctx->pc = 0x182B60u;
    SET_GPR_U32(ctx, 31, 0x182B68u);
    ctx->pc = 0x182B64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182B60u;
            // 0x182b64: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186EA8u;
    if (runtime->hasFunction(0x186EA8u)) {
        auto targetFn = runtime->lookupFunction(0x186EA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182B68u; }
        if (ctx->pc != 0x182B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186EA8_0x186ea8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182B68u; }
        if (ctx->pc != 0x182B68u) { return; }
    }
    ctx->pc = 0x182B68u;
label_182b68:
    // 0x182b68: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x182B68u;
    {
        const bool branch_taken_0x182b68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x182b68) {
            ctx->pc = 0x182B9Cu;
            goto label_182b9c;
        }
    }
    ctx->pc = 0x182B70u;
    // 0x182b70: 0x24020898  addiu       $v0, $zero, 0x898
    ctx->pc = 0x182b70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
label_182b74:
    // 0x182b74: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x182b74u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x182b78: 0x2628018  mult        $s0, $s3, $v0
    ctx->pc = 0x182b78u;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 16, (int32_t)result); }
    // 0x182b7c: 0x24715f48  addiu       $s1, $v1, 0x5F48
    ctx->pc = 0x182b7cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 24392));
    // 0x182b80: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x182b80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182b84: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x182b84u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x182b88: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x182b88u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x182b8c: 0xc061b98  jal         func_186E60
    ctx->pc = 0x182B8Cu;
    SET_GPR_U32(ctx, 31, 0x182B94u);
    ctx->pc = 0x182B90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x182B8Cu;
            // 0x182b90: 0x2112821  addu        $a1, $s0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186E60u;
    if (runtime->hasFunction(0x186E60u)) {
        auto targetFn = runtime->lookupFunction(0x186E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182B94u; }
        if (ctx->pc != 0x182B94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186E60_0x186e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182B94u; }
        if (ctx->pc != 0x182B94u) { return; }
    }
    ctx->pc = 0x182B94u;
label_182b94:
    // 0x182b94: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x182B94u;
    {
        const bool branch_taken_0x182b94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x182b94) {
            ctx->pc = 0x182B98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x182B94u;
            // 0x182b98: 0x2301021  addu        $v0, $s1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x182BB0u;
            goto label_182bb0;
        }
    }
    ctx->pc = 0x182B9Cu;
label_182b9c:
    // 0x182b9c: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x182b9cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x182ba0: 0x3463006f  ori         $v1, $v1, 0x6F
    ctx->pc = 0x182ba0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)111);
    // 0x182ba4: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x182BA4u;
    {
        const bool branch_taken_0x182ba4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x182BA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182BA4u;
            // 0x182ba8: 0xaea30000  sw          $v1, 0x0($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182ba4) {
            ctx->pc = 0x182BD8u;
            goto label_182bd8;
        }
    }
    ctx->pc = 0x182BACu;
    // 0x182bac: 0x0  nop
    ctx->pc = 0x182bacu;
    // NOP
label_182bb0:
    // 0x182bb0: 0xac520400  sw          $s2, 0x400($v0)
    ctx->pc = 0x182bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1024), GPR_U32(ctx, 18));
    // 0x182bb4: 0x24020226  addiu       $v0, $zero, 0x226
    ctx->pc = 0x182bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 550));
label_182bb8:
    // 0x182bb8: 0x26e35b48  addiu       $v1, $s7, 0x5B48
    ctx->pc = 0x182bb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), 23368));
    // 0x182bbc: 0x2622018  mult        $a0, $s3, $v0
    ctx->pc = 0x182bbcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x182bc0: 0x961021  addu        $v0, $a0, $s6
    ctx->pc = 0x182bc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 22)));
    // 0x182bc4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x182bc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x182bc8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x182bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x182bcc: 0x8c520400  lw          $s2, 0x400($v0)
    ctx->pc = 0x182bccu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1024)));
    // 0x182bd0: 0xaea00000  sw          $zero, 0x0($s5)
    ctx->pc = 0x182bd0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
    // 0x182bd4: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x182bd4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_182bd8:
    // 0x182bd8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x182bd8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x182bdc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x182bdcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x182be0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x182be0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x182be4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x182be4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x182be8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x182be8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x182bec: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x182becu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x182bf0: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x182bf0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x182bf4: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x182bf4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x182bf8: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x182bf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x182bfc: 0x3e00008  jr          $ra
    ctx->pc = 0x182BFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182C00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182BFCu;
            // 0x182c00: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182AECu: goto label_182aec;
            case 0x182B28u: goto label_182b28;
            case 0x182B68u: goto label_182b68;
            case 0x182B74u: goto label_182b74;
            case 0x182B94u: goto label_182b94;
            case 0x182B9Cu: goto label_182b9c;
            case 0x182BB0u: goto label_182bb0;
            case 0x182BB8u: goto label_182bb8;
            case 0x182BD8u: goto label_182bd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182C04u;
    // 0x182c04: 0x0  nop
    ctx->pc = 0x182c04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
