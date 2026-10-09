#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F878
// Address: 0x11f878 - 0x11fbb4
void sub_0011F878_0x11f878(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F878_0x11f878");
#endif

    switch (ctx->pc) {
        case 0x11f900u: goto label_11f900;
        case 0x11fac8u: goto label_11fac8;
        case 0x11fad4u: goto label_11fad4;
        case 0x11fae0u: goto label_11fae0;
        case 0x11fb60u: goto label_11fb60;
        case 0x11fb74u: goto label_11fb74;
        case 0x11fb90u: goto label_11fb90;
        case 0x11fba4u: goto label_11fba4;
        default: break;
    }

    ctx->pc = 0x11f878u;

    // 0x11f878: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11f878u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11f87c: 0x80602d  daddu       $t4, $a0, $zero
    ctx->pc = 0x11f87cu;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f880: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f884: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x11f884u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f888: 0x3383c  dsll32      $a3, $v1, 0
    ctx->pc = 0x11f888u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) << (32 + 0));
    // 0x11f88c: 0x7383f  dsra32      $a3, $a3, 0
    ctx->pc = 0x11f88cu;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 0));
    // 0x11f890: 0x3583f  dsra32      $t3, $v1, 0
    ctx->pc = 0x11f890u;
    SET_GPR_S64(ctx, 11, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x11f894: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x11f894u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x11f898: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11f898u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11f89c: 0x1624824  and         $t1, $t3, $v0
    ctx->pc = 0x11f89cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 11) & GPR_U64(ctx, 2));
    // 0x11f8a0: 0x180182d  daddu       $v1, $t4, $zero
    ctx->pc = 0x11f8a0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f8a4: 0x3303c  dsll32      $a2, $v1, 0
    ctx->pc = 0x11f8a4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) << (32 + 0));
    // 0x11f8a8: 0x6303f  dsra32      $a2, $a2, 0
    ctx->pc = 0x11f8a8u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x11f8ac: 0x3503f  dsra32      $t2, $v1, 0
    ctx->pc = 0x11f8acu;
    SET_GPR_S64(ctx, 10, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x11f8b0: 0x1424024  and         $t0, $t2, $v0
    ctx->pc = 0x11f8b0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 10) & GPR_U64(ctx, 2));
    // 0x11f8b4: 0x3c037ff0  lui         $v1, 0x7FF0
    ctx->pc = 0x11f8b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32752 << 16));
    // 0x11f8b8: 0x71023  negu        $v0, $a3
    ctx->pc = 0x11f8b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 7)));
    // 0x11f8bc: 0xe21025  or          $v0, $a3, $v0
    ctx->pc = 0x11f8bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x11f8c0: 0x217c2  srl         $v0, $v0, 31
    ctx->pc = 0x11f8c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x11f8c4: 0x1221025  or          $v0, $t1, $v0
    ctx->pc = 0x11f8c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x11f8c8: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x11f8c8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x11f8cc: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11F8CCu;
    {
        const bool branch_taken_0x11f8cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F8D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F8CCu;
            // 0x11f8d0: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f8cc) {
            ctx->pc = 0x11F8F0u;
            goto label_11f8f0;
        }
    }
    ctx->pc = 0x11F8D4u;
    // 0x11f8d4: 0x61023  negu        $v0, $a2
    ctx->pc = 0x11f8d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 6)));
    // 0x11f8d8: 0xc21025  or          $v0, $a2, $v0
    ctx->pc = 0x11f8d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x11f8dc: 0x217c2  srl         $v0, $v0, 31
    ctx->pc = 0x11f8dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x11f8e0: 0x1021025  or          $v0, $t0, $v0
    ctx->pc = 0x11f8e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x11f8e4: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x11f8e4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x11f8e8: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x11F8E8u;
    {
        const bool branch_taken_0x11f8e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f8e8) {
            ctx->pc = 0x11F8ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F8E8u;
            // 0x11f8ec: 0x3c02c010  lui         $v0, 0xC010 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49168 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F908u;
            goto label_11f908;
        }
    }
    ctx->pc = 0x11F8F0u;
