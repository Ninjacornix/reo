#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A050
// Address: 0x10a050 - 0x10a1d0
void sub_0010A050_0x10a050(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A050_0x10a050");
#endif

    switch (ctx->pc) {
        case 0x10a090u: goto label_10a090;
        case 0x10a0d0u: goto label_10a0d0;
        case 0x10a118u: goto label_10a118;
        case 0x10a14cu: goto label_10a14c;
        case 0x10a168u: goto label_10a168;
        case 0x10a180u: goto label_10a180;
        default: break;
    }

    ctx->pc = 0x10a050u;

    // 0x10a050: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10a050u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10a054: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10a054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10a058: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x10a058u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a05c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x10a05cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x10a060: 0x8e030054  lw          $v1, 0x54($s0)
    ctx->pc = 0x10a060u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10a064: 0x54600006  bnel        $v1, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x10A064u;
    {
        const bool branch_taken_0x10a064 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x10a064) {
            ctx->pc = 0x10A068u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A064u;
            // 0x10a068: 0x8c620038  lw          $v0, 0x38($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A080u;
            goto label_10a080;
        }
    }
    ctx->pc = 0x10A06Cu;
    // 0x10a06c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x10a06cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x10a070: 0x8c4397f0  lw          $v1, -0x6810($v0)
    ctx->pc = 0x10a070u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x10a074: 0xae030054  sw          $v1, 0x54($s0)
    ctx->pc = 0x10a074u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 3));
    // 0x10a078: 0x8c620038  lw          $v0, 0x38($v1)
    ctx->pc = 0x10a078u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 56)));
    // 0x10a07c: 0x0  nop
    ctx->pc = 0x10a07cu;
    // NOP
label_10a080:
    // 0x10a080: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x10A080u;
    {
        const bool branch_taken_0x10a080 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10a080) {
            ctx->pc = 0x10A084u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A080u;
            // 0x10a084: 0x9604000c  lhu         $a0, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A094u;
            goto label_10a094;
        }
    }
    ctx->pc = 0x10A088u;
    // 0x10a088: 0xc041544  jal         func_105510
    ctx->pc = 0x10A088u;
    SET_GPR_U32(ctx, 31, 0x10A090u);
    ctx->pc = 0x10A08Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A088u;
            // 0x10a08c: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105510u;
    if (runtime->hasFunction(0x105510u)) {
        auto targetFn = runtime->lookupFunction(0x105510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A090u; }
        if (ctx->pc != 0x10A090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105510_0x105510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A090u; }
        if (ctx->pc != 0x10A090u) { return; }
    }
    ctx->pc = 0x10A090u;
label_10a090:
    // 0x10a090: 0x9604000c  lhu         $a0, 0xC($s0)
    ctx->pc = 0x10a090u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
