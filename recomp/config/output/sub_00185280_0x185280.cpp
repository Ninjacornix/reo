#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00185280
// Address: 0x185280 - 0x1858c8
void sub_00185280_0x185280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00185280_0x185280");
#endif

    switch (ctx->pc) {
        case 0x1852bcu: goto label_1852bc;
        case 0x185308u: goto label_185308;
        case 0x185320u: goto label_185320;
        case 0x185340u: goto label_185340;
        case 0x185368u: goto label_185368;
        case 0x185380u: goto label_185380;
        case 0x1853a0u: goto label_1853a0;
        case 0x1853dcu: goto label_1853dc;
        case 0x185400u: goto label_185400;
        case 0x185448u: goto label_185448;
        case 0x18546cu: goto label_18546c;
        case 0x185484u: goto label_185484;
        case 0x18549cu: goto label_18549c;
        case 0x1855a4u: goto label_1855a4;
        case 0x185600u: goto label_185600;
        case 0x18562cu: goto label_18562c;
        case 0x185738u: goto label_185738;
        case 0x185854u: goto label_185854;
        case 0x185864u: goto label_185864;
        case 0x185880u: goto label_185880;
        default: break;
    }

    ctx->pc = 0x185280u;

    // 0x185280: 0x27bdfb10  addiu       $sp, $sp, -0x4F0
    ctx->pc = 0x185280u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966032));
    // 0x185284: 0xffb004a0  sd          $s0, 0x4A0($sp)
    ctx->pc = 0x185284u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1184), GPR_U64(ctx, 16));
    // 0x185288: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x185288u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18528c: 0xffb504c8  sd          $s5, 0x4C8($sp)
    ctx->pc = 0x18528cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1224), GPR_U64(ctx, 21));
    // 0x185290: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x185290u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185294: 0xffb704d8  sd          $s7, 0x4D8($sp)
    ctx->pc = 0x185294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1240), GPR_U64(ctx, 23));
    // 0x185298: 0xffb104a8  sd          $s1, 0x4A8($sp)
    ctx->pc = 0x185298u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1192), GPR_U64(ctx, 17));
    // 0x18529c: 0xffb204b0  sd          $s2, 0x4B0($sp)
    ctx->pc = 0x18529cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1200), GPR_U64(ctx, 18));
    // 0x1852a0: 0xffb304b8  sd          $s3, 0x4B8($sp)
    ctx->pc = 0x1852a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1208), GPR_U64(ctx, 19));
    // 0x1852a4: 0xffb404c0  sd          $s4, 0x4C0($sp)
    ctx->pc = 0x1852a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1216), GPR_U64(ctx, 20));
    // 0x1852a8: 0xffb604d0  sd          $s6, 0x4D0($sp)
    ctx->pc = 0x1852a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1232), GPR_U64(ctx, 22));
    // 0x1852ac: 0xffbe04e0  sd          $fp, 0x4E0($sp)
    ctx->pc = 0x1852acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1248), GPR_U64(ctx, 30));
    // 0x1852b0: 0xffbf04e8  sd          $ra, 0x4E8($sp)
    ctx->pc = 0x1852b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1256), GPR_U64(ctx, 31));
    // 0x1852b4: 0xc062210  jal         func_188840
    ctx->pc = 0x1852B4u;
    SET_GPR_U32(ctx, 31, 0x1852BCu);
    ctx->pc = 0x1852B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1852B4u;
            // 0x1852b8: 0x80b82d  daddu       $s7, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188840u;
    if (runtime->hasFunction(0x188840u)) {
        auto targetFn = runtime->lookupFunction(0x188840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1852BCu; }
        if (ctx->pc != 0x1852BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188840_0x188840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1852BCu; }
        if (ctx->pc != 0x1852BCu) { return; }
    }
    ctx->pc = 0x1852BCu;