label_11f8f0:
    // 0x11f8f0: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x11f8f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f8f4: 0x180282d  daddu       $a1, $t4, $zero
    ctx->pc = 0x11f8f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f8f8: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11F8F8u;
    SET_GPR_U32(ctx, 31, 0x11F900u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F900u; }
        if (ctx->pc != 0x11F900u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F900u; }
        if (ctx->pc != 0x11F900u) { return; }
    }
    ctx->pc = 0x11F900u;
label_11f900:
    // 0x11f900: 0x100000a9  b           . + 4 + (0xA9 << 2)
    ctx->pc = 0x11F900u;
    {
        const bool branch_taken_0x11f900 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F900u;
            // 0x11f904: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f900) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F908u;
label_11f908:
    // 0x11f908: 0x1621021  addu        $v0, $t3, $v0
    ctx->pc = 0x11f908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
    // 0x11f90c: 0x471025  or          $v0, $v0, $a3
    ctx->pc = 0x11f90cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 7));
    // 0x11f910: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x11F910u;
    {
        const bool branch_taken_0x11f910 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11f910) {
            ctx->pc = 0x11F914u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F910u;
            // 0x11f914: 0xb1783  sra         $v0, $t3, 30 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 11), 30));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F928u;
            goto label_11f928;
        }
    }
    ctx->pc = 0x11F918u;
    // 0x11f918: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f918u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f91c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x11f91cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x11f920: 0x804868a  j           func_121A28
    ctx->pc = 0x11F920u;
    ctx->pc = 0x11F924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F920u;
            // 0x11f924: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x121A28u;
    if (runtime->hasFunction(0x121A28u)) {
        auto targetFn = runtime->lookupFunction(0x121A28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00121A28_0x121a28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11F928u;
label_11f928:
    // 0x11f928: 0xa1fc2  srl         $v1, $t2, 31
    ctx->pc = 0x11f928u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 10), 31));
    // 0x11f92c: 0x30420002  andi        $v0, $v0, 0x2
    ctx->pc = 0x11f92cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2);
    // 0x11f930: 0x1062025  or          $a0, $t0, $a2
    ctx->pc = 0x11f930u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 8) | GPR_U64(ctx, 6));
    // 0x11f934: 0x14800012  bnez        $a0, . + 4 + (0x12 << 2)
    ctx->pc = 0x11F934u;
    {
        const bool branch_taken_0x11f934 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F934u;
            // 0x11f938: 0x628025  or          $s0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f934) {
            ctx->pc = 0x11F980u;
            goto label_11f980;
        }
    }
    ctx->pc = 0x11F93Cu;
    // 0x11f93c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x11f93cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x11f940: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11f940u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11f944: 0xdc228c90  ld          $v0, -0x7370($at)
    ctx->pc = 0x11f944u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937744)));
    // 0x11f948: 0x52030097  beql        $s0, $v1, . + 4 + (0x97 << 2)
    ctx->pc = 0x11F948u;
    {
        const bool branch_taken_0x11f948 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x11f948) {
            ctx->pc = 0x11F94Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F948u;
            // 0x11f94c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F950u;
    // 0x11f950: 0x2a020003  slti        $v0, $s0, 0x3
    ctx->pc = 0x11f950u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x11f954: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x11F954u;
    {
        const bool branch_taken_0x11f954 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f954) {
            ctx->pc = 0x11F958u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F954u;
            // 0x11f958: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F970u;
            goto label_11f970;
        }
    }
    ctx->pc = 0x11F95Cu;
    // 0x11f95c: 0x6020009  bltzl       $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x11F95Cu;
    {
        const bool branch_taken_0x11f95c = (GPR_S64(ctx, 16) < 0);
        if (branch_taken_0x11f95c) {
            ctx->pc = 0x11F960u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F95Cu;
            // 0x11f960: 0x1271025  or          $v0, $t1, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) | GPR_U64(ctx, 7));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F984u;
            goto label_11f984;
        }
    }
    ctx->pc = 0x11F964u;
    // 0x11f964: 0x180102d  daddu       $v0, $t4, $zero
    ctx->pc = 0x11f964u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f968: 0x1000008f  b           . + 4 + (0x8F << 2)
    ctx->pc = 0x11F968u;
    {
        const bool branch_taken_0x11f968 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F96Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F968u;
            // 0x11f96c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f968) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F970u;
label_11f970:
    // 0x11f970: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11f970u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11f974: 0xdc228c98  ld          $v0, -0x7368($at)
    ctx->pc = 0x11f974u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937752)));
    // 0x11f978: 0x5203008b  beql        $s0, $v1, . + 4 + (0x8B << 2)
    ctx->pc = 0x11F978u;
    {
        const bool branch_taken_0x11f978 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x11f978) {
            ctx->pc = 0x11F97Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F978u;
            // 0x11f97c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F980u;
label_11f980:
    // 0x11f980: 0x1271025  or          $v0, $t1, $a3
    ctx->pc = 0x11f980u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) | GPR_U64(ctx, 7));
