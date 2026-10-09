#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A0350
// Address: 0x1a0350 - 0x1a0920
void sub_001A0350_0x1a0350(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A0350_0x1a0350");
#endif

    switch (ctx->pc) {
        case 0x1a0454u: goto label_1a0454;
        case 0x1a0464u: goto label_1a0464;
        case 0x1a046cu: goto label_1a046c;
        case 0x1a047cu: goto label_1a047c;
        case 0x1a0490u: goto label_1a0490;
        default: break;
    }

    ctx->pc = 0x1a0350u;

    // 0x1a0350: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a0350u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a0354: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x1a0354u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1a0358: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a0358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a035c: 0x3c06002a  lui         $a2, 0x2A
    ctx->pc = 0x1a035cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)42 << 16));
    // 0x1a0360: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a0360u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a0364: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x1a0364u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1a0368: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a0368u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a036c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a036cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0370: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x1a0370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x1a0374: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a0374u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0378: 0x32140  sll         $a0, $v1, 5
    ctx->pc = 0x1a0378u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1a037c: 0x24c6f870  addiu       $a2, $a2, -0x790
    ctx->pc = 0x1a037cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294965360));
    // 0x1a0380: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1a0380u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a0384: 0x1043002f  beq         $v0, $v1, . + 4 + (0x2F << 2)
    ctx->pc = 0x1A0384u;
    {
        const bool branch_taken_0x1a0384 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A0388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0384u;
            // 0x1a0388: 0xc48021  addu        $s0, $a2, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0384) {
            ctx->pc = 0x1A0444u;
            goto label_1a0444;
        }
    }
    ctx->pc = 0x1A038Cu;
    // 0x1a038c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a038cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0390: 0x8c22f9fc  lw          $v0, -0x604($at)
    ctx->pc = 0x1a0390u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965756)));
    // 0x1a0394: 0x14430014  bne         $v0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1A0394u;
    {
        const bool branch_taken_0x1a0394 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1A0398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0394u;
            // 0x1a0398: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0394) {
            ctx->pc = 0x1A03E8u;
            goto label_1a03e8;
        }
    }
    ctx->pc = 0x1A039Cu;
    // 0x1a039c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a039cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a03a0: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1a03a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1a03a4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a03a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a03a8: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1a03a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1a03ac: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x1a03acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1a03b0: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1a03b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1a03b4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a03b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a03b8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1a03b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1a03bc: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1a03bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a03c0: 0xfe020060  sd          $v0, 0x60($s0)
    ctx->pc = 0x1a03c0u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 96), GPR_U64(ctx, 2));
    // 0x1a03c4: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1a03c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1a03c8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a03c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a03cc: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1a03ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1a03d0: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x1a03d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1a03d4: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1a03d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1a03d8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1a03d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1a03dc: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1a03dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a03e0: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1A03E0u;
    {
        const bool branch_taken_0x1a03e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A03E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A03E0u;
            // 0x1a03e4: 0xfe020070  sd          $v0, 0x70($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 112), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a03e0) {
            ctx->pc = 0x1A0444u;
            goto label_1a0444;
        }
    }
    ctx->pc = 0x1A03E8u;
label_1a03e8:
    // 0x1a03e8: 0x8c23fd58  lw          $v1, -0x2A8($at)
    ctx->pc = 0x1a03e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1a03ec: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a03ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a03f0: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1a03f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1a03f4: 0x8c22fd54  lw          $v0, -0x2AC($at)
    ctx->pc = 0x1a03f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1a03f8: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1a03f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1a03fc: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1a03fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a0400: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1a0400u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1a0404: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1a0404u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a0408: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1a0408u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1a040c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a040cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0410: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1a0410u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1a0414: 0xfe020060  sd          $v0, 0x60($s0)
    ctx->pc = 0x1a0414u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 96), GPR_U64(ctx, 2));
    // 0x1a0418: 0x8c23fd58  lw          $v1, -0x2A8($at)
    ctx->pc = 0x1a0418u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1a041c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a041cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0420: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1a0420u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1a0424: 0x8c22fd54  lw          $v0, -0x2AC($at)
    ctx->pc = 0x1a0424u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1a0428: 0x24630008  addiu       $v1, $v1, 0x8
    ctx->pc = 0x1a0428u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
    // 0x1a042c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1a042cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a0430: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1a0430u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1a0434: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1a0434u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a0438: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1a0438u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1a043c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1a043cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1a0440: 0xfe020070  sd          $v0, 0x70($s0)
    ctx->pc = 0x1a0440u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 112), GPR_U64(ctx, 2));