label_1852bc:
    // 0x1852bc: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1852BCu;
    {
        const bool branch_taken_0x1852bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1852C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1852BCu;
            // 0x1852c0: 0x24030898  addiu       $v1, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1852bc) {
            ctx->pc = 0x1852D0u;
            goto label_1852d0;
        }
    }
    ctx->pc = 0x1852C4u;
    // 0x1852c4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1852c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1852c8: 0x10000173  b           . + 4 + (0x173 << 2)
    ctx->pc = 0x1852C8u;
    {
        const bool branch_taken_0x1852c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1852CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1852C8u;
            // 0x1852cc: 0x34420013  ori         $v0, $v0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1852c8) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x1852D0u;
label_1852d0:
    // 0x1852d0: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1852d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1852d4: 0x2e31818  mult        $v1, $s7, $v1
    ctx->pc = 0x1852d4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 23) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1852d8: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x1852d8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x1852dc: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x1852dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1852e0: 0x8c8463d4  lw          $a0, 0x63D4($a0)
    ctx->pc = 0x1852e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 25556)));
    // 0x1852e4: 0x1080016c  beqz        $a0, . + 4 + (0x16C << 2)
    ctx->pc = 0x1852E4u;
    {
        const bool branch_taken_0x1852e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1852E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1852E4u;
            // 0x1852e8: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1852e4) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x1852ECu;
    // 0x1852ec: 0x27be0400  addiu       $fp, $sp, 0x400
    ctx->pc = 0x1852ecu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), 1024));
    // 0x1852f0: 0x34028417  ori         $v0, $zero, 0x8417
    ctx->pc = 0x1852f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33815);
    // 0x1852f4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1852f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1852f8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1852f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1852fc: 0x3c0302d  daddu       $a2, $fp, $zero
    ctx->pc = 0x1852fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185300: 0xc0609a2  jal         func_182688
    ctx->pc = 0x185300u;
    SET_GPR_U32(ctx, 31, 0x185308u);
    ctx->pc = 0x185304u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185300u;
            // 0x185304: 0x55a80a  movz        $s5, $v0, $s5 (Delay Slot)
        if (GPR_U64(ctx, 21) == 0) SET_GPR_VEC(ctx, 21, GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182688u;
    if (runtime->hasFunction(0x182688u)) {
        auto targetFn = runtime->lookupFunction(0x182688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185308u; }
        if (ctx->pc != 0x185308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182688_0x182688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185308u; }
        if (ctx->pc != 0x185308u) { return; }
    }
    ctx->pc = 0x185308u;
label_185308:
    // 0x185308: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x185308u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18530c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18530cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x185310: 0x12200161  beqz        $s1, . + 4 + (0x161 << 2)
    ctx->pc = 0x185310u;
    {
        const bool branch_taken_0x185310 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x185314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185310u;
            // 0x185314: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x185310) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x185318u;
    // 0x185318: 0xc06089c  jal         func_182270
    ctx->pc = 0x185318u;
    SET_GPR_U32(ctx, 31, 0x185320u);
    ctx->pc = 0x18531Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185318u;
            // 0x18531c: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182270u;
    if (runtime->hasFunction(0x182270u)) {
        auto targetFn = runtime->lookupFunction(0x182270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185320u; }
        if (ctx->pc != 0x185320u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182270_0x182270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185320u; }
        if (ctx->pc != 0x185320u) { return; }
    }
    ctx->pc = 0x185320u;
label_185320:
    // 0x185320: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x185320u;
    {
        const bool branch_taken_0x185320 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x185320) {
            ctx->pc = 0x185338u;
            goto label_185338;
        }
    }
    ctx->pc = 0x185328u;
    // 0x185328: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x185328u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18532c: 0x1000015a  b           . + 4 + (0x15A << 2)
    ctx->pc = 0x18532Cu;
    {
        const bool branch_taken_0x18532c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x185330u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18532Cu;
            // 0x185330: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18532c) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x185334u;
    // 0x185334: 0x0  nop
    ctx->pc = 0x185334u;
    // NOP
label_185338:
    // 0x185338: 0xc060880  jal         func_182200
    ctx->pc = 0x185338u;
    SET_GPR_U32(ctx, 31, 0x185340u);
    ctx->pc = 0x18533Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185338u;
            // 0x18533c: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182200u;
    if (runtime->hasFunction(0x182200u)) {
        auto targetFn = runtime->lookupFunction(0x182200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185340u; }
        if (ctx->pc != 0x185340u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182200_0x182200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185340u; }
        if (ctx->pc != 0x185340u) { return; }
    }
    ctx->pc = 0x185340u;
label_185340:
    // 0x185340: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x185340u;
    {
        const bool branch_taken_0x185340 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x185344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185340u;
            // 0x185344: 0x32b60020  andi        $s6, $s5, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 22, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)32);
        ctx->in_delay_slot = false;
        if (branch_taken_0x185340) {
            ctx->pc = 0x185358u;
            goto label_185358;
        }
    }
    ctx->pc = 0x185348u;
    // 0x185348: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x185348u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18534c: 0x10000152  b           . + 4 + (0x152 << 2)
    ctx->pc = 0x18534Cu;
    {
        const bool branch_taken_0x18534c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x185350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18534Cu;
            // 0x185350: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18534c) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x185354u;
    // 0x185354: 0x0  nop
    ctx->pc = 0x185354u;
    // NOP
label_185358:
    // 0x185358: 0x12c00007  beqz        $s6, . + 4 + (0x7 << 2)
    ctx->pc = 0x185358u;
    {
        const bool branch_taken_0x185358 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        if (branch_taken_0x185358) {
            ctx->pc = 0x185378u;
            goto label_185378;
        }
    }
    ctx->pc = 0x185360u;
    // 0x185360: 0xc060990  jal         func_182640
    ctx->pc = 0x185360u;
    SET_GPR_U32(ctx, 31, 0x185368u);
    ctx->pc = 0x185364u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185360u;
            // 0x185364: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182640u;
    if (runtime->hasFunction(0x182640u)) {
        auto targetFn = runtime->lookupFunction(0x182640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185368u; }
        if (ctx->pc != 0x185368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182640_0x182640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185368u; }
        if (ctx->pc != 0x185368u) { return; }
    }
    ctx->pc = 0x185368u;
label_185368:
    // 0x185368: 0x28430002  slti        $v1, $v0, 0x2
    ctx->pc = 0x185368u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x18536c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18536cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x185370: 0x10600149  beqz        $v1, . + 4 + (0x149 << 2)
    ctx->pc = 0x185370u;
    {
        const bool branch_taken_0x185370 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x185374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185370u;
            // 0x185374: 0x34429004  ori         $v0, $v0, 0x9004 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36868);
        ctx->in_delay_slot = false;
        if (branch_taken_0x185370) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x185378u;
label_185378:
    // 0x185378: 0xc060990  jal         func_182640
    ctx->pc = 0x185378u;
    SET_GPR_U32(ctx, 31, 0x185380u);
    ctx->pc = 0x18537Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185378u;
            // 0x18537c: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182640u;
    if (runtime->hasFunction(0x182640u)) {
        auto targetFn = runtime->lookupFunction(0x182640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185380u; }
        if (ctx->pc != 0x185380u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182640_0x182640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185380u; }
        if (ctx->pc != 0x185380u) { return; }
    }
    ctx->pc = 0x185380u;
label_185380:
    // 0x185380: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x185380u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185384: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x185384u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x185388: 0x3c0282d  daddu       $a1, $fp, $zero
    ctx->pc = 0x185388u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18538c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x18538cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185390: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x185390u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185394: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x185394u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185398: 0xc0610d8  jal         func_184360
    ctx->pc = 0x185398u;
    SET_GPR_U32(ctx, 31, 0x1853A0u);
    ctx->pc = 0x18539Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185398u;
            // 0x18539c: 0x2c500001  sltiu       $s0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 16, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
    ctx->pc = 0x184360u;
    if (runtime->hasFunction(0x184360u)) {
        auto targetFn = runtime->lookupFunction(0x184360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1853A0u; }
        if (ctx->pc != 0x1853A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184360_0x184360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1853A0u; }
        if (ctx->pc != 0x1853A0u) { return; }
    }
    ctx->pc = 0x1853A0u;
label_1853a0:
    // 0x1853a0: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x1853a0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x1853a4: 0x34630002  ori         $v1, $v1, 0x2
    ctx->pc = 0x1853a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2);
    // 0x1853a8: 0x1443013b  bne         $v0, $v1, . + 4 + (0x13B << 2)
    ctx->pc = 0x1853A8u;
    {
        const bool branch_taken_0x1853a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1853ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1853A8u;
            // 0x1853ac: 0xafa20490  sw          $v0, 0x490($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 1168), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1853a8) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x1853B0u;
    // 0x1853b0: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1853B0u;
    {
        const bool branch_taken_0x1853b0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1853B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1853B0u;
            // 0x1853b4: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1853b0) {
            ctx->pc = 0x1853D4u;
            goto label_1853d4;
        }
    }
    ctx->pc = 0x1853B8u;
    // 0x1853b8: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x1853b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1853bc: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1853bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1853c0: 0x711823  subu        $v1, $v1, $s1
    ctx->pc = 0x1853c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1853c4: 0x28630014  slti        $v1, $v1, 0x14
    ctx->pc = 0x1853c4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1853c8: 0x10600133  beqz        $v1, . + 4 + (0x133 << 2)
    ctx->pc = 0x1853C8u;
    {
        const bool branch_taken_0x1853c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1853CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1853C8u;
            // 0x1853cc: 0x34420017  ori         $v0, $v0, 0x17 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)23);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1853c8) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x1853D0u;
    // 0x1853d0: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1853d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
label_1853d4:
    // 0x1853d4: 0xc060bcc  jal         func_182F30
    ctx->pc = 0x1853D4u;
    SET_GPR_U32(ctx, 31, 0x1853DCu);
    ctx->pc = 0x1853D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1853D4u;
            // 0x1853d8: 0x27a50490  addiu       $a1, $sp, 0x490 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 1168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182F30u;
    if (runtime->hasFunction(0x182F30u)) {
        auto targetFn = runtime->lookupFunction(0x182F30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1853DCu; }
        if (ctx->pc != 0x1853DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182F30_0x182f30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1853DCu; }
        if (ctx->pc != 0x1853DCu) { return; }
    }
    ctx->pc = 0x1853DCu;
label_1853dc:
    // 0x1853dc: 0x8fa30490  lw          $v1, 0x490($sp)
    ctx->pc = 0x1853dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1168)));
    // 0x1853e0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1853e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1853e4: 0x1460012c  bnez        $v1, . + 4 + (0x12C << 2)
    ctx->pc = 0x1853E4u;
    {
        const bool branch_taken_0x1853e4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1853E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1853E4u;
            // 0x1853e8: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1853e4) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x1853ECu;
    // 0x1853ec: 0x8fa50010  lw          $a1, 0x10($sp)
    ctx->pc = 0x1853ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1853f0: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1853f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1853f4: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x1853f4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1853f8: 0xc061318  jal         func_184C60
    ctx->pc = 0x1853F8u;
    SET_GPR_U32(ctx, 31, 0x185400u);
    ctx->pc = 0x1853FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1853F8u;
            // 0x1853fc: 0x27a70490  addiu       $a3, $sp, 0x490 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 1168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184C60u;
    if (runtime->hasFunction(0x184C60u)) {
        auto targetFn = runtime->lookupFunction(0x184C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185400u; }
        if (ctx->pc != 0x185400u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184C60_0x184c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185400u; }
        if (ctx->pc != 0x185400u) { return; }
    }
    ctx->pc = 0x185400u;
label_185400:
    // 0x185400: 0x8fa30490  lw          $v1, 0x490($sp)
    ctx->pc = 0x185400u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1168)));
    // 0x185404: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x185404u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185408: 0x14600123  bnez        $v1, . + 4 + (0x123 << 2)
    ctx->pc = 0x185408u;
    {
        const bool branch_taken_0x185408 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x18540Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185408u;
            // 0x18540c: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185408) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x185410u;
    // 0x185410: 0x71102a  slt         $v0, $v1, $s1
    ctx->pc = 0x185410u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x185414: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x185414u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x185418: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x185418u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18541c: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x18541cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x185420: 0x96180a  movz        $v1, $a0, $s6
    ctx->pc = 0x185420u;
    if (GPR_U64(ctx, 22) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
    // 0x185424: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x185424u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x185428: 0x203182a  slt         $v1, $s0, $v1
    ctx->pc = 0x185428u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x18542c: 0x1460011a  bnez        $v1, . + 4 + (0x11A << 2)
    ctx->pc = 0x18542Cu;
    {
        const bool branch_taken_0x18542c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x185430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18542Cu;
            // 0x185430: 0x3442001c  ori         $v0, $v0, 0x1C (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)28);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18542c) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x185434u;
    // 0x185434: 0x12c00011  beqz        $s6, . + 4 + (0x11 << 2)
    ctx->pc = 0x185434u;
    {
        const bool branch_taken_0x185434 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x185438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185434u;
            // 0x185438: 0x27a50480  addiu       $a1, $sp, 0x480 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 1152));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185434) {
            ctx->pc = 0x18547Cu;
            goto label_18547c;
        }
    }
    ctx->pc = 0x18543Cu;
    // 0x18543c: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x18543cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185440: 0xc060b7a  jal         func_182DE8
    ctx->pc = 0x185440u;
    SET_GPR_U32(ctx, 31, 0x185448u);
    ctx->pc = 0x185444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185440u;
            // 0x185444: 0x27a50490  addiu       $a1, $sp, 0x490 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 1168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182DE8u;
    if (runtime->hasFunction(0x182DE8u)) {
        auto targetFn = runtime->lookupFunction(0x182DE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185448u; }
        if (ctx->pc != 0x185448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182DE8_0x182de8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185448u; }
        if (ctx->pc != 0x185448u) { return; }
    }
    ctx->pc = 0x185448u;
label_185448:
    // 0x185448: 0x8fa30490  lw          $v1, 0x490($sp)
    ctx->pc = 0x185448u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1168)));
    // 0x18544c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x18544cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185450: 0x14600111  bnez        $v1, . + 4 + (0x111 << 2)
    ctx->pc = 0x185450u;
    {
        const bool branch_taken_0x185450 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x185454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185450u;
            // 0x185454: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185450) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x185458u;
    // 0x185458: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x185458u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18545c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x18545cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185460: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x185460u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x185464: 0xc060b28  jal         func_182CA0
    ctx->pc = 0x185464u;
    SET_GPR_U32(ctx, 31, 0x18546Cu);
    ctx->pc = 0x185468u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185464u;
            // 0x185468: 0x27a70490  addiu       $a3, $sp, 0x490 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 1168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182CA0u;
    if (runtime->hasFunction(0x182CA0u)) {
        auto targetFn = runtime->lookupFunction(0x182CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18546Cu; }
        if (ctx->pc != 0x18546Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182CA0_0x182ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18546Cu; }
        if (ctx->pc != 0x18546Cu) { return; }
    }
    ctx->pc = 0x18546Cu;
label_18546c:
    // 0x18546c: 0x8fa30490  lw          $v1, 0x490($sp)
    ctx->pc = 0x18546cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1168)));
    // 0x185470: 0x14600109  bnez        $v1, . + 4 + (0x109 << 2)
    ctx->pc = 0x185470u;
    {
        const bool branch_taken_0x185470 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x185474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185470u;
            // 0x185474: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185470) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x185478u;
    // 0x185478: 0x27a50480  addiu       $a1, $sp, 0x480
    ctx->pc = 0x185478u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 1152));