label_11f984:
    // 0x11f984: 0x1040003a  beqz        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x11F984u;
    {
        const bool branch_taken_0x11f984 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F984u;
            // 0x11f988: 0x3c027ff0  lui         $v0, 0x7FF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32752 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f984) {
            ctx->pc = 0x11FA70u;
            goto label_11fa70;
        }
    }
    ctx->pc = 0x11F98Cu;
    // 0x11f98c: 0x15220036  bne         $t1, $v0, . + 4 + (0x36 << 2)
    ctx->pc = 0x11F98Cu;
    {
        const bool branch_taken_0x11f98c = (GPR_U64(ctx, 9) != GPR_U64(ctx, 2));
        if (branch_taken_0x11f98c) {
            ctx->pc = 0x11FA68u;
            goto label_11fa68;
        }
    }
    ctx->pc = 0x11F994u;
    // 0x11f994: 0x1509001c  bne         $t0, $t1, . + 4 + (0x1C << 2)
    ctx->pc = 0x11F994u;
    {
        const bool branch_taken_0x11f994 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 9));
        ctx->pc = 0x11F998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F994u;
            // 0x11f998: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f994) {
            ctx->pc = 0x11FA08u;
            goto label_11fa08;
        }
    }
    ctx->pc = 0x11F99Cu;
    // 0x11f99c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x11f99cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11f9a0: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11f9a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11f9a4: 0xdc228ca0  ld          $v0, -0x7360($at)
    ctx->pc = 0x11f9a4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937760)));
    // 0x11f9a8: 0x5203007f  beql        $s0, $v1, . + 4 + (0x7F << 2)
    ctx->pc = 0x11F9A8u;
    {
        const bool branch_taken_0x11f9a8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x11f9a8) {
            ctx->pc = 0x11F9ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9A8u;
            // 0x11f9ac: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F9B0u;
    // 0x11f9b0: 0x2a020002  slti        $v0, $s0, 0x2
    ctx->pc = 0x11f9b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x11f9b4: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x11F9B4u;
    {
        const bool branch_taken_0x11f9b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f9b4) {
            ctx->pc = 0x11F9B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9B4u;
            // 0x11f9b8: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F9D8u;
            goto label_11f9d8;
        }
    }
    ctx->pc = 0x11F9BCu;
    // 0x11f9bc: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11f9bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11f9c0: 0xdc228ca8  ld          $v0, -0x7358($at)
    ctx->pc = 0x11f9c0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937768)));
    // 0x11f9c4: 0x52000078  beql        $s0, $zero, . + 4 + (0x78 << 2)
    ctx->pc = 0x11F9C4u;
    {
        const bool branch_taken_0x11f9c4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f9c4) {
            ctx->pc = 0x11F9C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9C4u;
            // 0x11f9c8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F9CCu;
    // 0x11f9cc: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x11F9CCu;
    {
        const bool branch_taken_0x11f9cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F9D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9CCu;
            // 0x11f9d0: 0x3c027ff0  lui         $v0, 0x7FF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32752 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f9cc) {
            ctx->pc = 0x11FA68u;
            goto label_11fa68;
        }
    }
    ctx->pc = 0x11F9D4u;
    // 0x11f9d4: 0x0  nop
    ctx->pc = 0x11f9d4u;
    // NOP
