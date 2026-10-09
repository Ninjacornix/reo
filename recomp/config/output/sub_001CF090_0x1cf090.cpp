#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CF090
// Address: 0x1cf090 - 0x1cf300
void sub_001CF090_0x1cf090(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CF090_0x1cf090");
#endif

    switch (ctx->pc) {
        case 0x1cf16cu: goto label_1cf16c;
        case 0x1cf1c8u: goto label_1cf1c8;
        case 0x1cf204u: goto label_1cf204;
        case 0x1cf21cu: goto label_1cf21c;
        case 0x1cf2acu: goto label_1cf2ac;
        case 0x1cf2c4u: goto label_1cf2c4;
        default: break;
    }

    ctx->pc = 0x1cf090u;

    // 0x1cf090: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1cf090u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1cf094: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cf094u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cf098: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x1cf098u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x1cf09c: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x1cf09cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf0a0: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1cf0a0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1cf0a4: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1cf0a4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1cf0a8: 0x100b82d  daddu       $s7, $t0, $zero
    ctx->pc = 0x1cf0a8u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf0ac: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1cf0acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1cf0b0: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x1cf0b0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf0b4: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1cf0b4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1cf0b8: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1cf0b8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf0bc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1cf0bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1cf0c0: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x1cf0c0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf0c4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cf0c4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cf0c8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cf0c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cf0cc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cf0ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cf0d0: 0x8c2366c8  lw          $v1, 0x66C8($at)
    ctx->pc = 0x1cf0d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26312)));
    // 0x1cf0d4: 0x28621200  slti        $v0, $v1, 0x1200
    ctx->pc = 0x1cf0d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4608) ? 1 : 0);
    // 0x1cf0d8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CF0D8u;
    {
        const bool branch_taken_0x1cf0d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF0DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF0D8u;
            // 0x1cf0dc: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf0d8) {
            ctx->pc = 0x1CF0F0u;
            goto label_1cf0f0;
        }
    }
    ctx->pc = 0x1CF0E0u;
    // 0x1cf0e0: 0x28611400  slti        $at, $v1, 0x1400
    ctx->pc = 0x1cf0e0u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)5120) ? 1 : 0);
    // 0x1cf0e4: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF0E4u;
    {
        const bool branch_taken_0x1cf0e4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF0E4u;
            // 0x1cf0e8: 0x28621400  slti        $v0, $v1, 0x1400 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)5120) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf0e4) {
            ctx->pc = 0x1CF0F4u;
            goto label_1cf0f4;
        }
    }
    ctx->pc = 0x1CF0ECu;
    // 0x1cf0ec: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x1cf0ecu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1cf0f0:
    // 0x1cf0f0: 0x28621400  slti        $v0, $v1, 0x1400
    ctx->pc = 0x1cf0f0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)5120) ? 1 : 0);
label_1cf0f4:
    // 0x1cf0f4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CF0F4u;
    {
        const bool branch_taken_0x1cf0f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF0F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF0F4u;
            // 0x1cf0f8: 0x28611800  slti        $at, $v1, 0x1800 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)6144) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf0f4) {
            ctx->pc = 0x1CF108u;
            goto label_1cf108;
        }
    }
    ctx->pc = 0x1CF0FCu;
    // 0x1cf0fc: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CF0FCu;
    {
        const bool branch_taken_0x1cf0fc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf0fc) {
            ctx->pc = 0x1CF108u;
            goto label_1cf108;
        }
    }
    ctx->pc = 0x1CF104u;
    // 0x1cf104: 0x24120002  addiu       $s2, $zero, 0x2
    ctx->pc = 0x1cf104u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1cf108:
    // 0x1cf108: 0x16400003  bnez        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF108u;
    {
        const bool branch_taken_0x1cf108 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF10Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF108u;
            // 0x1cf10c: 0x3c028000  lui         $v0, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf108) {
            ctx->pc = 0x1CF118u;
            goto label_1cf118;
        }
    }
    ctx->pc = 0x1CF110u;
    // 0x1cf110: 0x1000006d  b           . + 4 + (0x6D << 2)
    ctx->pc = 0x1CF110u;
    {
        const bool branch_taken_0x1cf110 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF110u;
            // 0x1cf114: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf110) {
            ctx->pc = 0x1CF2C8u;
            goto label_1cf2c8;
        }
    }
    ctx->pc = 0x1CF118u;
