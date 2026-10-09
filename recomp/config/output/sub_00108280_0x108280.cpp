#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108280
// Address: 0x108280 - 0x108490
void sub_00108280_0x108280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108280_0x108280");
#endif

    switch (ctx->pc) {
        case 0x1082e4u: goto label_1082e4;
        case 0x108308u: goto label_108308;
        case 0x108348u: goto label_108348;
        case 0x108360u: goto label_108360;
        case 0x1083d8u: goto label_1083d8;
        case 0x108440u: goto label_108440;
        default: break;
    }

    ctx->pc = 0x108280u;

    // 0x108280: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x108280u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x108284: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x108284u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x108288: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x108288u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10828c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x10828cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x108290: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x108290u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108294: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x108294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x108298: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x108298u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x10829c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x10829cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1082a0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1082a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1082a4: 0x8e130010  lw          $s3, 0x10($s0)
    ctx->pc = 0x1082a4u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1082a8: 0x8e510010  lw          $s1, 0x10($s2)
    ctx->pc = 0x1082a8u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1082ac: 0x271102a  slt         $v0, $s3, $s1
    ctx->pc = 0x1082acu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1082b0: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1082B0u;
    {
        const bool branch_taken_0x1082b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1082b0) {
            ctx->pc = 0x1082B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1082B0u;
            // 0x1082b4: 0x8e050008  lw          $a1, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1082D0u;
            goto label_1082d0;
        }
    }
    ctx->pc = 0x1082B8u;
    // 0x1082b8: 0x200c02d  daddu       $t8, $s0, $zero
    ctx->pc = 0x1082b8u;
    SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1082bc: 0x240802d  daddu       $s0, $s2, $zero
    ctx->pc = 0x1082bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1082c0: 0x300902d  daddu       $s2, $t8, $zero
    ctx->pc = 0x1082c0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 24) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1082c4: 0x220982d  daddu       $s3, $s1, $zero
    ctx->pc = 0x1082c4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1082c8: 0x8e510010  lw          $s1, 0x10($s2)
    ctx->pc = 0x1082c8u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1082cc: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x1082ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_1082d0:
    // 0x1082d0: 0x271a021  addu        $s4, $s3, $s1
    ctx->pc = 0x1082d0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
    // 0x1082d4: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1082d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1082d8: 0xb4282a  slt         $a1, $a1, $s4
    ctx->pc = 0x1082d8u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x1082dc: 0xc041f7e  jal         func_107DF8
    ctx->pc = 0x1082DCu;
    SET_GPR_U32(ctx, 31, 0x1082E4u);
    ctx->pc = 0x1082E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1082DCu;
            // 0x1082e0: 0x452821  addu        $a1, $v0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DF8u;
    if (runtime->hasFunction(0x107DF8u)) {
        auto targetFn = runtime->lookupFunction(0x107DF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1082E4u; }
        if (ctx->pc != 0x1082E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DF8_0x107df8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1082E4u; }
        if (ctx->pc != 0x1082E4u) { return; }
    }
    ctx->pc = 0x1082E4u;
label_1082e4:
    // 0x1082e4: 0x14c880  sll         $t9, $s4, 2
    ctx->pc = 0x1082e4u;
    SET_GPR_S32(ctx, 25, (int32_t)SLL32(GPR_U32(ctx, 20), 2));
    // 0x1082e8: 0x40c02d  daddu       $t8, $v0, $zero
    ctx->pc = 0x1082e8u;
    SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1082ec: 0x270f0014  addiu       $t7, $t8, 0x14
    ctx->pc = 0x1082ecu;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 24), 20));
    // 0x1082f0: 0x1f96821  addu        $t5, $t7, $t9
    ctx->pc = 0x1082f0u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 15), GPR_U32(ctx, 25)));
    // 0x1082f4: 0x1ed102b  sltu        $v0, $t7, $t5
    ctx->pc = 0x1082f4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 15) < (uint64_t)GPR_U64(ctx, 13)) ? 1 : 0);
    // 0x1082f8: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1082F8u;
    {
        const bool branch_taken_0x1082f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1082FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1082F8u;
            // 0x1082fc: 0x1e0402d  daddu       $t0, $t7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 15) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1082f8) {
            ctx->pc = 0x108324u;
            goto label_108324;
        }
    }
    ctx->pc = 0x108300u;
    // 0x108300: 0xad000000  sw          $zero, 0x0($t0)
    ctx->pc = 0x108300u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 0));
    // 0x108304: 0x0  nop
    ctx->pc = 0x108304u;
    // NOP
