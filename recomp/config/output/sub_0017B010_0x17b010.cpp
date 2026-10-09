#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017B010
// Address: 0x17b010 - 0x17b530
void sub_0017B010_0x17b010(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017B010_0x17b010");
#endif

    switch (ctx->pc) {
        case 0x17b04cu: goto label_17b04c;
        case 0x17b054u: goto label_17b054;
        case 0x17b064u: goto label_17b064;
        case 0x17b074u: goto label_17b074;
        case 0x17b138u: goto label_17b138;
        case 0x17b174u: goto label_17b174;
        case 0x17b1a8u: goto label_17b1a8;
        case 0x17b1d8u: goto label_17b1d8;
        case 0x17b208u: goto label_17b208;
        case 0x17b238u: goto label_17b238;
        case 0x17b2d4u: goto label_17b2d4;
        case 0x17b32cu: goto label_17b32c;
        case 0x17b344u: goto label_17b344;
        case 0x17b3e8u: goto label_17b3e8;
        case 0x17b43cu: goto label_17b43c;
        case 0x17b524u: goto label_17b524;
        default: break;
    }

    ctx->pc = 0x17b010u;

    // 0x17b010: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17b010u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17b014: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17b014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17b018: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17b018u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b01c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17b01cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17b020: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17b020u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b024: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17b024u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17b028: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x17b028u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b02c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x17b02cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x17b030: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x17b030u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b034: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17b034u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17b038: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b038u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b03c: 0xae090044  sw          $t1, 0x44($s0)
    ctx->pc = 0x17b03cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 9));
    // 0x17b040: 0x100302d  daddu       $a2, $t0, $zero
    ctx->pc = 0x17b040u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b044: 0xc05f550  jal         func_17D540
    ctx->pc = 0x17B044u;
    SET_GPR_U32(ctx, 31, 0x17B04Cu);
    ctx->pc = 0x17B048u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B044u;
            // 0x17b048: 0xae0a0048  sw          $t2, 0x48($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D540u;
    if (runtime->hasFunction(0x17D540u)) {
        auto targetFn = runtime->lookupFunction(0x17D540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B04Cu; }
        if (ctx->pc != 0x17B04Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D540_0x17d540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B04Cu; }
        if (ctx->pc != 0x17B04Cu) { return; }
    }
    ctx->pc = 0x17B04Cu;
label_17b04c:
    // 0x17b04c: 0xc05f494  jal         func_17D250
    ctx->pc = 0x17B04Cu;
    SET_GPR_U32(ctx, 31, 0x17B054u);
    ctx->pc = 0x17B050u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B04Cu;
            // 0x17b050: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D250u;
    if (runtime->hasFunction(0x17D250u)) {
        auto targetFn = runtime->lookupFunction(0x17D250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B054u; }
        if (ctx->pc != 0x17B054u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D250_0x17d250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B054u; }
        if (ctx->pc != 0x17B054u) { return; }
    }
    ctx->pc = 0x17B054u;
label_17b054:
    // 0x17b054: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17b054u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b058: 0x24050011  addiu       $a1, $zero, 0x11
    ctx->pc = 0x17b058u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x17b05c: 0xc05f492  jal         func_17D248
    ctx->pc = 0x17B05Cu;
    SET_GPR_U32(ctx, 31, 0x17B064u);
    ctx->pc = 0x17B060u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B05Cu;
            // 0x17b060: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D248u;
    if (runtime->hasFunction(0x17D248u)) {
        auto targetFn = runtime->lookupFunction(0x17D248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B064u; }
        if (ctx->pc != 0x17B064u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D248_0x17d248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B064u; }
        if (ctx->pc != 0x17B064u) { return; }
    }
    ctx->pc = 0x17B064u;
label_17b064:
    // 0x17b064: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17b064u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b068: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17b068u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b06c: 0xc05ea46  jal         func_17A918
    ctx->pc = 0x17B06Cu;
    SET_GPR_U32(ctx, 31, 0x17B074u);
    ctx->pc = 0x17B070u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B06Cu;
            // 0x17b070: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A918u;
    if (runtime->hasFunction(0x17A918u)) {
        auto targetFn = runtime->lookupFunction(0x17A918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B074u; }
        if (ctx->pc != 0x17B074u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A918_0x17a918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B074u; }
        if (ctx->pc != 0x17B074u) { return; }
    }
    ctx->pc = 0x17B074u;