label_1a0444:
    // 0x1a0444: 0x14a00005  bnez        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A0444u;
    {
        const bool branch_taken_0x1a0444 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A0448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0444u;
            // 0x1a0448: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0444) {
            ctx->pc = 0x1A045Cu;
            goto label_1a045c;
        }
    }
    ctx->pc = 0x1A044Cu;
    // 0x1a044c: 0xc045234  jal         func_1148D0
    ctx->pc = 0x1A044Cu;
    SET_GPR_U32(ctx, 31, 0x1A0454u);
    ctx->pc = 0x1A0450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A044Cu;
            // 0x1a0450: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148D0u;
    if (runtime->hasFunction(0x1148D0u)) {
        auto targetFn = runtime->lookupFunction(0x1148D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0454u; }
        if (ctx->pc != 0x1A0454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148D0_0x1148d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0454u; }
        if (ctx->pc != 0x1A0454u) { return; }
    }
    ctx->pc = 0x1A0454u;
label_1a0454:
    // 0x1a0454: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A0454u;
    {
        const bool branch_taken_0x1a0454 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a0454) {
            ctx->pc = 0x1A0464u;
            goto label_1a0464;
        }
    }
    ctx->pc = 0x1A045Cu;
label_1a045c:
    // 0x1a045c: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1A045Cu;
    SET_GPR_U32(ctx, 31, 0x1A0464u);
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0464u; }
        if (ctx->pc != 0x1A0464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0464u; }
        if (ctx->pc != 0x1A0464u) { return; }
    }
    ctx->pc = 0x1A0464u;
label_1a0464:
    // 0x1a0464: 0xc063594  jal         func_18D650
    ctx->pc = 0x1A0464u;
    SET_GPR_U32(ctx, 31, 0x1A046Cu);
    ctx->pc = 0x18D650u;
    if (runtime->hasFunction(0x18D650u)) {
        auto targetFn = runtime->lookupFunction(0x18D650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A046Cu; }
        if (ctx->pc != 0x1A046Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D650_0x18d650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A046Cu; }
        if (ctx->pc != 0x1A046Cu) { return; }
    }
    ctx->pc = 0x1A046Cu;
label_1a046c:
    // 0x1a046c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a046cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0470: 0x8c24fd7c  lw          $a0, -0x284($at)
    ctx->pc = 0x1a0470u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966652)));
    // 0x1a0474: 0xc040ce4  jal         func_103390
    ctx->pc = 0x1A0474u;
    SET_GPR_U32(ctx, 31, 0x1A047Cu);
    ctx->pc = 0x1A0478u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0474u;
            // 0x1a0478: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103390u;
    if (runtime->hasFunction(0x103390u)) {
        auto targetFn = runtime->lookupFunction(0x103390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A047Cu; }
        if (ctx->pc != 0x1A047Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103390_0x103390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A047Cu; }
        if (ctx->pc != 0x1A047Cu) { return; }
    }
    ctx->pc = 0x1A047Cu;
label_1a047c:
    // 0x1a047c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a047cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0480: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1a0480u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a0484: 0x8c24fd7c  lw          $a0, -0x284($at)
    ctx->pc = 0x1a0484u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966652)));
    // 0x1a0488: 0xc040d8c  jal         func_103630
    ctx->pc = 0x1A0488u;
    SET_GPR_U32(ctx, 31, 0x1A0490u);
    ctx->pc = 0x1A048Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0488u;
            // 0x1a048c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103630u;
    if (runtime->hasFunction(0x103630u)) {
        auto targetFn = runtime->lookupFunction(0x103630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0490u; }
        if (ctx->pc != 0x1A0490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103630_0x103630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0490u; }
        if (ctx->pc != 0x1A0490u) { return; }
    }
    ctx->pc = 0x1A0490u;