label_108308:
    // 0x108308: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x108308u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x10830c: 0x10d102b  sltu        $v0, $t0, $t5
    ctx->pc = 0x10830cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 13)) ? 1 : 0);
    // 0x108310: 0x0  nop
    ctx->pc = 0x108310u;
    // NOP
    // 0x108314: 0x0  nop
    ctx->pc = 0x108314u;
    // NOP
    // 0x108318: 0x0  nop
    ctx->pc = 0x108318u;
    // NOP
    // 0x10831c: 0x5440fffa  bnel        $v0, $zero, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10831Cu;
    {
        const bool branch_taken_0x10831c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10831c) {
            ctx->pc = 0x108320u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10831Cu;
            // 0x108320: 0xad000000  sw          $zero, 0x0($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108308u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108308;
        }
    }
    ctx->pc = 0x108324u;
label_108324:
    // 0x108324: 0x264b0014  addiu       $t3, $s2, 0x14
    ctx->pc = 0x108324u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 18), 20));
    // 0x108328: 0x111080  sll         $v0, $s1, 2
    ctx->pc = 0x108328u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x10832c: 0x1628821  addu        $s1, $t3, $v0
    ctx->pc = 0x10832cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
    // 0x108330: 0x131080  sll         $v0, $s3, 2
    ctx->pc = 0x108330u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    // 0x108334: 0x260d0014  addiu       $t5, $s0, 0x14
    ctx->pc = 0x108334u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x108338: 0x171182b  sltu        $v1, $t3, $s1
    ctx->pc = 0x108338u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x10833c: 0x1a27021  addu        $t6, $t5, $v0
    ctx->pc = 0x10833cu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 2)));
    // 0x108340: 0x1060003e  beqz        $v1, . + 4 + (0x3E << 2)
    ctx->pc = 0x108340u;
    {
        const bool branch_taken_0x108340 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x108344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108340u;
            // 0x108344: 0x1e0602d  daddu       $t4, $t7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 15) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108340) {
            ctx->pc = 0x10843Cu;
            goto label_10843c;
        }
    }
    ctx->pc = 0x108348u;
