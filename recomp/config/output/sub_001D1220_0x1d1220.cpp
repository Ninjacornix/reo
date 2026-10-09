#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D1220
// Address: 0x1d1220 - 0x1d13e4
void sub_001D1220_0x1d1220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D1220_0x1d1220");
#endif

    switch (ctx->pc) {
        case 0x1d123cu: goto label_1d123c;
        case 0x1d1248u: goto label_1d1248;
        case 0x1d1254u: goto label_1d1254;
        case 0x1d1260u: goto label_1d1260;
        case 0x1d126cu: goto label_1d126c;
        case 0x1d1278u: goto label_1d1278;
        case 0x1d1284u: goto label_1d1284;
        case 0x1d1290u: goto label_1d1290;
        case 0x1d129cu: goto label_1d129c;
        case 0x1d12a8u: goto label_1d12a8;
        case 0x1d12b8u: goto label_1d12b8;
        case 0x1d12d4u: goto label_1d12d4;
        case 0x1d12e8u: goto label_1d12e8;
        case 0x1d1308u: goto label_1d1308;
        case 0x1d1368u: goto label_1d1368;
        case 0x1d1388u: goto label_1d1388;
        case 0x1d139cu: goto label_1d139c;
        case 0x1d13b4u: goto label_1d13b4;
        default: break;
    }

    ctx->pc = 0x1d1220u;

    // 0x1d1220: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1d1220u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1d1224: 0x24042400  addiu       $a0, $zero, 0x2400
    ctx->pc = 0x1d1224u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9216));
    // 0x1d1228: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d1228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d122c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d122cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d1230: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d1230u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d1234: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D1234u;
    SET_GPR_U32(ctx, 31, 0x1D123Cu);
    ctx->pc = 0x1D1238u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1234u;
            // 0x1d1238: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D123Cu; }
        if (ctx->pc != 0x1D123Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D123Cu; }
        if (ctx->pc != 0x1D123Cu) { return; }
    }
    ctx->pc = 0x1D123Cu;
label_1d123c:
    // 0x1d123c: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d123cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d1240: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1240u;
    SET_GPR_U32(ctx, 31, 0x1D1248u);
    ctx->pc = 0x1D1244u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1240u;
            // 0x1d1244: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1248u; }
        if (ctx->pc != 0x1D1248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1248u; }
        if (ctx->pc != 0x1D1248u) { return; }
    }
    ctx->pc = 0x1D1248u;
label_1d1248:
    // 0x1d1248: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d1248u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d124c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D124Cu;
    SET_GPR_U32(ctx, 31, 0x1D1254u);
    ctx->pc = 0x1D1250u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D124Cu;
            // 0x1d1250: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1254u; }
        if (ctx->pc != 0x1D1254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1254u; }
        if (ctx->pc != 0x1D1254u) { return; }
    }
    ctx->pc = 0x1D1254u;
label_1d1254:
    // 0x1d1254: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d1254u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d1258: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1258u;
    SET_GPR_U32(ctx, 31, 0x1D1260u);
    ctx->pc = 0x1D125Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1258u;
            // 0x1d125c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1260u; }
        if (ctx->pc != 0x1D1260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1260u; }
        if (ctx->pc != 0x1D1260u) { return; }
    }
    ctx->pc = 0x1D1260u;
label_1d1260:
    // 0x1d1260: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d1260u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d1264: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1264u;
    SET_GPR_U32(ctx, 31, 0x1D126Cu);
    ctx->pc = 0x1D1268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1264u;
            // 0x1d1268: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D126Cu; }
        if (ctx->pc != 0x1D126Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D126Cu; }
        if (ctx->pc != 0x1D126Cu) { return; }
    }
    ctx->pc = 0x1D126Cu;
label_1d126c:
    // 0x1d126c: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d126cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d1270: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1270u;
    SET_GPR_U32(ctx, 31, 0x1D1278u);
    ctx->pc = 0x1D1274u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1270u;
            // 0x1d1274: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1278u; }
        if (ctx->pc != 0x1D1278u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1278u; }
        if (ctx->pc != 0x1D1278u) { return; }
    }
    ctx->pc = 0x1D1278u;