label_1cf118:
    // 0x1cf118: 0x2821024  and         $v0, $s4, $v0
    ctx->pc = 0x1cf118u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & GPR_U64(ctx, 2));
    // 0x1cf11c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF11Cu;
    {
        const bool branch_taken_0x1cf11c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF11Cu;
            // 0x1cf120: 0x24080004  addiu       $t0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf11c) {
            ctx->pc = 0x1CF12Cu;
            goto label_1cf12c;
        }
    }
    ctx->pc = 0x1CF124u;
    // 0x1cf124: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CF124u;
    {
        const bool branch_taken_0x1cf124 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF124u;
            // 0x1cf128: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf124) {
            ctx->pc = 0x1CF144u;
            goto label_1cf144;
        }
    }
    ctx->pc = 0x1CF12Cu;
label_1cf12c:
    // 0x1cf12c: 0x3c024000  lui         $v0, 0x4000
    ctx->pc = 0x1cf12cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
    // 0x1cf130: 0x2821024  and         $v0, $s4, $v0
    ctx->pc = 0x1cf130u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & GPR_U64(ctx, 2));
    // 0x1cf134: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CF134u;
    {
        const bool branch_taken_0x1cf134 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF134u;
            // 0x1cf138: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf134) {
            ctx->pc = 0x1CF140u;
            goto label_1cf140;
        }
    }
    ctx->pc = 0x1CF13Cu;
    // 0x1cf13c: 0x24080002  addiu       $t0, $zero, 0x2
    ctx->pc = 0x1cf13cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1cf140:
    // 0x1cf140: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x1cf140u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
label_1cf144:
    // 0x1cf144: 0x324400ff  andi        $a0, $s2, 0xFF
    ctx->pc = 0x1cf144u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1cf148: 0x2821824  and         $v1, $s4, $v0
    ctx->pc = 0x1cf148u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) & GPR_U64(ctx, 2));
    // 0x1cf14c: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1cf14cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf150: 0x3802b  sltu        $s0, $zero, $v1
    ctx->pc = 0x1cf150u;
    SET_GPR_U64(ctx, 16, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1cf154: 0x32a2ffff  andi        $v0, $s5, 0xFFFF
    ctx->pc = 0x1cf154u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)65535);
    // 0x1cf158: 0x101bc0  sll         $v1, $s0, 15
    ctx->pc = 0x1cf158u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 15));
    // 0x1cf15c: 0x3067ffff  andi        $a3, $v1, 0xFFFF
    ctx->pc = 0x1cf15cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1cf160: 0x475025  or          $t2, $v0, $a3
    ctx->pc = 0x1cf160u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 2) | GPR_U64(ctx, 7));
    // 0x1cf164: 0xc073ba4  jal         func_1CEE90
    ctx->pc = 0x1CF164u;
    SET_GPR_U32(ctx, 31, 0x1CF16Cu);
    ctx->pc = 0x1CF168u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF164u;
            // 0x1cf168: 0x3145ffff  andi        $a1, $t2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CEE90u;
    if (runtime->hasFunction(0x1CEE90u)) {
        auto targetFn = runtime->lookupFunction(0x1CEE90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF16Cu; }
        if (ctx->pc != 0x1CF16Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CEE90_0x1cee90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF16Cu; }
        if (ctx->pc != 0x1CF16Cu) { return; }
    }
    ctx->pc = 0x1CF16Cu;