label_10a094:
    // 0x10a094: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10a094u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10a098: 0x30830020  andi        $v1, $a0, 0x20
    ctx->pc = 0x10a098u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32);
    // 0x10a09c: 0x14600047  bnez        $v1, . + 4 + (0x47 << 2)
    ctx->pc = 0x10A09Cu;
    {
        const bool branch_taken_0x10a09c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A0A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A09Cu;
            // 0x10a0a0: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a09c) {
            ctx->pc = 0x10A1BCu;
            goto label_10a1bc;
        }
    }
    ctx->pc = 0x10A0A4u;
    // 0x10a0a4: 0x30820004  andi        $v0, $a0, 0x4
    ctx->pc = 0x10a0a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)4);
    // 0x10a0a8: 0x54400015  bnel        $v0, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x10A0A8u;
    {
        const bool branch_taken_0x10a0a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10a0a8) {
            ctx->pc = 0x10A0ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A0A8u;
            // 0x10a0ac: 0x8e050030  lw          $a1, 0x30($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A100u;
            goto label_10a100;
        }
    }
    ctx->pc = 0x10A0B0u;
    // 0x10a0b0: 0x30830010  andi        $v1, $a0, 0x10
    ctx->pc = 0x10a0b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)16);
    // 0x10a0b4: 0x10600041  beqz        $v1, . + 4 + (0x41 << 2)
    ctx->pc = 0x10A0B4u;
    {
        const bool branch_taken_0x10a0b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A0B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A0B4u;
            // 0x10a0b8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a0b4) {
            ctx->pc = 0x10A1BCu;
            goto label_10a1bc;
        }
    }
    ctx->pc = 0x10A0BCu;
    // 0x10a0bc: 0x30820008  andi        $v0, $a0, 0x8
    ctx->pc = 0x10a0bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8);
    // 0x10a0c0: 0x5040000c  beql        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x10A0C0u;
    {
        const bool branch_taken_0x10a0c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10a0c0) {
            ctx->pc = 0x10A0C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A0C0u;
            // 0x10a0c4: 0x34820004  ori         $v0, $a0, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A0F4u;
            goto label_10a0f4;
        }
    }
    ctx->pc = 0x10A0C8u;
    // 0x10a0c8: 0xc04142c  jal         func_1050B0
    ctx->pc = 0x10A0C8u;
    SET_GPR_U32(ctx, 31, 0x10A0D0u);
    ctx->pc = 0x10A0CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A0C8u;
            // 0x10a0cc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1050B0u;
    if (runtime->hasFunction(0x1050B0u)) {
        auto targetFn = runtime->lookupFunction(0x1050B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A0D0u; }
        if (ctx->pc != 0x10A0D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001050B0_0x1050b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A0D0u; }
        if (ctx->pc != 0x10A0D0u) { return; }
    }
    ctx->pc = 0x10A0D0u;
label_10a0d0:
    // 0x10a0d0: 0x1440003a  bnez        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x10A0D0u;
    {
        const bool branch_taken_0x10a0d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A0D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A0D0u;
            // 0x10a0d4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a0d0) {
            ctx->pc = 0x10A1BCu;
            goto label_10a1bc;
        }
    }
    ctx->pc = 0x10A0D8u;
    // 0x10a0d8: 0x9602000c  lhu         $v0, 0xC($s0)
    ctx->pc = 0x10a0d8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x10a0dc: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x10a0dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x10a0e0: 0x3042fff7  andi        $v0, $v0, 0xFFF7
    ctx->pc = 0x10a0e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65527);
    // 0x10a0e4: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x10a0e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x10a0e8: 0xa602000c  sh          $v0, 0xC($s0)
    ctx->pc = 0x10a0e8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x10a0ec: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10a0ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a0f0: 0x34820004  ori         $v0, $a0, 0x4
    ctx->pc = 0x10a0f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4);
label_10a0f4:
    // 0x10a0f4: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x10A0F4u;
    {
        const bool branch_taken_0x10a0f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A0F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A0F4u;
            // 0x10a0f8: 0xa602000c  sh          $v0, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a0f4) {
            ctx->pc = 0x10A138u;
            goto label_10a138;
        }
    }
    ctx->pc = 0x10A0FCu;
    // 0x10a0fc: 0x0  nop
    ctx->pc = 0x10a0fcu;
    // NOP
label_10a100:
    // 0x10a100: 0x10a0000d  beqz        $a1, . + 4 + (0xD << 2)
    ctx->pc = 0x10A100u;
    {
        const bool branch_taken_0x10a100 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A100u;
            // 0x10a104: 0x26020040  addiu       $v0, $s0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a100) {
            ctx->pc = 0x10A138u;
            goto label_10a138;
        }
    }
    ctx->pc = 0x10A108u;
    // 0x10a108: 0x50a20004  beql        $a1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10A108u;
    {
        const bool branch_taken_0x10a108 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x10a108) {
            ctx->pc = 0x10A10Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A108u;
            // 0x10a10c: 0x8e02003c  lw          $v0, 0x3C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A11Cu;
            goto label_10a11c;
        }
    }
    ctx->pc = 0x10A110u;
    // 0x10a110: 0xc041636  jal         func_1058D8
    ctx->pc = 0x10A110u;
    SET_GPR_U32(ctx, 31, 0x10A118u);
    ctx->pc = 0x10A114u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A110u;
            // 0x10a114: 0x8e040054  lw          $a0, 0x54($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A118u; }
        if (ctx->pc != 0x10A118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A118u; }
        if (ctx->pc != 0x10A118u) { return; }
    }
    ctx->pc = 0x10A118u;
