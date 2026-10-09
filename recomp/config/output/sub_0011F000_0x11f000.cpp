#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F000
// Address: 0x11f000 - 0x11f128
void sub_0011F000_0x11f000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F000_0x11f000");
#endif

    switch (ctx->pc) {
        case 0x11f030u: goto label_11f030;
        case 0x11f048u: goto label_11f048;
        case 0x11f058u: goto label_11f058;
        case 0x11f0a8u: goto label_11f0a8;
        case 0x11f104u: goto label_11f104;
        default: break;
    }

    ctx->pc = 0x11f000u;

    // 0x11f000: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x11f000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x11f004: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11f004u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11f008: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11f008u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11f00c: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x11f00cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f010: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11f010u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11f014: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x11f014u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f018: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f018u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f01c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x11f01cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f020: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x11f020u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x11f024: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x11f024u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x11f028: 0xc047598  jal         func_11D660
    ctx->pc = 0x11F028u;
    SET_GPR_U32(ctx, 31, 0x11F030u);
    ctx->pc = 0x11F02Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F028u;
            // 0x11f02c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F030u; }
        if (ctx->pc != 0x11F030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F030u; }
        if (ctx->pc != 0x11F030u) { return; }
    }
    ctx->pc = 0x11F030u;
label_11f030:
    // 0x11f030: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11f030u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f034: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x11f034u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f038: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x11f038u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f03c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x11f03cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f040: 0xc047bc2  jal         func_11EF08
    ctx->pc = 0x11F040u;
    SET_GPR_U32(ctx, 31, 0x11F048u);
    ctx->pc = 0x11F044u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F040u;
            // 0x11f044: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EF08u;
    if (runtime->hasFunction(0x11EF08u)) {
        auto targetFn = runtime->lookupFunction(0x11EF08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F048u; }
        if (ctx->pc != 0x11F048u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011EF08_0x11ef08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F048u; }
        if (ctx->pc != 0x11F048u) { return; }
    }
    ctx->pc = 0x11F048u;
label_11f048:
    // 0x11f048: 0x12800003  beqz        $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x11F048u;
    {
        const bool branch_taken_0x11f048 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F04Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F048u;
            // 0x11f04c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f048) {
            ctx->pc = 0x11F058u;
            goto label_11f058;
        }
    }
    ctx->pc = 0x11F050u;
    // 0x11f050: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11F050u;
    SET_GPR_U32(ctx, 31, 0x11F058u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F058u; }
        if (ctx->pc != 0x11F058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F058u; }
        if (ctx->pc != 0x11F058u) { return; }
    }
    ctx->pc = 0x11F058u;
label_11f058:
    // 0x11f058: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11f058u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f05c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x11f05cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11f060: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x11f060u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11f064: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11f064u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11f068: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11f068u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11f06c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11f06cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f070: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f070u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f074: 0x3e00008  jr          $ra
    ctx->pc = 0x11F074u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F074u;
            // 0x11f078: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F030u: goto label_11f030;
            case 0x11F048u: goto label_11f048;
            case 0x11F058u: goto label_11f058;
            case 0x11F0A8u: goto label_11f0a8;
            case 0x11F0B8u: goto label_11f0b8;
            case 0x11F104u: goto label_11f104;
            case 0x11F110u: goto label_11f110;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F07Cu;
    // 0x11f07c: 0x0  nop
    ctx->pc = 0x11f07cu;
    // NOP
    // 0x11f080: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11f080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11f084: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11f084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11f088: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f088u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f08c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11f08cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f090: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11f090u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11f094: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x11f094u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f098: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11f098u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11f09c: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x11f09cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f0a0: 0xc044210  jal         func_110840
    ctx->pc = 0x11F0A0u;
    SET_GPR_U32(ctx, 31, 0x11F0A8u);
    ctx->pc = 0x11F0A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F0A0u;
            // 0x11f0a4: 0x3c0508ca  lui         $a1, 0x8CA (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)2250 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x110840u;
    if (runtime->hasFunction(0x110840u)) {
        auto targetFn = runtime->lookupFunction(0x110840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F0A8u; }
        if (ctx->pc != 0x11F0A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00110840_0x110840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F0A8u; }
        if (ctx->pc != 0x11F0A8u) { return; }
    }
    ctx->pc = 0x11F0A8u;
