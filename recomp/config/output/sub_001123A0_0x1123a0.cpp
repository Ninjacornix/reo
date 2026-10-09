#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001123A0
// Address: 0x1123a0 - 0x112440
void sub_001123A0_0x1123a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001123A0_0x1123a0");
#endif

    switch (ctx->pc) {
        case 0x1123b8u: goto label_1123b8;
        default: break;
    }

    ctx->pc = 0x1123a0u;

    // 0x1123a0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1123a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1123a4: 0xffa40020  sd          $a0, 0x20($sp)
    ctx->pc = 0x1123a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 4));
    // 0x1123a8: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1123a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1123ac: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1123acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1123b0: 0xc044674  jal         func_1119D0
    ctx->pc = 0x1123B0u;
    SET_GPR_U32(ctx, 31, 0x1123B8u);
    ctx->pc = 0x1123B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1123B0u;
            // 0x1123b4: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1119D0u;
    if (runtime->hasFunction(0x1119D0u)) {
        auto targetFn = runtime->lookupFunction(0x1119D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1123B8u; }
        if (ctx->pc != 0x1123B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001119D0_0x1119d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1123B8u; }
        if (ctx->pc != 0x1123B8u) { return; }
    }
    ctx->pc = 0x1123B8u;
label_1123b8:
    // 0x1123b8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1123b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1123bc: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x1123bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1123c0: 0x38830002  xori        $v1, $a0, 0x2
    ctx->pc = 0x1123c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)2);
    // 0x1123c4: 0x1060001a  beqz        $v1, . + 4 + (0x1A << 2)
    ctx->pc = 0x1123C4u;
    {
        const bool branch_taken_0x1123c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1123C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1123C4u;
            // 0x1123c8: 0x2c850002  sltiu       $a1, $a0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1123c4) {
            ctx->pc = 0x112430u;
            goto label_112430;
        }
    }
    ctx->pc = 0x1123CCu;
    // 0x1123cc: 0x14a00019  bnez        $a1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1123CCu;
    {
        const bool branch_taken_0x1123cc = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1123D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1123CCu;
            // 0x1123d0: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1123cc) {
            ctx->pc = 0x112434u;
            goto label_112434;
        }
    }
    ctx->pc = 0x1123D4u;
    // 0x1123d4: 0x38820004  xori        $v0, $a0, 0x4
    ctx->pc = 0x1123d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)4);
    // 0x1123d8: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1123D8u;
    {
        const bool branch_taken_0x1123d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1123DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1123D8u;
            // 0x1123dc: 0x8fa30004  lw          $v1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1123d8) {
            ctx->pc = 0x1123FCu;
            goto label_1123fc;
        }
    }
    ctx->pc = 0x1123E0u;
    // 0x1123e0: 0x8fa50008  lw          $a1, 0x8($sp)
    ctx->pc = 0x1123e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1123e4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1123e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1123e8: 0x4a00012  bltz        $a1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1123E8u;
    {
        const bool branch_taken_0x1123e8 = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x1123ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1123E8u;
            // 0x1123ec: 0x28a3001f  slti        $v1, $a1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)31) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1123e8) {
            ctx->pc = 0x112434u;
            goto label_112434;
        }
    }
    ctx->pc = 0x1123F0u;
    // 0x1123f0: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1123F0u;
    {
        const bool branch_taken_0x1123f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1123F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1123F0u;
            // 0x1123f4: 0x2403003c  addiu       $v1, $zero, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1123f0) {
            ctx->pc = 0x112410u;
            goto label_112410;
        }
    }
    ctx->pc = 0x1123F8u;
    // 0x1123f8: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x1123f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_1123fc:
    // 0x1123fc: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x1123fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x112400: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x112400u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x112404: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x112404u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x112408: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x112408u;
    {
        const bool branch_taken_0x112408 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11240Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112408u;
            // 0x11240c: 0x83100b  movn        $v0, $a0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x112408) {
            ctx->pc = 0x112430u;
            goto label_112430;
        }
    }
    ctx->pc = 0x112410u;
label_112410:
    // 0x112410: 0xdfa20010  ld          $v0, 0x10($sp)
    ctx->pc = 0x112410u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x112414: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x112414u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x112418: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x112418u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x11241c: 0x621016  dsrlv       $v0, $v0, $v1
    ctx->pc = 0x11241cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (GPR_U32(ctx, 3) & 0x3F));
    // 0x112420: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x112420u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x112424: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x112424u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x112428: 0x21823  negu        $v1, $v0
    ctx->pc = 0x112428u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x11242c: 0x64100b  movn        $v0, $v1, $a0
    ctx->pc = 0x11242cu;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
label_112430:
    // 0x112430: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x112430u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_112434:
    // 0x112434: 0x3e00008  jr          $ra
    ctx->pc = 0x112434u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x112434u;
            // 0x112438: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1123B8u: goto label_1123b8;
            case 0x1123FCu: goto label_1123fc;
            case 0x112410u: goto label_112410;
            case 0x112430u: goto label_112430;
            case 0x112434u: goto label_112434;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11243Cu;
    // 0x11243c: 0x0  nop
    ctx->pc = 0x11243cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
