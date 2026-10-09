#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B5FB0
// Address: 0x1b5fb0 - 0x1b6380
void sub_001B5FB0_0x1b5fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B5FB0_0x1b5fb0");
#endif

    switch (ctx->pc) {
        case 0x1b5ff4u: goto label_1b5ff4;
        case 0x1b6004u: goto label_1b6004;
        case 0x1b6010u: goto label_1b6010;
        case 0x1b601cu: goto label_1b601c;
        case 0x1b6078u: goto label_1b6078;
        case 0x1b6098u: goto label_1b6098;
        case 0x1b60e0u: goto label_1b60e0;
        case 0x1b6118u: goto label_1b6118;
        case 0x1b6150u: goto label_1b6150;
        case 0x1b61bcu: goto label_1b61bc;
        case 0x1b61f4u: goto label_1b61f4;
        case 0x1b6244u: goto label_1b6244;
        case 0x1b6250u: goto label_1b6250;
        case 0x1b6280u: goto label_1b6280;
        case 0x1b629cu: goto label_1b629c;
        case 0x1b62e4u: goto label_1b62e4;
        case 0x1b631cu: goto label_1b631c;
        case 0x1b6370u: goto label_1b6370;
        default: break;
    }

    ctx->pc = 0x1b5fb0u;

    // 0x1b5fb0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b5fb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b5fb4: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5fb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5fb8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b5fb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b5fbc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b5fbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b5fc0: 0x8c22aaf0  lw          $v0, -0x5510($at)
    ctx->pc = 0x1b5fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945520)));
    // 0x1b5fc4: 0x3c10002c  lui         $s0, 0x2C
    ctx->pc = 0x1b5fc4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
    // 0x1b5fc8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B5FC8u;
    {
        const bool branch_taken_0x1b5fc8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5FC8u;
            // 0x1b5fcc: 0x2610aaf0  addiu       $s0, $s0, -0x5510 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945520));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5fc8) {
            ctx->pc = 0x1B5FDCu;
            goto label_1b5fdc;
        }
    }
    ctx->pc = 0x1B5FD0u;
    // 0x1b5fd0: 0x8e02009c  lw          $v0, 0x9C($s0)
    ctx->pc = 0x1b5fd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 156)));
    // 0x1b5fd4: 0x1000009e  b           . + 4 + (0x9E << 2)
    ctx->pc = 0x1B5FD4u;
    {
        const bool branch_taken_0x1b5fd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5FD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5FD4u;
            // 0x1b5fd8: 0xae020050  sw          $v0, 0x50($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5fd4) {
            ctx->pc = 0x1B6250u;
            goto label_1b6250;
        }
    }
    ctx->pc = 0x1B5FDCu;
label_1b5fdc:
    // 0x1b5fdc: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1b5fdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1b5fe0: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1b5fe0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1b5fe4: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B5FE4u;
    {
        const bool branch_taken_0x1b5fe4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B5FE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5FE4u;
            // 0x1b5fe8: 0x2404005f  addiu       $a0, $zero, 0x5F (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5fe4) {
            ctx->pc = 0x1B5FFCu;
            goto label_1b5ffc;
        }
    }
    ctx->pc = 0x1B5FECu;
    // 0x1b5fec: 0xc06dec0  jal         func_1B7B00
    ctx->pc = 0x1B5FECu;
    SET_GPR_U32(ctx, 31, 0x1B5FF4u);
    ctx->pc = 0x1B7B00u;
    if (runtime->hasFunction(0x1B7B00u)) {
        auto targetFn = runtime->lookupFunction(0x1B7B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5FF4u; }
        if (ctx->pc != 0x1B5FF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7B00_0x1b7b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5FF4u; }
        if (ctx->pc != 0x1B5FF4u) { return; }
    }
    ctx->pc = 0x1B5FF4u;
label_1b5ff4:
    // 0x1b5ff4: 0x100000df  b           . + 4 + (0xDF << 2)
    ctx->pc = 0x1B5FF4u;
    {
        const bool branch_taken_0x1b5ff4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5FF4u;
            // 0x1b5ff8: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5ff4) {
            ctx->pc = 0x1B6374u;
            goto label_1b6374;
        }
    }
    ctx->pc = 0x1B5FFCu;
label_1b5ffc:
    // 0x1b5ffc: 0xc065804  jal         func_196010
    ctx->pc = 0x1B5FFCu;
    SET_GPR_U32(ctx, 31, 0x1B6004u);
    ctx->pc = 0x1B6000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5FFCu;
            // 0x1b6000: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x196010u;
    if (runtime->hasFunction(0x196010u)) {
        auto targetFn = runtime->lookupFunction(0x196010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6004u; }
        if (ctx->pc != 0x1B6004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00196010_0x196010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6004u; }
        if (ctx->pc != 0x1B6004u) { return; }
    }
    ctx->pc = 0x1B6004u;
