#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017BC28
// Address: 0x17bc28 - 0x17bd98
void sub_0017BC28_0x17bc28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017BC28_0x17bc28");
#endif

    switch (ctx->pc) {
        case 0x17bcb8u: goto label_17bcb8;
        case 0x17bcf4u: goto label_17bcf4;
        case 0x17bd48u: goto label_17bd48;
        default: break;
    }

    ctx->pc = 0x17bc28u;

    // 0x17bc28: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17bc28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17bc2c: 0x24020041  addiu       $v0, $zero, 0x41
    ctx->pc = 0x17bc2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x17bc30: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17bc30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17bc34: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17bc34u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bc38: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17bc38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17bc3c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17bc3cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bc40: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17bc40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17bc44: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17bc44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17bc48: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x17bc48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17bc4c: 0x10620048  beq         $v1, $v0, . + 4 + (0x48 << 2)
    ctx->pc = 0x17BC4Cu;
    {
        const bool branch_taken_0x17bc4c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17BC50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BC4Cu;
            // 0x17bc50: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17bc4c) {
            ctx->pc = 0x17BD70u;
            goto label_17bd70;
        }
    }
    ctx->pc = 0x17BC54u;
    // 0x17bc54: 0x28620042  slti        $v0, $v1, 0x42
    ctx->pc = 0x17bc54u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)66) ? 1 : 0);
    // 0x17bc58: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x17BC58u;
    {
        const bool branch_taken_0x17bc58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17BC5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BC58u;
            // 0x17bc5c: 0x24020101  addiu       $v0, $zero, 0x101 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17bc58) {
            ctx->pc = 0x17BC88u;
            goto label_17bc88;
        }
    }
    ctx->pc = 0x17BC60u;
    // 0x17bc60: 0x24020021  addiu       $v0, $zero, 0x21
    ctx->pc = 0x17bc60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x17bc64: 0x10620042  beq         $v1, $v0, . + 4 + (0x42 << 2)
    ctx->pc = 0x17BC64u;
    {
        const bool branch_taken_0x17bc64 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17BC68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BC64u;
            // 0x17bc68: 0x28620022  slti        $v0, $v1, 0x22 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)34) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17bc64) {
            ctx->pc = 0x17BD70u;
            goto label_17bd70;
        }
    }
    ctx->pc = 0x17BC6Cu;
    // 0x17bc6c: 0x50400041  beql        $v0, $zero, . + 4 + (0x41 << 2)
    ctx->pc = 0x17BC6Cu;
    {
        const bool branch_taken_0x17bc6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17bc6c) {
            ctx->pc = 0x17BC70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17BC6Cu;
            // 0x17bc70: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17BD74u;
            goto label_17bd74;
        }
    }
    ctx->pc = 0x17BC74u;
    // 0x17bc74: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x17bc74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x17bc78: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x17BC78u;
    {
        const bool branch_taken_0x17bc78 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17bc78) {
            ctx->pc = 0x17BCB0u;
            goto label_17bcb0;
        }
    }
    ctx->pc = 0x17BC80u;
    // 0x17bc80: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x17BC80u;
    {
        const bool branch_taken_0x17bc80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17BC84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BC80u;
            // 0x17bc84: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17bc80) {
            ctx->pc = 0x17BD74u;
            goto label_17bd74;
        }
    }
    ctx->pc = 0x17BC88u;
label_17bc88:
    // 0x17bc88: 0x10620025  beq         $v1, $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x17BC88u;
    {
        const bool branch_taken_0x17bc88 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17BC8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BC88u;
            // 0x17bc8c: 0x28620102  slti        $v0, $v1, 0x102 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)258) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17bc88) {
            ctx->pc = 0x17BD20u;
            goto label_17bd20;
        }
    }
    ctx->pc = 0x17BC90u;
    // 0x17bc90: 0x54400038  bnel        $v0, $zero, . + 4 + (0x38 << 2)
    ctx->pc = 0x17BC90u;
    {
        const bool branch_taken_0x17bc90 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17bc90) {
            ctx->pc = 0x17BC94u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17BC90u;
            // 0x17bc94: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17BD74u;
            goto label_17bd74;
        }
    }
    ctx->pc = 0x17BC98u;
    // 0x17bc98: 0x24021001  addiu       $v0, $zero, 0x1001
    ctx->pc = 0x17bc98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4097));
    // 0x17bc9c: 0x10620028  beq         $v1, $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x17BC9Cu;
    {
        const bool branch_taken_0x17bc9c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17bc9c) {
            ctx->pc = 0x17BD40u;
            goto label_17bd40;
        }
    }
    ctx->pc = 0x17BCA4u;
    // 0x17bca4: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x17BCA4u;
    {
        const bool branch_taken_0x17bca4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17BCA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BCA4u;
            // 0x17bca8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17bca4) {
            ctx->pc = 0x17BD74u;
            goto label_17bd74;
        }
    }
    ctx->pc = 0x17BCACu;
    // 0x17bcac: 0x0  nop
    ctx->pc = 0x17bcacu;
    // NOP