label_1a0490:
    // 0x1a0490: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A0490u;
    {
        const bool branch_taken_0x1a0490 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a0490) {
            ctx->pc = 0x1A047Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a047c;
        }
    }
    ctx->pc = 0x1A0498u;
    // 0x1a0498: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0498u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a049c: 0x8c28fd64  lw          $t0, -0x29C($at)
    ctx->pc = 0x1a049cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966628)));
    // 0x1a04a0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a04a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a04a4: 0x8c27fd6c  lw          $a3, -0x294($at)
    ctx->pc = 0x1a04a4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966636)));
    // 0x1a04a8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a04a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a04ac: 0x8c26f9c4  lw          $a2, -0x63C($at)
    ctx->pc = 0x1a04acu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965700)));
    // 0x1a04b0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a04b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a04b4: 0x8c24fd68  lw          $a0, -0x298($at)
    ctx->pc = 0x1a04b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966632)));
    // 0x1a04b8: 0xe63018  mult        $a2, $a3, $a2
    ctx->pc = 0x1a04b8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x1a04bc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a04bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a04c0: 0x8c23fd70  lw          $v1, -0x290($at)
    ctx->pc = 0x1a04c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966640)));
    // 0x1a04c4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a04c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a04c8: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1a04c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1a04cc: 0x8c25f9b4  lw          $a1, -0x64C($at)
    ctx->pc = 0x1a04ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x1a04d0: 0x14a0004a  bnez        $a1, . + 4 + (0x4A << 2)
    ctx->pc = 0x1A04D0u;
    {
        const bool branch_taken_0x1a04d0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A04D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A04D0u;
            // 0x1a04d4: 0x1062021  addu        $a0, $t0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a04d0) {
            ctx->pc = 0x1A05FCu;
            goto label_1a05fc;
        }
    }
    ctx->pc = 0x1A04D8u;
    // 0x1a04d8: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x1a04d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a04dc: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a04dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a04e0: 0xfc260020  sd          $a2, 0x20($at)
    ctx->pc = 0x1a04e0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 32), GPR_U64(ctx, 6));
    // 0x1a04e4: 0x24050066  addiu       $a1, $zero, 0x66
    ctx->pc = 0x1a04e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1a04e8: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a04e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a04ec: 0x16200017  bnez        $s1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1A04ECu;
    {
        const bool branch_taken_0x1a04ec = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A04F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A04ECu;
            // 0x1a04f0: 0xfc250000  sd          $a1, 0x0($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 0), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a04ec) {
            ctx->pc = 0x1A054Cu;
            goto label_1a054c;
        }
    }
    ctx->pc = 0x1A04F4u;
    // 0x1a04f4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a04f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a04f8: 0x8c26fed8  lw          $a2, -0x128($at)
    ctx->pc = 0x1a04f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967000)));
    // 0x1a04fc: 0x4c10003  bgez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A04FCu;
    {
        const bool branch_taken_0x1a04fc = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1A0500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A04FCu;
            // 0x1a0500: 0x62983  sra         $a1, $a2, 6 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 6), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a04fc) {
            ctx->pc = 0x1A050Cu;
            goto label_1a050c;
        }
    }
    ctx->pc = 0x1A0504u;
    // 0x1a0504: 0x24c5003f  addiu       $a1, $a2, 0x3F
    ctx->pc = 0x1a0504u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 63));
    // 0x1a0508: 0x52983  sra         $a1, $a1, 6
    ctx->pc = 0x1a0508u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 6));
label_1a050c:
    // 0x1a050c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a050cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0510: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1a0510u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1a0514: 0x8c26f9d8  lw          $a2, -0x628($at)
    ctx->pc = 0x1a0514u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965720)));
    // 0x1a0518: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x1a0518u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1a051c: 0x53a78  dsll        $a3, $a1, 9
    ctx->pc = 0x1a051cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) << 9);
    // 0x1a0520: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0520u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0524: 0x63142  srl         $a2, $a2, 5
    ctx->pc = 0x1a0524u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 5));
    // 0x1a0528: 0x9c25f9cc  lwu         $a1, -0x634($at)
    ctx->pc = 0x1a0528u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 4294965708)));
    // 0x1a052c: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x1a052cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x1a0530: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x1a0530u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x1a0534: 0xc73025  or          $a2, $a2, $a3
    ctx->pc = 0x1a0534u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
    // 0x1a0538: 0x52bf8  dsll        $a1, $a1, 15
    ctx->pc = 0x1a0538u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 15);
    // 0x1a053c: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a053cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a0540: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x1a0540u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x1a0544: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1A0544u;
    {
        const bool branch_taken_0x1a0544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0544u;
            // 0x1a0548: 0xfc250090  sd          $a1, 0x90($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 144), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0544) {
            ctx->pc = 0x1A05A0u;
            goto label_1a05a0;
        }
    }
    ctx->pc = 0x1A054Cu;
label_1a054c:
    // 0x1a054c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a054cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0550: 0x8c26fed8  lw          $a2, -0x128($at)
    ctx->pc = 0x1a0550u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967000)));
    // 0x1a0554: 0x4c10003  bgez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A0554u;
    {
        const bool branch_taken_0x1a0554 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1A0558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0554u;
            // 0x1a0558: 0x62983  sra         $a1, $a2, 6 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 6), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0554) {
            ctx->pc = 0x1A0564u;
            goto label_1a0564;
        }
    }
    ctx->pc = 0x1A055Cu;
    // 0x1a055c: 0x24c5003f  addiu       $a1, $a2, 0x3F
    ctx->pc = 0x1a055cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 63));
    // 0x1a0560: 0x52983  sra         $a1, $a1, 6
    ctx->pc = 0x1a0560u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 6));