label_18547c:
    // 0x18547c: 0xc061ffe  jal         func_187FF8
    ctx->pc = 0x18547Cu;
    SET_GPR_U32(ctx, 31, 0x185484u);
    ctx->pc = 0x185480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18547Cu;
            // 0x185480: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187FF8u;
    if (runtime->hasFunction(0x187FF8u)) {
        auto targetFn = runtime->lookupFunction(0x187FF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185484u; }
        if (ctx->pc != 0x185484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187FF8_0x187ff8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185484u; }
        if (ctx->pc != 0x185484u) { return; }
    }
    ctx->pc = 0x185484u;
label_185484:
    // 0x185484: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x185484u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185488: 0x27a20200  addiu       $v0, $sp, 0x200
    ctx->pc = 0x185488u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
    // 0x18548c: 0x24060200  addiu       $a2, $zero, 0x200
    ctx->pc = 0x18548cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x185490: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x185490u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185494: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x185494u;
    SET_GPR_U32(ctx, 31, 0x18549Cu);
    ctx->pc = 0x185498u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185494u;
            // 0x185498: 0x2413ffff  addiu       $s3, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18549Cu; }
        if (ctx->pc != 0x18549Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18549Cu; }
        if (ctx->pc != 0x18549Cu) { return; }
    }
    ctx->pc = 0x18549Cu;