label_1cf16c:
    // 0x1cf16c: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1cf16cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf170: 0x1260000b  beqz        $s3, . + 4 + (0xB << 2)
    ctx->pc = 0x1CF170u;
    {
        const bool branch_taken_0x1cf170 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf170) {
            ctx->pc = 0x1CF1A0u;
            goto label_1cf1a0;
        }
    }
    ctx->pc = 0x1CF178u;
    // 0x1cf178: 0x92630003  lbu         $v1, 0x3($s3)
    ctx->pc = 0x1cf178u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 3)));
    // 0x1cf17c: 0x1001027  not         $v0, $t0
    ctx->pc = 0x1cf17cu;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 8) | GPR_U64(ctx, 0)));
    // 0x1cf180: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1cf180u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1cf184: 0x1021025  or          $v0, $t0, $v0
    ctx->pc = 0x1cf184u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1cf188: 0x12c00019  beqz        $s6, . + 4 + (0x19 << 2)
    ctx->pc = 0x1CF188u;
    {
        const bool branch_taken_0x1cf188 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF18Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF188u;
            // 0x1cf18c: 0xa2620003  sb          $v0, 0x3($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 3), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf188) {
            ctx->pc = 0x1CF1F0u;
            goto label_1cf1f0;
        }
    }
    ctx->pc = 0x1CF190u;
    // 0x1cf190: 0x92620000  lbu         $v0, 0x0($s3)
    ctx->pc = 0x1cf190u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1cf194: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cf194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cf198: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1CF198u;
    {
        const bool branch_taken_0x1cf198 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF19Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF198u;
            // 0x1cf19c: 0xa2620000  sb          $v0, 0x0($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf198) {
            ctx->pc = 0x1CF1F0u;
            goto label_1cf1f0;
        }
    }
    ctx->pc = 0x1CF1A0u;
label_1cf1a0:
    // 0x1cf1a0: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1cf1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1cf1a4: 0x15020005  bne         $t0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CF1A4u;
    {
        const bool branch_taken_0x1cf1a4 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 2));
        ctx->pc = 0x1CF1A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF1A4u;
            // 0x1cf1a8: 0x24110002  addiu       $s1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf1a4) {
            ctx->pc = 0x1CF1BCu;
            goto label_1cf1bc;
        }
    }
    ctx->pc = 0x1CF1ACu;
    // 0x1cf1ac: 0x12c00004  beqz        $s6, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CF1ACu;
    {
        const bool branch_taken_0x1cf1ac = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF1B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF1ACu;
            // 0x1cf1b0: 0x100202d  daddu       $a0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf1ac) {
            ctx->pc = 0x1CF1C0u;
            goto label_1cf1c0;
        }
    }
    ctx->pc = 0x1CF1B4u;
    // 0x1cf1b4: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x1CF1B4u;
    {
        const bool branch_taken_0x1cf1b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF1B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF1B4u;
            // 0x1cf1b8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf1b4) {
            ctx->pc = 0x1CF2C8u;
            goto label_1cf2c8;
        }
    }
    ctx->pc = 0x1CF1BCu;
label_1cf1bc:
    // 0x1cf1bc: 0x100202d  daddu       $a0, $t0, $zero
    ctx->pc = 0x1cf1bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_1cf1c0:
    // 0x1cf1c0: 0xc073b7c  jal         func_1CEDF0
    ctx->pc = 0x1CF1C0u;
    SET_GPR_U32(ctx, 31, 0x1CF1C8u);
    ctx->pc = 0x1CEDF0u;
    if (runtime->hasFunction(0x1CEDF0u)) {
        auto targetFn = runtime->lookupFunction(0x1CEDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF1C8u; }
        if (ctx->pc != 0x1CF1C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CEDF0_0x1cedf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF1C8u; }
        if (ctx->pc != 0x1CF1C8u) { return; }
    }
    ctx->pc = 0x1CF1C8u;
