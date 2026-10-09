#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F080
// Address: 0x11f080 - 0x11f128
void sub_0011F080_0x11f080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F080_0x11f080");
#endif

    switch (ctx->pc) {
        case 0x11f0a8u: goto label_11f0a8;
        case 0x11f104u: goto label_11f104;
        default: break;
    }

    ctx->pc = 0x11f080u;

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