label_11f9d8:
    // 0x11f9d8: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11f9d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11f9dc: 0xdc228cb0  ld          $v0, -0x7350($at)
    ctx->pc = 0x11f9dcu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937776)));
    // 0x11f9e0: 0x52030071  beql        $s0, $v1, . + 4 + (0x71 << 2)
    ctx->pc = 0x11F9E0u;
    {
        const bool branch_taken_0x11f9e0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x11f9e0) {
            ctx->pc = 0x11F9E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9E0u;
            // 0x11f9e4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11F9E8u;
    // 0x11f9e8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x11f9e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x11f9ec: 0x5602001e  bnel        $s0, $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x11F9ECu;
    {
        const bool branch_taken_0x11f9ec = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x11f9ec) {
            ctx->pc = 0x11F9F0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9ECu;
            // 0x11f9f0: 0x3c027ff0  lui         $v0, 0x7FF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32752 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FA68u;
            goto label_11fa68;
        }
    }
    ctx->pc = 0x11F9F4u;
    // 0x11f9f4: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11f9f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11f9f8: 0xdc228cb8  ld          $v0, -0x7348($at)
    ctx->pc = 0x11f9f8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937784)));
    // 0x11f9fc: 0x1000006a  b           . + 4 + (0x6A << 2)
    ctx->pc = 0x11F9FCu;
    {
        const bool branch_taken_0x11f9fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FA00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F9FCu;
            // 0x11fa00: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f9fc) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FA04u;
    // 0x11fa04: 0x0  nop
    ctx->pc = 0x11fa04u;
    // NOP
label_11fa08:
    // 0x11fa08: 0x12020013  beq         $s0, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x11FA08u;
    {
        const bool branch_taken_0x11fa08 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x11FA0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA08u;
            // 0x11fa0c: 0x3c030024  lui         $v1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa08) {
            ctx->pc = 0x11FA58u;
            goto label_11fa58;
        }
    }
    ctx->pc = 0x11FA10u;
    // 0x11fa10: 0x2a020002  slti        $v0, $s0, 0x2
    ctx->pc = 0x11fa10u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x11fa14: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11FA14u;
    {
        const bool branch_taken_0x11fa14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FA18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA14u;
            // 0x11fa18: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa14) {
            ctx->pc = 0x11FA30u;
            goto label_11fa30;
        }
    }
    ctx->pc = 0x11FA1Cu;
    // 0x11fa1c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11fa1cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fa20: 0x52000061  beql        $s0, $zero, . + 4 + (0x61 << 2)
    ctx->pc = 0x11FA20u;
    {
        const bool branch_taken_0x11fa20 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fa20) {
            ctx->pc = 0x11FA24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA20u;
            // 0x11fa24: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FA28u;
    // 0x11fa28: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11FA28u;
    {
        const bool branch_taken_0x11fa28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FA2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA28u;
            // 0x11fa2c: 0x3c027ff0  lui         $v0, 0x7FF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32752 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa28) {
            ctx->pc = 0x11FA68u;
            goto label_11fa68;
        }
    }
    ctx->pc = 0x11FA30u;
label_11fa30:
    // 0x11fa30: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fa30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fa34: 0xdc228cc0  ld          $v0, -0x7340($at)
    ctx->pc = 0x11fa34u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937792)));
    // 0x11fa38: 0x1203005a  beq         $s0, $v1, . + 4 + (0x5A << 2)
    ctx->pc = 0x11FA38u;
    {
        const bool branch_taken_0x11fa38 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        ctx->pc = 0x11FA3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA38u;
            // 0x11fa3c: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa38) {
            ctx->pc = 0x11FBA4u;
            goto label_11fba4;
        }
    }
    ctx->pc = 0x11FA40u;
    // 0x11fa40: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fa40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fa44: 0xdc228cc8  ld          $v0, -0x7338($at)
    ctx->pc = 0x11fa44u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937800)));
    // 0x11fa48: 0x52030057  beql        $s0, $v1, . + 4 + (0x57 << 2)
    ctx->pc = 0x11FA48u;
    {
        const bool branch_taken_0x11fa48 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x11fa48) {
            ctx->pc = 0x11FA4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA48u;
            // 0x11fa4c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FA50u;
    // 0x11fa50: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11FA50u;
    {
        const bool branch_taken_0x11fa50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FA54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA50u;
            // 0x11fa54: 0x3c027ff0  lui         $v0, 0x7FF0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32752 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa50) {
            ctx->pc = 0x11FA68u;
            goto label_11fa68;
        }
    }
    ctx->pc = 0x11FA58u;