label_1cf1c8:
    // 0x1cf1c8: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1cf1c8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf1cc: 0x16600003  bnez        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF1CCu;
    {
        const bool branch_taken_0x1cf1cc = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cf1cc) {
            ctx->pc = 0x1CF1DCu;
            goto label_1cf1dc;
        }
    }
    ctx->pc = 0x1CF1D4u;
    // 0x1cf1d4: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1CF1D4u;
    {
        const bool branch_taken_0x1cf1d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF1D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF1D4u;
            // 0x1cf1d8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf1d4) {
            ctx->pc = 0x1CF2C8u;
            goto label_1cf2c8;
        }
    }
    ctx->pc = 0x1CF1DCu;
label_1cf1dc:
    // 0x1cf1dc: 0xa2680003  sb          $t0, 0x3($s3)
    ctx->pc = 0x1cf1dcu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 3), (uint8_t)GPR_U32(ctx, 8));
    // 0x1cf1e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cf1e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cf1e4: 0xa66a000a  sh          $t2, 0xA($s3)
    ctx->pc = 0x1cf1e4u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 10), (uint16_t)GPR_U32(ctx, 10));
    // 0x1cf1e8: 0xa2620000  sb          $v0, 0x0($s3)
    ctx->pc = 0x1cf1e8u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cf1ec: 0xa2720008  sb          $s2, 0x8($s3)
    ctx->pc = 0x1cf1ecu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 8), (uint8_t)GPR_U32(ctx, 18));
label_1cf1f0:
    // 0x1cf1f0: 0x3122ffff  andi        $v0, $t1, 0xFFFF
    ctx->pc = 0x1cf1f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
    // 0x1cf1f4: 0x324400ff  andi        $a0, $s2, 0xFF
    ctx->pc = 0x1cf1f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1cf1f8: 0x473825  or          $a3, $v0, $a3
    ctx->pc = 0x1cf1f8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) | GPR_U64(ctx, 7));
    // 0x1cf1fc: 0xc0739e4  jal         func_1CE790
    ctx->pc = 0x1CF1FCu;
    SET_GPR_U32(ctx, 31, 0x1CF204u);
    ctx->pc = 0x1CF200u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF1FCu;
            // 0x1cf200: 0x30e5ffff  andi        $a1, $a3, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE790u;
    if (runtime->hasFunction(0x1CE790u)) {
        auto targetFn = runtime->lookupFunction(0x1CE790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF204u; }
        if (ctx->pc != 0x1CF204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE790_0x1ce790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF204u; }
        if (ctx->pc != 0x1CF204u) { return; }
    }
    ctx->pc = 0x1CF204u;
label_1cf204:
    // 0x1cf204: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1CF204u;
    {
        const bool branch_taken_0x1cf204 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF204u;
            // 0x1cf208: 0x30e5ffff  andi        $a1, $a3, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf204) {
            ctx->pc = 0x1CF24Cu;
            goto label_1cf24c;
        }
    }
    ctx->pc = 0x1CF20Cu;
    // 0x1cf20c: 0x100302d  daddu       $a2, $t0, $zero
    ctx->pc = 0x1cf20cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf210: 0x324400ff  andi        $a0, $s2, 0xFF
    ctx->pc = 0x1cf210u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1cf214: 0xc073a00  jal         func_1CE800
    ctx->pc = 0x1CF214u;
    SET_GPR_U32(ctx, 31, 0x1CF21Cu);
    ctx->pc = 0x1CF218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF214u;
            // 0x1cf218: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE800u;
    if (runtime->hasFunction(0x1CE800u)) {
        auto targetFn = runtime->lookupFunction(0x1CE800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF21Cu; }
        if (ctx->pc != 0x1CF21Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE800_0x1ce800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF21Cu; }
        if (ctx->pc != 0x1CF21Cu) { return; }
    }
    ctx->pc = 0x1CF21Cu;