label_18549c:
    // 0x18549c: 0x256980b  movn        $s3, $s2, $s6
    ctx->pc = 0x18549cu;
    if (GPR_U64(ctx, 22) != 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 18));
    // 0x1854a0: 0x93a40487  lbu         $a0, 0x487($sp)
    ctx->pc = 0x1854a0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1159)));
    // 0x1854a4: 0x24140002  addiu       $s4, $zero, 0x2
    ctx->pc = 0x1854a4u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1854a8: 0x93ae0486  lbu         $t6, 0x486($sp)
    ctx->pc = 0x1854a8u;
    SET_GPR_U32(ctx, 14, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1158)));
    // 0x1854ac: 0x16a00a  movz        $s4, $zero, $s6
    ctx->pc = 0x1854acu;
    if (GPR_U64(ctx, 22) == 0) SET_GPR_VEC(ctx, 20, GPR_VEC(ctx, 0));
    // 0x1854b0: 0x93ac0485  lbu         $t4, 0x485($sp)
    ctx->pc = 0x1854b0u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1157)));
    // 0x1854b4: 0x42902  srl         $a1, $a0, 4
    ctx->pc = 0x1854b4u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 4));
    // 0x1854b8: 0x93ab0483  lbu         $t3, 0x483($sp)
    ctx->pc = 0x1854b8u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1155)));
    // 0x1854bc: 0xe9102  srl         $s2, $t6, 4
    ctx->pc = 0x1854bcu;
    SET_GPR_S32(ctx, 18, (int32_t)SRL32(GPR_U32(ctx, 14), 4));
    // 0x1854c0: 0x93aa0482  lbu         $t2, 0x482($sp)
    ctx->pc = 0x1854c0u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1154)));
    // 0x1854c4: 0xc8902  srl         $s1, $t4, 4
    ctx->pc = 0x1854c4u;
    SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 12), 4));
    // 0x1854c8: 0x93a90481  lbu         $t1, 0x481($sp)
    ctx->pc = 0x1854c8u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1153)));
    // 0x1854cc: 0xb7902  srl         $t7, $t3, 4
    ctx->pc = 0x1854ccu;
    SET_GPR_S32(ctx, 15, (int32_t)SRL32(GPR_U32(ctx, 11), 4));
    // 0x1854d0: 0xa8102  srl         $s0, $t2, 4
    ctx->pc = 0x1854d0u;
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 10), 4));
    // 0x1854d4: 0x314a000f  andi        $t2, $t2, 0xF
    ctx->pc = 0x1854d4u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)15);
    // 0x1854d8: 0x96902  srl         $t5, $t1, 4
    ctx->pc = 0x1854d8u;
    SET_GPR_S32(ctx, 13, (int32_t)SRL32(GPR_U32(ctx, 9), 4));
    // 0x1854dc: 0x3129000f  andi        $t1, $t1, 0xF
    ctx->pc = 0x1854dcu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)15);
    // 0x1854e0: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x1854e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1854e4: 0xf3080  sll         $a2, $t7, 2
    ctx->pc = 0x1854e4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 15), 2));
    // 0x1854e8: 0xd4080  sll         $t0, $t5, 2
    ctx->pc = 0x1854e8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 13), 2));
    // 0x1854ec: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1854ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1854f0: 0x121880  sll         $v1, $s2, 2
    ctx->pc = 0x1854f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x1854f4: 0x103880  sll         $a3, $s0, 2
    ctx->pc = 0x1854f4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1854f8: 0x112880  sll         $a1, $s1, 2
    ctx->pc = 0x1854f8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1854fc: 0xcf3021  addu        $a2, $a2, $t7
    ctx->pc = 0x1854fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 15)));
    // 0x185500: 0x10d4021  addu        $t0, $t0, $t5
    ctx->pc = 0x185500u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 13)));
    // 0x185504: 0x3084000f  andi        $a0, $a0, 0xF
    ctx->pc = 0x185504u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x185508: 0x721821  addu        $v1, $v1, $s2
    ctx->pc = 0x185508u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x18550c: 0xb12821  addu        $a1, $a1, $s1
    ctx->pc = 0x18550cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 17)));
    // 0x185510: 0xf03821  addu        $a3, $a3, $s0
    ctx->pc = 0x185510u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 16)));
    // 0x185514: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x185514u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x185518: 0x31ce000f  andi        $t6, $t6, 0xF
    ctx->pc = 0x185518u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) & (uint64_t)(uint16_t)15);
    // 0x18551c: 0x318c000f  andi        $t4, $t4, 0xF
    ctx->pc = 0x18551cu;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)15);
    // 0x185520: 0x316b000f  andi        $t3, $t3, 0xF
    ctx->pc = 0x185520u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)15);
    // 0x185524: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x185524u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x185528: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x185528u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x18552c: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x18552cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x185530: 0x63040  sll         $a2, $a2, 1
    ctx->pc = 0x185530u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x185534: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x185534u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x185538: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x185538u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x18553c: 0x6e1821  addu        $v1, $v1, $t6
    ctx->pc = 0x18553cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 14)));
    // 0x185540: 0x1094021  addu        $t0, $t0, $t1
    ctx->pc = 0x185540u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
    // 0x185544: 0xcb3021  addu        $a2, $a2, $t3
    ctx->pc = 0x185544u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 11)));
    // 0x185548: 0xea3821  addu        $a3, $a3, $t2
    ctx->pc = 0x185548u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x18554c: 0xac2821  addu        $a1, $a1, $t4
    ctx->pc = 0x18554cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x185550: 0x244207d0  addiu       $v0, $v0, 0x7D0
    ctx->pc = 0x185550u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2000));
    // 0x185554: 0xa3a3020d  sb          $v1, 0x20D($sp)
    ctx->pc = 0x185554u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 525), (uint8_t)GPR_U32(ctx, 3));
    // 0x185558: 0xa3a5020c  sb          $a1, 0x20C($sp)
    ctx->pc = 0x185558u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 524), (uint8_t)GPR_U32(ctx, 5));
    // 0x18555c: 0x2405002f  addiu       $a1, $zero, 0x2F
    ctx->pc = 0x18555cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x185560: 0xa3a6020b  sb          $a2, 0x20B($sp)
    ctx->pc = 0x185560u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 523), (uint8_t)GPR_U32(ctx, 6));
    // 0x185564: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x185564u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185568: 0xa3a7020a  sb          $a3, 0x20A($sp)
    ctx->pc = 0x185568u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 522), (uint8_t)GPR_U32(ctx, 7));
    // 0x18556c: 0xa3a80209  sb          $t0, 0x209($sp)
    ctx->pc = 0x18556cu;
    WRITE8(ADD32(GPR_U32(ctx, 29), 521), (uint8_t)GPR_U32(ctx, 8));
    // 0x185570: 0xa7b50200  sh          $s5, 0x200($sp)
    ctx->pc = 0x185570u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 512), (uint16_t)GPR_U32(ctx, 21));
    // 0x185574: 0xa7a2020e  sh          $v0, 0x20E($sp)
    ctx->pc = 0x185574u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 526), (uint16_t)GPR_U32(ctx, 2));
    // 0x185578: 0xa7a00202  sh          $zero, 0x202($sp)
    ctx->pc = 0x185578u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 514), (uint16_t)GPR_U32(ctx, 0));
    // 0x18557c: 0xa3a00208  sb          $zero, 0x208($sp)
    ctx->pc = 0x18557cu;
    WRITE8(ADD32(GPR_U32(ctx, 29), 520), (uint8_t)GPR_U32(ctx, 0));
    // 0x185580: 0xafb30210  sw          $s3, 0x210($sp)
    ctx->pc = 0x185580u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 19));
    // 0x185584: 0x6ba3020f  ldl         $v1, 0x20F($sp)
    ctx->pc = 0x185584u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 527); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x185588: 0x6fa30208  ldr         $v1, 0x208($sp)
    ctx->pc = 0x185588u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 520); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x18558c: 0xb3a3021f  sdl         $v1, 0x21F($sp)
    ctx->pc = 0x18558cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 543); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x185590: 0xb7a30218  sdr         $v1, 0x218($sp)
    ctx->pc = 0x185590u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 536); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x185594: 0xafb40204  sw          $s4, 0x204($sp)
    ctx->pc = 0x185594u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 516), GPR_U32(ctx, 20));
    // 0x185598: 0xafa00214  sw          $zero, 0x214($sp)
    ctx->pc = 0x185598u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 532), GPR_U32(ctx, 0));
    // 0x18559c: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x18559Cu;
    SET_GPR_U32(ctx, 31, 0x1855A4u);
    ctx->pc = 0x1855A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18559Cu;
            // 0x1855a0: 0xafa00220  sw          $zero, 0x220($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 544), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1855A4u; }
        if (ctx->pc != 0x1855A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1855A4u; }
        if (ctx->pc != 0x1855A4u) { return; }
    }
    ctx->pc = 0x1855A4u;
