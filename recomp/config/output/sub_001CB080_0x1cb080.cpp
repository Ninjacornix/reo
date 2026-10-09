#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CB080
// Address: 0x1cb080 - 0x1cb17c
void sub_001CB080_0x1cb080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CB080_0x1cb080");
#endif

    switch (ctx->pc) {
        case 0x1cb124u: goto label_1cb124;
        default: break;
    }

    ctx->pc = 0x1cb080u;

    // 0x1cb080: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1cb080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1cb084: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb084u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb088: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1cb088u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1cb08c: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1cb08cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1cb090: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1cb090u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1cb094: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x1cb094u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb098: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1cb098u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1cb09c: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1cb09cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb0a0: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1cb0a0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1cb0a4: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x1cb0a4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb0a8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cb0a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cb0ac: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1cb0acu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb0b0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cb0b0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cb0b4: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x1cb0b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb0b8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cb0b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cb0bc: 0x120882d  daddu       $s1, $t1, $zero
    ctx->pc = 0x1cb0bcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb0c0: 0x9023c6ec  lbu         $v1, -0x3914($at)
    ctx->pc = 0x1cb0c0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1cb0c4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb0c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb0c8: 0x9022c6ed  lbu         $v0, -0x3913($at)
    ctx->pc = 0x1cb0c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952685)));
    // 0x1cb0cc: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1cb0ccu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1cb0d0: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CB0D0u;
    {
        const bool branch_taken_0x1cb0d0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB0D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB0D0u;
            // 0x1cb0d4: 0x140802d  daddu       $s0, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb0d0) {
            ctx->pc = 0x1CB0DCu;
            goto label_1cb0dc;
        }
    }
    ctx->pc = 0x1CB0D8u;
    // 0x1cb0d8: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1cb0d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1cb0dc:
    // 0x1cb0dc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb0dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb0e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cb0e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cb0e4: 0xa023c6ed  sb          $v1, -0x3913($at)
    ctx->pc = 0x1cb0e4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952685), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cb0e8: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1cb0e8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1cb0ec: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1CB0ECu;
    {
        const bool branch_taken_0x1cb0ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CB0F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB0ECu;
            // 0x1cb0f0: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb0ec) {
            ctx->pc = 0x1CB11Cu;
            goto label_1cb11c;
        }
    }
    ctx->pc = 0x1CB0F4u;
    // 0x1cb0f4: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB0F4u;
    {
        const bool branch_taken_0x1cb0f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb0f4) {
            ctx->pc = 0x1CB104u;
            goto label_1cb104;
        }
    }
    ctx->pc = 0x1CB0FCu;
    // 0x1cb0fc: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1CB0FCu;
    {
        const bool branch_taken_0x1cb0fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB0FCu;
            // 0x1cb100: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb0fc) {
            ctx->pc = 0x1CB154u;
            goto label_1cb154;
        }
    }
    ctx->pc = 0x1CB104u;
label_1cb104:
    // 0x1cb104: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cb104u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cb108: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb108u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb10c: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1cb10cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cb110: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cb110u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb114: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1CB114u;
    {
        const bool branch_taken_0x1cb114 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB114u;
            // 0x1cb118: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb114) {
            ctx->pc = 0x1CB154u;
            goto label_1cb154;
        }
    }
    ctx->pc = 0x1CB11Cu;
label_1cb11c:
    // 0x1cb11c: 0xc072c60  jal         func_1CB180
    ctx->pc = 0x1CB11Cu;
    SET_GPR_U32(ctx, 31, 0x1CB124u);
    ctx->pc = 0x1CB120u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB11Cu;
            // 0x1cb120: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB180u;
    if (runtime->hasFunction(0x1CB180u)) {
        auto targetFn = runtime->lookupFunction(0x1CB180u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB124u; }
        if (ctx->pc != 0x1CB124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB180_0x1cb180(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB124u; }
        if (ctx->pc != 0x1CB124u) { return; }
    }
    ctx->pc = 0x1CB124u;
label_1cb124:
    // 0x1cb124: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CB124u;
    {
        const bool branch_taken_0x1cb124 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb124) {
            ctx->pc = 0x1CB150u;
            goto label_1cb150;
        }
    }
    ctx->pc = 0x1CB12Cu;
    // 0x1cb12c: 0xa2c00000  sb          $zero, 0x0($s6)
    ctx->pc = 0x1cb12cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb130: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1cb130u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1cb134: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cb134u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb138: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cb138u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb13c: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cb13cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cb140: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cb140u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cb144: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cb144u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cb148: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1CB148u;
    {
        const bool branch_taken_0x1cb148 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB14Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB148u;
            // 0x1cb14c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb148) {
            ctx->pc = 0x1CB154u;
            goto label_1cb154;
        }
    }
    ctx->pc = 0x1CB150u;
label_1cb150:
    // 0x1cb150: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb150u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cb154:
    // 0x1cb154: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1cb154u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1cb158: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1cb158u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1cb15c: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1cb15cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1cb160: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1cb160u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1cb164: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1cb164u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cb168: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cb168u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cb16c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cb16cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cb170: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cb170u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cb174: 0x3e00008  jr          $ra
    ctx->pc = 0x1CB174u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CB178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB174u;
            // 0x1cb178: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CB0DCu: goto label_1cb0dc;
            case 0x1CB104u: goto label_1cb104;
            case 0x1CB11Cu: goto label_1cb11c;
            case 0x1CB124u: goto label_1cb124;
            case 0x1CB150u: goto label_1cb150;
            case 0x1CB154u: goto label_1cb154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CB17Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