label_1a0564:
    // 0x1a0564: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0564u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0568: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1a0568u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1a056c: 0x8c26f9dc  lw          $a2, -0x624($at)
    ctx->pc = 0x1a056cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965724)));
    // 0x1a0570: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x1a0570u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1a0574: 0x53a78  dsll        $a3, $a1, 9
    ctx->pc = 0x1a0574u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) << 9);
    // 0x1a0578: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0578u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a057c: 0x63142  srl         $a2, $a2, 5
    ctx->pc = 0x1a057cu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 5));
    // 0x1a0580: 0x9c25f9cc  lwu         $a1, -0x634($at)
    ctx->pc = 0x1a0580u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 4294965708)));
    // 0x1a0584: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x1a0584u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x1a0588: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x1a0588u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x1a058c: 0xc73025  or          $a2, $a2, $a3
    ctx->pc = 0x1a058cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
    // 0x1a0590: 0x52bf8  dsll        $a1, $a1, 15
    ctx->pc = 0x1a0590u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 15);
    // 0x1a0594: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a0594u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a0598: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x1a0598u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x1a059c: 0xfc250090  sd          $a1, 0x90($at)
    ctx->pc = 0x1a059cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 144), GPR_U64(ctx, 5));
label_1a05a0:
    // 0x1a05a0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a05a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a05a4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1a05a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a05a8: 0x9c25f9c4  lwu         $a1, -0x63C($at)
    ctx->pc = 0x1a05a8u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 4294965700)));
    // 0x1a05ac: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x1a05acu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1a05b0: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1a05b0u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1a05b4: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x1a05b4u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x1a05b8: 0x31b38  dsll        $v1, $v1, 12
    ctx->pc = 0x1a05b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 12);
    // 0x1a05bc: 0x833025  or          $a2, $a0, $v1
    ctx->pc = 0x1a05bcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a05c0: 0x240309ff  addiu       $v1, $zero, 0x9FF
    ctx->pc = 0x1a05c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2559));
    // 0x1a05c4: 0x3203c  dsll32      $a0, $v1, 0
    ctx->pc = 0x1a05c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a05c8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a05c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a05cc: 0x52df8  dsll        $a1, $a1, 23
    ctx->pc = 0x1a05ccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 23);
    // 0x1a05d0: 0x8c23f9c0  lw          $v1, -0x640($at)
    ctx->pc = 0x1a05d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965696)));
    // 0x1a05d4: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x1a05d4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x1a05d8: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1a05d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1a05dc: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1a05dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a05e0: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a05e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a05e4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1a05e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a05e8: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1a05e8u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1a05ec: 0x31b3c  dsll32      $v1, $v1, 12
    ctx->pc = 0x1a05ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 12));
    // 0x1a05f0: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1a05f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1a05f4: 0x100000c0  b           . + 4 + (0xC0 << 2)
    ctx->pc = 0x1A05F4u;
    {
        const bool branch_taken_0x1a05f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A05F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A05F4u;
            // 0x1a05f8: 0xfc2300a0  sd          $v1, 0xA0($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 160), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a05f4) {
            ctx->pc = 0x1A08F8u;
            goto label_1a08f8;
        }
    }
    ctx->pc = 0x1A05FCu;
label_1a05fc:
    // 0x1a05fc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a05fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0600: 0x8c25f9b8  lw          $a1, -0x648($at)
    ctx->pc = 0x1a0600u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965688)));
    // 0x1a0604: 0x14a00075  bnez        $a1, . + 4 + (0x75 << 2)
    ctx->pc = 0x1A0604u;
    {
        const bool branch_taken_0x1a0604 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A0608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0604u;
            // 0x1a0608: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0604) {
            ctx->pc = 0x1A07DCu;
            goto label_1a07dc;
        }
    }
    ctx->pc = 0x1A060Cu;
    // 0x1a060c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1a060cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a0610: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a0610u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a0614: 0xfc260020  sd          $a2, 0x20($at)
    ctx->pc = 0x1a0614u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 32), GPR_U64(ctx, 6));
    // 0x1a0618: 0x24057f27  addiu       $a1, $zero, 0x7F27
    ctx->pc = 0x1a0618u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32551));
    // 0x1a061c: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a061cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a0620: 0x16200023  bnez        $s1, . + 4 + (0x23 << 2)
    ctx->pc = 0x1A0620u;
    {
        const bool branch_taken_0x1a0620 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A0624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0620u;
            // 0x1a0624: 0xfc250000  sd          $a1, 0x0($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 0), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0620) {
            ctx->pc = 0x1A06B0u;
            goto label_1a06b0;
        }
    }
    ctx->pc = 0x1A0628u;
    // 0x1a0628: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0628u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a062c: 0x8c26fed8  lw          $a2, -0x128($at)
    ctx->pc = 0x1a062cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967000)));
    // 0x1a0630: 0x4c10003  bgez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A0630u;
    {
        const bool branch_taken_0x1a0630 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1A0634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0630u;
            // 0x1a0634: 0x62983  sra         $a1, $a2, 6 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 6), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0630) {
            ctx->pc = 0x1A0640u;
            goto label_1a0640;
        }
    }
    ctx->pc = 0x1A0638u;
    // 0x1a0638: 0x24c5003f  addiu       $a1, $a2, 0x3F
    ctx->pc = 0x1a0638u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 63));
    // 0x1a063c: 0x52983  sra         $a1, $a1, 6
    ctx->pc = 0x1a063cu;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 6));