label_17b074:
    // 0x17b074: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17b074u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b078: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17b078u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b07c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b07cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b080: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b080u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b084: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b084u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b088: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17b088u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b08c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17b08cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17b090: 0x805f492  j           func_17D248
    ctx->pc = 0x17B090u;
    ctx->pc = 0x17B094u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B090u;
            // 0x17b094: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D248u;
    if (runtime->hasFunction(0x17D248u)) {
        auto targetFn = runtime->lookupFunction(0x17D248u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D248_0x17d248(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B098u;
    // 0x17b098: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17b098u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17b09c: 0x24020041  addiu       $v0, $zero, 0x41
    ctx->pc = 0x17b09cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x17b0a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17b0a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17b0a4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17b0a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b0a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17b0a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17b0ac: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17b0acu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b0b0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17b0b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17b0b4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17b0b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17b0b8: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x17b0b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17b0bc: 0x10620050  beq         $v1, $v0, . + 4 + (0x50 << 2)
    ctx->pc = 0x17B0BCu;
    {
        const bool branch_taken_0x17b0bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B0C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B0BCu;
            // 0x17b0c0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b0bc) {
            ctx->pc = 0x17B200u;
            goto label_17b200;
        }
    }
    ctx->pc = 0x17B0C4u;
    // 0x17b0c4: 0x28620042  slti        $v0, $v1, 0x42
    ctx->pc = 0x17b0c4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)66) ? 1 : 0);
    // 0x17b0c8: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x17B0C8u;
    {
        const bool branch_taken_0x17b0c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B0CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B0C8u;
            // 0x17b0cc: 0x24020101  addiu       $v0, $zero, 0x101 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b0c8) {
            ctx->pc = 0x17B108u;
            goto label_17b108;
        }
    }
    ctx->pc = 0x17B0D0u;
    // 0x17b0d0: 0x24020021  addiu       $v0, $zero, 0x21
    ctx->pc = 0x17b0d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x17b0d4: 0x10620056  beq         $v1, $v0, . + 4 + (0x56 << 2)
    ctx->pc = 0x17B0D4u;
    {
        const bool branch_taken_0x17b0d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B0D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B0D4u;
            // 0x17b0d8: 0x28620022  slti        $v0, $v1, 0x22 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)34) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b0d4) {
            ctx->pc = 0x17B230u;
            goto label_17b230;
        }
    }
    ctx->pc = 0x17B0DCu;
    // 0x17b0dc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17B0DCu;
    {
        const bool branch_taken_0x17b0dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B0E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B0DCu;
            // 0x17b0e0: 0x24020031  addiu       $v0, $zero, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b0dc) {
            ctx->pc = 0x17B0F8u;
            goto label_17b0f8;
        }
    }
    ctx->pc = 0x17B0E4u;
    // 0x17b0e4: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x17b0e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x17b0e8: 0x10620011  beq         $v1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x17B0E8u;
    {
        const bool branch_taken_0x17b0e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17b0e8) {
            ctx->pc = 0x17B130u;
            goto label_17b130;
        }
    }
    ctx->pc = 0x17B0F0u;
    // 0x17b0f0: 0x1000005c  b           . + 4 + (0x5C << 2)
    ctx->pc = 0x17B0F0u;
    {
        const bool branch_taken_0x17b0f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B0F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B0F0u;
            // 0x17b0f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b0f0) {
            ctx->pc = 0x17B264u;
            goto label_17b264;
        }
    }
    ctx->pc = 0x17B0F8u;
label_17b0f8:
    // 0x17b0f8: 0x10620035  beq         $v1, $v0, . + 4 + (0x35 << 2)
    ctx->pc = 0x17B0F8u;
    {
        const bool branch_taken_0x17b0f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17b0f8) {
            ctx->pc = 0x17B1D0u;
            goto label_17b1d0;
        }
    }
    ctx->pc = 0x17B100u;
    // 0x17b100: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x17B100u;
    {
        const bool branch_taken_0x17b100 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B100u;
            // 0x17b104: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b100) {
            ctx->pc = 0x17B264u;
            goto label_17b264;
        }
    }
    ctx->pc = 0x17B108u;
label_17b108:
    // 0x17b108: 0x10620055  beq         $v1, $v0, . + 4 + (0x55 << 2)
    ctx->pc = 0x17B108u;
    {
        const bool branch_taken_0x17b108 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B10Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B108u;
            // 0x17b10c: 0x28620102  slti        $v0, $v1, 0x102 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)258) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b108) {
            ctx->pc = 0x17B260u;
            goto label_17b260;
        }
    }
    ctx->pc = 0x17B110u;
    // 0x17b110: 0x54400054  bnel        $v0, $zero, . + 4 + (0x54 << 2)
    ctx->pc = 0x17B110u;
    {
        const bool branch_taken_0x17b110 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17b110) {
            ctx->pc = 0x17B114u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17B110u;
            // 0x17b114: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17B264u;
            goto label_17b264;
        }
    }
    ctx->pc = 0x17B118u;
    // 0x17b118: 0x24021001  addiu       $v0, $zero, 0x1001
    ctx->pc = 0x17b118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4097));
    // 0x17b11c: 0x10620020  beq         $v1, $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x17B11Cu;
    {
        const bool branch_taken_0x17b11c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17b11c) {
            ctx->pc = 0x17B1A0u;
            goto label_17b1a0;
        }
    }
    ctx->pc = 0x17B124u;
    // 0x17b124: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x17B124u;
    {
        const bool branch_taken_0x17b124 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B124u;
            // 0x17b128: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b124) {
            ctx->pc = 0x17B264u;
            goto label_17b264;
        }
    }
    ctx->pc = 0x17B12Cu;
    // 0x17b12c: 0x0  nop
    ctx->pc = 0x17b12cu;
    // NOP
