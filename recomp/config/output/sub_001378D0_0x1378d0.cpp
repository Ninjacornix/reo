#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001378D0
// Address: 0x1378d0 - 0x1379d0
void sub_001378D0_0x1378d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001378D0_0x1378d0");
#endif

    switch (ctx->pc) {
        case 0x137938u: goto label_137938;
        case 0x137940u: goto label_137940;
        case 0x137948u: goto label_137948;
        case 0x137954u: goto label_137954;
        case 0x13795cu: goto label_13795c;
        case 0x137970u: goto label_137970;
        case 0x137978u: goto label_137978;
        case 0x137984u: goto label_137984;
        case 0x1379b0u: goto label_1379b0;
        default: break;
    }

    ctx->pc = 0x1378d0u;

    // 0x1378d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1378d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1378d4: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x1378d4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x1378d8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1378d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1378dc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1378dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1378e0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1378e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1378e4: 0x2463bbd4  addiu       $v1, $v1, -0x442C
    ctx->pc = 0x1378e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949844));
    // 0x1378e8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1378e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1378ec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1378ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1378f0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1378f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1378f4: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1378f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1378f8: 0x1080002e  beqz        $a0, . + 4 + (0x2E << 2)
    ctx->pc = 0x1378F8u;
    {
        const bool branch_taken_0x1378f8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1378FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1378F8u;
            // 0x1378fc: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1378f8) {
            ctx->pc = 0x1379B4u;
            goto label_1379b4;
        }
    }
    ctx->pc = 0x137900u;
    // 0x137900: 0x82240002  lb          $a0, 0x2($s1)
    ctx->pc = 0x137900u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x137904: 0x5483002c  bnel        $a0, $v1, . + 4 + (0x2C << 2)
    ctx->pc = 0x137904u;
    {
        const bool branch_taken_0x137904 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x137904) {
            ctx->pc = 0x137908u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x137904u;
            // 0x137908: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1379B8u;
            goto label_1379b8;
        }
    }
    ctx->pc = 0x13790Cu;
    // 0x13790c: 0x3c120022  lui         $s2, 0x22
    ctx->pc = 0x13790cu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)34 << 16));
    // 0x137910: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x137910u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137914: 0x2644bbdc  addiu       $a0, $s2, -0x4424
    ctx->pc = 0x137914u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 4294949852));
    // 0x137918: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x137918u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13791c: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x13791cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x137920: 0x2442bbd0  addiu       $v0, $v0, -0x4430
    ctx->pc = 0x137920u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949840));
    // 0x137924: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x137924u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x137928: 0x1465000f  bne         $v1, $a1, . + 4 + (0xF << 2)
    ctx->pc = 0x137928u;
    {
        const bool branch_taken_0x137928 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x137928) {
            ctx->pc = 0x137968u;
            goto label_137968;
        }
    }
    ctx->pc = 0x137930u;
    // 0x137930: 0xc0505cc  jal         func_141730
    ctx->pc = 0x137930u;
    SET_GPR_U32(ctx, 31, 0x137938u);
    ctx->pc = 0x141730u;
    if (runtime->hasFunction(0x141730u)) {
        auto targetFn = runtime->lookupFunction(0x141730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137938u; }
        if (ctx->pc != 0x137938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141730_0x141730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137938u; }
        if (ctx->pc != 0x137938u) { return; }
    }
    ctx->pc = 0x137938u;
label_137938:
    // 0x137938: 0xc04e082  jal         func_138208
    ctx->pc = 0x137938u;
    SET_GPR_U32(ctx, 31, 0x137940u);
    ctx->pc = 0x13793Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137938u;
            // 0x13793c: 0x24041400  addiu       $a0, $zero, 0x1400 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5120));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137940u; }
        if (ctx->pc != 0x137940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137940u; }
        if (ctx->pc != 0x137940u) { return; }
    }
    ctx->pc = 0x137940u;
label_137940:
    // 0x137940: 0xc0406ba  jal         func_101AE8
    ctx->pc = 0x137940u;
    SET_GPR_U32(ctx, 31, 0x137948u);
    ctx->pc = 0x101AE8u;
    if (runtime->hasFunction(0x101AE8u)) {
        auto targetFn = runtime->lookupFunction(0x101AE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137948u; }
        if (ctx->pc != 0x137948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101AE8_0x101ae8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137948u; }
        if (ctx->pc != 0x137948u) { return; }
    }
    ctx->pc = 0x137948u;
label_137948:
    // 0x137948: 0x24041401  addiu       $a0, $zero, 0x1401
    ctx->pc = 0x137948u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5121));
    // 0x13794c: 0xc04e082  jal         func_138208
    ctx->pc = 0x13794Cu;
    SET_GPR_U32(ctx, 31, 0x137954u);
    ctx->pc = 0x137950u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13794Cu;
            // 0x137950: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137954u; }
        if (ctx->pc != 0x137954u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137954u; }
        if (ctx->pc != 0x137954u) { return; }
    }
    ctx->pc = 0x137954u;