label_1a0640:
    // 0x1a0640: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0640u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0644: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1a0644u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1a0648: 0x9c26f9cc  lwu         $a2, -0x634($at)
    ctx->pc = 0x1a0648u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 1), 4294965708)));
    // 0x1a064c: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x1a064cu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1a0650: 0x53a78  dsll        $a3, $a1, 9
    ctx->pc = 0x1a0650u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) << 9);
    // 0x1a0654: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0654u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0658: 0x633f8  dsll        $a2, $a2, 15
    ctx->pc = 0x1a0658u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 15);
    // 0x1a065c: 0x8c25f9d8  lw          $a1, -0x628($at)
    ctx->pc = 0x1a065cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965720)));
    // 0x1a0660: 0x52942  srl         $a1, $a1, 5
    ctx->pc = 0x1a0660u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 5));
    // 0x1a0664: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a0664u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a0668: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1a0668u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1a066c: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x1a066cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x1a0670: 0xa72825  or          $a1, $a1, $a3
    ctx->pc = 0x1a0670u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x1a0674: 0xc52825  or          $a1, $a2, $a1
    ctx->pc = 0x1a0674u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x1a0678: 0xfc250070  sd          $a1, 0x70($at)
    ctx->pc = 0x1a0678u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 112), GPR_U64(ctx, 5));
    // 0x1a067c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a067cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0680: 0x9c26f9cc  lwu         $a2, -0x634($at)
    ctx->pc = 0x1a0680u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 1), 4294965708)));
    // 0x1a0684: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0684u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0688: 0x633f8  dsll        $a2, $a2, 15
    ctx->pc = 0x1a0688u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 15);
    // 0x1a068c: 0x8c25f9d8  lw          $a1, -0x628($at)
    ctx->pc = 0x1a068cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965720)));
    // 0x1a0690: 0x52942  srl         $a1, $a1, 5
    ctx->pc = 0x1a0690u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 5));
    // 0x1a0694: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a0694u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a0698: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1a0698u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1a069c: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x1a069cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x1a06a0: 0xa72825  or          $a1, $a1, $a3
    ctx->pc = 0x1a06a0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x1a06a4: 0xc52825  or          $a1, $a2, $a1
    ctx->pc = 0x1a06a4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x1a06a8: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1A06A8u;
    {
        const bool branch_taken_0x1a06a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A06ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A06A8u;
            // 0x1a06ac: 0xfc250090  sd          $a1, 0x90($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 144), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a06a8) {
            ctx->pc = 0x1A0734u;
            goto label_1a0734;
        }
    }
    ctx->pc = 0x1A06B0u;
label_1a06b0:
    // 0x1a06b0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a06b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a06b4: 0x8c26fed8  lw          $a2, -0x128($at)
    ctx->pc = 0x1a06b4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967000)));
    // 0x1a06b8: 0x4c10003  bgez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A06B8u;
    {
        const bool branch_taken_0x1a06b8 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1A06BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A06B8u;
            // 0x1a06bc: 0x62983  sra         $a1, $a2, 6 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 6), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a06b8) {
            ctx->pc = 0x1A06C8u;
            goto label_1a06c8;
        }
    }
    ctx->pc = 0x1A06C0u;
    // 0x1a06c0: 0x24c5003f  addiu       $a1, $a2, 0x3F
    ctx->pc = 0x1a06c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 63));
    // 0x1a06c4: 0x52983  sra         $a1, $a1, 6
    ctx->pc = 0x1a06c4u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 6));