label_1b6004:
    // 0x1b6004: 0x24040060  addiu       $a0, $zero, 0x60
    ctx->pc = 0x1b6004u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x1b6008: 0xc065804  jal         func_196010
    ctx->pc = 0x1B6008u;
    SET_GPR_U32(ctx, 31, 0x1B6010u);
    ctx->pc = 0x1B600Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6008u;
            // 0x1b600c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x196010u;
    if (runtime->hasFunction(0x196010u)) {
        auto targetFn = runtime->lookupFunction(0x196010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6010u; }
        if (ctx->pc != 0x1B6010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00196010_0x196010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6010u; }
        if (ctx->pc != 0x1B6010u) { return; }
    }
    ctx->pc = 0x1B6010u;
label_1b6010:
    // 0x1b6010: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x1b6010u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1b6014: 0xc065804  jal         func_196010
    ctx->pc = 0x1B6014u;
    SET_GPR_U32(ctx, 31, 0x1B601Cu);
    ctx->pc = 0x1B6018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6014u;
            // 0x1b6018: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x196010u;
    if (runtime->hasFunction(0x196010u)) {
        auto targetFn = runtime->lookupFunction(0x196010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B601Cu; }
        if (ctx->pc != 0x1B601Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00196010_0x196010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B601Cu; }
        if (ctx->pc != 0x1B601Cu) { return; }
    }
    ctx->pc = 0x1B601Cu;
label_1b601c:
    // 0x1b601c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b601cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b6020: 0x902343d6  lbu         $v1, 0x43D6($at)
    ctx->pc = 0x1b6020u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17366)));
    // 0x1b6024: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B6024u;
    {
        const bool branch_taken_0x1b6024 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6024u;
            // 0x1b6028: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6024) {
            ctx->pc = 0x1B6038u;
            goto label_1b6038;
        }
    }
    ctx->pc = 0x1B602Cu;
    // 0x1b602c: 0x902343ea  lbu         $v1, 0x43EA($at)
    ctx->pc = 0x1b602cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17386)));
    // 0x1b6030: 0x106000cf  beqz        $v1, . + 4 + (0xCF << 2)
    ctx->pc = 0x1B6030u;
    {
        const bool branch_taken_0x1b6030 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6030) {
            ctx->pc = 0x1B6370u;
            goto label_1b6370;
        }
    }
    ctx->pc = 0x1B6038u;
label_1b6038:
    // 0x1b6038: 0x8e020088  lw          $v0, 0x88($s0)
    ctx->pc = 0x1b6038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 136)));
    // 0x1b603c: 0x18400092  blez        $v0, . + 4 + (0x92 << 2)
    ctx->pc = 0x1B603Cu;
    {
        const bool branch_taken_0x1b603c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1B6040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B603Cu;
            // 0x1b6040: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b603c) {
            ctx->pc = 0x1B6288u;
            goto label_1b6288;
        }
    }
    ctx->pc = 0x1B6044u;
    // 0x1b6044: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b6044u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b6048: 0x902243ea  lbu         $v0, 0x43EA($at)
    ctx->pc = 0x1b6048u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17386)));
    // 0x1b604c: 0x1040006b  beqz        $v0, . + 4 + (0x6B << 2)
    ctx->pc = 0x1B604Cu;
    {
        const bool branch_taken_0x1b604c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B604Cu;
            // 0x1b6050: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b604c) {
            ctx->pc = 0x1B61FCu;
            goto label_1b61fc;
        }
    }
    ctx->pc = 0x1B6054u;
    // 0x1b6054: 0x8c22f704  lw          $v0, -0x8FC($at)
    ctx->pc = 0x1b6054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294964996)));
    // 0x1b6058: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B6058u;
    {
        const bool branch_taken_0x1b6058 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b6058) {
            ctx->pc = 0x1B6070u;
            goto label_1b6070;
        }
    }
    ctx->pc = 0x1B6060u;
    // 0x1b6060: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b6060u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b6064: 0x8c22f708  lw          $v0, -0x8F8($at)
    ctx->pc = 0x1b6064u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965000)));
    // 0x1b6068: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6068u;
    {
        const bool branch_taken_0x1b6068 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6068) {
            ctx->pc = 0x1B6078u;
            goto label_1b6078;
        }
    }
    ctx->pc = 0x1B6070u;