label_1855a4:
    // 0x1855a4: 0x68490008  ldl         $t1, 0x8($v0)
    ctx->pc = 0x1855a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem << shift)); }
    // 0x1855a8: 0x6c490001  ldr         $t1, 0x1($v0)
    ctx->pc = 0x1855a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 1); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem >> shift)); }
    // 0x1855ac: 0x68430010  ldl         $v1, 0x10($v0)
    ctx->pc = 0x1855acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1855b0: 0x6c430009  ldr         $v1, 0x9($v0)
    ctx->pc = 0x1855b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 9); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1855b4: 0x68440018  ldl         $a0, 0x18($v0)
    ctx->pc = 0x1855b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1855b8: 0x6c440011  ldr         $a0, 0x11($v0)
    ctx->pc = 0x1855b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 17); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1855bc: 0x68450020  ldl         $a1, 0x20($v0)
    ctx->pc = 0x1855bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x1855c0: 0x6c450019  ldr         $a1, 0x19($v0)
    ctx->pc = 0x1855c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 25); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x1855c4: 0xb3a90247  sdl         $t1, 0x247($sp)
    ctx->pc = 0x1855c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 583); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1855c8: 0xb7a90240  sdr         $t1, 0x240($sp)
    ctx->pc = 0x1855c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 576); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1855cc: 0xb3a3024f  sdl         $v1, 0x24F($sp)
    ctx->pc = 0x1855ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 591); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1855d0: 0xb7a30248  sdr         $v1, 0x248($sp)
    ctx->pc = 0x1855d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 584); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1855d4: 0xb3a40257  sdl         $a0, 0x257($sp)
    ctx->pc = 0x1855d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 599); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1855d8: 0xb7a40250  sdr         $a0, 0x250($sp)
    ctx->pc = 0x1855d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 592); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1855dc: 0xb3a5025f  sdl         $a1, 0x25F($sp)
    ctx->pc = 0x1855dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 607); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1855e0: 0xb7a50258  sdr         $a1, 0x258($sp)
    ctx->pc = 0x1855e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 600); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1855e4: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1855e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1855e8: 0x27a60200  addiu       $a2, $sp, 0x200
    ctx->pc = 0x1855e8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
    // 0x1855ec: 0x27a80490  addiu       $t0, $sp, 0x490
    ctx->pc = 0x1855ecu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 1168));
    // 0x1855f0: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x1855f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1855f4: 0x8fa60010  lw          $a2, 0x10($sp)
    ctx->pc = 0x1855f4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1855f8: 0xc061362  jal         func_184D88
    ctx->pc = 0x1855F8u;
    SET_GPR_U32(ctx, 31, 0x185600u);
    ctx->pc = 0x1855FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1855F8u;
            // 0x1855fc: 0x8fa70004  lw          $a3, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184D88u;
    if (runtime->hasFunction(0x184D88u)) {
        auto targetFn = runtime->lookupFunction(0x184D88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185600u; }
        if (ctx->pc != 0x185600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184D88_0x184d88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185600u; }
        if (ctx->pc != 0x185600u) { return; }
    }
    ctx->pc = 0x185600u;
label_185600:
    // 0x185600: 0x40f02d  daddu       $fp, $v0, $zero
    ctx->pc = 0x185600u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185604: 0x7c000a4  bltz        $fp, . + 4 + (0xA4 << 2)
    ctx->pc = 0x185604u;
    {
        const bool branch_taken_0x185604 = (GPR_S64(ctx, 30) < 0);
        ctx->pc = 0x185608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185604u;
            // 0x185608: 0x8fa20490  lw          $v0, 0x490($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1168)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x185604) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x18560Cu;
    // 0x18560c: 0x12c00093  beqz        $s6, . + 4 + (0x93 << 2)
    ctx->pc = 0x18560Cu;
    {
        const bool branch_taken_0x18560c = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x185610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18560Cu;
            // 0x185610: 0x3c100028  lui         $s0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)40 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18560c) {
            ctx->pc = 0x18585Cu;
            goto label_18585c;
        }
    }
    ctx->pc = 0x185614u;
    // 0x185614: 0x24148427  addiu       $s4, $zero, -0x7BD9
    ctx->pc = 0x185614u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 4294935591));
    // 0x185618: 0x26106c80  addiu       $s0, $s0, 0x6C80
    ctx->pc = 0x185618u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 27776));
    // 0x18561c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x18561cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185620: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x185620u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185624: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x185624u;
    SET_GPR_U32(ctx, 31, 0x18562Cu);
    ctx->pc = 0x185628u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185624u;
            // 0x185628: 0x24060200  addiu       $a2, $zero, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18562Cu; }
        if (ctx->pc != 0x18562Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18562Cu; }
        if (ctx->pc != 0x18562Cu) { return; }
    }
    ctx->pc = 0x18562Cu;