label_1a06c8:
    // 0x1a06c8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a06c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a06cc: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1a06ccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1a06d0: 0x9c26f9cc  lwu         $a2, -0x634($at)
    ctx->pc = 0x1a06d0u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 1), 4294965708)));
    // 0x1a06d4: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x1a06d4u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1a06d8: 0x53a78  dsll        $a3, $a1, 9
    ctx->pc = 0x1a06d8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) << 9);
    // 0x1a06dc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a06dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a06e0: 0x633f8  dsll        $a2, $a2, 15
    ctx->pc = 0x1a06e0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 15);
    // 0x1a06e4: 0x8c25f9dc  lw          $a1, -0x624($at)
    ctx->pc = 0x1a06e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965724)));
    // 0x1a06e8: 0x52942  srl         $a1, $a1, 5
    ctx->pc = 0x1a06e8u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 5));
    // 0x1a06ec: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a06ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a06f0: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1a06f0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1a06f4: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x1a06f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x1a06f8: 0xa72825  or          $a1, $a1, $a3
    ctx->pc = 0x1a06f8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x1a06fc: 0xc52825  or          $a1, $a2, $a1
    ctx->pc = 0x1a06fcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x1a0700: 0xfc250070  sd          $a1, 0x70($at)
    ctx->pc = 0x1a0700u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 112), GPR_U64(ctx, 5));
    // 0x1a0704: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0704u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0708: 0x9c26f9cc  lwu         $a2, -0x634($at)
    ctx->pc = 0x1a0708u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 1), 4294965708)));
    // 0x1a070c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a070cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0710: 0x633f8  dsll        $a2, $a2, 15
    ctx->pc = 0x1a0710u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 15);
    // 0x1a0714: 0x8c25f9dc  lw          $a1, -0x624($at)
    ctx->pc = 0x1a0714u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965724)));
    // 0x1a0718: 0x52942  srl         $a1, $a1, 5
    ctx->pc = 0x1a0718u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 5));
    // 0x1a071c: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a071cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a0720: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1a0720u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1a0724: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x1a0724u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x1a0728: 0xa72825  or          $a1, $a1, $a3
    ctx->pc = 0x1a0728u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x1a072c: 0xc52825  or          $a1, $a2, $a1
    ctx->pc = 0x1a072cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x1a0730: 0xfc250090  sd          $a1, 0x90($at)
    ctx->pc = 0x1a0730u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 144), GPR_U64(ctx, 5));
label_1a0734:
    // 0x1a0734: 0x4283c  dsll32      $a1, $a0, 0
    ctx->pc = 0x1a0734u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1a0738: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0738u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a073c: 0x24640001  addiu       $a0, $v1, 0x1
    ctx->pc = 0x1a073cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a0740: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x1a0740u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1a0744: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x1a0744u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1a0748: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1a0748u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a074c: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x1a074cu;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x1a0750: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1a0750u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1a0754: 0x42338  dsll        $a0, $a0, 12
    ctx->pc = 0x1a0754u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 12);
    // 0x1a0758: 0x31b38  dsll        $v1, $v1, 12
    ctx->pc = 0x1a0758u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 12);
    // 0x1a075c: 0xa43825  or          $a3, $a1, $a0
    ctx->pc = 0x1a075cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1a0760: 0xa32025  or          $a0, $a1, $v1
    ctx->pc = 0x1a0760u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x1a0764: 0x9c25f9c4  lwu         $a1, -0x63C($at)
    ctx->pc = 0x1a0764u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 4294965700)));
    // 0x1a0768: 0x240309ff  addiu       $v1, $zero, 0x9FF
    ctx->pc = 0x1a0768u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2559));
    // 0x1a076c: 0x3303c  dsll32      $a2, $v1, 0
    ctx->pc = 0x1a076cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a0770: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0770u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0774: 0x52df8  dsll        $a1, $a1, 23
    ctx->pc = 0x1a0774u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 23);
    // 0x1a0778: 0x8c23f9c0  lw          $v1, -0x640($at)
    ctx->pc = 0x1a0778u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965696)));
    // 0x1a077c: 0xa72825  or          $a1, $a1, $a3
    ctx->pc = 0x1a077cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x1a0780: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x1a0780u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x1a0784: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1a0784u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a0788: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a0788u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a078c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1a078cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a0790: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1a0790u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1a0794: 0x31b3c  dsll32      $v1, $v1, 12
    ctx->pc = 0x1a0794u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 12));
    // 0x1a0798: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x1a0798u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x1a079c: 0xfc230080  sd          $v1, 0x80($at)
    ctx->pc = 0x1a079cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 128), GPR_U64(ctx, 3));
    // 0x1a07a0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a07a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a07a4: 0x9c25f9c4  lwu         $a1, -0x63C($at)
    ctx->pc = 0x1a07a4u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 4294965700)));
    // 0x1a07a8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a07a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a07ac: 0x52df8  dsll        $a1, $a1, 23
    ctx->pc = 0x1a07acu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 23);
    // 0x1a07b0: 0x8c23f9c0  lw          $v1, -0x640($at)
    ctx->pc = 0x1a07b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965696)));
    // 0x1a07b4: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1a07b4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1a07b8: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x1a07b8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x1a07bc: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1a07bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a07c0: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a07c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a07c4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1a07c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a07c8: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1a07c8u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1a07cc: 0x31b3c  dsll32      $v1, $v1, 12
    ctx->pc = 0x1a07ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 12));
    // 0x1a07d0: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1a07d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1a07d4: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1A07D4u;
    {
        const bool branch_taken_0x1a07d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A07D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A07D4u;
            // 0x1a07d8: 0xfc2300a0  sd          $v1, 0xA0($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 160), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a07d4) {
            ctx->pc = 0x1A08F8u;
            goto label_1a08f8;
        }
    }
    ctx->pc = 0x1A07DCu;