label_137954:
    // 0x137954: 0xc0505ea  jal         func_1417A8
    ctx->pc = 0x137954u;
    SET_GPR_U32(ctx, 31, 0x13795Cu);
    ctx->pc = 0x1417A8u;
    if (runtime->hasFunction(0x1417A8u)) {
        auto targetFn = runtime->lookupFunction(0x1417A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13795Cu; }
        if (ctx->pc != 0x13795Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001417A8_0x1417a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13795Cu; }
        if (ctx->pc != 0x13795Cu) { return; }
    }
    ctx->pc = 0x13795Cu;
label_13795c:
    // 0x13795c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x13795Cu;
    {
        const bool branch_taken_0x13795c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x137960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13795Cu;
            // 0x137960: 0x26020001  addiu       $v0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13795c) {
            ctx->pc = 0x137988u;
            goto label_137988;
        }
    }
    ctx->pc = 0x137964u;
    // 0x137964: 0x0  nop
    ctx->pc = 0x137964u;
    // NOP
label_137968:
    // 0x137968: 0xc04e082  jal         func_138208
    ctx->pc = 0x137968u;
    SET_GPR_U32(ctx, 31, 0x137970u);
    ctx->pc = 0x13796Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137968u;
            // 0x13796c: 0x24041500  addiu       $a0, $zero, 0x1500 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5376));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137970u; }
        if (ctx->pc != 0x137970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137970u; }
        if (ctx->pc != 0x137970u) { return; }
    }
    ctx->pc = 0x137970u;
label_137970:
    // 0x137970: 0xc0406ba  jal         func_101AE8
    ctx->pc = 0x137970u;
    SET_GPR_U32(ctx, 31, 0x137978u);
    ctx->pc = 0x101AE8u;
    if (runtime->hasFunction(0x101AE8u)) {
        auto targetFn = runtime->lookupFunction(0x101AE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137978u; }
        if (ctx->pc != 0x137978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101AE8_0x101ae8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137978u; }
        if (ctx->pc != 0x137978u) { return; }
    }
    ctx->pc = 0x137978u;
label_137978:
    // 0x137978: 0x24041501  addiu       $a0, $zero, 0x1501
    ctx->pc = 0x137978u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5377));
    // 0x13797c: 0xc04e082  jal         func_138208
    ctx->pc = 0x13797Cu;
    SET_GPR_U32(ctx, 31, 0x137984u);
    ctx->pc = 0x137980u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13797Cu;
            // 0x137980: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137984u; }
        if (ctx->pc != 0x137984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137984u; }
        if (ctx->pc != 0x137984u) { return; }
    }
    ctx->pc = 0x137984u;
label_137984:
    // 0x137984: 0x26020001  addiu       $v0, $s0, 0x1
    ctx->pc = 0x137984u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_137988:
    // 0x137988: 0x2643bbdc  addiu       $v1, $s2, -0x4424
    ctx->pc = 0x137988u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 4294949852));
    // 0x13798c: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x13798cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x137990: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x137990u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x137994: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x137994u;
    {
        const bool branch_taken_0x137994 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x137994) {
            ctx->pc = 0x137998u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x137994u;
            // 0x137998: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1379B4u;
            goto label_1379b4;
        }
    }
    ctx->pc = 0x13799Cu;
    // 0x13799c: 0xae300034  sw          $s0, 0x34($s1)
    ctx->pc = 0x13799cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 16));
    // 0x1379a0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1379a0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1379a4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1379a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1379a8: 0xc045a12  jal         func_116848
    ctx->pc = 0x1379A8u;
    SET_GPR_U32(ctx, 31, 0x1379B0u);
    ctx->pc = 0x1379ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1379A8u;
            // 0x1379ac: 0x2484c520  addiu       $a0, $a0, -0x3AE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952224));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1379B0u; }
        if (ctx->pc != 0x1379B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1379B0u; }
        if (ctx->pc != 0x1379B0u) { return; }
    }
    ctx->pc = 0x1379B0u;
label_1379b0:
    // 0x1379b0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1379b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1379b4:
    // 0x1379b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1379b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1379b8:
    // 0x1379b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1379b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1379bc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1379bcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1379c0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1379c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1379c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1379C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1379C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1379C4u;
            // 0x1379c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137938u: goto label_137938;
            case 0x137940u: goto label_137940;
            case 0x137948u: goto label_137948;
            case 0x137954u: goto label_137954;
            case 0x13795Cu: goto label_13795c;
            case 0x137968u: goto label_137968;
            case 0x137970u: goto label_137970;
            case 0x137978u: goto label_137978;
            case 0x137984u: goto label_137984;
            case 0x137988u: goto label_137988;
            case 0x1379B0u: goto label_1379b0;
            case 0x1379B4u: goto label_1379b4;
            case 0x1379B8u: goto label_1379b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1379CCu;
    // 0x1379cc: 0x0  nop
    ctx->pc = 0x1379ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