label_17b130:
    // 0x17b130: 0xc05f51a  jal         func_17D468
    ctx->pc = 0x17B130u;
    SET_GPR_U32(ctx, 31, 0x17B138u);
    ctx->pc = 0x17D468u;
    if (runtime->hasFunction(0x17D468u)) {
        auto targetFn = runtime->lookupFunction(0x17D468u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B138u; }
        if (ctx->pc != 0x17B138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D468_0x17d468(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B138u; }
        if (ctx->pc != 0x17B138u) { return; }
    }
    ctx->pc = 0x17B138u;
label_17b138:
    // 0x17b138: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17b138u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b13c: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x17B13Cu;
    {
        const bool branch_taken_0x17b13c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17B140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B13Cu;
            // 0x17b140: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b13c) {
            ctx->pc = 0x17B168u;
            goto label_17b168;
        }
    }
    ctx->pc = 0x17B144u;
    // 0x17b144: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b144u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b148: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b148u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b14c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b14cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b150: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b150u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b154: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b154u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b158: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b158u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b15c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17b15cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b160: 0x805eca2  j           func_17B288
    ctx->pc = 0x17B160u;
    ctx->pc = 0x17B164u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B160u;
            // 0x17b164: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B288u;
    goto label_17b288;
    ctx->pc = 0x17B168u;
label_17b168:
    // 0x17b168: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b168u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b16c: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B16Cu;
    SET_GPR_U32(ctx, 31, 0x17B174u);
    ctx->pc = 0x17B170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B16Cu;
            // 0x17b170: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B174u; }
        if (ctx->pc != 0x17B174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B174u; }
        if (ctx->pc != 0x17B174u) { return; }
    }
    ctx->pc = 0x17B174u;
label_17b174:
    // 0x17b174: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b174u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b178: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b178u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b17c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b17cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b180: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b180u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b184: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b184u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b188: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b188u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b18c: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17b18cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b190: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b190u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b194: 0x805eca2  j           func_17B288
    ctx->pc = 0x17B194u;
    ctx->pc = 0x17B198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B194u;
            // 0x17b198: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B288u;
    goto label_17b288;
    ctx->pc = 0x17B19Cu;
    // 0x17b19c: 0x0  nop
    ctx->pc = 0x17b19cu;
    // NOP
label_17b1a0:
    // 0x17b1a0: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B1A0u;
    SET_GPR_U32(ctx, 31, 0x17B1A8u);
    ctx->pc = 0x17B1A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B1A0u;
            // 0x17b1a4: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B1A8u; }
        if (ctx->pc != 0x17B1A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B1A8u; }
        if (ctx->pc != 0x17B1A8u) { return; }
    }
    ctx->pc = 0x17B1A8u;
label_17b1a8:
    // 0x17b1a8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b1a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b1ac: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b1acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b1b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b1b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b1b4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b1b4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b1b8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b1b8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b1bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b1bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b1c0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17b1c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b1c4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b1c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b1c8: 0x805eca2  j           func_17B288
    ctx->pc = 0x17B1C8u;
    ctx->pc = 0x17B1CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B1C8u;
            // 0x17b1cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B288u;
    goto label_17b288;
    ctx->pc = 0x17B1D0u;
label_17b1d0:
    // 0x17b1d0: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B1D0u;
    SET_GPR_U32(ctx, 31, 0x17B1D8u);
    ctx->pc = 0x17B1D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B1D0u;
            // 0x17b1d4: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B1D8u; }
        if (ctx->pc != 0x17B1D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B1D8u; }
        if (ctx->pc != 0x17B1D8u) { return; }
    }
    ctx->pc = 0x17B1D8u;
label_17b1d8:
    // 0x17b1d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b1d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b1dc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b1dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b1e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b1e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b1e4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b1e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b1e8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b1e8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b1ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b1ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b1f0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17b1f0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b1f4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b1f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b1f8: 0x805eca2  j           func_17B288
    ctx->pc = 0x17B1F8u;
    ctx->pc = 0x17B1FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B1F8u;
            // 0x17b1fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B288u;
    goto label_17b288;
    ctx->pc = 0x17B200u;
label_17b200:
    // 0x17b200: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B200u;
    SET_GPR_U32(ctx, 31, 0x17B208u);
    ctx->pc = 0x17B204u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B200u;
            // 0x17b204: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B208u; }
        if (ctx->pc != 0x17B208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B208u; }
        if (ctx->pc != 0x17B208u) { return; }
    }
    ctx->pc = 0x17B208u;
label_17b208:
    // 0x17b208: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b208u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b20c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b20cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b210: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b210u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b214: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b214u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b218: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b218u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b21c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b21cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b220: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17b220u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b224: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b224u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b228: 0x805eca2  j           func_17B288
    ctx->pc = 0x17B228u;
    ctx->pc = 0x17B22Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B228u;
            // 0x17b22c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B288u;
    goto label_17b288;
    ctx->pc = 0x17B230u;
label_17b230:
    // 0x17b230: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17B230u;
    SET_GPR_U32(ctx, 31, 0x17B238u);
    ctx->pc = 0x17B234u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B230u;
            // 0x17b234: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B238u; }
        if (ctx->pc != 0x17B238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B238u; }
        if (ctx->pc != 0x17B238u) { return; }
    }
    ctx->pc = 0x17B238u;
label_17b238:
    // 0x17b238: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b238u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b23c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b23cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b240: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b240u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b244: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17b244u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b248: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b248u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b24c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b24cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b250: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b250u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b254: 0x805ecd8  j           func_17B360
    ctx->pc = 0x17B254u;
    ctx->pc = 0x17B258u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B254u;
            // 0x17b258: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B360u;
    goto label_17b360;
    ctx->pc = 0x17B25Cu;
    // 0x17b25c: 0x0  nop
    ctx->pc = 0x17b25cu;
    // NOP