label_1d1278:
    // 0x1d1278: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d1278u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d127c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D127Cu;
    SET_GPR_U32(ctx, 31, 0x1D1284u);
    ctx->pc = 0x1D1280u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D127Cu;
            // 0x1d1280: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1284u; }
        if (ctx->pc != 0x1D1284u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1284u; }
        if (ctx->pc != 0x1D1284u) { return; }
    }
    ctx->pc = 0x1D1284u;
label_1d1284:
    // 0x1d1284: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d1284u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d1288: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1288u;
    SET_GPR_U32(ctx, 31, 0x1D1290u);
    ctx->pc = 0x1D128Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1288u;
            // 0x1d128c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1290u; }
        if (ctx->pc != 0x1D1290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1290u; }
        if (ctx->pc != 0x1D1290u) { return; }
    }
    ctx->pc = 0x1D1290u;
label_1d1290:
    // 0x1d1290: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d1290u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d1294: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1294u;
    SET_GPR_U32(ctx, 31, 0x1D129Cu);
    ctx->pc = 0x1D1298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1294u;
            // 0x1d1298: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D129Cu; }
        if (ctx->pc != 0x1D129Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D129Cu; }
        if (ctx->pc != 0x1D129Cu) { return; }
    }
    ctx->pc = 0x1D129Cu;
label_1d129c:
    // 0x1d129c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d129cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d12a0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D12A0u;
    SET_GPR_U32(ctx, 31, 0x1D12A8u);
    ctx->pc = 0x1D12A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D12A0u;
            // 0x1d12a4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12A8u; }
        if (ctx->pc != 0x1D12A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12A8u; }
        if (ctx->pc != 0x1D12A8u) { return; }
    }
    ctx->pc = 0x1D12A8u;
label_1d12a8:
    // 0x1d12a8: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d12a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d12ac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d12acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d12b0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D12B0u;
    SET_GPR_U32(ctx, 31, 0x1D12B8u);
    ctx->pc = 0x1D12B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D12B0u;
            // 0x1d12b4: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12B8u; }
        if (ctx->pc != 0x1D12B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12B8u; }
        if (ctx->pc != 0x1D12B8u) { return; }
    }
    ctx->pc = 0x1D12B8u;
label_1d12b8:
    // 0x1d12b8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d12b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d12bc: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d12bcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d12c0: 0x943043da  lhu         $s0, 0x43DA($at)
    ctx->pc = 0x1d12c0u;
    SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d12c4: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d12c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d12c8: 0x24a56340  addiu       $a1, $a1, 0x6340
    ctx->pc = 0x1d12c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25408));
    // 0x1d12cc: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D12CCu;
    SET_GPR_U32(ctx, 31, 0x1D12D4u);
    ctx->pc = 0x1D12D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D12CCu;
            // 0x1d12d0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12D4u; }
        if (ctx->pc != 0x1D12D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12D4u; }
        if (ctx->pc != 0x1D12D4u) { return; }
    }
    ctx->pc = 0x1D12D4u;
label_1d12d4:
    // 0x1d12d4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d12d4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d12d8: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d12d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d12dc: 0x24a56350  addiu       $a1, $a1, 0x6350
    ctx->pc = 0x1d12dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25424));
    // 0x1d12e0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D12E0u;
    SET_GPR_U32(ctx, 31, 0x1D12E8u);
    ctx->pc = 0x1D12E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D12E0u;
            // 0x1d12e4: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12E8u; }
        if (ctx->pc != 0x1D12E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D12E8u; }
        if (ctx->pc != 0x1D12E8u) { return; }
    }
    ctx->pc = 0x1D12E8u;