label_108348:
    // 0x108348: 0x8d620000  lw          $v0, 0x0($t3)
    ctx->pc = 0x108348u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x10834c: 0x3049ffff  andi        $t1, $v0, 0xFFFF
    ctx->pc = 0x10834cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x108350: 0x11200019  beqz        $t1, . + 4 + (0x19 << 2)
    ctx->pc = 0x108350u;
    {
        const bool branch_taken_0x108350 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        ctx->pc = 0x108354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108350u;
            // 0x108354: 0x180382d  daddu       $a3, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108350) {
            ctx->pc = 0x1083B8u;
            goto label_1083b8;
        }
    }
    ctx->pc = 0x108358u;
    // 0x108358: 0x1a0402d  daddu       $t0, $t5, $zero
    ctx->pc = 0x108358u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10835c: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x10835cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_108360:
    // 0x108360: 0x8d030000  lw          $v1, 0x0($t0)
    ctx->pc = 0x108360u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x108364: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x108364u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x108368: 0x8ce50000  lw          $a1, 0x0($a3)
    ctx->pc = 0x108368u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x10836c: 0x10e302b  sltu        $a2, $t0, $t6
    ctx->pc = 0x10836cu;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 14)) ? 1 : 0);
    // 0x108370: 0x3062ffff  andi        $v0, $v1, 0xFFFF
    ctx->pc = 0x108370u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x108374: 0x31c02  srl         $v1, $v1, 16
    ctx->pc = 0x108374u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 16));
    // 0x108378: 0x491018  mult        $v0, $v0, $t1
    ctx->pc = 0x108378u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x10837c: 0x70691818  mult1       $v1, $v1, $t1
    ctx->pc = 0x10837cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 9); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x108380: 0x30a4ffff  andi        $a0, $a1, 0xFFFF
    ctx->pc = 0x108380u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x108384: 0x52c02  srl         $a1, $a1, 16
    ctx->pc = 0x108384u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
    // 0x108388: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x108388u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x10838c: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x10838cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x108390: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x108390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x108394: 0x25402  srl         $t2, $v0, 16
    ctx->pc = 0x108394u;
    SET_GPR_S32(ctx, 10, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x108398: 0xa4e20000  sh          $v0, 0x0($a3)
    ctx->pc = 0x108398u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x10839c: 0x6a1021  addu        $v0, $v1, $t2
    ctx->pc = 0x10839cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x1083a0: 0xa4e20002  sh          $v0, 0x2($a3)
    ctx->pc = 0x1083a0u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1083a4: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x1083a4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x1083a8: 0x14c0ffed  bnez        $a2, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1083A8u;
    {
        const bool branch_taken_0x1083a8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1083ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1083A8u;
            // 0x1083ac: 0x25402  srl         $t2, $v0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1083a8) {
            ctx->pc = 0x108360u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108360;
        }
    }
    ctx->pc = 0x1083B0u;
    // 0x1083b0: 0xacea0000  sw          $t2, 0x0($a3)
    ctx->pc = 0x1083b0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 10));
    // 0x1083b4: 0x8d620000  lw          $v0, 0x0($t3)
    ctx->pc = 0x1083b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
label_1083b8:
    // 0x1083b8: 0x24c02  srl         $t1, $v0, 16
    ctx->pc = 0x1083b8u;
    SET_GPR_S32(ctx, 9, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1083bc: 0x1120001b  beqz        $t1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1083BCu;
    {
        const bool branch_taken_0x1083bc = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        ctx->pc = 0x1083C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1083BCu;
            // 0x1083c0: 0x180382d  daddu       $a3, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1083bc) {
            ctx->pc = 0x10842Cu;
            goto label_10842c;
        }
    }
    ctx->pc = 0x1083C4u;
    // 0x1083c4: 0x1a0402d  daddu       $t0, $t5, $zero
    ctx->pc = 0x1083c4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1083c8: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x1083c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1083cc: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1083ccu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1083d0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1083d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1083d4: 0x0  nop
    ctx->pc = 0x1083d4u;
    // NOP
label_1083d8:
    // 0x1083d8: 0x8d030000  lw          $v1, 0x0($t0)
    ctx->pc = 0x1083d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1083dc: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x1083dcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x1083e0: 0xa4e20000  sh          $v0, 0x0($a3)
    ctx->pc = 0x1083e0u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1083e4: 0x42402  srl         $a0, $a0, 16
    ctx->pc = 0x1083e4u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x1083e8: 0x3062ffff  andi        $v0, $v1, 0xFFFF
    ctx->pc = 0x1083e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1083ec: 0x31c02  srl         $v1, $v1, 16
    ctx->pc = 0x1083ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 16));
    // 0x1083f0: 0x491018  mult        $v0, $v0, $t1
    ctx->pc = 0x1083f0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1083f4: 0x70691818  mult1       $v1, $v1, $t1
    ctx->pc = 0x1083f4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 9); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1083f8: 0x10e282b  sltu        $a1, $t0, $t6
    ctx->pc = 0x1083f8u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 14)) ? 1 : 0);
    // 0x1083fc: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1083fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x108400: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x108400u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x108404: 0xa4e20002  sh          $v0, 0x2($a3)
    ctx->pc = 0x108404u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x108408: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x108408u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x10840c: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x10840cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x108410: 0x25402  srl         $t2, $v0, 16
    ctx->pc = 0x108410u;
    SET_GPR_S32(ctx, 10, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x108414: 0x3082ffff  andi        $v0, $a0, 0xFFFF
    ctx->pc = 0x108414u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x108418: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x108418u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10841c: 0x6a1021  addu        $v0, $v1, $t2
    ctx->pc = 0x10841cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x108420: 0x14a0ffed  bnez        $a1, . + 4 + (-0x13 << 2)
    ctx->pc = 0x108420u;
    {
        const bool branch_taken_0x108420 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x108424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108420u;
            // 0x108424: 0x25402  srl         $t2, $v0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108420) {
            ctx->pc = 0x1083D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1083d8;
        }
    }
    ctx->pc = 0x108428u;
    // 0x108428: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x108428u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