label_17b260:
    // 0x17b260: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17b260u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_17b264:
    // 0x17b264: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17b264u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b268: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17b268u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b26c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17b26cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17b270: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17b270u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17b274: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17b274u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17b278: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17b278u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17b27c: 0x24c60e70  addiu       $a2, $a2, 0xE70
    ctx->pc = 0x17b27cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 3696));
    // 0x17b280: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17B280u;
    ctx->pc = 0x17B284u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B280u;
            // 0x17b284: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B288u;
label_17b288:
    // 0x17b288: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x17b288u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17b28c: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x17b28cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x17b290: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17b290u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b294: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x17b294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x17b298: 0x26110004  addiu       $s1, $s0, 0x4
    ctx->pc = 0x17b298u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x17b29c: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x17b29cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x17b2a0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17b2a0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b2a4: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x17b2a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x17b2a8: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x17b2a8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b2ac: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x17b2acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x17b2b0: 0xafa60010  sw          $a2, 0x10($sp)
    ctx->pc = 0x17b2b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 6));
    // 0x17b2b4: 0x8e050044  lw          $a1, 0x44($s0)
    ctx->pc = 0x17b2b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x17b2b8: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17b2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17b2bc: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x17b2bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17b2c0: 0xafa50014  sw          $a1, 0x14($sp)
    ctx->pc = 0x17b2c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 5));
    // 0x17b2c4: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x17b2c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x17b2c8: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x17b2c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x17b2cc: 0xc05eb6a  jal         func_17ADA8
    ctx->pc = 0x17B2CCu;
    SET_GPR_U32(ctx, 31, 0x17B2D4u);
    ctx->pc = 0x17B2D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B2CCu;
            // 0x17b2d0: 0xafa20008  sw          $v0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17ADA8u;
    if (runtime->hasFunction(0x17ADA8u)) {
        auto targetFn = runtime->lookupFunction(0x17ADA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B2D4u; }
        if (ctx->pc != 0x17B2D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017ADA8_0x17ada8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B2D4u; }
        if (ctx->pc != 0x17B2D4u) { return; }
    }
    ctx->pc = 0x17B2D4u;
label_17b2d4:
    // 0x17b2d4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17b2d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b2d8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b2d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b2dc: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x17b2dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17b2e0: 0x14430007  bne         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x17B2E0u;
    {
        const bool branch_taken_0x17b2e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17B2E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B2E0u;
            // 0x17b2e4: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b2e0) {
            ctx->pc = 0x17B300u;
            goto label_17b300;
        }
    }
    ctx->pc = 0x17B2E8u;
    // 0x17b2e8: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17b2e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17b2ec: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x17b2ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x17b2f0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17b2f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17b2f4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x17B2F4u;
    {
        const bool branch_taken_0x17b2f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B2F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B2F4u;
            // 0x17b2f8: 0x21043  sra         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b2f4) {
            ctx->pc = 0x17B304u;
            goto label_17b304;
        }
    }
    ctx->pc = 0x17B2FCu;
    // 0x17b2fc: 0x0  nop
    ctx->pc = 0x17b2fcu;
    // NOP
label_17b300:
    // 0x17b300: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17b300u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
label_17b304:
    // 0x17b304: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x17b304u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x17b308: 0x8e420008  lw          $v0, 0x8($s2)
    ctx->pc = 0x17b308u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x17b30c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17B30Cu;
    {
        const bool branch_taken_0x17b30c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17b30c) {
            ctx->pc = 0x17B31Cu;
            goto label_17b31c;
        }
    }
    ctx->pc = 0x17B314u;
    // 0x17b314: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x17b314u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x17b318: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x17b318u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_17b31c:
    // 0x17b31c: 0x16660006  bne         $s3, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x17B31Cu;
    {
        const bool branch_taken_0x17b31c = (GPR_U64(ctx, 19) != GPR_U64(ctx, 6));
        ctx->pc = 0x17B320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B31Cu;
            // 0x17b320: 0xafa2001c  sw          $v0, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b31c) {
            ctx->pc = 0x17B338u;
            goto label_17b338;
        }
    }
    ctx->pc = 0x17B324u;
    // 0x17b324: 0xc053dfa  jal         func_14F7E8
    ctx->pc = 0x17B324u;
    SET_GPR_U32(ctx, 31, 0x17B32Cu);
    ctx->pc = 0x17B328u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B324u;
            // 0x17b328: 0x8e46003c  lw          $a2, 0x3C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14F7E8u;
    if (runtime->hasFunction(0x14F7E8u)) {
        auto targetFn = runtime->lookupFunction(0x14F7E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B32Cu; }
        if (ctx->pc != 0x17B32Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014F7E8_0x14f7e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B32Cu; }
        if (ctx->pc != 0x17B32Cu) { return; }
    }
    ctx->pc = 0x17B32Cu;
label_17b32c:
    // 0x17b32c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x17B32Cu;
    {
        const bool branch_taken_0x17b32c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B330u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B32Cu;
            // 0x17b330: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b32c) {
            ctx->pc = 0x17B348u;
            goto label_17b348;
        }
    }
    ctx->pc = 0x17B334u;
    // 0x17b334: 0x0  nop
    ctx->pc = 0x17b334u;
    // NOP
label_17b338:
    // 0x17b338: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b338u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b33c: 0xc053df2  jal         func_14F7C8
    ctx->pc = 0x17B33Cu;
    SET_GPR_U32(ctx, 31, 0x17B344u);
    ctx->pc = 0x17B340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B33Cu;
            // 0x17b340: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14F7C8u;
    if (runtime->hasFunction(0x14F7C8u)) {
        auto targetFn = runtime->lookupFunction(0x14F7C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B344u; }
        if (ctx->pc != 0x17B344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014F7C8_0x14f7c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B344u; }
        if (ctx->pc != 0x17B344u) { return; }
    }
    ctx->pc = 0x17B344u;