label_1a07dc:
    // 0x1a07dc: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a07dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a07e0: 0xfc260020  sd          $a2, 0x20($at)
    ctx->pc = 0x1a07e0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 32), GPR_U64(ctx, 6));
    // 0x1a07e4: 0x24050066  addiu       $a1, $zero, 0x66
    ctx->pc = 0x1a07e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1a07e8: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a07e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a07ec: 0x16200017  bnez        $s1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1A07ECu;
    {
        const bool branch_taken_0x1a07ec = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A07F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A07ECu;
            // 0x1a07f0: 0xfc250000  sd          $a1, 0x0($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 0), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a07ec) {
            ctx->pc = 0x1A084Cu;
            goto label_1a084c;
        }
    }
    ctx->pc = 0x1A07F4u;
    // 0x1a07f4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a07f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a07f8: 0x8c26fed8  lw          $a2, -0x128($at)
    ctx->pc = 0x1a07f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967000)));
    // 0x1a07fc: 0x4c10003  bgez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A07FCu;
    {
        const bool branch_taken_0x1a07fc = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1A0800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A07FCu;
            // 0x1a0800: 0x62983  sra         $a1, $a2, 6 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 6), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a07fc) {
            ctx->pc = 0x1A080Cu;
            goto label_1a080c;
        }
    }
    ctx->pc = 0x1A0804u;
    // 0x1a0804: 0x24c5003f  addiu       $a1, $a2, 0x3F
    ctx->pc = 0x1a0804u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 63));
    // 0x1a0808: 0x52983  sra         $a1, $a1, 6
    ctx->pc = 0x1a0808u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 6));
label_1a080c:
    // 0x1a080c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a080cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0810: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1a0810u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1a0814: 0x8c26f9d8  lw          $a2, -0x628($at)
    ctx->pc = 0x1a0814u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965720)));
    // 0x1a0818: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x1a0818u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1a081c: 0x53a78  dsll        $a3, $a1, 9
    ctx->pc = 0x1a081cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) << 9);
    // 0x1a0820: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0820u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0824: 0x63142  srl         $a2, $a2, 5
    ctx->pc = 0x1a0824u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 5));
    // 0x1a0828: 0x9c25f9cc  lwu         $a1, -0x634($at)
    ctx->pc = 0x1a0828u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 4294965708)));
    // 0x1a082c: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x1a082cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x1a0830: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x1a0830u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x1a0834: 0xc73025  or          $a2, $a2, $a3
    ctx->pc = 0x1a0834u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
    // 0x1a0838: 0x52bf8  dsll        $a1, $a1, 15
    ctx->pc = 0x1a0838u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 15);
    // 0x1a083c: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a083cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a0840: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x1a0840u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x1a0844: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1A0844u;
    {
        const bool branch_taken_0x1a0844 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0844u;
            // 0x1a0848: 0xfc250090  sd          $a1, 0x90($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 144), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0844) {
            ctx->pc = 0x1A08A0u;
            goto label_1a08a0;
        }
    }
    ctx->pc = 0x1A084Cu;
label_1a084c:
    // 0x1a084c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a084cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0850: 0x8c26fed8  lw          $a2, -0x128($at)
    ctx->pc = 0x1a0850u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967000)));
    // 0x1a0854: 0x4c10003  bgez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A0854u;
    {
        const bool branch_taken_0x1a0854 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1A0858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0854u;
            // 0x1a0858: 0x62983  sra         $a1, $a2, 6 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 6), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0854) {
            ctx->pc = 0x1A0864u;
            goto label_1a0864;
        }
    }
    ctx->pc = 0x1A085Cu;
    // 0x1a085c: 0x24c5003f  addiu       $a1, $a2, 0x3F
    ctx->pc = 0x1a085cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 63));
    // 0x1a0860: 0x52983  sra         $a1, $a1, 6
    ctx->pc = 0x1a0860u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 6));