label_11f0a8:
    // 0x11f0a8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x11f0a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x11f0ac: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x11f0acu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x11f0b0: 0x56000001  bnel        $s0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x11F0B0u;
    {
        const bool branch_taken_0x11f0b0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11f0b0) {
            ctx->pc = 0x11F0B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F0B0u;
            // 0x11f0b4: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F0B8u;
            goto label_11f0b8;
        }
    }
    ctx->pc = 0x11F0B8u;
label_11f0b8:
    // 0x11f0b8: 0x12400015  beqz        $s2, . + 4 + (0x15 << 2)
    ctx->pc = 0x11F0B8u;
    {
        const bool branch_taken_0x11f0b8 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F0BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F0B8u;
            // 0x11f0bc: 0x3c0308ca  lui         $v1, 0x8CA (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)2250 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f0b8) {
            ctx->pc = 0x11F110u;
            goto label_11f110;
        }
    }
    ctx->pc = 0x11F0C0u;
    // 0x11f0c0: 0x3c0508ca  lui         $a1, 0x8CA
    ctx->pc = 0x11f0c0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)2250 << 16));
    // 0x11f0c4: 0x430019  multu       $v0, $v1
    ctx->pc = 0x11f0c4u;
    { uint64_t result = (uint64_t)GPR_U32(ctx, 2) * (uint64_t)GPR_U32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x11f0c8: 0x3012  mflo        $a2
    ctx->pc = 0x11f0c8u;
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x11f0cc: 0x1810  mfhi        $v1
    ctx->pc = 0x11f0ccu;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x11f0d0: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x11f0d0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x11f0d4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x11f0d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x11f0d8: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x11f0d8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x11f0dc: 0x661825  or          $v1, $v1, $a2
    ctx->pc = 0x11f0dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 6));
    // 0x11f0e0: 0x223182f  dsubu       $v1, $s1, $v1
    ctx->pc = 0x11f0e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) - GPR_U64(ctx, 3));
    // 0x11f0e4: 0x31178  dsll        $v0, $v1, 5
    ctx->pc = 0x11f0e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << 5);
    // 0x11f0e8: 0x43102f  dsubu       $v0, $v0, $v1
    ctx->pc = 0x11f0e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 3));
    // 0x11f0ec: 0x221b8  dsll        $a0, $v0, 6
    ctx->pc = 0x11f0ecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << 6);
    // 0x11f0f0: 0x82202f  dsubu       $a0, $a0, $v0
    ctx->pc = 0x11f0f0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) - GPR_U64(ctx, 2));
    // 0x11f0f4: 0x420f8  dsll        $a0, $a0, 3
    ctx->pc = 0x11f0f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 3);
    // 0x11f0f8: 0x83202d  daddu       $a0, $a0, $v1
    ctx->pc = 0x11f0f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 3));
    // 0x11f0fc: 0xc044210  jal         func_110840
    ctx->pc = 0x11F0FCu;
    SET_GPR_U32(ctx, 31, 0x11F104u);
    ctx->pc = 0x11F100u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F0FCu;
            // 0x11f100: 0x421b8  dsll        $a0, $a0, 6 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 6);
        ctx->in_delay_slot = false;
    ctx->pc = 0x110840u;
    if (runtime->hasFunction(0x110840u)) {
        auto targetFn = runtime->lookupFunction(0x110840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F104u; }
        if (ctx->pc != 0x11F104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00110840_0x110840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F104u; }
        if (ctx->pc != 0x11F104u) { return; }
    }
    ctx->pc = 0x11F104u;
label_11f104:
    // 0x11f104: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x11f104u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x11f108: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x11f108u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x11f10c: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x11f10cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_11f110:
    // 0x11f110: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11f110u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11f114: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11f114u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11f118: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11f118u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f11c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f11cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f120: 0x3e00008  jr          $ra
    ctx->pc = 0x11F120u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F120u;
            // 0x11f124: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F030u: goto label_11f030;
            case 0x11F048u: goto label_11f048;
            case 0x11F058u: goto label_11f058;
            case 0x11F0A8u: goto label_11f0a8;
            case 0x11F0B8u: goto label_11f0b8;
            case 0x11F104u: goto label_11f104;
            case 0x11F110u: goto label_11f110;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F128u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