label_17b344:
    // 0x17b344: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x17b344u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_17b348:
    // 0x17b348: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x17b348u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17b34c: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x17b34cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17b350: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x17b350u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17b354: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x17b354u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17b358: 0x3e00008  jr          $ra
    ctx->pc = 0x17B358u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17B35Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B358u;
            // 0x17b35c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17B04Cu: goto label_17b04c;
            case 0x17B054u: goto label_17b054;
            case 0x17B064u: goto label_17b064;
            case 0x17B074u: goto label_17b074;
            case 0x17B0F8u: goto label_17b0f8;
            case 0x17B108u: goto label_17b108;
            case 0x17B130u: goto label_17b130;
            case 0x17B138u: goto label_17b138;
            case 0x17B168u: goto label_17b168;
            case 0x17B174u: goto label_17b174;
            case 0x17B1A0u: goto label_17b1a0;
            case 0x17B1A8u: goto label_17b1a8;
            case 0x17B1D0u: goto label_17b1d0;
            case 0x17B1D8u: goto label_17b1d8;
            case 0x17B200u: goto label_17b200;
            case 0x17B208u: goto label_17b208;
            case 0x17B230u: goto label_17b230;
            case 0x17B238u: goto label_17b238;
            case 0x17B260u: goto label_17b260;
            case 0x17B264u: goto label_17b264;
            case 0x17B288u: goto label_17b288;
            case 0x17B2D4u: goto label_17b2d4;
            case 0x17B300u: goto label_17b300;
            case 0x17B304u: goto label_17b304;
            case 0x17B31Cu: goto label_17b31c;
            case 0x17B32Cu: goto label_17b32c;
            case 0x17B338u: goto label_17b338;
            case 0x17B344u: goto label_17b344;
            case 0x17B348u: goto label_17b348;
            case 0x17B360u: goto label_17b360;
            case 0x17B3D8u: goto label_17b3d8;
            case 0x17B3DCu: goto label_17b3dc;
            case 0x17B3E8u: goto label_17b3e8;
            case 0x17B430u: goto label_17b430;
            case 0x17B434u: goto label_17b434;
            case 0x17B43Cu: goto label_17b43c;
            case 0x17B4B0u: goto label_17b4b0;
            case 0x17B4C0u: goto label_17b4c0;
            case 0x17B4C4u: goto label_17b4c4;
            case 0x17B4C8u: goto label_17b4c8;
            case 0x17B4E0u: goto label_17b4e0;
            case 0x17B4E8u: goto label_17b4e8;
            case 0x17B524u: goto label_17b524;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17B360u;
label_17b360:
    // 0x17b360: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x17b360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17b364: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x17b364u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x17b368: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17b368u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b36c: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x17b36cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x17b370: 0x26320004  addiu       $s2, $s1, 0x4
    ctx->pc = 0x17b370u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x17b374: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x17b374u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x17b378: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x17b378u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b37c: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x17b37cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x17b380: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x17b380u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b384: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x17b384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x17b388: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b388u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b38c: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x17b38cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x17b390: 0x8e230048  lw          $v1, 0x48($s1)
    ctx->pc = 0x17b390u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x17b394: 0x8e270044  lw          $a3, 0x44($s1)
    ctx->pc = 0x17b394u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x17b398: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x17b398u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x17b39c: 0x8e680008  lw          $t0, 0x8($s3)
    ctx->pc = 0x17b39cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x17b3a0: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x17b3a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x17b3a4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x17b3a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x17b3a8: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x17b3a8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17b3ac: 0xafa70014  sw          $a3, 0x14($sp)
    ctx->pc = 0x17b3acu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
    // 0x17b3b0: 0xafa50000  sw          $a1, 0x0($sp)
    ctx->pc = 0x17b3b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
    // 0x17b3b4: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x17b3b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x17b3b8: 0xafa70004  sw          $a3, 0x4($sp)
    ctx->pc = 0x17b3b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 7));
    // 0x17b3bc: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x17b3bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x17b3c0: 0x15000005  bnez        $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17B3C0u;
    {
        const bool branch_taken_0x17b3c0 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x17B3C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B3C0u;
            // 0x17b3c4: 0xafb40010  sw          $s4, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b3c0) {
            ctx->pc = 0x17B3D8u;
            goto label_17b3d8;
        }
    }
    ctx->pc = 0x17B3C8u;
    // 0x17b3c8: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x17b3c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x17b3cc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x17b3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x17b3d0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x17B3D0u;
    {
        const bool branch_taken_0x17b3d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B3D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B3D0u;
            // 0x17b3d4: 0xafa2001c  sw          $v0, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b3d0) {
            ctx->pc = 0x17B3DCu;
            goto label_17b3dc;
        }
    }
    ctx->pc = 0x17B3D8u;
label_17b3d8:
    // 0x17b3d8: 0xafa8001c  sw          $t0, 0x1C($sp)
    ctx->pc = 0x17b3d8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 8));