label_1b6070:
    // 0x1b6070: 0xc063594  jal         func_18D650
    ctx->pc = 0x1B6070u;
    SET_GPR_U32(ctx, 31, 0x1B6078u);
    ctx->pc = 0x18D650u;
    if (runtime->hasFunction(0x18D650u)) {
        auto targetFn = runtime->lookupFunction(0x18D650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6078u; }
        if (ctx->pc != 0x1B6078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D650_0x18d650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6078u; }
        if (ctx->pc != 0x1B6078u) { return; }
    }
    ctx->pc = 0x1B6078u;
label_1b6078:
    // 0x1b6078: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b6078u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b607c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b607cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b6080: 0x902343c3  lbu         $v1, 0x43C3($at)
    ctx->pc = 0x1b6080u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17347)));
    // 0x1b6084: 0x10620030  beq         $v1, $v0, . + 4 + (0x30 << 2)
    ctx->pc = 0x1B6084u;
    {
        const bool branch_taken_0x1b6084 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1b6084) {
            ctx->pc = 0x1B6148u;
            goto label_1b6148;
        }
    }
    ctx->pc = 0x1B608Cu;
    // 0x1b608c: 0x3c10002c  lui         $s0, 0x2C
    ctx->pc = 0x1b608cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
    // 0x1b6090: 0xc06d694  jal         func_1B5A50
    ctx->pc = 0x1B6090u;
    SET_GPR_U32(ctx, 31, 0x1B6098u);
    ctx->pc = 0x1B6094u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6090u;
            // 0x1b6094: 0x2610aa40  addiu       $s0, $s0, -0x55C0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5A50u;
    if (runtime->hasFunction(0x1B5A50u)) {
        auto targetFn = runtime->lookupFunction(0x1B5A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6098u; }
        if (ctx->pc != 0x1B6098u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5A50_0x1b5a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6098u; }
        if (ctx->pc != 0x1B6098u) { return; }
    }
    ctx->pc = 0x1B6098u;
label_1b6098:
    // 0x1b6098: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b6098u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b609c: 0x2405ffbf  addiu       $a1, $zero, -0x41
    ctx->pc = 0x1b609cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
    // 0x1b60a0: 0x8c28fd7c  lw          $t0, -0x284($at)
    ctx->pc = 0x1b60a0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966652)));
    // 0x1b60a4: 0x64060040  daddiu      $a2, $zero, 0x40
    ctx->pc = 0x1b60a4u;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)64);
    // 0x1b60a8: 0x2402ff7f  addiu       $v0, $zero, -0x81
    ctx->pc = 0x1b60a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x1b60ac: 0x64030080  daddiu      $v1, $zero, 0x80
    ctx->pc = 0x1b60acu;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)128);
    // 0x1b60b0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b60b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b60b4: 0x91070000  lbu         $a3, 0x0($t0)
    ctx->pc = 0x1b60b4u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1b60b8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b60b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b60bc: 0xe52824  and         $a1, $a3, $a1
    ctx->pc = 0x1b60bcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & GPR_U64(ctx, 5));
    // 0x1b60c0: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x1b60c0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x1b60c4: 0xa1050000  sb          $a1, 0x0($t0)
    ctx->pc = 0x1b60c4u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1b60c8: 0x8c26fd7c  lw          $a2, -0x284($at)
    ctx->pc = 0x1b60c8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966652)));
    // 0x1b60cc: 0x90c50000  lbu         $a1, 0x0($a2)
    ctx->pc = 0x1b60ccu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1b60d0: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x1b60d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x1b60d4: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1b60d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1b60d8: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1B60D8u;
    SET_GPR_U32(ctx, 31, 0x1B60E0u);
    ctx->pc = 0x1B60DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B60D8u;
            // 0x1b60dc: 0xa0c20000  sb          $v0, 0x0($a2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B60E0u; }
        if (ctx->pc != 0x1B60E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B60E0u; }
        if (ctx->pc != 0x1B60E0u) { return; }
    }
    ctx->pc = 0x1B60E0u;