label_10842c:
    // 0x10842c: 0x256b0004  addiu       $t3, $t3, 0x4
    ctx->pc = 0x10842cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 4));
    // 0x108430: 0x171102b  sltu        $v0, $t3, $s1
    ctx->pc = 0x108430u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x108434: 0x1440ffc4  bnez        $v0, . + 4 + (-0x3C << 2)
    ctx->pc = 0x108434u;
    {
        const bool branch_taken_0x108434 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x108438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108434u;
            // 0x108438: 0x258c0004  addiu       $t4, $t4, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108434) {
            ctx->pc = 0x108348u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108348;
        }
    }
    ctx->pc = 0x10843Cu;
label_10843c:
    // 0x10843c: 0x1f93821  addu        $a3, $t7, $t9
    ctx->pc = 0x10843cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 15), GPR_U32(ctx, 25)));
label_108440:
    // 0x108440: 0x5a800009  blezl       $s4, . + 4 + (0x9 << 2)
    ctx->pc = 0x108440u;
    {
        const bool branch_taken_0x108440 = (GPR_S64(ctx, 20) <= 0);
        if (branch_taken_0x108440) {
            ctx->pc = 0x108444u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x108440u;
            // 0x108444: 0xaf140010  sw          $s4, 0x10($t8) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 24), 16), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108468u;
            goto label_108468;
        }
    }
    ctx->pc = 0x108448u;
    // 0x108448: 0x24e7fffc  addiu       $a3, $a3, -0x4
    ctx->pc = 0x108448u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967292));
    // 0x10844c: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x10844cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x108450: 0x0  nop
    ctx->pc = 0x108450u;
    // NOP
    // 0x108454: 0x0  nop
    ctx->pc = 0x108454u;
    // NOP
    // 0x108458: 0x0  nop
    ctx->pc = 0x108458u;
    // NOP
    // 0x10845c: 0x5040fff8  beql        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x10845Cu;
    {
        const bool branch_taken_0x10845c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10845c) {
            ctx->pc = 0x108460u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10845Cu;
            // 0x108460: 0x2694ffff  addiu       $s4, $s4, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108440u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108440;
        }
    }
    ctx->pc = 0x108464u;
    // 0x108464: 0xaf140010  sw          $s4, 0x10($t8)
    ctx->pc = 0x108464u;
    WRITE32(ADD32(GPR_U32(ctx, 24), 16), GPR_U32(ctx, 20));
label_108468:
    // 0x108468: 0x300102d  daddu       $v0, $t8, $zero
    ctx->pc = 0x108468u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 24) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10846c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10846cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x108470: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x108470u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x108474: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x108474u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x108478: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x108478u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10847c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x10847cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x108480: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x108480u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x108484: 0x3e00008  jr          $ra
    ctx->pc = 0x108484u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x108488u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108484u;
            // 0x108488: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1082D0u: goto label_1082d0;
            case 0x1082E4u: goto label_1082e4;
            case 0x108308u: goto label_108308;
            case 0x108324u: goto label_108324;
            case 0x108348u: goto label_108348;
            case 0x108360u: goto label_108360;
            case 0x1083B8u: goto label_1083b8;
            case 0x1083D8u: goto label_1083d8;
            case 0x10842Cu: goto label_10842c;
            case 0x10843Cu: goto label_10843c;
            case 0x108440u: goto label_108440;
            case 0x108468u: goto label_108468;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10848Cu;
    // 0x10848c: 0x0  nop
    ctx->pc = 0x10848cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