label_18562c:
    // 0x18562c: 0xa6140000  sh          $s4, 0x0($s0)
    ctx->pc = 0x18562cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 20));
    // 0x185630: 0x3c180024  lui         $t8, 0x24
    ctx->pc = 0x185630u;
    SET_GPR_S32(ctx, 24, (int32_t)((uint32_t)36 << 16));
    // 0x185634: 0x200b02d  daddu       $s6, $s0, $zero
    ctx->pc = 0x185634u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185638: 0x93a50487  lbu         $a1, 0x487($sp)
    ctx->pc = 0x185638u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1159)));
    // 0x18563c: 0x93ae0486  lbu         $t6, 0x486($sp)
    ctx->pc = 0x18563cu;
    SET_GPR_U32(ctx, 14, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1158)));
    // 0x185640: 0x93ac0485  lbu         $t4, 0x485($sp)
    ctx->pc = 0x185640u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1157)));
    // 0x185644: 0x52102  srl         $a0, $a1, 4
    ctx->pc = 0x185644u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 5), 4));
    // 0x185648: 0x93ab0483  lbu         $t3, 0x483($sp)
    ctx->pc = 0x185648u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1155)));
    // 0x18564c: 0xe9902  srl         $s3, $t6, 4
    ctx->pc = 0x18564cu;
    SET_GPR_S32(ctx, 19, (int32_t)SRL32(GPR_U32(ctx, 14), 4));
    // 0x185650: 0x93aa0482  lbu         $t2, 0x482($sp)
    ctx->pc = 0x185650u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1154)));
    // 0x185654: 0xc9102  srl         $s2, $t4, 4
    ctx->pc = 0x185654u;
    SET_GPR_S32(ctx, 18, (int32_t)SRL32(GPR_U32(ctx, 12), 4));
    // 0x185658: 0x93a60481  lbu         $a2, 0x481($sp)
    ctx->pc = 0x185658u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1153)));
    // 0x18565c: 0xb7902  srl         $t7, $t3, 4
    ctx->pc = 0x18565cu;
    SET_GPR_S32(ctx, 15, (int32_t)SRL32(GPR_U32(ctx, 11), 4));
    // 0x185660: 0xa8902  srl         $s1, $t2, 4
    ctx->pc = 0x185660u;
    SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 10), 4));
    // 0x185664: 0x314a000f  andi        $t2, $t2, 0xF
    ctx->pc = 0x185664u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)15);
    // 0x185668: 0x66902  srl         $t5, $a2, 4
    ctx->pc = 0x185668u;
    SET_GPR_S32(ctx, 13, (int32_t)SRL32(GPR_U32(ctx, 6), 4));
    // 0x18566c: 0x30c6000f  andi        $a2, $a2, 0xF
    ctx->pc = 0x18566cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
    // 0x185670: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x185670u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x185674: 0xf3880  sll         $a3, $t7, 2
    ctx->pc = 0x185674u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 15), 2));
    // 0x185678: 0xd4880  sll         $t1, $t5, 2
    ctx->pc = 0x185678u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 13), 2));
    // 0x18567c: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x18567cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x185680: 0x131880  sll         $v1, $s3, 2
    ctx->pc = 0x185680u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    // 0x185684: 0x114080  sll         $t0, $s1, 2
    ctx->pc = 0x185684u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x185688: 0x122080  sll         $a0, $s2, 2
    ctx->pc = 0x185688u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x18568c: 0xef3821  addu        $a3, $a3, $t7
    ctx->pc = 0x18568cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 15)));
    // 0x185690: 0x12d4821  addu        $t1, $t1, $t5
    ctx->pc = 0x185690u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 13)));
    // 0x185694: 0x731821  addu        $v1, $v1, $s3
    ctx->pc = 0x185694u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
    // 0x185698: 0x922021  addu        $a0, $a0, $s2
    ctx->pc = 0x185698u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x18569c: 0x1114021  addu        $t0, $t0, $s1
    ctx->pc = 0x18569cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 17)));
    // 0x1856a0: 0x30a5000f  andi        $a1, $a1, 0xF
    ctx->pc = 0x1856a0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)15);
    // 0x1856a4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1856a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1856a8: 0x31ce000f  andi        $t6, $t6, 0xF
    ctx->pc = 0x1856a8u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) & (uint64_t)(uint16_t)15);
    // 0x1856ac: 0x318c000f  andi        $t4, $t4, 0xF
    ctx->pc = 0x1856acu;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)15);
    // 0x1856b0: 0x316b000f  andi        $t3, $t3, 0xF
    ctx->pc = 0x1856b0u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)15);
    // 0x1856b4: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1856b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1856b8: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1856b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1856bc: 0x42040  sll         $a0, $a0, 1
    ctx->pc = 0x1856bcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1856c0: 0x73840  sll         $a3, $a3, 1
    ctx->pc = 0x1856c0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1856c4: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x1856c4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1856c8: 0x94840  sll         $t1, $t1, 1
    ctx->pc = 0x1856c8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x1856cc: 0x6e1821  addu        $v1, $v1, $t6
    ctx->pc = 0x1856ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 14)));
    // 0x1856d0: 0xeb3821  addu        $a3, $a3, $t3
    ctx->pc = 0x1856d0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x1856d4: 0x10a4021  addu        $t0, $t0, $t2
    ctx->pc = 0x1856d4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 10)));
    // 0x1856d8: 0x1264821  addu        $t1, $t1, $a2
    ctx->pc = 0x1856d8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
    // 0x1856dc: 0x24060200  addiu       $a2, $zero, 0x200
    ctx->pc = 0x1856dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x1856e0: 0x8c2021  addu        $a0, $a0, $t4
    ctx->pc = 0x1856e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 12)));
    // 0x1856e4: 0x244207d0  addiu       $v0, $v0, 0x7D0
    ctx->pc = 0x1856e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2000));
    // 0x1856e8: 0xa203000d  sb          $v1, 0xD($s0)
    ctx->pc = 0x1856e8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 13), (uint8_t)GPR_U32(ctx, 3));
    // 0x1856ec: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1856ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1856f0: 0xa602000e  sh          $v0, 0xE($s0)
    ctx->pc = 0x1856f0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x1856f4: 0xa204000c  sb          $a0, 0xC($s0)
    ctx->pc = 0x1856f4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 12), (uint8_t)GPR_U32(ctx, 4));
    // 0x1856f8: 0xa207000b  sb          $a3, 0xB($s0)
    ctx->pc = 0x1856f8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 11), (uint8_t)GPR_U32(ctx, 7));
    // 0x1856fc: 0xa208000a  sb          $t0, 0xA($s0)
    ctx->pc = 0x1856fcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 8));
    // 0x185700: 0xa2090009  sb          $t1, 0x9($s0)
    ctx->pc = 0x185700u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 9));
    // 0x185704: 0xa6000002  sh          $zero, 0x2($s0)
    ctx->pc = 0x185704u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 0));
    // 0x185708: 0x970217b0  lhu         $v0, 0x17B0($t8)
    ctx->pc = 0x185708u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 24), 6064)));
    // 0x18570c: 0x6a07000f  ldl         $a3, 0xF($s0)
    ctx->pc = 0x18570cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x185710: 0x6e070008  ldr         $a3, 0x8($s0)
    ctx->pc = 0x185710u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x185714: 0xb207001f  sdl         $a3, 0x1F($s0)
    ctx->pc = 0x185714u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x185718: 0xb6070018  sdr         $a3, 0x18($s0)
    ctx->pc = 0x185718u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18571c: 0xae1e0014  sw          $fp, 0x14($s0)
    ctx->pc = 0x18571cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 30));
    // 0x185720: 0xa6020040  sh          $v0, 0x40($s0)
    ctx->pc = 0x185720u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 64), (uint16_t)GPR_U32(ctx, 2));
    // 0x185724: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x185724u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x185728: 0xae000010  sw          $zero, 0x10($s0)
    ctx->pc = 0x185728u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x18572c: 0x26100200  addiu       $s0, $s0, 0x200
    ctx->pc = 0x18572cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 512));
    // 0x185730: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x185730u;
    SET_GPR_U32(ctx, 31, 0x185738u);
    ctx->pc = 0x185734u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185730u;
            // 0x185734: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185738u; }
        if (ctx->pc != 0x185738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185738u; }
        if (ctx->pc != 0x185738u) { return; }
    }
    ctx->pc = 0x185738u;