label_10a118:
    // 0x10a118: 0x8e02003c  lw          $v0, 0x3C($s0)
    ctx->pc = 0x10a118u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
label_10a11c:
    // 0x10a11c: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x10a11cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x10a120: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10A120u;
    {
        const bool branch_taken_0x10a120 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A120u;
            // 0x10a124: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a120) {
            ctx->pc = 0x10A138u;
            goto label_10a138;
        }
    }
    ctx->pc = 0x10A128u;
    // 0x10a128: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x10a128u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x10a12c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10a12cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a130: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x10A130u;
    {
        const bool branch_taken_0x10a130 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A130u;
            // 0x10a134: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a130) {
            ctx->pc = 0x10A1BCu;
            goto label_10a1bc;
        }
    }
    ctx->pc = 0x10A138u;
label_10a138:
    // 0x10a138: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x10a138u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x10a13c: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x10A13Cu;
    {
        const bool branch_taken_0x10a13c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10a13c) {
            ctx->pc = 0x10A140u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A13Cu;
            // 0x10a140: 0x9602000c  lhu         $v0, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A150u;
            goto label_10a150;
        }
    }
    ctx->pc = 0x10A144u;
    // 0x10a144: 0xc041ad6  jal         func_106B58
    ctx->pc = 0x10A144u;
    SET_GPR_U32(ctx, 31, 0x10A14Cu);
    ctx->pc = 0x10A148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A144u;
            // 0x10a148: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106B58u;
    if (runtime->hasFunction(0x106B58u)) {
        auto targetFn = runtime->lookupFunction(0x106B58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A14Cu; }
        if (ctx->pc != 0x10A14Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106B58_0x106b58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A14Cu; }
        if (ctx->pc != 0x10A14Cu) { return; }
    }
    ctx->pc = 0x10A14Cu;
label_10a14c:
    // 0x10a14c: 0x9602000c  lhu         $v0, 0xC($s0)
    ctx->pc = 0x10a14cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
label_10a150:
    // 0x10a150: 0x30420003  andi        $v0, $v0, 0x3
    ctx->pc = 0x10a150u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x10a154: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10A154u;
    {
        const bool branch_taken_0x10a154 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A154u;
            // 0x10a158: 0x3c050011  lui         $a1, 0x11 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)17 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a154) {
            ctx->pc = 0x10A168u;
            goto label_10a168;
        }
    }
    ctx->pc = 0x10A15Cu;
    // 0x10a15c: 0x8e040054  lw          $a0, 0x54($s0)
    ctx->pc = 0x10a15cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x10a160: 0xc0419ce  jal         func_106738
    ctx->pc = 0x10A160u;
    SET_GPR_U32(ctx, 31, 0x10A168u);
    ctx->pc = 0x10A164u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A160u;
            // 0x10a164: 0x24a5a018  addiu       $a1, $a1, -0x5FE8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294942744));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106738u;
    if (runtime->hasFunction(0x106738u)) {
        auto targetFn = runtime->lookupFunction(0x106738u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A168u; }
        if (ctx->pc != 0x10A168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106738_0x106738(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A168u; }
        if (ctx->pc != 0x10A168u) { return; }
    }
    ctx->pc = 0x10A168u;
label_10a168:
    // 0x10a168: 0x8e050010  lw          $a1, 0x10($s0)
    ctx->pc = 0x10a168u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x10a16c: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x10a16cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x10a170: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x10a170u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x10a174: 0xae050000  sw          $a1, 0x0($s0)
    ctx->pc = 0x10a174u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 5));
    // 0x10a178: 0x40f809  jalr        $v0
    ctx->pc = 0x10A178u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x10A180u);
        ctx->pc = 0x10A17Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A178u;
            // 0x10a17c: 0x8e060014  lw          $a2, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x10A180u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A080u: goto label_10a080;
            case 0x10A090u: goto label_10a090;
            case 0x10A094u: goto label_10a094;
            case 0x10A0D0u: goto label_10a0d0;
            case 0x10A0F4u: goto label_10a0f4;
            case 0x10A100u: goto label_10a100;
            case 0x10A118u: goto label_10a118;
            case 0x10A11Cu: goto label_10a11c;
            case 0x10A138u: goto label_10a138;
            case 0x10A14Cu: goto label_10a14c;
            case 0x10A150u: goto label_10a150;
            case 0x10A168u: goto label_10a168;
            case 0x10A180u: goto label_10a180;
            case 0x10A1B0u: goto label_10a1b0;
            case 0x10A1B4u: goto label_10a1b4;
            case 0x10A1BCu: goto label_10a1bc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x10A180u; }
            if (ctx->pc != 0x10A180u) { return; }
        }
        }
    }
    ctx->pc = 0x10A180u;