label_1d12e8:
    // 0x1d12e8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d12e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d12ec: 0x3c02002f  lui         $v0, 0x2F
    ctx->pc = 0x1d12ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)47 << 16));
    // 0x1d12f0: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d12f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d12f4: 0x3442f000  ori         $v0, $v0, 0xF000
    ctx->pc = 0x1d12f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)61440);
    // 0x1d12f8: 0x24040200  addiu       $a0, $zero, 0x200
    ctx->pc = 0x1d12f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x1d12fc: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1d12fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1d1300: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D1300u;
    SET_GPR_U32(ctx, 31, 0x1D1308u);
    ctx->pc = 0x1D1304u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1300u;
            // 0x1d1304: 0x628821  addu        $s1, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1308u; }
        if (ctx->pc != 0x1D1308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1308u; }
        if (ctx->pc != 0x1D1308u) { return; }
    }
    ctx->pc = 0x1D1308u;
label_1d1308:
    // 0x1d1308: 0xae220808  sw          $v0, 0x808($s1)
    ctx->pc = 0x1d1308u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2056), GPR_U32(ctx, 2));
    // 0x1d130c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d130cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1310: 0xae200818  sw          $zero, 0x818($s1)
    ctx->pc = 0x1d1310u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2072), GPR_U32(ctx, 0));
    // 0x1d1314: 0x3c020030  lui         $v0, 0x30
    ctx->pc = 0x1d1314u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48 << 16));
    // 0x1d1318: 0x8c24440c  lw          $a0, 0x440C($at)
    ctx->pc = 0x1d1318u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d131c: 0x34431000  ori         $v1, $v0, 0x1000
    ctx->pc = 0x1d131cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4096);
    // 0x1d1320: 0x34421100  ori         $v0, $v0, 0x1100
    ctx->pc = 0x1d1320u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4352);
    // 0x1d1324: 0x839021  addu        $s2, $a0, $v1
    ctx->pc = 0x1d1324u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1d1328: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1328u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d132c: 0xae510018  sw          $s1, 0x18($s2)
    ctx->pc = 0x1d132cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 17));
    // 0x1d1330: 0xae400020  sw          $zero, 0x20($s2)
    ctx->pc = 0x1d1330u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 32), GPR_U32(ctx, 0));
    // 0x1d1334: 0xae400024  sw          $zero, 0x24($s2)
    ctx->pc = 0x1d1334u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 0));
    // 0x1d1338: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d1338u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d133c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1d133cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1d1340: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1340u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1344: 0xae42001c  sw          $v0, 0x1C($s2)
    ctx->pc = 0x1d1344u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 28), GPR_U32(ctx, 2));
    // 0x1d1348: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d1348u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d134c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D134Cu;
    {
        const bool branch_taken_0x1d134c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D1350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D134Cu;
            // 0x1d1350: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d134c) {
            ctx->pc = 0x1D1370u;
            goto label_1d1370;
        }
    }
    ctx->pc = 0x1D1354u;
    // 0x1d1354: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1d1354u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1358: 0x942443da  lhu         $a0, 0x43DA($at)
    ctx->pc = 0x1d1358u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d135c: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d135cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d1360: 0xc073844  jal         func_1CE110
    ctx->pc = 0x1D1360u;
    SET_GPR_U32(ctx, 31, 0x1D1368u);
    ctx->pc = 0x1D1364u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1360u;
            // 0x1d1364: 0x24070002  addiu       $a3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE110u;
    if (runtime->hasFunction(0x1CE110u)) {
        auto targetFn = runtime->lookupFunction(0x1CE110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1368u; }
        if (ctx->pc != 0x1D1368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE110_0x1ce110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1368u; }
        if (ctx->pc != 0x1D1368u) { return; }
    }
    ctx->pc = 0x1D1368u;
label_1d1368:
    // 0x1d1368: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1D1368u;
    {
        const bool branch_taken_0x1d1368 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D136Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1368u;
            // 0x1d136c: 0x8e45001c  lw          $a1, 0x1C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1368) {
            ctx->pc = 0x1D13A0u;
            goto label_1d13a0;
        }
    }
    ctx->pc = 0x1D1370u;