label_17bcb0:
    // 0x17bcb0: 0xc05f51a  jal         func_17D468
    ctx->pc = 0x17BCB0u;
    SET_GPR_U32(ctx, 31, 0x17BCB8u);
    ctx->pc = 0x17D468u;
    if (runtime->hasFunction(0x17D468u)) {
        auto targetFn = runtime->lookupFunction(0x17D468u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BCB8u; }
        if (ctx->pc != 0x17BCB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D468_0x17d468(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BCB8u; }
        if (ctx->pc != 0x17BCB8u) { return; }
    }
    ctx->pc = 0x17BCB8u;
label_17bcb8:
    // 0x17bcb8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17bcb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17bcbc: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x17BCBCu;
    {
        const bool branch_taken_0x17bcbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17BCC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BCBCu;
            // 0x17bcc0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17bcbc) {
            ctx->pc = 0x17BCE8u;
            goto label_17bce8;
        }
    }
    ctx->pc = 0x17BCC4u;
    // 0x17bcc4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17bcc4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17bcc8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17bcc8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bccc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17bcccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17bcd0: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17bcd0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bcd4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17bcd4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17bcd8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17bcd8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17bcdc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17bcdcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bce0: 0x805ef66  j           func_17BD98
    ctx->pc = 0x17BCE0u;
    ctx->pc = 0x17BCE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BCE0u;
            // 0x17bce4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BD98u;
    if (runtime->hasFunction(0x17BD98u)) {
        auto targetFn = runtime->lookupFunction(0x17BD98u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017BD98_0x17bd98(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17BCE8u;
label_17bce8:
    // 0x17bce8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17bce8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bcec: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17BCECu;
    SET_GPR_U32(ctx, 31, 0x17BCF4u);
    ctx->pc = 0x17BCF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BCECu;
            // 0x17bcf0: 0x24060016  addiu       $a2, $zero, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BCF4u; }
        if (ctx->pc != 0x17BCF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BCF4u; }
        if (ctx->pc != 0x17BCF4u) { return; }
    }
    ctx->pc = 0x17BCF4u;
label_17bcf4:
    // 0x17bcf4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17bcf4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bcf8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17bcf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bcfc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17bcfcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17bd00: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17bd00u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bd04: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17bd04u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17bd08: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17bd08u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17bd0c: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17bd0cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17bd10: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17bd10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17bd14: 0x805ef66  j           func_17BD98
    ctx->pc = 0x17BD14u;
    ctx->pc = 0x17BD18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BD14u;
            // 0x17bd18: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BD98u;
    if (runtime->hasFunction(0x17BD98u)) {
        auto targetFn = runtime->lookupFunction(0x17BD98u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017BD98_0x17bd98(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17BD1Cu;
    // 0x17bd1c: 0x0  nop
    ctx->pc = 0x17bd1cu;
    // NOP
label_17bd20:
    // 0x17bd20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17bd20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17bd24: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17bd24u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bd28: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17bd28u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17bd2c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17bd2cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17bd30: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17bd30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17bd34: 0x805ef66  j           func_17BD98
    ctx->pc = 0x17BD34u;
    ctx->pc = 0x17BD38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BD34u;
            // 0x17bd38: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BD98u;
    if (runtime->hasFunction(0x17BD98u)) {
        auto targetFn = runtime->lookupFunction(0x17BD98u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017BD98_0x17bd98(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17BD3Cu;
    // 0x17bd3c: 0x0  nop
    ctx->pc = 0x17bd3cu;
    // NOP
label_17bd40:
    // 0x17bd40: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17BD40u;
    SET_GPR_U32(ctx, 31, 0x17BD48u);
    ctx->pc = 0x17BD44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BD40u;
            // 0x17bd44: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BD48u; }
        if (ctx->pc != 0x17BD48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BD48u; }
        if (ctx->pc != 0x17BD48u) { return; }
    }
    ctx->pc = 0x17BD48u;
label_17bd48:
    // 0x17bd48: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17bd48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bd4c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17bd4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bd50: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17bd50u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17bd54: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17bd54u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bd58: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17bd58u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17bd5c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17bd5cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17bd60: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17bd60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17bd64: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17bd64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17bd68: 0x805ef66  j           func_17BD98
    ctx->pc = 0x17BD68u;
    ctx->pc = 0x17BD6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BD68u;
            // 0x17bd6c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BD98u;
    if (runtime->hasFunction(0x17BD98u)) {
        auto targetFn = runtime->lookupFunction(0x17BD98u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017BD98_0x17bd98(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17BD70u;
label_17bd70:
    // 0x17bd70: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17bd70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_17bd74:
    // 0x17bd74: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17bd74u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17bd78: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17bd78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bd7c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17bd7cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17bd80: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17bd80u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17bd84: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17bd84u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17bd88: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17bd88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17bd8c: 0x24c60fc0  addiu       $a2, $a2, 0xFC0
    ctx->pc = 0x17bd8cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4032));
    // 0x17bd90: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17BD90u;
    ctx->pc = 0x17BD94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BD90u;
            // 0x17bd94: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17BD98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