label_1b60e0:
    // 0x1b60e0: 0x3c011001  lui         $at, 0x1001
    ctx->pc = 0x1b60e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4097 << 16));
    // 0x1b60e4: 0x8c22a000  lw          $v0, -0x6000($at)
    ctx->pc = 0x1b60e4u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294942720))); // MMIO: 0x1000a000
    // 0x1b60e8: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x1b60e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x1b60ec: 0x0  nop
    ctx->pc = 0x1b60ecu;
    // NOP
    // 0x1b60f0: 0x0  nop
    ctx->pc = 0x1b60f0u;
    // NOP
    // 0x1b60f4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B60F4u;
    {
        const bool branch_taken_0x1b60f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b60f4) {
            ctx->pc = 0x1B60E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b60e0;
        }
    }
    ctx->pc = 0x1B60FCu;
    // 0x1b60fc: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x1b60fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1b6100: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b6100u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b6104: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1b6104u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1b6108: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b6108u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b610c: 0x8c450038  lw          $a1, 0x38($v0)
    ctx->pc = 0x1b610cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x1b6110: 0xc040ce4  jal         func_103390
    ctx->pc = 0x1B6110u;
    SET_GPR_U32(ctx, 31, 0x1B6118u);
    ctx->pc = 0x1B6114u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6110u;
            // 0x1b6114: 0x8c24fd7c  lw          $a0, -0x284($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966652)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103390u;
    if (runtime->hasFunction(0x103390u)) {
        auto targetFn = runtime->lookupFunction(0x103390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6118u; }
        if (ctx->pc != 0x1B6118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103390_0x103390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6118u; }
        if (ctx->pc != 0x1B6118u) { return; }
    }
    ctx->pc = 0x1B6118u;
label_1b6118:
    // 0x1b6118: 0x8e030048  lw          $v1, 0x48($s0)
    ctx->pc = 0x1b6118u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1b611c: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1b611cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1b6120: 0xae030048  sw          $v1, 0x48($s0)
    ctx->pc = 0x1b6120u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 3));
    // 0x1b6124: 0x8e030048  lw          $v1, 0x48($s0)
    ctx->pc = 0x1b6124u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1b6128: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b6128u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b612c: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1b612cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b6130: 0x8c630040  lw          $v1, 0x40($v1)
    ctx->pc = 0x1b6130u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 64)));
    // 0x1b6134: 0xae03004c  sw          $v1, 0x4C($s0)
    ctx->pc = 0x1b6134u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 3));
    // 0x1b6138: 0x8e030064  lw          $v1, 0x64($s0)
    ctx->pc = 0x1b6138u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x1b613c: 0xae030068  sw          $v1, 0x68($s0)
    ctx->pc = 0x1b613cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 104), GPR_U32(ctx, 3));
    // 0x1b6140: 0x1000008b  b           . + 4 + (0x8B << 2)
    ctx->pc = 0x1B6140u;
    {
        const bool branch_taken_0x1b6140 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6144u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6140u;
            // 0x1b6144: 0xae000064  sw          $zero, 0x64($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6140) {
            ctx->pc = 0x1B6370u;
            goto label_1b6370;
        }
    }
    ctx->pc = 0x1B6148u;
label_1b6148:
    // 0x1b6148: 0xc06d694  jal         func_1B5A50
    ctx->pc = 0x1B6148u;
    SET_GPR_U32(ctx, 31, 0x1B6150u);
    ctx->pc = 0x1B5A50u;
    if (runtime->hasFunction(0x1B5A50u)) {
        auto targetFn = runtime->lookupFunction(0x1B5A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6150u; }
        if (ctx->pc != 0x1B6150u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5A50_0x1b5a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6150u; }
        if (ctx->pc != 0x1B6150u) { return; }
    }
    ctx->pc = 0x1B6150u;