label_17b3dc:
    // 0x17b3dc: 0x27b00010  addiu       $s0, $sp, 0x10
    ctx->pc = 0x17b3dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17b3e0: 0xc053df2  jal         func_14F7C8
    ctx->pc = 0x17B3E0u;
    SET_GPR_U32(ctx, 31, 0x17B3E8u);
    ctx->pc = 0x17B3E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B3E0u;
            // 0x17b3e4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14F7C8u;
    if (runtime->hasFunction(0x14F7C8u)) {
        auto targetFn = runtime->lookupFunction(0x14F7C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B3E8u; }
        if (ctx->pc != 0x17B3E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014F7C8_0x14f7c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B3E8u; }
        if (ctx->pc != 0x17B3E8u) { return; }
    }
    ctx->pc = 0x17B3E8u;
label_17b3e8:
    // 0x17b3e8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17b3e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b3ec: 0x8e260048  lw          $a2, 0x48($s1)
    ctx->pc = 0x17b3ecu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x17b3f0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b3f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b3f4: 0x8e230044  lw          $v1, 0x44($s1)
    ctx->pc = 0x17b3f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x17b3f8: 0x8e670008  lw          $a3, 0x8($s3)
    ctx->pc = 0x17b3f8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x17b3fc: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x17b3fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x17b400: 0xafa30014  sw          $v1, 0x14($sp)
    ctx->pc = 0x17b400u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0x17b404: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x17b404u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x17b408: 0xafb40010  sw          $s4, 0x10($sp)
    ctx->pc = 0x17b408u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 20));
    // 0x17b40c: 0xafa60018  sw          $a2, 0x18($sp)
    ctx->pc = 0x17b40cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 6));
    // 0x17b410: 0xafa30004  sw          $v1, 0x4($sp)
    ctx->pc = 0x17b410u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    // 0x17b414: 0x14e00006  bnez        $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x17B414u;
    {
        const bool branch_taken_0x17b414 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x17B418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B414u;
            // 0x17b418: 0xafa60008  sw          $a2, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b414) {
            ctx->pc = 0x17B430u;
            goto label_17b430;
        }
    }
    ctx->pc = 0x17B41Cu;
    // 0x17b41c: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x17b41cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x17b420: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x17b420u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x17b424: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x17B424u;
    {
        const bool branch_taken_0x17b424 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B424u;
            // 0x17b428: 0xafa2001c  sw          $v0, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b424) {
            ctx->pc = 0x17B434u;
            goto label_17b434;
        }
    }
    ctx->pc = 0x17B42Cu;
    // 0x17b42c: 0x0  nop
    ctx->pc = 0x17b42cu;
    // NOP
label_17b430:
    // 0x17b430: 0xafa7001c  sw          $a3, 0x1C($sp)
    ctx->pc = 0x17b430u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 7));
label_17b434:
    // 0x17b434: 0xc054000  jal         func_150000
    ctx->pc = 0x17B434u;
    SET_GPR_U32(ctx, 31, 0x17B43Cu);
    ctx->pc = 0x17B438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B434u;
            // 0x17b438: 0x8e66003c  lw          $a2, 0x3C($s3) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 60)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150000u;
    if (runtime->hasFunction(0x150000u)) {
        auto targetFn = runtime->lookupFunction(0x150000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B43Cu; }
        if (ctx->pc != 0x17B43Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150000_0x150000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B43Cu; }
        if (ctx->pc != 0x17B43Cu) { return; }
    }
    ctx->pc = 0x17B43Cu;