label_185738:
    // 0x185738: 0xa6140000  sh          $s4, 0x0($s0)
    ctx->pc = 0x185738u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 20));
    // 0x18573c: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x18573cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x185740: 0x3c160024  lui         $s6, 0x24
    ctx->pc = 0x185740u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)36 << 16));
    // 0x185744: 0x93a40487  lbu         $a0, 0x487($sp)
    ctx->pc = 0x185744u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1159)));
    // 0x185748: 0x93af0486  lbu         $t7, 0x486($sp)
    ctx->pc = 0x185748u;
    SET_GPR_U32(ctx, 15, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1158)));
    // 0x18574c: 0x93ad0485  lbu         $t5, 0x485($sp)
    ctx->pc = 0x18574cu;
    SET_GPR_U32(ctx, 13, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1157)));
    // 0x185750: 0x43102  srl         $a2, $a0, 4
    ctx->pc = 0x185750u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 4), 4));
    // 0x185754: 0x93ac0483  lbu         $t4, 0x483($sp)
    ctx->pc = 0x185754u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1155)));
    // 0x185758: 0xfa102  srl         $s4, $t7, 4
    ctx->pc = 0x185758u;
    SET_GPR_S32(ctx, 20, (int32_t)SRL32(GPR_U32(ctx, 15), 4));
    // 0x18575c: 0x93ab0482  lbu         $t3, 0x482($sp)
    ctx->pc = 0x18575cu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1154)));
    // 0x185760: 0xd9902  srl         $s3, $t5, 4
    ctx->pc = 0x185760u;
    SET_GPR_S32(ctx, 19, (int32_t)SRL32(GPR_U32(ctx, 13), 4));
    // 0x185764: 0x93a70481  lbu         $a3, 0x481($sp)
    ctx->pc = 0x185764u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 1153)));
    // 0x185768: 0xc8902  srl         $s1, $t4, 4
    ctx->pc = 0x185768u;
    SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 12), 4));
    // 0x18576c: 0xb9102  srl         $s2, $t3, 4
    ctx->pc = 0x18576cu;
    SET_GPR_S32(ctx, 18, (int32_t)SRL32(GPR_U32(ctx, 11), 4));
    // 0x185770: 0x316b000f  andi        $t3, $t3, 0xF
    ctx->pc = 0x185770u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)15);
    // 0x185774: 0x77102  srl         $t6, $a3, 4
    ctx->pc = 0x185774u;
    SET_GPR_S32(ctx, 14, (int32_t)SRL32(GPR_U32(ctx, 7), 4));
    // 0x185778: 0x30e7000f  andi        $a3, $a3, 0xF
    ctx->pc = 0x185778u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)15);
    // 0x18577c: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x18577cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x185780: 0x141880  sll         $v1, $s4, 2
    ctx->pc = 0x185780u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 2));
    // 0x185784: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x185784u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x185788: 0x133080  sll         $a2, $s3, 2
    ctx->pc = 0x185788u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    // 0x18578c: 0x114080  sll         $t0, $s1, 2
    ctx->pc = 0x18578cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x185790: 0x124880  sll         $t1, $s2, 2
    ctx->pc = 0x185790u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x185794: 0xe5080  sll         $t2, $t6, 2
    ctx->pc = 0x185794u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 14), 2));
    // 0x185798: 0x3084000f  andi        $a0, $a0, 0xF
    ctx->pc = 0x185798u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x18579c: 0x741821  addu        $v1, $v1, $s4
    ctx->pc = 0x18579cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
    // 0x1857a0: 0xd33021  addu        $a2, $a2, $s3
    ctx->pc = 0x1857a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x1857a4: 0x1114021  addu        $t0, $t0, $s1
    ctx->pc = 0x1857a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 17)));
    // 0x1857a8: 0x1324821  addu        $t1, $t1, $s2
    ctx->pc = 0x1857a8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 18)));
    // 0x1857ac: 0x14e5021  addu        $t2, $t2, $t6
    ctx->pc = 0x1857acu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 14)));
    // 0x1857b0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1857b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1857b4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1857b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1857b8: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x1857b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1857bc: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1857bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1857c0: 0x31ef000f  andi        $t7, $t7, 0xF
    ctx->pc = 0x1857c0u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) & (uint64_t)(uint16_t)15);
    // 0x1857c4: 0x63040  sll         $a2, $a2, 1
    ctx->pc = 0x1857c4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x1857c8: 0x31ad000f  andi        $t5, $t5, 0xF
    ctx->pc = 0x1857c8u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) & (uint64_t)(uint16_t)15);
    // 0x1857cc: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x1857ccu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1857d0: 0x318c000f  andi        $t4, $t4, 0xF
    ctx->pc = 0x1857d0u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)15);
    // 0x1857d4: 0x94840  sll         $t1, $t1, 1
    ctx->pc = 0x1857d4u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x1857d8: 0xa5040  sll         $t2, $t2, 1
    ctx->pc = 0x1857d8u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
    // 0x1857dc: 0x6f1821  addu        $v1, $v1, $t7
    ctx->pc = 0x1857dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 15)));
    // 0x1857e0: 0x10c4021  addu        $t0, $t0, $t4
    ctx->pc = 0x1857e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 12)));
    // 0x1857e4: 0x12b4821  addu        $t1, $t1, $t3
    ctx->pc = 0x1857e4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 11)));
    // 0x1857e8: 0x244207d0  addiu       $v0, $v0, 0x7D0
    ctx->pc = 0x1857e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2000));
    // 0x1857ec: 0xcd3021  addu        $a2, $a2, $t5
    ctx->pc = 0x1857ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 13)));
    // 0x1857f0: 0x1475021  addu        $t2, $t2, $a3
    ctx->pc = 0x1857f0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 7)));
    // 0x1857f4: 0xa203000d  sb          $v1, 0xD($s0)
    ctx->pc = 0x1857f4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 13), (uint8_t)GPR_U32(ctx, 3));
    // 0x1857f8: 0xa206000c  sb          $a2, 0xC($s0)
    ctx->pc = 0x1857f8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 12), (uint8_t)GPR_U32(ctx, 6));
    // 0x1857fc: 0xa208000b  sb          $t0, 0xB($s0)
    ctx->pc = 0x1857fcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 11), (uint8_t)GPR_U32(ctx, 8));
    // 0x185800: 0xa209000a  sb          $t1, 0xA($s0)
    ctx->pc = 0x185800u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10), (uint8_t)GPR_U32(ctx, 9));
    // 0x185804: 0xa20a0009  sb          $t2, 0x9($s0)
    ctx->pc = 0x185804u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 9), (uint8_t)GPR_U32(ctx, 10));
    // 0x185808: 0xa2000008  sb          $zero, 0x8($s0)
    ctx->pc = 0x185808u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 8), (uint8_t)GPR_U32(ctx, 0));
    // 0x18580c: 0xa602000e  sh          $v0, 0xE($s0)
    ctx->pc = 0x18580cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x185810: 0xa6000002  sh          $zero, 0x2($s0)
    ctx->pc = 0x185810u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 0));
    // 0x185814: 0x8fa60210  lw          $a2, 0x210($sp)
    ctx->pc = 0x185814u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x185818: 0x6a08000f  ldl         $t0, 0xF($s0)
    ctx->pc = 0x185818u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x18581c: 0x6e080008  ldr         $t0, 0x8($s0)
    ctx->pc = 0x18581cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x185820: 0xb208001f  sdl         $t0, 0x1F($s0)
    ctx->pc = 0x185820u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x185824: 0xb6080018  sdr         $t0, 0x18($s0)
    ctx->pc = 0x185824u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x185828: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x185828u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x18582c: 0xae000010  sw          $zero, 0x10($s0)
    ctx->pc = 0x18582cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x185830: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x185830u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x185834: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x185834u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x185838: 0x26c317b8  addiu       $v1, $s6, 0x17B8
    ctx->pc = 0x185838u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 22), 6072));
    // 0x18583c: 0x84680000  lh          $t0, 0x0($v1)
    ctx->pc = 0x18583cu;
    SET_GPR_S32(ctx, 8, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x185840: 0x80690002  lb          $t1, 0x2($v1)
    ctx->pc = 0x185840u;
    SET_GPR_S32(ctx, 9, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 2)));
    // 0x185844: 0xa6080040  sh          $t0, 0x40($s0)
    ctx->pc = 0x185844u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 64), (uint16_t)GPR_U32(ctx, 8));
    // 0x185848: 0xa2090042  sb          $t1, 0x42($s0)
    ctx->pc = 0x185848u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 66), (uint8_t)GPR_U32(ctx, 9));
    // 0x18584c: 0xc061d24  jal         func_187490
    ctx->pc = 0x18584Cu;
    SET_GPR_U32(ctx, 31, 0x185854u);
    ctx->pc = 0x185850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18584Cu;
            // 0x185850: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187490u;
    if (runtime->hasFunction(0x187490u)) {
        auto targetFn = runtime->lookupFunction(0x187490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185854u; }
        if (ctx->pc != 0x185854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187490_0x187490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185854u; }
        if (ctx->pc != 0x185854u) { return; }
    }
    ctx->pc = 0x185854u;