label_1b6150:
    // 0x1b6150: 0x8e020064  lw          $v0, 0x64($s0)
    ctx->pc = 0x1b6150u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x1b6154: 0x1040003e  beqz        $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x1B6154u;
    {
        const bool branch_taken_0x1b6154 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6154) {
            ctx->pc = 0x1B6250u;
            goto label_1b6250;
        }
    }
    ctx->pc = 0x1B615Cu;
    // 0x1b615c: 0x8e08004c  lw          $t0, 0x4C($s0)
    ctx->pc = 0x1b615cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x1b6160: 0x3c07f000  lui         $a3, 0xF000
    ctx->pc = 0x1b6160u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)61440 << 16));
    // 0x1b6164: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b6164u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b6168: 0x2405ffbf  addiu       $a1, $zero, -0x41
    ctx->pc = 0x1b6168u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
    // 0x1b616c: 0x64060040  daddiu      $a2, $zero, 0x40
    ctx->pc = 0x1b616cu;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)64);
    // 0x1b6170: 0x2402ff7f  addiu       $v0, $zero, -0x81
    ctx->pc = 0x1b6170u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x1b6174: 0x64030080  daddiu      $v1, $zero, 0x80
    ctx->pc = 0x1b6174u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)128);
    // 0x1b6178: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b6178u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b617c: 0xad070000  sw          $a3, 0x0($t0)
    ctx->pc = 0x1b617cu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 7));
    // 0x1b6180: 0xad000004  sw          $zero, 0x4($t0)
    ctx->pc = 0x1b6180u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 4), GPR_U32(ctx, 0));
    // 0x1b6184: 0xad000008  sw          $zero, 0x8($t0)
    ctx->pc = 0x1b6184u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 8), GPR_U32(ctx, 0));
    // 0x1b6188: 0xad00000c  sw          $zero, 0xC($t0)
    ctx->pc = 0x1b6188u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 12), GPR_U32(ctx, 0));
    // 0x1b618c: 0x8c28fd7c  lw          $t0, -0x284($at)
    ctx->pc = 0x1b618cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966652)));
    // 0x1b6190: 0x91070000  lbu         $a3, 0x0($t0)
    ctx->pc = 0x1b6190u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1b6194: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b6194u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b6198: 0xe52824  and         $a1, $a3, $a1
    ctx->pc = 0x1b6198u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & GPR_U64(ctx, 5));
    // 0x1b619c: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x1b619cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x1b61a0: 0xa1050000  sb          $a1, 0x0($t0)
    ctx->pc = 0x1b61a0u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1b61a4: 0x8c26fd7c  lw          $a2, -0x284($at)
    ctx->pc = 0x1b61a4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966652)));
    // 0x1b61a8: 0x90c50000  lbu         $a1, 0x0($a2)
    ctx->pc = 0x1b61a8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1b61ac: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x1b61acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x1b61b0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1b61b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1b61b4: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1B61B4u;
    SET_GPR_U32(ctx, 31, 0x1B61BCu);
    ctx->pc = 0x1B61B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B61B4u;
            // 0x1b61b8: 0xa0c20000  sb          $v0, 0x0($a2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B61BCu; }
        if (ctx->pc != 0x1B61BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B61BCu; }
        if (ctx->pc != 0x1B61BCu) { return; }
    }
    ctx->pc = 0x1B61BCu;
label_1b61bc:
    // 0x1b61bc: 0x3c011001  lui         $at, 0x1001
    ctx->pc = 0x1b61bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4097 << 16));
    // 0x1b61c0: 0x8c22a000  lw          $v0, -0x6000($at)
    ctx->pc = 0x1b61c0u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294942720))); // MMIO: 0x1000a000
    // 0x1b61c4: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x1b61c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x1b61c8: 0x0  nop
    ctx->pc = 0x1b61c8u;
    // NOP
    // 0x1b61cc: 0x0  nop
    ctx->pc = 0x1b61ccu;
    // NOP
    // 0x1b61d0: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B61D0u;
    {
        const bool branch_taken_0x1b61d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b61d0) {
            ctx->pc = 0x1B61BCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b61bc;
        }
    }
    ctx->pc = 0x1B61D8u;
    // 0x1b61d8: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x1b61d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1b61dc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b61dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b61e0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1b61e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1b61e4: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b61e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b61e8: 0x8c450038  lw          $a1, 0x38($v0)
    ctx->pc = 0x1b61e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x1b61ec: 0xc040ce4  jal         func_103390
    ctx->pc = 0x1B61ECu;
    SET_GPR_U32(ctx, 31, 0x1B61F4u);
    ctx->pc = 0x1B61F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B61ECu;
            // 0x1b61f0: 0x8c24fd7c  lw          $a0, -0x284($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966652)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103390u;
    if (runtime->hasFunction(0x103390u)) {
        auto targetFn = runtime->lookupFunction(0x103390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B61F4u; }
        if (ctx->pc != 0x1B61F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103390_0x103390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B61F4u; }
        if (ctx->pc != 0x1B61F4u) { return; }
    }
    ctx->pc = 0x1B61F4u;
label_1b61f4:
    // 0x1b61f4: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1B61F4u;
    {
        const bool branch_taken_0x1b61f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B61F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B61F4u;
            // 0x1b61f8: 0x8e020048  lw          $v0, 0x48($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b61f4) {
            ctx->pc = 0x1B6254u;
            goto label_1b6254;
        }
    }
    ctx->pc = 0x1B61FCu;