label_17b43c:
    // 0x17b43c: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x17b43cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17b440: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x17b440u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17b444: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x17b444u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17b448: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x17b448u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17b44c: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x17b44cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17b450: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x17b450u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x17b454: 0x3e00008  jr          $ra
    ctx->pc = 0x17B454u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17B458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B454u;
            // 0x17b458: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17B04Cu: goto label_17b04c;
            case 0x17B054u: goto label_17b054;
            case 0x17B064u: goto label_17b064;
            case 0x17B074u: goto label_17b074;
            case 0x17B0F8u: goto label_17b0f8;
            case 0x17B108u: goto label_17b108;
            case 0x17B130u: goto label_17b130;
            case 0x17B138u: goto label_17b138;
            case 0x17B168u: goto label_17b168;
            case 0x17B174u: goto label_17b174;
            case 0x17B1A0u: goto label_17b1a0;
            case 0x17B1A8u: goto label_17b1a8;
            case 0x17B1D0u: goto label_17b1d0;
            case 0x17B1D8u: goto label_17b1d8;
            case 0x17B200u: goto label_17b200;
            case 0x17B208u: goto label_17b208;
            case 0x17B230u: goto label_17b230;
            case 0x17B238u: goto label_17b238;
            case 0x17B260u: goto label_17b260;
            case 0x17B264u: goto label_17b264;
            case 0x17B288u: goto label_17b288;
            case 0x17B2D4u: goto label_17b2d4;
            case 0x17B300u: goto label_17b300;
            case 0x17B304u: goto label_17b304;
            case 0x17B31Cu: goto label_17b31c;
            case 0x17B32Cu: goto label_17b32c;
            case 0x17B338u: goto label_17b338;
            case 0x17B344u: goto label_17b344;
            case 0x17B348u: goto label_17b348;
            case 0x17B360u: goto label_17b360;
            case 0x17B3D8u: goto label_17b3d8;
            case 0x17B3DCu: goto label_17b3dc;
            case 0x17B3E8u: goto label_17b3e8;
            case 0x17B430u: goto label_17b430;
            case 0x17B434u: goto label_17b434;
            case 0x17B43Cu: goto label_17b43c;
            case 0x17B4B0u: goto label_17b4b0;
            case 0x17B4C0u: goto label_17b4c0;
            case 0x17B4C4u: goto label_17b4c4;
            case 0x17B4C8u: goto label_17b4c8;
            case 0x17B4E0u: goto label_17b4e0;
            case 0x17B4E8u: goto label_17b4e8;
            case 0x17B524u: goto label_17b524;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17B45Cu;
    // 0x17b45c: 0x0  nop
    ctx->pc = 0x17b45cu;
    // NOP
    // 0x17b460: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17b460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17b464: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x17b464u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b468: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17b468u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17b46c: 0x24020041  addiu       $v0, $zero, 0x41
    ctx->pc = 0x17b46cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x17b470: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x17b470u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x17b474: 0x10620012  beq         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x17B474u;
    {
        const bool branch_taken_0x17b474 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B474u;
            // 0x17b478: 0xa0402d  daddu       $t0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b474) {
            ctx->pc = 0x17B4C0u;
            goto label_17b4c0;
        }
    }
    ctx->pc = 0x17B47Cu;
    // 0x17b47c: 0x28620042  slti        $v0, $v1, 0x42
    ctx->pc = 0x17b47cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)66) ? 1 : 0);
    // 0x17b480: 0x50400010  beql        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x17B480u;
    {
        const bool branch_taken_0x17b480 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17b480) {
            ctx->pc = 0x17B484u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17B480u;
            // 0x17b484: 0x3c060024  lui         $a2, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17B4C4u;
            goto label_17b4c4;
        }
    }
    ctx->pc = 0x17B488u;
    // 0x17b488: 0x24020021  addiu       $v0, $zero, 0x21
    ctx->pc = 0x17b488u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x17b48c: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x17B48Cu;
    {
        const bool branch_taken_0x17b48c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B48Cu;
            // 0x17b490: 0x28620022  slti        $v0, $v1, 0x22 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)34) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b48c) {
            ctx->pc = 0x17B4B0u;
            goto label_17b4b0;
        }
    }
    ctx->pc = 0x17B494u;
    // 0x17b494: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x17B494u;
    {
        const bool branch_taken_0x17b494 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B494u;
            // 0x17b498: 0x3c060024  lui         $a2, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b494) {
            ctx->pc = 0x17B4C4u;
            goto label_17b4c4;
        }
    }
    ctx->pc = 0x17B49Cu;
    // 0x17b49c: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x17b49cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x17b4a0: 0x1062000f  beq         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x17B4A0u;
    {
        const bool branch_taken_0x17b4a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B4A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B4A0u;
            // 0x17b4a4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b4a0) {
            ctx->pc = 0x17B4E0u;
            goto label_17b4e0;
        }
    }
    ctx->pc = 0x17B4A8u;
    // 0x17b4a8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x17B4A8u;
    {
        const bool branch_taken_0x17b4a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x17b4a8) {
            ctx->pc = 0x17B4C8u;
            goto label_17b4c8;
        }
    }
    ctx->pc = 0x17B4B0u;
label_17b4b0:
    // 0x17b4b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17b4b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b4b4: 0x805ed3a  j           func_17B4E8
    ctx->pc = 0x17B4B4u;
    ctx->pc = 0x17B4B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B4B4u;
            // 0x17b4b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B4E8u;
    goto label_17b4e8;
    ctx->pc = 0x17B4BCu;
    // 0x17b4bc: 0x0  nop
    ctx->pc = 0x17b4bcu;
    // NOP
label_17b4c0:
    // 0x17b4c0: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17b4c0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
label_17b4c4:
    // 0x17b4c4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17b4c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17b4c8:
    // 0x17b4c8: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x17b4c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b4cc: 0x100282d  daddu       $a1, $t0, $zero
    ctx->pc = 0x17b4ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b4d0: 0x24c60e70  addiu       $a2, $a2, 0xE70
    ctx->pc = 0x17b4d0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 3696));
    // 0x17b4d4: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17B4D4u;
    ctx->pc = 0x17B4D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B4D4u;
            // 0x17b4d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B4DCu;
    // 0x17b4dc: 0x0  nop
    ctx->pc = 0x17b4dcu;
    // NOP
