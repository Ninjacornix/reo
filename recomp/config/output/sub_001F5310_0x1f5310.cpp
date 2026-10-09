#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F5310
// Address: 0x1f5310 - 0x1f5448
void sub_001F5310_0x1f5310(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F5310_0x1f5310");
#endif

    switch (ctx->pc) {
        case 0x1f5344u: goto label_1f5344;
        case 0x1f5384u: goto label_1f5384;
        case 0x1f539cu: goto label_1f539c;
        case 0x1f53c8u: goto label_1f53c8;
        default: break;
    }

    ctx->pc = 0x1f5310u;

    // 0x1f5310: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1f5310u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1f5314: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5314u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5318: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1f5318u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1f531c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1f531cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1f5320: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f5320u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f5324: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f5324u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f5328: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1f5328u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f532c: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f532cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f5330: 0x1040003e  beqz        $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x1F5330u;
    {
        const bool branch_taken_0x1f5330 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5330u;
            // 0x1f5334: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5330) {
            ctx->pc = 0x1F542Cu;
            goto label_1f542c;
        }
    }
    ctx->pc = 0x1F5338u;
    // 0x1f5338: 0x27a50040  addiu       $a1, $sp, 0x40
    ctx->pc = 0x1f5338u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1f533c: 0xc07d244  jal         func_1F4910
    ctx->pc = 0x1F533Cu;
    SET_GPR_U32(ctx, 31, 0x1F5344u);
    ctx->pc = 0x1F5340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F533Cu;
            // 0x1f5340: 0x2406000a  addiu       $a2, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4910u;
    if (runtime->hasFunction(0x1F4910u)) {
        auto targetFn = runtime->lookupFunction(0x1F4910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5344u; }
        if (ctx->pc != 0x1F5344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4910_0x1f4910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5344u; }
        if (ctx->pc != 0x1F5344u) { return; }
    }
    ctx->pc = 0x1F5344u;
label_1f5344:
    // 0x1f5344: 0x441000c  bgez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1F5344u;
    {
        const bool branch_taken_0x1f5344 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F5348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5344u;
            // 0x1f5348: 0x3c050036  lui         $a1, 0x36 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)54 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5344) {
            ctx->pc = 0x1F5378u;
            goto label_1f5378;
        }
    }
    ctx->pc = 0x1F534Cu;
    // 0x1f534c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1f534cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f5350: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f5350u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f5354: 0xae23008c  sw          $v1, 0x8C($s1)
    ctx->pc = 0x1f5354u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 3));
    // 0x1f5358: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f5358u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f535c: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f535cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5360: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f5360u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5364: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f5364u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5368: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f5368u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f536c: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f536cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5370: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f5370u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5374: 0xa620000a  sh          $zero, 0xA($s1)
    ctx->pc = 0x1f5374u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f5378:
    // 0x1f5378: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1f5378u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1f537c: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1F537Cu;
    SET_GPR_U32(ctx, 31, 0x1F5384u);
    ctx->pc = 0x1F5380u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F537Cu;
            // 0x1f5380: 0x24a5ec21  addiu       $a1, $a1, -0x13DF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294962209));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5384u; }
        if (ctx->pc != 0x1F5384u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5384u; }
        if (ctx->pc != 0x1F5384u) { return; }
    }
    ctx->pc = 0x1F5384u;
label_1f5384:
    // 0x1f5384: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F5384u;
    {
        const bool branch_taken_0x1f5384 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5384u;
            // 0x1f5388: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5384) {
            ctx->pc = 0x1F5394u;
            goto label_1f5394;
        }
    }
    ctx->pc = 0x1F538Cu;
    // 0x1f538c: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1F538Cu;
    {
        const bool branch_taken_0x1f538c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F538Cu;
            // 0x1f5390: 0x2402ffc1  addiu       $v0, $zero, -0x3F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967233));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f538c) {
            ctx->pc = 0x1F5430u;
            goto label_1f5430;
        }
    }
    ctx->pc = 0x1F5394u;
label_1f5394:
    // 0x1f5394: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5394u;
    SET_GPR_U32(ctx, 31, 0x1F539Cu);
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F539Cu; }
        if (ctx->pc != 0x1F539Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F539Cu; }
        if (ctx->pc != 0x1F539Cu) { return; }
    }
    ctx->pc = 0x1F539Cu;