label_1b61fc:
    // 0x1b61fc: 0x8e020064  lw          $v0, 0x64($s0)
    ctx->pc = 0x1b61fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x1b6200: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B6200u;
    {
        const bool branch_taken_0x1b6200 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6200) {
            ctx->pc = 0x1B6250u;
            goto label_1b6250;
        }
    }
    ctx->pc = 0x1B6208u;
    // 0x1b6208: 0x8e03004c  lw          $v1, 0x4C($s0)
    ctx->pc = 0x1b6208u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x1b620c: 0x3c02f000  lui         $v0, 0xF000
    ctx->pc = 0x1b620cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)61440 << 16));
    // 0x1b6210: 0x3c05002a  lui         $a1, 0x2A
    ctx->pc = 0x1b6210u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)42 << 16));
    // 0x1b6214: 0x24a5f6f0  addiu       $a1, $a1, -0x910
    ctx->pc = 0x1b6214u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294964976));
    // 0x1b6218: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1b6218u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1b621c: 0xac600004  sw          $zero, 0x4($v1)
    ctx->pc = 0x1b621cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
    // 0x1b6220: 0xac600008  sw          $zero, 0x8($v1)
    ctx->pc = 0x1b6220u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 0));
    // 0x1b6224: 0xac60000c  sw          $zero, 0xC($v1)
    ctx->pc = 0x1b6224u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
    // 0x1b6228: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x1b6228u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1b622c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1b622cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1b6230: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b6230u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b6234: 0x8c420038  lw          $v0, 0x38($v0)
    ctx->pc = 0x1b6234u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x1b6238: 0x2213c  dsll32      $a0, $v0, 4
    ctx->pc = 0x1b6238u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 4));
    // 0x1b623c: 0xc0633bc  jal         func_18CEF0
    ctx->pc = 0x1B623Cu;
    SET_GPR_U32(ctx, 31, 0x1B6244u);
    ctx->pc = 0x1B6240u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B623Cu;
            // 0x1b6240: 0x4213e  dsrl32      $a0, $a0, 4 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CEF0u;
    if (runtime->hasFunction(0x18CEF0u)) {
        auto targetFn = runtime->lookupFunction(0x18CEF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6244u; }
        if (ctx->pc != 0x1B6244u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CEF0_0x18cef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6244u; }
        if (ctx->pc != 0x1B6244u) { return; }
    }
    ctx->pc = 0x1B6244u;
label_1b6244:
    // 0x1b6244: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x1b6244u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1b6248: 0xc065804  jal         func_196010
    ctx->pc = 0x1B6248u;
    SET_GPR_U32(ctx, 31, 0x1B6250u);
    ctx->pc = 0x1B624Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6248u;
            // 0x1b624c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x196010u;
    if (runtime->hasFunction(0x196010u)) {
        auto targetFn = runtime->lookupFunction(0x196010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6250u; }
        if (ctx->pc != 0x1B6250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00196010_0x196010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6250u; }
        if (ctx->pc != 0x1B6250u) { return; }
    }
    ctx->pc = 0x1B6250u;
label_1b6250:
    // 0x1b6250: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x1b6250u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
label_1b6254:
    // 0x1b6254: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1b6254u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1b6258: 0xae020048  sw          $v0, 0x48($s0)
    ctx->pc = 0x1b6258u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 2));
    // 0x1b625c: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x1b625cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1b6260: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1b6260u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1b6264: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b6264u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b6268: 0x8c420040  lw          $v0, 0x40($v0)
    ctx->pc = 0x1b6268u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x1b626c: 0xae02004c  sw          $v0, 0x4C($s0)
    ctx->pc = 0x1b626cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 2));
    // 0x1b6270: 0x8e020064  lw          $v0, 0x64($s0)
    ctx->pc = 0x1b6270u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x1b6274: 0xae020068  sw          $v0, 0x68($s0)
    ctx->pc = 0x1b6274u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 104), GPR_U32(ctx, 2));
    // 0x1b6278: 0xc06bddc  jal         func_1AF770
    ctx->pc = 0x1B6278u;
    SET_GPR_U32(ctx, 31, 0x1B6280u);
    ctx->pc = 0x1B627Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6278u;
            // 0x1b627c: 0xae000064  sw          $zero, 0x64($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF770u;
    if (runtime->hasFunction(0x1AF770u)) {
        auto targetFn = runtime->lookupFunction(0x1AF770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6280u; }
        if (ctx->pc != 0x1B6280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF770_0x1af770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6280u; }
        if (ctx->pc != 0x1B6280u) { return; }
    }
    ctx->pc = 0x1B6280u;
label_1b6280:
    // 0x1b6280: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1B6280u;
    {
        const bool branch_taken_0x1b6280 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6280) {
            ctx->pc = 0x1B6370u;
            goto label_1b6370;
        }
    }
    ctx->pc = 0x1B6288u;