label_17b4e0:
    // 0x17b4e0: 0x3e00008  jr          $ra
    ctx->pc = 0x17B4E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17B4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B4E0u;
            // 0x17b4e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17B04Cu: goto label_17b04c;
            case 0x17B054u: goto label_17b054;
            case 0x17B064u: goto label_17b064;
            case 0x17B074u: goto label_17b074;
            case 0x17B0F8u: goto label_17b0f8;
            case 0x17B108u: goto label_17b108;
            case 0x17B130u: goto label_17b130;
            case 0x17B138u: goto label_17b138;
            case 0x17B168u: goto label_17b168;
            case 0x17B174u: goto label_17b174;
            case 0x17B1A0u: goto label_17b1a0;
            case 0x17B1A8u: goto label_17b1a8;
            case 0x17B1D0u: goto label_17b1d0;
            case 0x17B1D8u: goto label_17b1d8;
            case 0x17B200u: goto label_17b200;
            case 0x17B208u: goto label_17b208;
            case 0x17B230u: goto label_17b230;
            case 0x17B238u: goto label_17b238;
            case 0x17B260u: goto label_17b260;
            case 0x17B264u: goto label_17b264;
            case 0x17B288u: goto label_17b288;
            case 0x17B2D4u: goto label_17b2d4;
            case 0x17B300u: goto label_17b300;
            case 0x17B304u: goto label_17b304;
            case 0x17B31Cu: goto label_17b31c;
            case 0x17B32Cu: goto label_17b32c;
            case 0x17B338u: goto label_17b338;
            case 0x17B344u: goto label_17b344;
            case 0x17B348u: goto label_17b348;
            case 0x17B360u: goto label_17b360;
            case 0x17B3D8u: goto label_17b3d8;
            case 0x17B3DCu: goto label_17b3dc;
            case 0x17B3E8u: goto label_17b3e8;
            case 0x17B430u: goto label_17b430;
            case 0x17B434u: goto label_17b434;
            case 0x17B43Cu: goto label_17b43c;
            case 0x17B4B0u: goto label_17b4b0;
            case 0x17B4C0u: goto label_17b4c0;
            case 0x17B4C4u: goto label_17b4c4;
            case 0x17B4C8u: goto label_17b4c8;
            case 0x17B4E0u: goto label_17b4e0;
            case 0x17B4E8u: goto label_17b4e8;
            case 0x17B524u: goto label_17b524;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17B4E8u;
label_17b4e8:
    // 0x17b4e8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x17b4e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x17b4ec: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x17b4ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b4f0: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x17b4f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x17b4f4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b4f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b4f8: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x17b4f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x17b4fc: 0x8c480048  lw          $t0, 0x48($v0)
    ctx->pc = 0x17b4fcu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 72)));
    // 0x17b500: 0x8c470044  lw          $a3, 0x44($v0)
    ctx->pc = 0x17b500u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 68)));
    // 0x17b504: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x17b504u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x17b508: 0xafa70024  sw          $a3, 0x24($sp)
    ctx->pc = 0x17b508u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 7));
    // 0x17b50c: 0xafa60020  sw          $a2, 0x20($sp)
    ctx->pc = 0x17b50cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 6));
    // 0x17b510: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x17b510u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x17b514: 0xafa80028  sw          $t0, 0x28($sp)
    ctx->pc = 0x17b514u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 8));
    // 0x17b518: 0xafa70004  sw          $a3, 0x4($sp)
    ctx->pc = 0x17b518u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 7));
    // 0x17b51c: 0xc053fd4  jal         func_14FF50
    ctx->pc = 0x17B51Cu;
    SET_GPR_U32(ctx, 31, 0x17B524u);
    ctx->pc = 0x17B520u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B51Cu;
            // 0x17b520: 0xafa80008  sw          $t0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14FF50u;
    if (runtime->hasFunction(0x14FF50u)) {
        auto targetFn = runtime->lookupFunction(0x14FF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B524u; }
        if (ctx->pc != 0x17B524u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014FF50_0x14ff50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B524u; }
        if (ctx->pc != 0x17B524u) { return; }
    }
    ctx->pc = 0x17B524u;
label_17b524:
    // 0x17b524: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x17b524u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17b528: 0x3e00008  jr          $ra
    ctx->pc = 0x17B528u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17B52Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B528u;
            // 0x17b52c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17B04Cu: goto label_17b04c;
            case 0x17B054u: goto label_17b054;
            case 0x17B064u: goto label_17b064;
            case 0x17B074u: goto label_17b074;
            case 0x17B0F8u: goto label_17b0f8;
            case 0x17B108u: goto label_17b108;
            case 0x17B130u: goto label_17b130;
            case 0x17B138u: goto label_17b138;
            case 0x17B168u: goto label_17b168;
            case 0x17B174u: goto label_17b174;
            case 0x17B1A0u: goto label_17b1a0;
            case 0x17B1A8u: goto label_17b1a8;
            case 0x17B1D0u: goto label_17b1d0;
            case 0x17B1D8u: goto label_17b1d8;
            case 0x17B200u: goto label_17b200;
            case 0x17B208u: goto label_17b208;
            case 0x17B230u: goto label_17b230;
            case 0x17B238u: goto label_17b238;
            case 0x17B260u: goto label_17b260;
            case 0x17B264u: goto label_17b264;
            case 0x17B288u: goto label_17b288;
            case 0x17B2D4u: goto label_17b2d4;
            case 0x17B300u: goto label_17b300;
            case 0x17B304u: goto label_17b304;
            case 0x17B31Cu: goto label_17b31c;
            case 0x17B32Cu: goto label_17b32c;
            case 0x17B338u: goto label_17b338;
            case 0x17B344u: goto label_17b344;
            case 0x17B348u: goto label_17b348;
            case 0x17B360u: goto label_17b360;
            case 0x17B3D8u: goto label_17b3d8;
            case 0x17B3DCu: goto label_17b3dc;
            case 0x17B3E8u: goto label_17b3e8;
            case 0x17B430u: goto label_17b430;
            case 0x17B434u: goto label_17b434;
            case 0x17B43Cu: goto label_17b43c;
            case 0x17B4B0u: goto label_17b4b0;
            case 0x17B4C0u: goto label_17b4c0;
            case 0x17B4C4u: goto label_17b4c4;
            case 0x17B4C8u: goto label_17b4c8;
            case 0x17B4E0u: goto label_17b4e0;
            case 0x17B4E8u: goto label_17b4e8;
            case 0x17B524u: goto label_17b524;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17B530u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