label_1a0864:
    // 0x1a0864: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0864u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a0868: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1a0868u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1a086c: 0x8c26f9dc  lw          $a2, -0x624($at)
    ctx->pc = 0x1a086cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965724)));
    // 0x1a0870: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x1a0870u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1a0874: 0x53a78  dsll        $a3, $a1, 9
    ctx->pc = 0x1a0874u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) << 9);
    // 0x1a0878: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a0878u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a087c: 0x63142  srl         $a2, $a2, 5
    ctx->pc = 0x1a087cu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 5));
    // 0x1a0880: 0x9c25f9cc  lwu         $a1, -0x634($at)
    ctx->pc = 0x1a0880u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 4294965708)));
    // 0x1a0884: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x1a0884u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x1a0888: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x1a0888u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x1a088c: 0xc73025  or          $a2, $a2, $a3
    ctx->pc = 0x1a088cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
    // 0x1a0890: 0x52bf8  dsll        $a1, $a1, 15
    ctx->pc = 0x1a0890u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 15);
    // 0x1a0894: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a0894u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a0898: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x1a0898u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x1a089c: 0xfc250090  sd          $a1, 0x90($at)
    ctx->pc = 0x1a089cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 144), GPR_U64(ctx, 5));
label_1a08a0:
    // 0x1a08a0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a08a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a08a4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1a08a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a08a8: 0x9c25f9c4  lwu         $a1, -0x63C($at)
    ctx->pc = 0x1a08a8u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 4294965700)));
    // 0x1a08ac: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x1a08acu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1a08b0: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1a08b0u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1a08b4: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x1a08b4u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x1a08b8: 0x31b38  dsll        $v1, $v1, 12
    ctx->pc = 0x1a08b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 12);
    // 0x1a08bc: 0x833025  or          $a2, $a0, $v1
    ctx->pc = 0x1a08bcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a08c0: 0x240309ff  addiu       $v1, $zero, 0x9FF
    ctx->pc = 0x1a08c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2559));
    // 0x1a08c4: 0x3203c  dsll32      $a0, $v1, 0
    ctx->pc = 0x1a08c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a08c8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a08c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a08cc: 0x52df8  dsll        $a1, $a1, 23
    ctx->pc = 0x1a08ccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 23);
    // 0x1a08d0: 0x8c23f9c0  lw          $v1, -0x640($at)
    ctx->pc = 0x1a08d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965696)));
    // 0x1a08d4: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x1a08d4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x1a08d8: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1a08d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1a08dc: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1a08dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a08e0: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a08e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a08e4: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1a08e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1a08e8: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x1a08e8u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1a08ec: 0x31b3c  dsll32      $v1, $v1, 12
    ctx->pc = 0x1a08ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 12));
    // 0x1a08f0: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1a08f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1a08f4: 0xfc2300a0  sd          $v1, 0xA0($at)
    ctx->pc = 0x1a08f4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 160), GPR_U64(ctx, 3));
label_1a08f8:
    // 0x1a08f8: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x1a08f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x1a08fc: 0xfc2000d0  sd          $zero, 0xD0($at)
    ctx->pc = 0x1a08fcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 208), GPR_U64(ctx, 0));
    // 0x1a0900: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a0900u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a0904: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a0904u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a0908: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a0908u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a090c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A090Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A0910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A090Cu;
            // 0x1a0910: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A03E8u: goto label_1a03e8;
            case 0x1A0444u: goto label_1a0444;
            case 0x1A0454u: goto label_1a0454;
            case 0x1A045Cu: goto label_1a045c;
            case 0x1A0464u: goto label_1a0464;
            case 0x1A046Cu: goto label_1a046c;
            case 0x1A047Cu: goto label_1a047c;
            case 0x1A0490u: goto label_1a0490;
            case 0x1A050Cu: goto label_1a050c;
            case 0x1A054Cu: goto label_1a054c;
            case 0x1A0564u: goto label_1a0564;
            case 0x1A05A0u: goto label_1a05a0;
            case 0x1A05FCu: goto label_1a05fc;
            case 0x1A0640u: goto label_1a0640;
            case 0x1A06B0u: goto label_1a06b0;
            case 0x1A06C8u: goto label_1a06c8;
            case 0x1A0734u: goto label_1a0734;
            case 0x1A07DCu: goto label_1a07dc;
            case 0x1A080Cu: goto label_1a080c;
            case 0x1A084Cu: goto label_1a084c;
            case 0x1A0864u: goto label_1a0864;
            case 0x1A08A0u: goto label_1a08a0;
            case 0x1A08F8u: goto label_1a08f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A0914u;
    // 0x1a0914: 0x0  nop
    ctx->pc = 0x1a0914u;
    // NOP
    // 0x1a0918: 0x0  nop
    ctx->pc = 0x1a0918u;
    // NOP
    // 0x1a091c: 0x0  nop
    ctx->pc = 0x1a091cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