label_1f539c:
    // 0x1f539c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1f539cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f53a0: 0x34018000  ori         $at, $zero, 0x8000
    ctx->pc = 0x1f53a0u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1f53a4: 0x241082a  slt         $at, $s2, $at
    ctx->pc = 0x1f53a4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1f53a8: 0x10200008  beqz        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F53A8u;
    {
        const bool branch_taken_0x1f53a8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F53ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F53A8u;
            // 0x1f53ac: 0x3c030036  lui         $v1, 0x36 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)54 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f53a8) {
            ctx->pc = 0x1F53CCu;
            goto label_1f53cc;
        }
    }
    ctx->pc = 0x1F53B0u;
    // 0x1f53b0: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x1f53b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1f53b4: 0x2463f080  addiu       $v1, $v1, -0xF80
    ctx->pc = 0x1f53b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963328));
    // 0x1f53b8: 0x523023  subu        $a2, $v0, $s2
    ctx->pc = 0x1f53b8u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1f53bc: 0x722821  addu        $a1, $v1, $s2
    ctx->pc = 0x1f53bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x1f53c0: 0xc07d244  jal         func_1F4910
    ctx->pc = 0x1F53C0u;
    SET_GPR_U32(ctx, 31, 0x1F53C8u);
    ctx->pc = 0x1F53C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F53C0u;
            // 0x1f53c4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4910u;
    if (runtime->hasFunction(0x1F4910u)) {
        auto targetFn = runtime->lookupFunction(0x1F4910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F53C8u; }
        if (ctx->pc != 0x1F53C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4910_0x1f4910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F53C8u; }
        if (ctx->pc != 0x1F53C8u) { return; }
    }
    ctx->pc = 0x1F53C8u;
label_1f53c8:
    // 0x1f53c8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1f53c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1f53cc:
    // 0x1f53cc: 0x601000b  bgez        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F53CCu;
    {
        const bool branch_taken_0x1f53cc = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x1F53D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F53CCu;
            // 0x1f53d0: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f53cc) {
            ctx->pc = 0x1F53FCu;
            goto label_1f53fc;
        }
    }
    ctx->pc = 0x1F53D4u;
    // 0x1f53d4: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f53d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f53d8: 0xae23008c  sw          $v1, 0x8C($s1)
    ctx->pc = 0x1f53d8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 3));
    // 0x1f53dc: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f53dcu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f53e0: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f53e0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f53e4: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f53e4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f53e8: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f53e8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f53ec: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f53ecu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f53f0: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f53f0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f53f4: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f53f4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f53f8: 0xa620000a  sh          $zero, 0xA($s1)
    ctx->pc = 0x1f53f8u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f53fc:
    // 0x1f53fc: 0x8e230064  lw          $v1, 0x64($s1)
    ctx->pc = 0x1f53fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 100)));
    // 0x1f5400: 0x2501021  addu        $v0, $s2, $s0
    ctx->pc = 0x1f5400u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x1f5404: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F5404u;
    {
        const bool branch_taken_0x1f5404 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1F5408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5404u;
            // 0x1f5408: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5404) {
            ctx->pc = 0x1F5428u;
            goto label_1f5428;
        }
    }
    ctx->pc = 0x1F540Cu;
    // 0x1f540c: 0x3c030036  lui         $v1, 0x36
    ctx->pc = 0x1f540cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)54 << 16));
    // 0x1f5410: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5410u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5414: 0x2463f080  addiu       $v1, $v1, -0xF80
    ctx->pc = 0x1f5414u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963328));
    // 0x1f5418: 0x2402000c  addiu       $v0, $zero, 0xC
    ctx->pc = 0x1f5418u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1f541c: 0xac23ec40  sw          $v1, -0x13C0($at)
    ctx->pc = 0x1f541cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962240), GPR_U32(ctx, 3));
    // 0x1f5420: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F5420u;
    {
        const bool branch_taken_0x1f5420 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5420u;
            // 0x1f5424: 0xa2220001  sb          $v0, 0x1($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5420) {
            ctx->pc = 0x1F542Cu;
            goto label_1f542c;
        }
    }
    ctx->pc = 0x1F5428u;
label_1f5428:
    // 0x1f5428: 0xa2220001  sb          $v0, 0x1($s1)
    ctx->pc = 0x1f5428u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 2));
label_1f542c:
    // 0x1f542c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f542cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f5430:
    // 0x1f5430: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1f5430u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1f5434: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1f5434u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f5438: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f5438u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f543c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f543cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f5440: 0x3e00008  jr          $ra
    ctx->pc = 0x1F5440u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F5444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5440u;
            // 0x1f5444: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F5344u: goto label_1f5344;
            case 0x1F5378u: goto label_1f5378;
            case 0x1F5384u: goto label_1f5384;
            case 0x1F5394u: goto label_1f5394;
            case 0x1F539Cu: goto label_1f539c;
            case 0x1F53C8u: goto label_1f53c8;
            case 0x1F53CCu: goto label_1f53cc;
            case 0x1F53FCu: goto label_1f53fc;
            case 0x1F5428u: goto label_1f5428;
            case 0x1F542Cu: goto label_1f542c;
            case 0x1F5430u: goto label_1f5430;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F5448u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