label_1cf21c:
    // 0x1cf21c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cf21cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cf220: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF220u;
    {
        const bool branch_taken_0x1cf220 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1CF224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF220u;
            // 0x1cf224: 0x22080  sll         $a0, $v0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf220) {
            ctx->pc = 0x1CF230u;
            goto label_1cf230;
        }
    }
    ctx->pc = 0x1CF228u;
    // 0x1cf228: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1CF228u;
    {
        const bool branch_taken_0x1cf228 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF22Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF228u;
            // 0x1cf22c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf228) {
            ctx->pc = 0x1CF2C8u;
            goto label_1cf2c8;
        }
    }
    ctx->pc = 0x1CF230u;
label_1cf230:
    // 0x1cf230: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1cf230u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1cf234: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x1cf234u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1cf238: 0x24631500  addiu       $v1, $v1, 0x1500
    ctx->pc = 0x1cf238u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5376));
    // 0x1cf23c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1cf23cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1cf240: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1cf240u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1cf244: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1CF244u;
    {
        const bool branch_taken_0x1cf244 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF244u;
            // 0x1cf248: 0x24460002  addiu       $a2, $v0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf244) {
            ctx->pc = 0x1CF274u;
            goto label_1cf274;
        }
    }
    ctx->pc = 0x1CF24Cu;
label_1cf24c:
    // 0x1cf24c: 0x9044000f  lbu         $a0, 0xF($v0)
    ctx->pc = 0x1cf24cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 15)));
    // 0x1cf250: 0x1001827  not         $v1, $t0
    ctx->pc = 0x1cf250u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 8) | GPR_U64(ctx, 0)));
    // 0x1cf254: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x1cf254u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1cf258: 0x1031825  or          $v1, $t0, $v1
    ctx->pc = 0x1cf258u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1cf25c: 0x12c00004  beqz        $s6, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CF25Cu;
    {
        const bool branch_taken_0x1cf25c = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF25Cu;
            // 0x1cf260: 0xa043000f  sb          $v1, 0xF($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 15), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf25c) {
            ctx->pc = 0x1CF270u;
            goto label_1cf270;
        }
    }
    ctx->pc = 0x1CF264u;
    // 0x1cf264: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1cf264u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cf268: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cf268u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cf26c: 0xa0430000  sb          $v1, 0x0($v0)
    ctx->pc = 0x1cf26cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
label_1cf270:
    // 0x1cf270: 0x24460002  addiu       $a2, $v0, 0x2
    ctx->pc = 0x1cf270u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
label_1cf274:
    // 0x1cf274: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cf274u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cf278: 0x16420002  bne         $s2, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CF278u;
    {
        const bool branch_taken_0x1cf278 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x1cf278) {
            ctx->pc = 0x1CF284u;
            goto label_1cf284;
        }
    }
    ctx->pc = 0x1CF280u;
    // 0x1cf280: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1cf280u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cf284:
    // 0x1cf284: 0x8e650004  lw          $a1, 0x4($s3)
    ctx->pc = 0x1cf284u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x1cf288: 0x1438fc  dsll32      $a3, $s4, 3
    ctx->pc = 0x1cf288u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 20) << (32 + 3));
    // 0x1cf28c: 0x1011c0  sll         $v0, $s0, 7
    ctx->pc = 0x1cf28cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 7));
    // 0x1cf290: 0x738fe  dsrl32      $a3, $a3, 3
    ctx->pc = 0x1cf290u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) >> (32 + 3));
    // 0x1cf294: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1cf294u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf298: 0x2e0482d  daddu       $t1, $s7, $zero
    ctx->pc = 0x1cf298u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf29c: 0x240502d  daddu       $t2, $s2, $zero
    ctx->pc = 0x1cf29cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf2a0: 0x2224025  or          $t0, $s1, $v0
    ctx->pc = 0x1cf2a0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    // 0x1cf2a4: 0xc073cc8  jal         func_1CF320
    ctx->pc = 0x1CF2A4u;
    SET_GPR_U32(ctx, 31, 0x1CF2ACu);
    ctx->pc = 0x1CF2A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF2A4u;
            // 0x1cf2a8: 0x2c0582d  daddu       $t3, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF320u;
    if (runtime->hasFunction(0x1CF320u)) {
        auto targetFn = runtime->lookupFunction(0x1CF320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF2ACu; }
        if (ctx->pc != 0x1CF2ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF320_0x1cf320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF2ACu; }
        if (ctx->pc != 0x1CF2ACu) { return; }
    }
    ctx->pc = 0x1CF2ACu;