label_1b6288:
    // 0x1b6288: 0x902243ea  lbu         $v0, 0x43EA($at)
    ctx->pc = 0x1b6288u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17386)));
    // 0x1b628c: 0x1040002f  beqz        $v0, . + 4 + (0x2F << 2)
    ctx->pc = 0x1B628Cu;
    {
        const bool branch_taken_0x1b628c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B628Cu;
            // 0x1b6290: 0x3c10002c  lui         $s0, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b628c) {
            ctx->pc = 0x1B634Cu;
            goto label_1b634c;
        }
    }
    ctx->pc = 0x1B6294u;
    // 0x1b6294: 0xc06d694  jal         func_1B5A50
    ctx->pc = 0x1B6294u;
    SET_GPR_U32(ctx, 31, 0x1B629Cu);
    ctx->pc = 0x1B6298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6294u;
            // 0x1b6298: 0x2610aa40  addiu       $s0, $s0, -0x55C0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5A50u;
    if (runtime->hasFunction(0x1B5A50u)) {
        auto targetFn = runtime->lookupFunction(0x1B5A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B629Cu; }
        if (ctx->pc != 0x1B629Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5A50_0x1b5a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B629Cu; }
        if (ctx->pc != 0x1B629Cu) { return; }
    }
    ctx->pc = 0x1B629Cu;
label_1b629c:
    // 0x1b629c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b629cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b62a0: 0x2405ffbf  addiu       $a1, $zero, -0x41
    ctx->pc = 0x1b62a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
    // 0x1b62a4: 0x8c28fd7c  lw          $t0, -0x284($at)
    ctx->pc = 0x1b62a4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966652)));
    // 0x1b62a8: 0x64060040  daddiu      $a2, $zero, 0x40
    ctx->pc = 0x1b62a8u;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)64);
    // 0x1b62ac: 0x2402ff7f  addiu       $v0, $zero, -0x81
    ctx->pc = 0x1b62acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x1b62b0: 0x64030080  daddiu      $v1, $zero, 0x80
    ctx->pc = 0x1b62b0u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)128);
    // 0x1b62b4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b62b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b62b8: 0x91070000  lbu         $a3, 0x0($t0)
    ctx->pc = 0x1b62b8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1b62bc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b62bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b62c0: 0xe52824  and         $a1, $a3, $a1
    ctx->pc = 0x1b62c0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & GPR_U64(ctx, 5));
    // 0x1b62c4: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x1b62c4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x1b62c8: 0xa1050000  sb          $a1, 0x0($t0)
    ctx->pc = 0x1b62c8u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1b62cc: 0x8c26fd7c  lw          $a2, -0x284($at)
    ctx->pc = 0x1b62ccu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966652)));
    // 0x1b62d0: 0x90c50000  lbu         $a1, 0x0($a2)
    ctx->pc = 0x1b62d0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1b62d4: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x1b62d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x1b62d8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1b62d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1b62dc: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1B62DCu;
    SET_GPR_U32(ctx, 31, 0x1B62E4u);
    ctx->pc = 0x1B62E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B62DCu;
            // 0x1b62e0: 0xa0c20000  sb          $v0, 0x0($a2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B62E4u; }
        if (ctx->pc != 0x1B62E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B62E4u; }
        if (ctx->pc != 0x1B62E4u) { return; }
    }
    ctx->pc = 0x1B62E4u;
label_1b62e4:
    // 0x1b62e4: 0x3c011001  lui         $at, 0x1001
    ctx->pc = 0x1b62e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4097 << 16));
    // 0x1b62e8: 0x8c22a000  lw          $v0, -0x6000($at)
    ctx->pc = 0x1b62e8u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294942720))); // MMIO: 0x1000a000
    // 0x1b62ec: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x1b62ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x1b62f0: 0x0  nop
    ctx->pc = 0x1b62f0u;
    // NOP
    // 0x1b62f4: 0x0  nop
    ctx->pc = 0x1b62f4u;
    // NOP
    // 0x1b62f8: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B62F8u;
    {
        const bool branch_taken_0x1b62f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b62f8) {
            ctx->pc = 0x1B62E4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b62e4;
        }
    }
    ctx->pc = 0x1B6300u;
    // 0x1b6300: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x1b6300u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1b6304: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1b6304u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1b6308: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1b6308u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1b630c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b630cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b6310: 0x8c450038  lw          $a1, 0x38($v0)
    ctx->pc = 0x1b6310u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x1b6314: 0xc040ce4  jal         func_103390
    ctx->pc = 0x1B6314u;
    SET_GPR_U32(ctx, 31, 0x1B631Cu);
    ctx->pc = 0x1B6318u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6314u;
            // 0x1b6318: 0x8c24fd7c  lw          $a0, -0x284($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966652)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103390u;
    if (runtime->hasFunction(0x103390u)) {
        auto targetFn = runtime->lookupFunction(0x103390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B631Cu; }
        if (ctx->pc != 0x1B631Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103390_0x103390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B631Cu; }
        if (ctx->pc != 0x1B631Cu) { return; }
    }
    ctx->pc = 0x1B631Cu;