label_1d1370:
    // 0x1d1370: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d1370u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d1374: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d1374u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1378: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d1378u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d137c: 0x24062400  addiu       $a2, $zero, 0x2400
    ctx->pc = 0x1d137cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9216));
    // 0x1d1380: 0xc06aab4  jal         func_1AAAD0
    ctx->pc = 0x1D1380u;
    SET_GPR_U32(ctx, 31, 0x1D1388u);
    ctx->pc = 0x1D1384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1380u;
            // 0x1d1384: 0x34470002  ori         $a3, $v0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AAAD0u;
    if (runtime->hasFunction(0x1AAAD0u)) {
        auto targetFn = runtime->lookupFunction(0x1AAAD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1388u; }
        if (ctx->pc != 0x1D1388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AAAD0_0x1aaad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1388u; }
        if (ctx->pc != 0x1D1388u) { return; }
    }
    ctx->pc = 0x1D1388u;
label_1d1388:
    // 0x1d1388: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1388u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d138c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d138cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1390: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d1390u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d1394: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1394u;
    SET_GPR_U32(ctx, 31, 0x1D139Cu);
    ctx->pc = 0x1D1398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1394u;
            // 0x1d1398: 0x24a56370  addiu       $a1, $a1, 0x6370 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25456));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D139Cu; }
        if (ctx->pc != 0x1D139Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D139Cu; }
        if (ctx->pc != 0x1D139Cu) { return; }
    }
    ctx->pc = 0x1D139Cu;
label_1d139c:
    // 0x1d139c: 0x8e45001c  lw          $a1, 0x1C($s2)
    ctx->pc = 0x1d139cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
label_1d13a0:
    // 0x1d13a0: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d13a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d13a4: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1d13a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d13a8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d13a8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d13ac: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D13ACu;
    SET_GPR_U32(ctx, 31, 0x1D13B4u);
    ctx->pc = 0x1D13B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D13ACu;
            // 0x1d13b0: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D13B4u; }
        if (ctx->pc != 0x1D13B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D13B4u; }
        if (ctx->pc != 0x1D13B4u) { return; }
    }
    ctx->pc = 0x1D13B4u;
label_1d13b4:
    // 0x1d13b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d13b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d13b8: 0x3c030030  lui         $v1, 0x30
    ctx->pc = 0x1d13b8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)48 << 16));
    // 0x1d13bc: 0x8c24440c  lw          $a0, 0x440C($at)
    ctx->pc = 0x1d13bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d13c0: 0x34631500  ori         $v1, $v1, 0x1500
    ctx->pc = 0x1d13c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)5376);
    // 0x1d13c4: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1d13c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1d13c8: 0xae43001c  sw          $v1, 0x1C($s2)
    ctx->pc = 0x1d13c8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 28), GPR_U32(ctx, 3));
    // 0x1d13cc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d13ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d13d0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d13d0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d13d4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d13d4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d13d8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d13d8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d13dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D13DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D13E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D13DCu;
            // 0x1d13e0: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D123Cu: goto label_1d123c;
            case 0x1D1248u: goto label_1d1248;
            case 0x1D1254u: goto label_1d1254;
            case 0x1D1260u: goto label_1d1260;
            case 0x1D126Cu: goto label_1d126c;
            case 0x1D1278u: goto label_1d1278;
            case 0x1D1284u: goto label_1d1284;
            case 0x1D1290u: goto label_1d1290;
            case 0x1D129Cu: goto label_1d129c;
            case 0x1D12A8u: goto label_1d12a8;
            case 0x1D12B8u: goto label_1d12b8;
            case 0x1D12D4u: goto label_1d12d4;
            case 0x1D12E8u: goto label_1d12e8;
            case 0x1D1308u: goto label_1d1308;
            case 0x1D1368u: goto label_1d1368;
            case 0x1D1370u: goto label_1d1370;
            case 0x1D1388u: goto label_1d1388;
            case 0x1D139Cu: goto label_1d139c;
            case 0x1D13A0u: goto label_1d13a0;
            case 0x1D13B4u: goto label_1d13b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D13E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