label_1cf2ac:
    // 0x1cf2ac: 0x12c00006  beqz        $s6, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CF2ACu;
    {
        const bool branch_taken_0x1cf2ac = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF2B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF2ACu;
            // 0x1cf2b0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf2ac) {
            ctx->pc = 0x1CF2C8u;
            goto label_1cf2c8;
        }
    }
    ctx->pc = 0x1CF2B4u;
    // 0x1cf2b4: 0x8e640004  lw          $a0, 0x4($s3)
    ctx->pc = 0x1cf2b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x1cf2b8: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x1cf2b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf2bc: 0xc073bc0  jal         func_1CEF00
    ctx->pc = 0x1CF2BCu;
    SET_GPR_U32(ctx, 31, 0x1CF2C4u);
    ctx->pc = 0x1CF2C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF2BCu;
            // 0x1cf2c0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CEF00u;
    if (runtime->hasFunction(0x1CEF00u)) {
        auto targetFn = runtime->lookupFunction(0x1CEF00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF2C4u; }
        if (ctx->pc != 0x1CF2C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CEF00_0x1cef00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF2C4u; }
        if (ctx->pc != 0x1CF2C4u) { return; }
    }
    ctx->pc = 0x1CF2C4u;
label_1cf2c4:
    // 0x1cf2c4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cf2c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1cf2c8:
    // 0x1cf2c8: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1cf2c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1cf2cc: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1cf2ccu;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1cf2d0: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1cf2d0u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1cf2d4: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1cf2d4u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1cf2d8: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1cf2d8u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1cf2dc: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1cf2dcu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cf2e0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cf2e0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cf2e4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cf2e4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cf2e8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cf2e8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cf2ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1CF2ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CF2F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF2ECu;
            // 0x1cf2f0: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CF0F0u: goto label_1cf0f0;
            case 0x1CF0F4u: goto label_1cf0f4;
            case 0x1CF108u: goto label_1cf108;
            case 0x1CF118u: goto label_1cf118;
            case 0x1CF12Cu: goto label_1cf12c;
            case 0x1CF140u: goto label_1cf140;
            case 0x1CF144u: goto label_1cf144;
            case 0x1CF16Cu: goto label_1cf16c;
            case 0x1CF1A0u: goto label_1cf1a0;
            case 0x1CF1BCu: goto label_1cf1bc;
            case 0x1CF1C0u: goto label_1cf1c0;
            case 0x1CF1C8u: goto label_1cf1c8;
            case 0x1CF1DCu: goto label_1cf1dc;
            case 0x1CF1F0u: goto label_1cf1f0;
            case 0x1CF204u: goto label_1cf204;
            case 0x1CF21Cu: goto label_1cf21c;
            case 0x1CF230u: goto label_1cf230;
            case 0x1CF24Cu: goto label_1cf24c;
            case 0x1CF270u: goto label_1cf270;
            case 0x1CF274u: goto label_1cf274;
            case 0x1CF284u: goto label_1cf284;
            case 0x1CF2ACu: goto label_1cf2ac;
            case 0x1CF2C4u: goto label_1cf2c4;
            case 0x1CF2C8u: goto label_1cf2c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CF2F4u;
    // 0x1cf2f4: 0x0  nop
    ctx->pc = 0x1cf2f4u;
    // NOP
    // 0x1cf2f8: 0x0  nop
    ctx->pc = 0x1cf2f8u;
    // NOP
    // 0x1cf2fc: 0x0  nop
    ctx->pc = 0x1cf2fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