label_11fa58:
    // 0x11fa58: 0xdc628c88  ld          $v0, -0x7378($v1)
    ctx->pc = 0x11fa58u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 4294937736)));
    // 0x11fa5c: 0x10000052  b           . + 4 + (0x52 << 2)
    ctx->pc = 0x11FA5Cu;
    {
        const bool branch_taken_0x11fa5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FA60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA5Cu;
            // 0x11fa60: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa5c) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FA64u;
    // 0x11fa64: 0x0  nop
    ctx->pc = 0x11fa64u;
    // NOP
label_11fa68:
    // 0x11fa68: 0x15020009  bne         $t0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x11FA68u;
    {
        const bool branch_taken_0x11fa68 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 2));
        ctx->pc = 0x11FA6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA68u;
            // 0x11fa6c: 0x1091823  subu        $v1, $t0, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa68) {
            ctx->pc = 0x11FA90u;
            goto label_11fa90;
        }
    }
    ctx->pc = 0x11FA70u;
label_11fa70:
    // 0x11fa70: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fa70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fa74: 0xdc228cd0  ld          $v0, -0x7330($at)
    ctx->pc = 0x11fa74u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937808)));
    // 0x11fa78: 0x540004a  bltz        $t2, . + 4 + (0x4A << 2)
    ctx->pc = 0x11FA78u;
    {
        const bool branch_taken_0x11fa78 = (GPR_S64(ctx, 10) < 0);
        ctx->pc = 0x11FA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA78u;
            // 0x11fa7c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa78) {
            ctx->pc = 0x11FBA4u;
            goto label_11fba4;
        }
    }
    ctx->pc = 0x11FA80u;
    // 0x11fa80: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fa80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fa84: 0xdc228cd8  ld          $v0, -0x7328($at)
    ctx->pc = 0x11fa84u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4294937816)));
    // 0x11fa88: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x11FA88u;
    {
        const bool branch_taken_0x11fa88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FA8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FA88u;
            // 0x11fa8c: 0xdfbf0008  ld          $ra, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fa88) {
            ctx->pc = 0x11FBACu;
            goto label_11fbac;
        }
    }
    ctx->pc = 0x11FA90u;
label_11fa90:
    // 0x11fa90: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fa90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fa94: 0xdc248ce0  ld          $a0, -0x7320($at)
    ctx->pc = 0x11fa94u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 1), 4294937824)));
    // 0x11fa98: 0x31d03  sra         $v1, $v1, 20
    ctx->pc = 0x11fa98u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 20));
    // 0x11fa9c: 0x2862003d  slti        $v0, $v1, 0x3D
    ctx->pc = 0x11fa9cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)61) ? 1 : 0);
    // 0x11faa0: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x11FAA0u;
    {
        const bool branch_taken_0x11faa0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FAA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FAA0u;
            // 0x11faa4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11faa0) {
            ctx->pc = 0x11FAE8u;
            goto label_11fae8;
        }
    }
    ctx->pc = 0x11FAA8u;
    // 0x11faa8: 0x5610004  bgez        $t3, . + 4 + (0x4 << 2)
    ctx->pc = 0x11FAA8u;
    {
        const bool branch_taken_0x11faa8 = (GPR_S64(ctx, 11) >= 0);
        ctx->pc = 0x11FAACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FAA8u;
            // 0x11faac: 0x2862ffc4  slti        $v0, $v1, -0x3C (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4294967236) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11faa8) {
            ctx->pc = 0x11FABCu;
            goto label_11fabc;
        }
    }
    ctx->pc = 0x11FAB0u;
    // 0x11fab0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x11fab0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fab4: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x11FAB4u;
    {
        const bool branch_taken_0x11fab4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11FAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FAB4u;
            // 0x11fab8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fab4) {
            ctx->pc = 0x11FAE8u;
            goto label_11fae8;
        }
    }
    ctx->pc = 0x11FABCu;
label_11fabc:
    // 0x11fabc: 0x180202d  daddu       $a0, $t4, $zero
    ctx->pc = 0x11fabcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fac0: 0xc04480e  jal         func_112038
    ctx->pc = 0x11FAC0u;
    SET_GPR_U32(ctx, 31, 0x11FAC8u);
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FAC8u; }
        if (ctx->pc != 0x11FAC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FAC8u; }
        if (ctx->pc != 0x11FAC8u) { return; }
    }
    ctx->pc = 0x11FAC8u;