label_1b631c:
    // 0x1b631c: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x1b631cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1b6320: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1b6320u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1b6324: 0xae020048  sw          $v0, 0x48($s0)
    ctx->pc = 0x1b6324u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 2));
    // 0x1b6328: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x1b6328u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1b632c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1b632cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1b6330: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b6330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b6334: 0x8c420040  lw          $v0, 0x40($v0)
    ctx->pc = 0x1b6334u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x1b6338: 0xae02004c  sw          $v0, 0x4C($s0)
    ctx->pc = 0x1b6338u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 2));
    // 0x1b633c: 0x8e020064  lw          $v0, 0x64($s0)
    ctx->pc = 0x1b633cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x1b6340: 0xae020068  sw          $v0, 0x68($s0)
    ctx->pc = 0x1b6340u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 104), GPR_U32(ctx, 2));
    // 0x1b6344: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B6344u;
    {
        const bool branch_taken_0x1b6344 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6344u;
            // 0x1b6348: 0xae000064  sw          $zero, 0x64($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6344) {
            ctx->pc = 0x1B6368u;
            goto label_1b6368;
        }
    }
    ctx->pc = 0x1B634Cu;
label_1b634c:
    // 0x1b634c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b634cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b6350: 0x8c22ab78  lw          $v0, -0x5488($at)
    ctx->pc = 0x1b6350u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945656)));
    // 0x1b6354: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B6354u;
    {
        const bool branch_taken_0x1b6354 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b6354) {
            ctx->pc = 0x1B6368u;
            goto label_1b6368;
        }
    }
    ctx->pc = 0x1B635Cu;
    // 0x1b635c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b635cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1b6360: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b6360u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b6364: 0xac22ab78  sw          $v0, -0x5488($at)
    ctx->pc = 0x1b6364u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945656), GPR_U32(ctx, 2));
label_1b6368:
    // 0x1b6368: 0xc06bddc  jal         func_1AF770
    ctx->pc = 0x1B6368u;
    SET_GPR_U32(ctx, 31, 0x1B6370u);
    ctx->pc = 0x1AF770u;
    if (runtime->hasFunction(0x1AF770u)) {
        auto targetFn = runtime->lookupFunction(0x1AF770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6370u; }
        if (ctx->pc != 0x1B6370u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF770_0x1af770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6370u; }
        if (ctx->pc != 0x1B6370u) { return; }
    }
    ctx->pc = 0x1B6370u;
label_1b6370:
    // 0x1b6370: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b6370u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b6374:
    // 0x1b6374: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b6374u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b6378: 0x3e00008  jr          $ra
    ctx->pc = 0x1B6378u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B637Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6378u;
            // 0x1b637c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B5FDCu: goto label_1b5fdc;
            case 0x1B5FF4u: goto label_1b5ff4;
            case 0x1B5FFCu: goto label_1b5ffc;
            case 0x1B6004u: goto label_1b6004;
            case 0x1B6010u: goto label_1b6010;
            case 0x1B601Cu: goto label_1b601c;
            case 0x1B6038u: goto label_1b6038;
            case 0x1B6070u: goto label_1b6070;
            case 0x1B6078u: goto label_1b6078;
            case 0x1B6098u: goto label_1b6098;
            case 0x1B60E0u: goto label_1b60e0;
            case 0x1B6118u: goto label_1b6118;
            case 0x1B6148u: goto label_1b6148;
            case 0x1B6150u: goto label_1b6150;
            case 0x1B61BCu: goto label_1b61bc;
            case 0x1B61F4u: goto label_1b61f4;
            case 0x1B61FCu: goto label_1b61fc;
            case 0x1B6244u: goto label_1b6244;
            case 0x1B6250u: goto label_1b6250;
            case 0x1B6254u: goto label_1b6254;
            case 0x1B6280u: goto label_1b6280;
            case 0x1B6288u: goto label_1b6288;
            case 0x1B629Cu: goto label_1b629c;
            case 0x1B62E4u: goto label_1b62e4;
            case 0x1B631Cu: goto label_1b631c;
            case 0x1B634Cu: goto label_1b634c;
            case 0x1B6368u: goto label_1b6368;
            case 0x1B6370u: goto label_1b6370;
            case 0x1B6374u: goto label_1b6374;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B6380u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