label_185854:
    // 0x185854: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x185854u;
    {
        const bool branch_taken_0x185854 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x185854) {
            ctx->pc = 0x18586Cu;
            goto label_18586c;
        }
    }
    ctx->pc = 0x18585Cu;
label_18585c:
    // 0x18585c: 0xc060a84  jal         func_182A10
    ctx->pc = 0x18585Cu;
    SET_GPR_U32(ctx, 31, 0x185864u);
    ctx->pc = 0x185860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18585Cu;
            // 0x185860: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182A10u;
    if (runtime->hasFunction(0x182A10u)) {
        auto targetFn = runtime->lookupFunction(0x182A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185864u; }
        if (ctx->pc != 0x185864u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182A10_0x182a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185864u; }
        if (ctx->pc != 0x185864u) { return; }
    }
    ctx->pc = 0x185864u;
label_185864:
    // 0x185864: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x185864u;
    {
        const bool branch_taken_0x185864 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x185864) {
            ctx->pc = 0x185878u;
            goto label_185878;
        }
    }
    ctx->pc = 0x18586Cu;
label_18586c:
    // 0x18586c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18586cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x185870: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x185870u;
    {
        const bool branch_taken_0x185870 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x185874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x185870u;
            // 0x185874: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x185870) {
            ctx->pc = 0x185898u;
            goto label_185898;
        }
    }
    ctx->pc = 0x185878u;
label_185878:
    // 0x185878: 0xc061bbc  jal         func_186EF0
    ctx->pc = 0x185878u;
    SET_GPR_U32(ctx, 31, 0x185880u);
    ctx->pc = 0x18587Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x185878u;
            // 0x18587c: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186EF0u;
    if (runtime->hasFunction(0x186EF0u)) {
        auto targetFn = runtime->lookupFunction(0x186EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185880u; }
        if (ctx->pc != 0x185880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186EF0_0x186ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x185880u; }
        if (ctx->pc != 0x185880u) { return; }
    }
    ctx->pc = 0x185880u;
label_185880:
    // 0x185880: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x185880u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x185884: 0x8fa40490  lw          $a0, 0x490($sp)
    ctx->pc = 0x185884u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1168)));
    // 0x185888: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x185888u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x18588c: 0x3463006f  ori         $v1, $v1, 0x6F
    ctx->pc = 0x18588cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)111);
    // 0x185890: 0x82180b  movn        $v1, $a0, $v0
    ctx->pc = 0x185890u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
    // 0x185894: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x185894u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_185898:
    // 0x185898: 0xdfb004a0  ld          $s0, 0x4A0($sp)
    ctx->pc = 0x185898u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 1184)));
    // 0x18589c: 0xdfb104a8  ld          $s1, 0x4A8($sp)
    ctx->pc = 0x18589cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 1192)));
    // 0x1858a0: 0xdfb204b0  ld          $s2, 0x4B0($sp)
    ctx->pc = 0x1858a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 1200)));
    // 0x1858a4: 0xdfb304b8  ld          $s3, 0x4B8($sp)
    ctx->pc = 0x1858a4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 1208)));
    // 0x1858a8: 0xdfb404c0  ld          $s4, 0x4C0($sp)
    ctx->pc = 0x1858a8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 1216)));
    // 0x1858ac: 0xdfb504c8  ld          $s5, 0x4C8($sp)
    ctx->pc = 0x1858acu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 1224)));
    // 0x1858b0: 0xdfb604d0  ld          $s6, 0x4D0($sp)
    ctx->pc = 0x1858b0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 1232)));
    // 0x1858b4: 0xdfb704d8  ld          $s7, 0x4D8($sp)
    ctx->pc = 0x1858b4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 1240)));
    // 0x1858b8: 0xdfbe04e0  ld          $fp, 0x4E0($sp)
    ctx->pc = 0x1858b8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 1248)));
    // 0x1858bc: 0xdfbf04e8  ld          $ra, 0x4E8($sp)
    ctx->pc = 0x1858bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 1256)));
    // 0x1858c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1858C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1858C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1858C0u;
            // 0x1858c4: 0x27bd04f0  addiu       $sp, $sp, 0x4F0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 1264));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1852BCu: goto label_1852bc;
            case 0x1852D0u: goto label_1852d0;
            case 0x185308u: goto label_185308;
            case 0x185320u: goto label_185320;
            case 0x185338u: goto label_185338;
            case 0x185340u: goto label_185340;
            case 0x185358u: goto label_185358;
            case 0x185368u: goto label_185368;
            case 0x185378u: goto label_185378;
            case 0x185380u: goto label_185380;
            case 0x1853A0u: goto label_1853a0;
            case 0x1853D4u: goto label_1853d4;
            case 0x1853DCu: goto label_1853dc;
            case 0x185400u: goto label_185400;
            case 0x185448u: goto label_185448;
            case 0x18546Cu: goto label_18546c;
            case 0x18547Cu: goto label_18547c;
            case 0x185484u: goto label_185484;
            case 0x18549Cu: goto label_18549c;
            case 0x1855A4u: goto label_1855a4;
            case 0x185600u: goto label_185600;
            case 0x18562Cu: goto label_18562c;
            case 0x185738u: goto label_185738;
            case 0x185854u: goto label_185854;
            case 0x18585Cu: goto label_18585c;
            case 0x185864u: goto label_185864;
            case 0x18586Cu: goto label_18586c;
            case 0x185878u: goto label_185878;
            case 0x185880u: goto label_185880;
            case 0x185898u: goto label_185898;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1858C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