label_11fac8:
    // 0x11fac8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fac8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11facc: 0xc0487bc  jal         func_121EF0
    ctx->pc = 0x11FACCu;
    SET_GPR_U32(ctx, 31, 0x11FAD4u);
    ctx->pc = 0x121EF0u;
    if (runtime->hasFunction(0x121EF0u)) {
        auto targetFn = runtime->lookupFunction(0x121EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FAD4u; }
        if (ctx->pc != 0x11FAD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00121EF0_0x121ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FAD4u; }
        if (ctx->pc != 0x11FAD4u) { return; }
    }
    ctx->pc = 0x11FAD4u;
label_11fad4:
    // 0x11fad4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fad4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fad8: 0xc04868a  jal         func_121A28
    ctx->pc = 0x11FAD8u;
    SET_GPR_U32(ctx, 31, 0x11FAE0u);
    ctx->pc = 0x121A28u;
    if (runtime->hasFunction(0x121A28u)) {
        auto targetFn = runtime->lookupFunction(0x121A28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FAE0u; }
        if (ctx->pc != 0x11FAE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00121A28_0x121a28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FAE0u; }
        if (ctx->pc != 0x11FAE0u) { return; }
    }
    ctx->pc = 0x11FAE0u;
label_11fae0:
    // 0x11fae0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fae0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fae4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11fae4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_11fae8:
    // 0x11fae8: 0x1202000d  beq         $s0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x11FAE8u;
    {
        const bool branch_taken_0x11fae8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x11FAECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FAE8u;
            // 0x11faec: 0x3c038000  lui         $v1, 0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fae8) {
            ctx->pc = 0x11FB20u;
            goto label_11fb20;
        }
    }
    ctx->pc = 0x11FAF0u;
    // 0x11faf0: 0x2a020002  slti        $v0, $s0, 0x2
    ctx->pc = 0x11faf0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x11faf4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11FAF4u;
    {
        const bool branch_taken_0x11faf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FAF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FAF4u;
            // 0x11faf8: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11faf4) {
            ctx->pc = 0x11FB10u;
            goto label_11fb10;
        }
    }
    ctx->pc = 0x11FAFCu;
    // 0x11fafc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x11fafcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fb00: 0x12000029  beqz        $s0, . + 4 + (0x29 << 2)
    ctx->pc = 0x11FB00u;
    {
        const bool branch_taken_0x11fb00 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FB04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FB00u;
            // 0x11fb04: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fb00) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FB08u;
    // 0x11fb08: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x11FB08u;
    {
        const bool branch_taken_0x11fb08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fb08) {
            ctx->pc = 0x11FB80u;
            goto label_11fb80;
        }
    }
    ctx->pc = 0x11FB10u;
label_11fb10:
    // 0x11fb10: 0x1202000f  beq         $s0, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x11FB10u;
    {
        const bool branch_taken_0x11fb10 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x11fb10) {
            ctx->pc = 0x11FB50u;
            goto label_11fb50;
        }
    }
    ctx->pc = 0x11FB18u;
    // 0x11fb18: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x11FB18u;
    {
        const bool branch_taken_0x11fb18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x11fb18) {
            ctx->pc = 0x11FB80u;
            goto label_11fb80;
        }
    }
    ctx->pc = 0x11FB20u;
label_11fb20:
    // 0x11fb20: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x11fb20u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fb24: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x11fb24u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x11fb28: 0x3c05ffff  lui         $a1, 0xFFFF
    ctx->pc = 0x11fb28u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65535 << 16));
    // 0x11fb2c: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x11fb2cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x11fb30: 0x431026  xor         $v0, $v0, $v1
    ctx->pc = 0x11fb30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x11fb34: 0x852024  and         $a0, $a0, $a1
    ctx->pc = 0x11fb34u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x11fb38: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x11fb38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x11fb3c: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x11fb3cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x11fb40: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x11fb40u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fb44: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x11FB44u;
    {
        const bool branch_taken_0x11fb44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FB48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FB44u;
            // 0x11fb48: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fb44) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FB4Cu;
    // 0x11fb4c: 0x0  nop
    ctx->pc = 0x11fb4cu;
    // NOP
label_11fb50:
    // 0x11fb50: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fb50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fb54: 0xdc258ce8  ld          $a1, -0x7318($at)
    ctx->pc = 0x11fb54u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937832)));
    // 0x11fb58: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FB58u;
    SET_GPR_U32(ctx, 31, 0x11FB60u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FB60u; }
        if (ctx->pc != 0x11FB60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FB60u; }
        if (ctx->pc != 0x11FB60u) { return; }
    }
    ctx->pc = 0x11FB60u;