label_10a180:
    // 0x10a180: 0x9603000c  lhu         $v1, 0xC($s0)
    ctx->pc = 0x10a180u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x10a184: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10a184u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a188: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10a188u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a18c: 0x3063dfff  andi        $v1, $v1, 0xDFFF
    ctx->pc = 0x10a18cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)57343);
    // 0x10a190: 0xae040004  sw          $a0, 0x4($s0)
    ctx->pc = 0x10a190u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 4));
    // 0x10a194: 0x1c800009  bgtz        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10A194u;
    {
        const bool branch_taken_0x10a194 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x10A198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A194u;
            // 0x10a198: 0xa603000c  sh          $v1, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a194) {
            ctx->pc = 0x10A1BCu;
            goto label_10a1bc;
        }
    }
    ctx->pc = 0x10A19Cu;
    // 0x10a19c: 0x54800004  bnel        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x10A19Cu;
    {
        const bool branch_taken_0x10a19c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x10a19c) {
            ctx->pc = 0x10A1A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A19Cu;
            // 0x10a1a0: 0x34620040  ori         $v0, $v1, 0x40 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)64);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A1B0u;
            goto label_10a1b0;
        }
    }
    ctx->pc = 0x10A1A4u;
    // 0x10a1a4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x10A1A4u;
    {
        const bool branch_taken_0x10a1a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A1A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A1A4u;
            // 0x10a1a8: 0x34620020  ori         $v0, $v1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)32);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a1a4) {
            ctx->pc = 0x10A1B4u;
            goto label_10a1b4;
        }
    }
    ctx->pc = 0x10A1ACu;
    // 0x10a1ac: 0x0  nop
    ctx->pc = 0x10a1acu;
    // NOP
label_10a1b0:
    // 0x10a1b0: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x10a1b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
label_10a1b4:
    // 0x10a1b4: 0xa602000c  sh          $v0, 0xC($s0)
    ctx->pc = 0x10a1b4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x10a1b8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10a1b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_10a1bc:
    // 0x10a1bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10a1bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a1c0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x10a1c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10a1c4: 0x3e00008  jr          $ra
    ctx->pc = 0x10A1C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A1C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A1C4u;
            // 0x10a1c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A080u: goto label_10a080;
            case 0x10A090u: goto label_10a090;
            case 0x10A094u: goto label_10a094;
            case 0x10A0D0u: goto label_10a0d0;
            case 0x10A0F4u: goto label_10a0f4;
            case 0x10A100u: goto label_10a100;
            case 0x10A118u: goto label_10a118;
            case 0x10A11Cu: goto label_10a11c;
            case 0x10A138u: goto label_10a138;
            case 0x10A14Cu: goto label_10a14c;
            case 0x10A150u: goto label_10a150;
            case 0x10A168u: goto label_10a168;
            case 0x10A180u: goto label_10a180;
            case 0x10A1B0u: goto label_10a1b0;
            case 0x10A1B4u: goto label_10a1b4;
            case 0x10A1BCu: goto label_10a1bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A1CCu;
    // 0x10a1cc: 0x0  nop
    ctx->pc = 0x10a1ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