label_11fb60:
    // 0x11fb60: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fb60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fb64: 0xdc248cf0  ld          $a0, -0x7310($at)
    ctx->pc = 0x11fb64u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 1), 4294937840)));
    // 0x11fb68: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x11fb68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fb6c: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FB6Cu;
    SET_GPR_U32(ctx, 31, 0x11FB74u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FB74u; }
        if (ctx->pc != 0x11FB74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FB74u; }
        if (ctx->pc != 0x11FB74u) { return; }
    }
    ctx->pc = 0x11FB74u;
label_11fb74:
    // 0x11fb74: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x11FB74u;
    {
        const bool branch_taken_0x11fb74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11FB78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FB74u;
            // 0x11fb78: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11fb74) {
            ctx->pc = 0x11FBA8u;
            goto label_11fba8;
        }
    }
    ctx->pc = 0x11FB7Cu;
    // 0x11fb7c: 0x0  nop
    ctx->pc = 0x11fb7cu;
    // NOP
label_11fb80:
    // 0x11fb80: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fb80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fb84: 0xdc258cf8  ld          $a1, -0x7308($at)
    ctx->pc = 0x11fb84u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937848)));
    // 0x11fb88: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FB88u;
    SET_GPR_U32(ctx, 31, 0x11FB90u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FB90u; }
        if (ctx->pc != 0x11FB90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FB90u; }
        if (ctx->pc != 0x11FB90u) { return; }
    }
    ctx->pc = 0x11FB90u;
label_11fb90:
    // 0x11fb90: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x11fb90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x11fb94: 0xdc258d00  ld          $a1, -0x7300($at)
    ctx->pc = 0x11fb94u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937856)));
    // 0x11fb98: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11fb98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11fb9c: 0xc044752  jal         func_111D48
    ctx->pc = 0x11FB9Cu;
    SET_GPR_U32(ctx, 31, 0x11FBA4u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FBA4u; }
        if (ctx->pc != 0x11FBA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11FBA4u; }
        if (ctx->pc != 0x11FBA4u) { return; }
    }
    ctx->pc = 0x11FBA4u;
label_11fba4:
    // 0x11fba4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11fba4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_11fba8:
    // 0x11fba8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x11fba8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_11fbac:
    // 0x11fbac: 0x3e00008  jr          $ra
    ctx->pc = 0x11FBACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11FBB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11FBACu;
            // 0x11fbb0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F8F0u: goto label_11f8f0;
            case 0x11F900u: goto label_11f900;
            case 0x11F908u: goto label_11f908;
            case 0x11F928u: goto label_11f928;
            case 0x11F970u: goto label_11f970;
            case 0x11F980u: goto label_11f980;
            case 0x11F984u: goto label_11f984;
            case 0x11F9D8u: goto label_11f9d8;
            case 0x11FA08u: goto label_11fa08;
            case 0x11FA30u: goto label_11fa30;
            case 0x11FA58u: goto label_11fa58;
            case 0x11FA68u: goto label_11fa68;
            case 0x11FA70u: goto label_11fa70;
            case 0x11FA90u: goto label_11fa90;
            case 0x11FABCu: goto label_11fabc;
            case 0x11FAC8u: goto label_11fac8;
            case 0x11FAD4u: goto label_11fad4;
            case 0x11FAE0u: goto label_11fae0;
            case 0x11FAE8u: goto label_11fae8;
            case 0x11FB10u: goto label_11fb10;
            case 0x11FB20u: goto label_11fb20;
            case 0x11FB50u: goto label_11fb50;
            case 0x11FB60u: goto label_11fb60;
            case 0x11FB74u: goto label_11fb74;
            case 0x11FB80u: goto label_11fb80;
            case 0x11FB90u: goto label_11fb90;
            case 0x11FBA4u: goto label_11fba4;
            case 0x11FBA8u: goto label_11fba8;
            case 0x11FBACu: goto label_11fbac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11FBB4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
