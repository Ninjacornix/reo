#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193ED0
// Address: 0x193ed0 - 0x194fd0
void sub_00193ED0_0x193ed0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193ED0_0x193ed0");
#endif

    switch (ctx->pc) {
        case 0x193fccu: goto label_193fcc;
        case 0x193fd8u: goto label_193fd8;
        case 0x194028u: goto label_194028;
        case 0x194038u: goto label_194038;
        case 0x194068u: goto label_194068;
        case 0x19410cu: goto label_19410c;
        case 0x19411cu: goto label_19411c;
        case 0x19414cu: goto label_19414c;
        case 0x1941f0u: goto label_1941f0;
        case 0x19424cu: goto label_19424c;
        case 0x194258u: goto label_194258;
        case 0x1942c8u: goto label_1942c8;
        case 0x1942d8u: goto label_1942d8;
        case 0x1943a0u: goto label_1943a0;
        case 0x1943c0u: goto label_1943c0;
        case 0x194458u: goto label_194458;
        case 0x1944acu: goto label_1944ac;
        case 0x1944b8u: goto label_1944b8;
        case 0x194508u: goto label_194508;
        case 0x194518u: goto label_194518;
        case 0x1945b0u: goto label_1945b0;
        case 0x1945c0u: goto label_1945c0;
        case 0x194658u: goto label_194658;
        case 0x194668u: goto label_194668;
        case 0x194700u: goto label_194700;
        case 0x194760u: goto label_194760;
        case 0x1947b4u: goto label_1947b4;
        case 0x1947dcu: goto label_1947dc;
        case 0x1947ecu: goto label_1947ec;
        case 0x19488cu: goto label_19488c;
        case 0x1948b4u: goto label_1948b4;
        case 0x1948c4u: goto label_1948c4;
        case 0x194964u: goto label_194964;
        case 0x19498cu: goto label_19498c;
        case 0x19499cu: goto label_19499c;
        case 0x194a34u: goto label_194a34;
        case 0x194a90u: goto label_194a90;
        case 0x194a9cu: goto label_194a9c;
        case 0x194aecu: goto label_194aec;
        case 0x194af8u: goto label_194af8;
        case 0x194b04u: goto label_194b04;
        case 0x194ba4u: goto label_194ba4;
        case 0x194bb0u: goto label_194bb0;
        case 0x194bbcu: goto label_194bbc;
        case 0x194c5cu: goto label_194c5c;
        case 0x194cb8u: goto label_194cb8;
        case 0x194cc4u: goto label_194cc4;
        case 0x194fb8u: goto label_194fb8;
        default: break;
    }

    ctx->pc = 0x193ed0u;

label_193ed0:
    // 0x193ed0: 0x24020fff  addiu       $v0, $zero, 0xFFF
    ctx->pc = 0x193ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4095));
    // 0x193ed4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x193ed4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x193ed8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x193ed8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x193edc: 0xc423fd54  lwc1        $f3, -0x2AC($at)
    ctx->pc = 0x193edcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x193ee0: 0x46800060  cvt.s.w     $f1, $f0
    ctx->pc = 0x193ee0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x193ee4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x193ee4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x193ee8: 0x46801820  cvt.s.w     $f0, $f3
    ctx->pc = 0x193ee8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x193eec: 0x46006300  add.s       $f12, $f12, $f0
    ctx->pc = 0x193eecu;
    ctx->f[12] = FPU_ADD_S(ctx->f[12], ctx->f[0]);
    // 0x193ef0: 0xc422fd58  lwc1        $f2, -0x2A8($at)
    ctx->pc = 0x193ef0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x193ef4: 0x460c0834  c.lt.s      $f1, $f12
    ctx->pc = 0x193ef4u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x193ef8: 0x46801020  cvt.s.w     $f0, $f2
    ctx->pc = 0x193ef8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x193efc: 0x45000003  bc1f        . + 4 + (0x3 << 2)
    ctx->pc = 0x193EFCu;
    {
        const bool branch_taken_0x193efc = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x193F00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193EFCu;
            // 0x193f00: 0x46006b40  add.s       $f13, $f13, $f0 (Delay Slot)
        ctx->f[13] = FPU_ADD_S(ctx->f[13], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x193efc) {
            ctx->pc = 0x193F0Cu;
            goto label_193f0c;
        }
    }
    ctx->pc = 0x193F04u;
    // 0x193f04: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x193F04u;
    {
        const bool branch_taken_0x193f04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x193F08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193F04u;
            // 0x193f08: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193f04) {
            ctx->pc = 0x193F7Cu;
            goto label_193f7c;
        }
    }
    ctx->pc = 0x193F0Cu;
label_193f0c:
    // 0x193f0c: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x193f0cu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x193f10: 0x0  nop
    ctx->pc = 0x193f10u;
    // NOP
    // 0x193f14: 0x460c0036  c.le.s      $f0, $f12
    ctx->pc = 0x193f14u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x193f18: 0x45010003  bc1t        . + 4 + (0x3 << 2)
    ctx->pc = 0x193F18u;
    {
        const bool branch_taken_0x193f18 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x193F1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193F18u;
            // 0x193f1c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193f18) {
            ctx->pc = 0x193F28u;
            goto label_193f28;
        }
    }
    ctx->pc = 0x193F20u;
    // 0x193f20: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x193F20u;
    {
        const bool branch_taken_0x193f20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x193f20) {
            ctx->pc = 0x193F7Cu;
            goto label_193f7c;
        }
    }
    ctx->pc = 0x193F28u;
label_193f28:
    // 0x193f28: 0x460d0834  c.lt.s      $f1, $f13
    ctx->pc = 0x193f28u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[13])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x193f2c: 0x45000003  bc1f        . + 4 + (0x3 << 2)
    ctx->pc = 0x193F2Cu;
    {
        const bool branch_taken_0x193f2c = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x193F30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193F2Cu;
            // 0x193f30: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193f2c) {
            ctx->pc = 0x193F3Cu;
            goto label_193f3c;
        }
    }
    ctx->pc = 0x193F34u;
    // 0x193f34: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x193F34u;
    {
        const bool branch_taken_0x193f34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x193f34) {
            ctx->pc = 0x193F7Cu;
            goto label_193f7c;
        }
    }
    ctx->pc = 0x193F3Cu;
label_193f3c:
    // 0x193f3c: 0x460d0036  c.le.s      $f0, $f13
    ctx->pc = 0x193f3cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[13])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x193f40: 0x45010003  bc1t        . + 4 + (0x3 << 2)
    ctx->pc = 0x193F40u;
    {
        const bool branch_taken_0x193f40 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x193F44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193F40u;
            // 0x193f44: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193f40) {
            ctx->pc = 0x193F50u;
            goto label_193f50;
        }
    }
    ctx->pc = 0x193F48u;
    // 0x193f48: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x193F48u;
    {
        const bool branch_taken_0x193f48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x193f48) {
            ctx->pc = 0x193F7Cu;
            goto label_193f7c;
        }
    }
    ctx->pc = 0x193F50u;
label_193f50:
    // 0x193f50: 0x46007034  c.lt.s      $f14, $f0
    ctx->pc = 0x193f50u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[14], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x193f54: 0x45000003  bc1f        . + 4 + (0x3 << 2)
    ctx->pc = 0x193F54u;
    {
        const bool branch_taken_0x193f54 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x193F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193F54u;
            // 0x193f58: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193f54) {
            ctx->pc = 0x193F64u;
            goto label_193f64;
        }
    }
    ctx->pc = 0x193F5Cu;
    // 0x193f5c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x193F5Cu;
    {
        const bool branch_taken_0x193f5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x193F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193F5Cu;
            // 0x193f60: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193f5c) {
            ctx->pc = 0x193F7Cu;
            goto label_193f7c;
        }
    }
    ctx->pc = 0x193F64u;
label_193f64:
    // 0x193f64: 0xc420f9f4  lwc1        $f0, -0x60C($at)
    ctx->pc = 0x193f64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193f68: 0x460e0034  c.lt.s      $f0, $f14
    ctx->pc = 0x193f68u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[0], ctx->f[14])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x193f6c: 0x45010002  bc1t        . + 4 + (0x2 << 2)
    ctx->pc = 0x193F6Cu;
    {
        const bool branch_taken_0x193f6c = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x193F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193F6Cu;
            // 0x193f70: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193f6c) {
            ctx->pc = 0x193F78u;
            goto label_193f78;
        }
    }
    ctx->pc = 0x193F74u;
    // 0x193f74: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x193f74u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_193f78:
    // 0x193f78: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x193f78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
label_193f7c:
    // 0x193f7c: 0x3e00008  jr          $ra
    ctx->pc = 0x193F7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193ED0u: goto label_193ed0;
            case 0x193F0Cu: goto label_193f0c;
            case 0x193F28u: goto label_193f28;
            case 0x193F3Cu: goto label_193f3c;
            case 0x193F50u: goto label_193f50;
            case 0x193F64u: goto label_193f64;
            case 0x193F78u: goto label_193f78;
            case 0x193F7Cu: goto label_193f7c;
            case 0x193FB8u: goto label_193fb8;
            case 0x193FCCu: goto label_193fcc;
            case 0x193FD8u: goto label_193fd8;
            case 0x194028u: goto label_194028;
            case 0x194038u: goto label_194038;
            case 0x194068u: goto label_194068;
            case 0x194078u: goto label_194078;
            case 0x1940D4u: goto label_1940d4;
            case 0x1940F0u: goto label_1940f0;
            case 0x19410Cu: goto label_19410c;
            case 0x19411Cu: goto label_19411c;
            case 0x19414Cu: goto label_19414c;
            case 0x19415Cu: goto label_19415c;
            case 0x1941B8u: goto label_1941b8;
            case 0x1941D4u: goto label_1941d4;
            case 0x1941F0u: goto label_1941f0;
            case 0x1941F4u: goto label_1941f4;
            case 0x194238u: goto label_194238;
            case 0x19424Cu: goto label_19424c;
            case 0x194258u: goto label_194258;
            case 0x1942C8u: goto label_1942c8;
            case 0x1942D8u: goto label_1942d8;
            case 0x194338u: goto label_194338;
            case 0x194354u: goto label_194354;
            case 0x1943A0u: goto label_1943a0;
            case 0x1943C0u: goto label_1943c0;
            case 0x194420u: goto label_194420;
            case 0x19443Cu: goto label_19443c;
            case 0x194458u: goto label_194458;
            case 0x19445Cu: goto label_19445c;
            case 0x194498u: goto label_194498;
            case 0x1944ACu: goto label_1944ac;
            case 0x1944B8u: goto label_1944b8;
            case 0x194508u: goto label_194508;
            case 0x194518u: goto label_194518;
            case 0x194578u: goto label_194578;
            case 0x194594u: goto label_194594;
            case 0x1945B0u: goto label_1945b0;
            case 0x1945C0u: goto label_1945c0;
            case 0x194620u: goto label_194620;
            case 0x19463Cu: goto label_19463c;
            case 0x194658u: goto label_194658;
            case 0x194668u: goto label_194668;
            case 0x1946C8u: goto label_1946c8;
            case 0x1946E4u: goto label_1946e4;
            case 0x194700u: goto label_194700;
            case 0x194704u: goto label_194704;
            case 0x19474Cu: goto label_19474c;
            case 0x194760u: goto label_194760;
            case 0x1947B4u: goto label_1947b4;
            case 0x1947DCu: goto label_1947dc;
            case 0x1947ECu: goto label_1947ec;
            case 0x19484Cu: goto label_19484c;
            case 0x194868u: goto label_194868;
            case 0x19488Cu: goto label_19488c;
            case 0x1948B4u: goto label_1948b4;
            case 0x1948C4u: goto label_1948c4;
            case 0x194924u: goto label_194924;
            case 0x194940u: goto label_194940;
            case 0x194964u: goto label_194964;
            case 0x19498Cu: goto label_19498c;
            case 0x19499Cu: goto label_19499c;
            case 0x1949FCu: goto label_1949fc;
            case 0x194A18u: goto label_194a18;
            case 0x194A34u: goto label_194a34;
            case 0x194A38u: goto label_194a38;
            case 0x194A7Cu: goto label_194a7c;
            case 0x194A90u: goto label_194a90;
            case 0x194A9Cu: goto label_194a9c;
            case 0x194AECu: goto label_194aec;
            case 0x194AF8u: goto label_194af8;
            case 0x194B04u: goto label_194b04;
            case 0x194B6Cu: goto label_194b6c;
            case 0x194B88u: goto label_194b88;
            case 0x194BA4u: goto label_194ba4;
            case 0x194BB0u: goto label_194bb0;
            case 0x194BBCu: goto label_194bbc;
            case 0x194C24u: goto label_194c24;
            case 0x194C40u: goto label_194c40;
            case 0x194C5Cu: goto label_194c5c;
            case 0x194C60u: goto label_194c60;
            case 0x194CA4u: goto label_194ca4;
            case 0x194CB8u: goto label_194cb8;
            case 0x194CC4u: goto label_194cc4;
            case 0x194D8Cu: goto label_194d8c;
            case 0x194DA0u: goto label_194da0;
            case 0x194E2Cu: goto label_194e2c;
            case 0x194E48u: goto label_194e48;
            case 0x194EDCu: goto label_194edc;
            case 0x194EF0u: goto label_194ef0;
            case 0x194F80u: goto label_194f80;
            case 0x194F9Cu: goto label_194f9c;
            case 0x194FB8u: goto label_194fb8;
            case 0x194FBCu: goto label_194fbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x193F84u;
    // 0x193f84: 0x0  nop
    ctx->pc = 0x193f84u;
    // NOP
    // 0x193f88: 0x0  nop
    ctx->pc = 0x193f88u;
    // NOP
    // 0x193f8c: 0x0  nop
    ctx->pc = 0x193f8cu;
    // NOP
    // 0x193f90: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x193f90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x193f94: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x193f94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x193f98: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x193f98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x193f9c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x193f9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x193fa0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x193fa0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x193fa4: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x193fa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x193fa8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x193FA8u;
    {
        const bool branch_taken_0x193fa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x193FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193FA8u;
            // 0x193fac: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193fa8) {
            ctx->pc = 0x193FB8u;
            goto label_193fb8;
        }
    }
    ctx->pc = 0x193FB0u;
    // 0x193fb0: 0x10000090  b           . + 4 + (0x90 << 2)
    ctx->pc = 0x193FB0u;
    {
        const bool branch_taken_0x193fb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x193FB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193FB0u;
            // 0x193fb4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193fb0) {
            ctx->pc = 0x1941F4u;
            goto label_1941f4;
        }
    }
    ctx->pc = 0x193FB8u;
label_193fb8:
    // 0x193fb8: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x193fb8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x193fbc: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x193fbcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x193fc0: 0x2484fe50  addiu       $a0, $a0, -0x1B0
    ctx->pc = 0x193fc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966864));
    // 0x193fc4: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x193FC4u;
    SET_GPR_U32(ctx, 31, 0x193FCCu);
    ctx->pc = 0x193FC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193FC4u;
            // 0x193fc8: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193FCCu; }
        if (ctx->pc != 0x193FCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193FCCu; }
        if (ctx->pc != 0x193FCCu) { return; }
    }
    ctx->pc = 0x193FCCu;
label_193fcc:
    // 0x193fcc: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x193fccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x193fd0: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x193FD0u;
    SET_GPR_U32(ctx, 31, 0x193FD8u);
    ctx->pc = 0x193FD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193FD0u;
            // 0x193fd4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193FD8u; }
        if (ctx->pc != 0x193FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193FD8u; }
        if (ctx->pc != 0x193FD8u) { return; }
    }
    ctx->pc = 0x193FD8u;
label_193fd8:
    // 0x193fd8: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x193fd8u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x193fdc: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x193fdcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x193fe0: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x193fe0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x193fe4: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x193fe4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x193fe8: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x193fe8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x193fec: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x193fecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x193ff0: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x193ff0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x193ff4: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x193ff4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x193ff8: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x193ff8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x193ffc: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x193ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x194000: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x194000u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194004: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194004u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194008: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194008u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19400c: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x19400cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x194010: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194010u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194014: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x194014u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194018: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x194018u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x19401c: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x19401cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x194020: 0xc06629c  jal         func_198A70
    ctx->pc = 0x194020u;
    SET_GPR_U32(ctx, 31, 0x194028u);
    ctx->pc = 0x194024u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194020u;
            // 0x194024: 0x86040000  lh          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194028u; }
        if (ctx->pc != 0x194028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194028u; }
        if (ctx->pc != 0x194028u) { return; }
    }
    ctx->pc = 0x194028u;
label_194028:
    // 0x194028: 0x86040002  lh          $a0, 0x2($s0)
    ctx->pc = 0x194028u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x19402c: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x19402cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194030: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x194030u;
    SET_GPR_U32(ctx, 31, 0x194038u);
    ctx->pc = 0x194034u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194030u;
            // 0x194034: 0x118c3f  dsra32      $s1, $s1, 16 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194038u; }
        if (ctx->pc != 0x194038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194038u; }
        if (ctx->pc != 0x194038u) { return; }
    }
    ctx->pc = 0x194038u;
label_194038:
    // 0x194038: 0x21c3c  dsll32      $v1, $v0, 16
    ctx->pc = 0x194038u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 16));
    // 0x19403c: 0x11143c  dsll32      $v0, $s1, 16
    ctx->pc = 0x19403cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << (32 + 16));
    // 0x194040: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x194040u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x194044: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x194044u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x194048: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194048u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19404c: 0x0  nop
    ctx->pc = 0x19404cu;
    // NOP
    // 0x194050: 0x46800320  cvt.s.w     $f12, $f0
    ctx->pc = 0x194050u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[12] = FPU_CVT_S_W(tmp); }
    // 0x194054: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x194054u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x194058: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x194058u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19405c: 0x44827000  mtc1        $v0, $f14
    ctx->pc = 0x19405cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[14], &bits, sizeof(bits)); }
    // 0x194060: 0xc064fb4  jal         func_193ED0
    ctx->pc = 0x194060u;
    SET_GPR_U32(ctx, 31, 0x194068u);
    ctx->pc = 0x194064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194060u;
            // 0x194064: 0x46800360  cvt.s.w     $f13, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[13] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x193ED0u;
    goto label_193ed0;
    ctx->pc = 0x194068u;
label_194068:
    // 0x194068: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x194068u;
    {
        const bool branch_taken_0x194068 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19406Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194068u;
            // 0x19406c: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194068) {
            ctx->pc = 0x194078u;
            goto label_194078;
        }
    }
    ctx->pc = 0x194070u;
    // 0x194070: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x194070u;
    {
        const bool branch_taken_0x194070 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194070u;
            // 0x194074: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194070) {
            ctx->pc = 0x1941F4u;
            goto label_1941f4;
        }
    }
    ctx->pc = 0x194078u;
label_194078:
    // 0x194078: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194078u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x19407c: 0x8c24fd54  lw          $a0, -0x2AC($at)
    ctx->pc = 0x19407cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x194080: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x194080u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x194084: 0x112c3c  dsll32      $a1, $s1, 16
    ctx->pc = 0x194084u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 17) << (32 + 16));
    // 0x194088: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x194088u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x19408c: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x19408cu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x194090: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194090u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194094: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194094u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194098: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x194098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x19409c: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x19409cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1940a0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1940a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1940a4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1940a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1940a8: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1940a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1940ac: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1940acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1940b0: 0x41900  sll         $v1, $a0, 4
    ctx->pc = 0x1940b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1940b4: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1940b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1940b8: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1940b8u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1940bc: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1940BCu;
    {
        const bool branch_taken_0x1940bc = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1940C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1940BCu;
            // 0x1940c0: 0x622025  or          $a0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1940bc) {
            ctx->pc = 0x1940D4u;
            goto label_1940d4;
        }
    }
    ctx->pc = 0x1940C4u;
    // 0x1940c4: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1940c4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1940c8: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1940c8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1940cc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1940CCu;
    {
        const bool branch_taken_0x1940cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1940D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1940CCu;
            // 0x1940d0: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1940cc) {
            ctx->pc = 0x1940F0u;
            goto label_1940f0;
        }
    }
    ctx->pc = 0x1940D4u;
label_1940d4:
    // 0x1940d4: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1940d4u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1940d8: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1940d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1940dc: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1940dcu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1940e0: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1940e0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1940e4: 0x0  nop
    ctx->pc = 0x1940e4u;
    // NOP
    // 0x1940e8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1940e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1940ec: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1940ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1940f0:
    // 0x1940f0: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1940f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1940f4: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1940f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1940f8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1940f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1940fc: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x1940fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x194100: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x194100u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x194104: 0xc06629c  jal         func_198A70
    ctx->pc = 0x194104u;
    SET_GPR_U32(ctx, 31, 0x19410Cu);
    ctx->pc = 0x194108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194104u;
            // 0x194108: 0x86040004  lh          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19410Cu; }
        if (ctx->pc != 0x19410Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19410Cu; }
        if (ctx->pc != 0x19410Cu) { return; }
    }
    ctx->pc = 0x19410Cu;
label_19410c:
    // 0x19410c: 0x86040006  lh          $a0, 0x6($s0)
    ctx->pc = 0x19410cu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x194110: 0x2843c  dsll32      $s0, $v0, 16
    ctx->pc = 0x194110u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194114: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x194114u;
    SET_GPR_U32(ctx, 31, 0x19411Cu);
    ctx->pc = 0x194118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194114u;
            // 0x194118: 0x10843f  dsra32      $s0, $s0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19411Cu; }
        if (ctx->pc != 0x19411Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19411Cu; }
        if (ctx->pc != 0x19411Cu) { return; }
    }
    ctx->pc = 0x19411Cu;
label_19411c:
    // 0x19411c: 0x21c3c  dsll32      $v1, $v0, 16
    ctx->pc = 0x19411cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194120: 0x10143c  dsll32      $v0, $s0, 16
    ctx->pc = 0x194120u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) << (32 + 16));
    // 0x194124: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x194124u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x194128: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x194128u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x19412c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x19412cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194130: 0x0  nop
    ctx->pc = 0x194130u;
    // NOP
    // 0x194134: 0x46800320  cvt.s.w     $f12, $f0
    ctx->pc = 0x194134u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[12] = FPU_CVT_S_W(tmp); }
    // 0x194138: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x194138u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x19413c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19413cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194140: 0x44827000  mtc1        $v0, $f14
    ctx->pc = 0x194140u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[14], &bits, sizeof(bits)); }
    // 0x194144: 0xc064fb4  jal         func_193ED0
    ctx->pc = 0x194144u;
    SET_GPR_U32(ctx, 31, 0x19414Cu);
    ctx->pc = 0x194148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194144u;
            // 0x194148: 0x46800360  cvt.s.w     $f13, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[13] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x193ED0u;
    goto label_193ed0;
    ctx->pc = 0x19414Cu;
label_19414c:
    // 0x19414c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19414Cu;
    {
        const bool branch_taken_0x19414c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x194150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19414Cu;
            // 0x194150: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19414c) {
            ctx->pc = 0x19415Cu;
            goto label_19415c;
        }
    }
    ctx->pc = 0x194154u;
    // 0x194154: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x194154u;
    {
        const bool branch_taken_0x194154 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194154u;
            // 0x194158: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194154) {
            ctx->pc = 0x1941F4u;
            goto label_1941f4;
        }
    }
    ctx->pc = 0x19415Cu;
label_19415c:
    // 0x19415c: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x19415cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194160: 0x8c24fd54  lw          $a0, -0x2AC($at)
    ctx->pc = 0x194160u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x194164: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x194164u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x194168: 0x102c3c  dsll32      $a1, $s0, 16
    ctx->pc = 0x194168u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) << (32 + 16));
    // 0x19416c: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x19416cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x194170: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x194170u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x194174: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194174u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194178: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194178u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19417c: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x19417cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x194180: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x194180u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x194184: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194184u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194188: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x194188u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x19418c: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x19418cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194190: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194190u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194194: 0x41900  sll         $v1, $a0, 4
    ctx->pc = 0x194194u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x194198: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194198u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x19419c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x19419cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1941a0: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1941A0u;
    {
        const bool branch_taken_0x1941a0 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1941A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1941A0u;
            // 0x1941a4: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1941a0) {
            ctx->pc = 0x1941B8u;
            goto label_1941b8;
        }
    }
    ctx->pc = 0x1941A8u;
    // 0x1941a8: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1941a8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1941ac: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1941acu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1941b0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1941B0u;
    {
        const bool branch_taken_0x1941b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1941B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1941B0u;
            // 0x1941b4: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1941b0) {
            ctx->pc = 0x1941D4u;
            goto label_1941d4;
        }
    }
    ctx->pc = 0x1941B8u;
label_1941b8:
    // 0x1941b8: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1941b8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1941bc: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1941bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1941c0: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1941c0u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1941c4: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1941c4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1941c8: 0x0  nop
    ctx->pc = 0x1941c8u;
    // NOP
    // 0x1941cc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1941ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1941d0: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1941d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1941d4:
    // 0x1941d4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1941d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1941d8: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1941d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1941dc: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1941dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1941e0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1941e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1941e4: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x1941e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x1941e8: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1941E8u;
    SET_GPR_U32(ctx, 31, 0x1941F0u);
    ctx->pc = 0x1941ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1941E8u;
            // 0x1941ec: 0xfc220038  sd          $v0, 0x38($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1941F0u; }
        if (ctx->pc != 0x1941F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1941F0u; }
        if (ctx->pc != 0x1941F0u) { return; }
    }
    ctx->pc = 0x1941F0u;
label_1941f0:
    // 0x1941f0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1941f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1941f4:
    // 0x1941f4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1941f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1941f8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1941f8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1941fc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1941fcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x194200: 0x3e00008  jr          $ra
    ctx->pc = 0x194200u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x194204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194200u;
            // 0x194204: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193ED0u: goto label_193ed0;
            case 0x193F0Cu: goto label_193f0c;
            case 0x193F28u: goto label_193f28;
            case 0x193F3Cu: goto label_193f3c;
            case 0x193F50u: goto label_193f50;
            case 0x193F64u: goto label_193f64;
            case 0x193F78u: goto label_193f78;
            case 0x193F7Cu: goto label_193f7c;
            case 0x193FB8u: goto label_193fb8;
            case 0x193FCCu: goto label_193fcc;
            case 0x193FD8u: goto label_193fd8;
            case 0x194028u: goto label_194028;
            case 0x194038u: goto label_194038;
            case 0x194068u: goto label_194068;
            case 0x194078u: goto label_194078;
            case 0x1940D4u: goto label_1940d4;
            case 0x1940F0u: goto label_1940f0;
            case 0x19410Cu: goto label_19410c;
            case 0x19411Cu: goto label_19411c;
            case 0x19414Cu: goto label_19414c;
            case 0x19415Cu: goto label_19415c;
            case 0x1941B8u: goto label_1941b8;
            case 0x1941D4u: goto label_1941d4;
            case 0x1941F0u: goto label_1941f0;
            case 0x1941F4u: goto label_1941f4;
            case 0x194238u: goto label_194238;
            case 0x19424Cu: goto label_19424c;
            case 0x194258u: goto label_194258;
            case 0x1942C8u: goto label_1942c8;
            case 0x1942D8u: goto label_1942d8;
            case 0x194338u: goto label_194338;
            case 0x194354u: goto label_194354;
            case 0x1943A0u: goto label_1943a0;
            case 0x1943C0u: goto label_1943c0;
            case 0x194420u: goto label_194420;
            case 0x19443Cu: goto label_19443c;
            case 0x194458u: goto label_194458;
            case 0x19445Cu: goto label_19445c;
            case 0x194498u: goto label_194498;
            case 0x1944ACu: goto label_1944ac;
            case 0x1944B8u: goto label_1944b8;
            case 0x194508u: goto label_194508;
            case 0x194518u: goto label_194518;
            case 0x194578u: goto label_194578;
            case 0x194594u: goto label_194594;
            case 0x1945B0u: goto label_1945b0;
            case 0x1945C0u: goto label_1945c0;
            case 0x194620u: goto label_194620;
            case 0x19463Cu: goto label_19463c;
            case 0x194658u: goto label_194658;
            case 0x194668u: goto label_194668;
            case 0x1946C8u: goto label_1946c8;
            case 0x1946E4u: goto label_1946e4;
            case 0x194700u: goto label_194700;
            case 0x194704u: goto label_194704;
            case 0x19474Cu: goto label_19474c;
            case 0x194760u: goto label_194760;
            case 0x1947B4u: goto label_1947b4;
            case 0x1947DCu: goto label_1947dc;
            case 0x1947ECu: goto label_1947ec;
            case 0x19484Cu: goto label_19484c;
            case 0x194868u: goto label_194868;
            case 0x19488Cu: goto label_19488c;
            case 0x1948B4u: goto label_1948b4;
            case 0x1948C4u: goto label_1948c4;
            case 0x194924u: goto label_194924;
            case 0x194940u: goto label_194940;
            case 0x194964u: goto label_194964;
            case 0x19498Cu: goto label_19498c;
            case 0x19499Cu: goto label_19499c;
            case 0x1949FCu: goto label_1949fc;
            case 0x194A18u: goto label_194a18;
            case 0x194A34u: goto label_194a34;
            case 0x194A38u: goto label_194a38;
            case 0x194A7Cu: goto label_194a7c;
            case 0x194A90u: goto label_194a90;
            case 0x194A9Cu: goto label_194a9c;
            case 0x194AECu: goto label_194aec;
            case 0x194AF8u: goto label_194af8;
            case 0x194B04u: goto label_194b04;
            case 0x194B6Cu: goto label_194b6c;
            case 0x194B88u: goto label_194b88;
            case 0x194BA4u: goto label_194ba4;
            case 0x194BB0u: goto label_194bb0;
            case 0x194BBCu: goto label_194bbc;
            case 0x194C24u: goto label_194c24;
            case 0x194C40u: goto label_194c40;
            case 0x194C5Cu: goto label_194c5c;
            case 0x194C60u: goto label_194c60;
            case 0x194CA4u: goto label_194ca4;
            case 0x194CB8u: goto label_194cb8;
            case 0x194CC4u: goto label_194cc4;
            case 0x194D8Cu: goto label_194d8c;
            case 0x194DA0u: goto label_194da0;
            case 0x194E2Cu: goto label_194e2c;
            case 0x194E48u: goto label_194e48;
            case 0x194EDCu: goto label_194edc;
            case 0x194EF0u: goto label_194ef0;
            case 0x194F80u: goto label_194f80;
            case 0x194F9Cu: goto label_194f9c;
            case 0x194FB8u: goto label_194fb8;
            case 0x194FBCu: goto label_194fbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x194208u;
    // 0x194208: 0x0  nop
    ctx->pc = 0x194208u;
    // NOP
    // 0x19420c: 0x0  nop
    ctx->pc = 0x19420cu;
    // NOP
    // 0x194210: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x194210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x194214: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194214u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194218: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x194218u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x19421c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19421cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x194220: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x194220u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x194224: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x194224u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x194228: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x194228u;
    {
        const bool branch_taken_0x194228 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19422Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194228u;
            // 0x19422c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194228) {
            ctx->pc = 0x194238u;
            goto label_194238;
        }
    }
    ctx->pc = 0x194230u;
    // 0x194230: 0x1000008a  b           . + 4 + (0x8A << 2)
    ctx->pc = 0x194230u;
    {
        const bool branch_taken_0x194230 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194230u;
            // 0x194234: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194230) {
            ctx->pc = 0x19445Cu;
            goto label_19445c;
        }
    }
    ctx->pc = 0x194238u;
label_194238:
    // 0x194238: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x194238u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x19423c: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x19423cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x194240: 0x2484fe90  addiu       $a0, $a0, -0x170
    ctx->pc = 0x194240u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966928));
    // 0x194244: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x194244u;
    SET_GPR_U32(ctx, 31, 0x19424Cu);
    ctx->pc = 0x194248u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194244u;
            // 0x194248: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19424Cu; }
        if (ctx->pc != 0x19424Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19424Cu; }
        if (ctx->pc != 0x19424Cu) { return; }
    }
    ctx->pc = 0x19424Cu;
label_19424c:
    // 0x19424c: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x19424cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x194250: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x194250u;
    SET_GPR_U32(ctx, 31, 0x194258u);
    ctx->pc = 0x194254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194250u;
            // 0x194254: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194258u; }
        if (ctx->pc != 0x194258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194258u; }
        if (ctx->pc != 0x194258u) { return; }
    }
    ctx->pc = 0x194258u;
label_194258:
    // 0x194258: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x194258u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x19425c: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x19425cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x194260: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x194260u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x194264: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x194264u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x194268: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x194268u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x19426c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19426cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194270: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194270u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194274: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x194274u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x194278: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x194278u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x19427c: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x19427cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x194280: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x194280u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194284: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194284u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194288: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194288u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19428c: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x19428cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x194290: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194290u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194294: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x194294u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194298: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x194298u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x19429c: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x19429cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x1942a0: 0x8602000e  lh          $v0, 0xE($s0)
    ctx->pc = 0x1942a0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x1942a4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1942a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1942a8: 0x8603000c  lh          $v1, 0xC($s0)
    ctx->pc = 0x1942a8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1942ac: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1942acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1942b0: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1942b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1942b4: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1942b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1942b8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1942b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1942bc: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x1942bcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x1942c0: 0xc06629c  jal         func_198A70
    ctx->pc = 0x1942C0u;
    SET_GPR_U32(ctx, 31, 0x1942C8u);
    ctx->pc = 0x1942C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1942C0u;
            // 0x1942c4: 0x86040000  lh          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1942C8u; }
        if (ctx->pc != 0x1942C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1942C8u; }
        if (ctx->pc != 0x1942C8u) { return; }
    }
    ctx->pc = 0x1942C8u;
label_1942c8:
    // 0x1942c8: 0x86040002  lh          $a0, 0x2($s0)
    ctx->pc = 0x1942c8u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1942cc: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1942ccu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1942d0: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x1942D0u;
    SET_GPR_U32(ctx, 31, 0x1942D8u);
    ctx->pc = 0x1942D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1942D0u;
            // 0x1942d4: 0x118c3f  dsra32      $s1, $s1, 16 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1942D8u; }
        if (ctx->pc != 0x1942D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1942D8u; }
        if (ctx->pc != 0x1942D8u) { return; }
    }
    ctx->pc = 0x1942D8u;
label_1942d8:
    // 0x1942d8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1942d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1942dc: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1942dcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1942e0: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1942e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1942e4: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1942e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1942e8: 0x11243c  dsll32      $a0, $s1, 16
    ctx->pc = 0x1942e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << (32 + 16));
    // 0x1942ec: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1942ecu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1942f0: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1942f0u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1942f4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1942f4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1942f8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1942f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1942fc: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1942fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x194300: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x194300u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x194304: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x194304u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x194308: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194308u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19430c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x19430cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x194310: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x194310u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194314: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194314u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194318: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194318u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x19431c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x19431cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194320: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194320u;
    {
        const bool branch_taken_0x194320 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194320u;
            // 0x194324: 0x622025  or          $a0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194320) {
            ctx->pc = 0x194338u;
            goto label_194338;
        }
    }
    ctx->pc = 0x194328u;
    // 0x194328: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194328u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x19432c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x19432cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194330: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194330u;
    {
        const bool branch_taken_0x194330 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194330u;
            // 0x194334: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194330) {
            ctx->pc = 0x194354u;
            goto label_194354;
        }
    }
    ctx->pc = 0x194338u;
label_194338:
    // 0x194338: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194338u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x19433c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x19433cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194340: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194340u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194344: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194344u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194348: 0x0  nop
    ctx->pc = 0x194348u;
    // NOP
    // 0x19434c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x19434cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194350: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194350u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194354:
    // 0x194354: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194354u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194358: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194358u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x19435c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x19435cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194360: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x194360u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x194364: 0xfc220038  sd          $v0, 0x38($at)
    ctx->pc = 0x194364u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
    // 0x194368: 0x86020012  lh          $v0, 0x12($s0)
    ctx->pc = 0x194368u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 18)));
    // 0x19436c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19436cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194370: 0x86030010  lh          $v1, 0x10($s0)
    ctx->pc = 0x194370u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x194374: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194374u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194378: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x194378u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x19437c: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x19437cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194380: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x194380u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194384: 0xfc220040  sd          $v0, 0x40($at)
    ctx->pc = 0x194384u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
    // 0x194388: 0x86030000  lh          $v1, 0x0($s0)
    ctx->pc = 0x194388u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x19438c: 0x86020004  lh          $v0, 0x4($s0)
    ctx->pc = 0x19438cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x194390: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x194390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x194394: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x194394u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194398: 0xc06629c  jal         func_198A70
    ctx->pc = 0x194398u;
    SET_GPR_U32(ctx, 31, 0x1943A0u);
    ctx->pc = 0x19439Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194398u;
            // 0x19439c: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1943A0u; }
        if (ctx->pc != 0x1943A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1943A0u; }
        if (ctx->pc != 0x1943A0u) { return; }
    }
    ctx->pc = 0x1943A0u;
label_1943a0:
    // 0x1943a0: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1943a0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1943a4: 0x86030002  lh          $v1, 0x2($s0)
    ctx->pc = 0x1943a4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1943a8: 0x86020006  lh          $v0, 0x6($s0)
    ctx->pc = 0x1943a8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x1943ac: 0x118c3f  dsra32      $s1, $s1, 16
    ctx->pc = 0x1943acu;
    SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
    // 0x1943b0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1943b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1943b4: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1943b4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1943b8: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x1943B8u;
    SET_GPR_U32(ctx, 31, 0x1943C0u);
    ctx->pc = 0x1943BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1943B8u;
            // 0x1943bc: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1943C0u; }
        if (ctx->pc != 0x1943C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1943C0u; }
        if (ctx->pc != 0x1943C0u) { return; }
    }
    ctx->pc = 0x1943C0u;
label_1943c0:
    // 0x1943c0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1943c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1943c4: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1943c4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1943c8: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1943c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1943cc: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1943ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1943d0: 0x11243c  dsll32      $a0, $s1, 16
    ctx->pc = 0x1943d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << (32 + 16));
    // 0x1943d4: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1943d4u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1943d8: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1943d8u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1943dc: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1943dcu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1943e0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1943e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1943e4: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1943e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1943e8: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x1943e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1943ec: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1943ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1943f0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1943f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1943f4: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1943f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1943f8: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1943f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1943fc: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1943fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194400: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194400u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194404: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x194404u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194408: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194408u;
    {
        const bool branch_taken_0x194408 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x19440Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194408u;
            // 0x19440c: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194408) {
            ctx->pc = 0x194420u;
            goto label_194420;
        }
    }
    ctx->pc = 0x194410u;
    // 0x194410: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194410u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194414: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194414u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194418: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194418u;
    {
        const bool branch_taken_0x194418 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19441Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194418u;
            // 0x19441c: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194418) {
            ctx->pc = 0x19443Cu;
            goto label_19443c;
        }
    }
    ctx->pc = 0x194420u;
label_194420:
    // 0x194420: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194420u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194424: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194424u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194428: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194428u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x19442c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x19442cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194430: 0x0  nop
    ctx->pc = 0x194430u;
    // NOP
    // 0x194434: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194434u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194438: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194438u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_19443c:
    // 0x19443c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19443cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194440: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194440u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194444: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x194444u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x194448: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194448u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x19444c: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x19444cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x194450: 0xc064f88  jal         func_193E20
    ctx->pc = 0x194450u;
    SET_GPR_U32(ctx, 31, 0x194458u);
    ctx->pc = 0x194454u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194450u;
            // 0x194454: 0xfc220048  sd          $v0, 0x48($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 72), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194458u; }
        if (ctx->pc != 0x194458u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194458u; }
        if (ctx->pc != 0x194458u) { return; }
    }
    ctx->pc = 0x194458u;
label_194458:
    // 0x194458: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194458u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_19445c:
    // 0x19445c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x19445cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x194460: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x194460u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x194464: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x194464u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x194468: 0x3e00008  jr          $ra
    ctx->pc = 0x194468u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19446Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194468u;
            // 0x19446c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193ED0u: goto label_193ed0;
            case 0x193F0Cu: goto label_193f0c;
            case 0x193F28u: goto label_193f28;
            case 0x193F3Cu: goto label_193f3c;
            case 0x193F50u: goto label_193f50;
            case 0x193F64u: goto label_193f64;
            case 0x193F78u: goto label_193f78;
            case 0x193F7Cu: goto label_193f7c;
            case 0x193FB8u: goto label_193fb8;
            case 0x193FCCu: goto label_193fcc;
            case 0x193FD8u: goto label_193fd8;
            case 0x194028u: goto label_194028;
            case 0x194038u: goto label_194038;
            case 0x194068u: goto label_194068;
            case 0x194078u: goto label_194078;
            case 0x1940D4u: goto label_1940d4;
            case 0x1940F0u: goto label_1940f0;
            case 0x19410Cu: goto label_19410c;
            case 0x19411Cu: goto label_19411c;
            case 0x19414Cu: goto label_19414c;
            case 0x19415Cu: goto label_19415c;
            case 0x1941B8u: goto label_1941b8;
            case 0x1941D4u: goto label_1941d4;
            case 0x1941F0u: goto label_1941f0;
            case 0x1941F4u: goto label_1941f4;
            case 0x194238u: goto label_194238;
            case 0x19424Cu: goto label_19424c;
            case 0x194258u: goto label_194258;
            case 0x1942C8u: goto label_1942c8;
            case 0x1942D8u: goto label_1942d8;
            case 0x194338u: goto label_194338;
            case 0x194354u: goto label_194354;
            case 0x1943A0u: goto label_1943a0;
            case 0x1943C0u: goto label_1943c0;
            case 0x194420u: goto label_194420;
            case 0x19443Cu: goto label_19443c;
            case 0x194458u: goto label_194458;
            case 0x19445Cu: goto label_19445c;
            case 0x194498u: goto label_194498;
            case 0x1944ACu: goto label_1944ac;
            case 0x1944B8u: goto label_1944b8;
            case 0x194508u: goto label_194508;
            case 0x194518u: goto label_194518;
            case 0x194578u: goto label_194578;
            case 0x194594u: goto label_194594;
            case 0x1945B0u: goto label_1945b0;
            case 0x1945C0u: goto label_1945c0;
            case 0x194620u: goto label_194620;
            case 0x19463Cu: goto label_19463c;
            case 0x194658u: goto label_194658;
            case 0x194668u: goto label_194668;
            case 0x1946C8u: goto label_1946c8;
            case 0x1946E4u: goto label_1946e4;
            case 0x194700u: goto label_194700;
            case 0x194704u: goto label_194704;
            case 0x19474Cu: goto label_19474c;
            case 0x194760u: goto label_194760;
            case 0x1947B4u: goto label_1947b4;
            case 0x1947DCu: goto label_1947dc;
            case 0x1947ECu: goto label_1947ec;
            case 0x19484Cu: goto label_19484c;
            case 0x194868u: goto label_194868;
            case 0x19488Cu: goto label_19488c;
            case 0x1948B4u: goto label_1948b4;
            case 0x1948C4u: goto label_1948c4;
            case 0x194924u: goto label_194924;
            case 0x194940u: goto label_194940;
            case 0x194964u: goto label_194964;
            case 0x19498Cu: goto label_19498c;
            case 0x19499Cu: goto label_19499c;
            case 0x1949FCu: goto label_1949fc;
            case 0x194A18u: goto label_194a18;
            case 0x194A34u: goto label_194a34;
            case 0x194A38u: goto label_194a38;
            case 0x194A7Cu: goto label_194a7c;
            case 0x194A90u: goto label_194a90;
            case 0x194A9Cu: goto label_194a9c;
            case 0x194AECu: goto label_194aec;
            case 0x194AF8u: goto label_194af8;
            case 0x194B04u: goto label_194b04;
            case 0x194B6Cu: goto label_194b6c;
            case 0x194B88u: goto label_194b88;
            case 0x194BA4u: goto label_194ba4;
            case 0x194BB0u: goto label_194bb0;
            case 0x194BBCu: goto label_194bbc;
            case 0x194C24u: goto label_194c24;
            case 0x194C40u: goto label_194c40;
            case 0x194C5Cu: goto label_194c5c;
            case 0x194C60u: goto label_194c60;
            case 0x194CA4u: goto label_194ca4;
            case 0x194CB8u: goto label_194cb8;
            case 0x194CC4u: goto label_194cc4;
            case 0x194D8Cu: goto label_194d8c;
            case 0x194DA0u: goto label_194da0;
            case 0x194E2Cu: goto label_194e2c;
            case 0x194E48u: goto label_194e48;
            case 0x194EDCu: goto label_194edc;
            case 0x194EF0u: goto label_194ef0;
            case 0x194F80u: goto label_194f80;
            case 0x194F9Cu: goto label_194f9c;
            case 0x194FB8u: goto label_194fb8;
            case 0x194FBCu: goto label_194fbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x194470u;
    // 0x194470: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x194470u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x194474: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194474u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194478: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x194478u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x19447c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19447cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x194480: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x194480u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x194484: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x194484u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x194488: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x194488u;
    {
        const bool branch_taken_0x194488 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19448Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194488u;
            // 0x19448c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194488) {
            ctx->pc = 0x194498u;
            goto label_194498;
        }
    }
    ctx->pc = 0x194490u;
    // 0x194490: 0x1000009c  b           . + 4 + (0x9C << 2)
    ctx->pc = 0x194490u;
    {
        const bool branch_taken_0x194490 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194490u;
            // 0x194494: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194490) {
            ctx->pc = 0x194704u;
            goto label_194704;
        }
    }
    ctx->pc = 0x194498u;
label_194498:
    // 0x194498: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x194498u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x19449c: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x19449cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x1944a0: 0x2484fee0  addiu       $a0, $a0, -0x120
    ctx->pc = 0x1944a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967008));
    // 0x1944a4: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x1944A4u;
    SET_GPR_U32(ctx, 31, 0x1944ACu);
    ctx->pc = 0x1944A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1944A4u;
            // 0x1944a8: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1944ACu; }
        if (ctx->pc != 0x1944ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1944ACu; }
        if (ctx->pc != 0x1944ACu) { return; }
    }
    ctx->pc = 0x1944ACu;
label_1944ac:
    // 0x1944ac: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x1944acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1944b0: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x1944B0u;
    SET_GPR_U32(ctx, 31, 0x1944B8u);
    ctx->pc = 0x1944B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1944B0u;
            // 0x1944b4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1944B8u; }
        if (ctx->pc != 0x1944B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1944B8u; }
        if (ctx->pc != 0x1944B8u) { return; }
    }
    ctx->pc = 0x1944B8u;
label_1944b8:
    // 0x1944b8: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x1944b8u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1944bc: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x1944bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1944c0: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x1944c0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1944c4: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1944c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1944c8: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x1944c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x1944cc: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1944ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1944d0: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1944d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1944d4: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1944d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1944d8: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1944d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1944dc: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1944dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1944e0: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x1944e0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1944e4: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1944e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1944e8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1944e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1944ec: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x1944ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x1944f0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1944f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1944f4: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1944f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1944f8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1944f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1944fc: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x1944fcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x194500: 0xc06629c  jal         func_198A70
    ctx->pc = 0x194500u;
    SET_GPR_U32(ctx, 31, 0x194508u);
    ctx->pc = 0x194504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194500u;
            // 0x194504: 0x86040000  lh          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194508u; }
        if (ctx->pc != 0x194508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194508u; }
        if (ctx->pc != 0x194508u) { return; }
    }
    ctx->pc = 0x194508u;
label_194508:
    // 0x194508: 0x86040002  lh          $a0, 0x2($s0)
    ctx->pc = 0x194508u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x19450c: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x19450cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194510: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x194510u;
    SET_GPR_U32(ctx, 31, 0x194518u);
    ctx->pc = 0x194514u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194510u;
            // 0x194514: 0x118c3f  dsra32      $s1, $s1, 16 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194518u; }
        if (ctx->pc != 0x194518u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194518u; }
        if (ctx->pc != 0x194518u) { return; }
    }
    ctx->pc = 0x194518u;
label_194518:
    // 0x194518: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194518u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19451c: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x19451cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194520: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x194520u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x194524: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194524u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194528: 0x11243c  dsll32      $a0, $s1, 16
    ctx->pc = 0x194528u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << (32 + 16));
    // 0x19452c: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x19452cu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x194530: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x194530u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x194534: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194534u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194538: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194538u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19453c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x19453cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x194540: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x194540u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x194544: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x194544u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x194548: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194548u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19454c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x19454cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x194550: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x194550u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194554: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194554u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194558: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194558u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x19455c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x19455cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194560: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194560u;
    {
        const bool branch_taken_0x194560 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194560u;
            // 0x194564: 0x622025  or          $a0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194560) {
            ctx->pc = 0x194578u;
            goto label_194578;
        }
    }
    ctx->pc = 0x194568u;
    // 0x194568: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194568u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x19456c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x19456cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194570: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194570u;
    {
        const bool branch_taken_0x194570 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194570u;
            // 0x194574: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194570) {
            ctx->pc = 0x194594u;
            goto label_194594;
        }
    }
    ctx->pc = 0x194578u;
label_194578:
    // 0x194578: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194578u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x19457c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x19457cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194580: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194580u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194584: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194584u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194588: 0x0  nop
    ctx->pc = 0x194588u;
    // NOP
    // 0x19458c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x19458cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194590: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194590u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194594:
    // 0x194594: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194594u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194598: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194598u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x19459c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x19459cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1945a0: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x1945a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x1945a4: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x1945a4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x1945a8: 0xc06629c  jal         func_198A70
    ctx->pc = 0x1945A8u;
    SET_GPR_U32(ctx, 31, 0x1945B0u);
    ctx->pc = 0x1945ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1945A8u;
            // 0x1945ac: 0x86040004  lh          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1945B0u; }
        if (ctx->pc != 0x1945B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1945B0u; }
        if (ctx->pc != 0x1945B0u) { return; }
    }
    ctx->pc = 0x1945B0u;
label_1945b0:
    // 0x1945b0: 0x86040006  lh          $a0, 0x6($s0)
    ctx->pc = 0x1945b0u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x1945b4: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1945b4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1945b8: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x1945B8u;
    SET_GPR_U32(ctx, 31, 0x1945C0u);
    ctx->pc = 0x1945BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1945B8u;
            // 0x1945bc: 0x118c3f  dsra32      $s1, $s1, 16 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1945C0u; }
        if (ctx->pc != 0x1945C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1945C0u; }
        if (ctx->pc != 0x1945C0u) { return; }
    }
    ctx->pc = 0x1945C0u;
label_1945c0:
    // 0x1945c0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1945c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1945c4: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1945c4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1945c8: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1945c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1945cc: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1945ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1945d0: 0x11243c  dsll32      $a0, $s1, 16
    ctx->pc = 0x1945d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << (32 + 16));
    // 0x1945d4: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1945d4u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1945d8: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1945d8u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1945dc: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1945dcu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1945e0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1945e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1945e4: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1945e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1945e8: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x1945e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1945ec: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1945ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1945f0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1945f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1945f4: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1945f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1945f8: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1945f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1945fc: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1945fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194600: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194600u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194604: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x194604u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194608: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194608u;
    {
        const bool branch_taken_0x194608 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x19460Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194608u;
            // 0x19460c: 0x622025  or          $a0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194608) {
            ctx->pc = 0x194620u;
            goto label_194620;
        }
    }
    ctx->pc = 0x194610u;
    // 0x194610: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194610u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194614: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194614u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194618: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194618u;
    {
        const bool branch_taken_0x194618 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19461Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194618u;
            // 0x19461c: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194618) {
            ctx->pc = 0x19463Cu;
            goto label_19463c;
        }
    }
    ctx->pc = 0x194620u;
label_194620:
    // 0x194620: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194620u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194624: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194624u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194628: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194628u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x19462c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x19462cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194630: 0x0  nop
    ctx->pc = 0x194630u;
    // NOP
    // 0x194634: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194634u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194638: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194638u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_19463c:
    // 0x19463c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19463cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194640: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194640u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194644: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194644u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194648: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x194648u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x19464c: 0xfc220038  sd          $v0, 0x38($at)
    ctx->pc = 0x19464cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
    // 0x194650: 0xc06629c  jal         func_198A70
    ctx->pc = 0x194650u;
    SET_GPR_U32(ctx, 31, 0x194658u);
    ctx->pc = 0x194654u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194650u;
            // 0x194654: 0x86040008  lh          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194658u; }
        if (ctx->pc != 0x194658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194658u; }
        if (ctx->pc != 0x194658u) { return; }
    }
    ctx->pc = 0x194658u;
label_194658:
    // 0x194658: 0x8604000a  lh          $a0, 0xA($s0)
    ctx->pc = 0x194658u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x19465c: 0x2843c  dsll32      $s0, $v0, 16
    ctx->pc = 0x19465cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194660: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x194660u;
    SET_GPR_U32(ctx, 31, 0x194668u);
    ctx->pc = 0x194664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194660u;
            // 0x194664: 0x10843f  dsra32      $s0, $s0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194668u; }
        if (ctx->pc != 0x194668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194668u; }
        if (ctx->pc != 0x194668u) { return; }
    }
    ctx->pc = 0x194668u;
label_194668:
    // 0x194668: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194668u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19466c: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x19466cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194670: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x194670u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x194674: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194674u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194678: 0x10243c  dsll32      $a0, $s0, 16
    ctx->pc = 0x194678u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) << (32 + 16));
    // 0x19467c: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x19467cu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x194680: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x194680u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x194684: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194684u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194688: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194688u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19468c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x19468cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x194690: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x194690u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x194694: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x194694u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x194698: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194698u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19469c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x19469cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1946a0: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1946a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1946a4: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1946a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1946a8: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1946a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1946ac: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1946acu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1946b0: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1946B0u;
    {
        const bool branch_taken_0x1946b0 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1946B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1946B0u;
            // 0x1946b4: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1946b0) {
            ctx->pc = 0x1946C8u;
            goto label_1946c8;
        }
    }
    ctx->pc = 0x1946B8u;
    // 0x1946b8: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1946b8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1946bc: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1946bcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1946c0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1946C0u;
    {
        const bool branch_taken_0x1946c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1946C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1946C0u;
            // 0x1946c4: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1946c0) {
            ctx->pc = 0x1946E4u;
            goto label_1946e4;
        }
    }
    ctx->pc = 0x1946C8u;
label_1946c8:
    // 0x1946c8: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1946c8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1946cc: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1946ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1946d0: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1946d0u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1946d4: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1946d4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1946d8: 0x0  nop
    ctx->pc = 0x1946d8u;
    // NOP
    // 0x1946dc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1946dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1946e0: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1946e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1946e4:
    // 0x1946e4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1946e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1946e8: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1946e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1946ec: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1946ecu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1946f0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1946f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1946f4: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x1946f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x1946f8: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1946F8u;
    SET_GPR_U32(ctx, 31, 0x194700u);
    ctx->pc = 0x1946FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1946F8u;
            // 0x1946fc: 0xfc220040  sd          $v0, 0x40($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194700u; }
        if (ctx->pc != 0x194700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194700u; }
        if (ctx->pc != 0x194700u) { return; }
    }
    ctx->pc = 0x194700u;
label_194700:
    // 0x194700: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_194704:
    // 0x194704: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x194704u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x194708: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x194708u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19470c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19470cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x194710: 0x3e00008  jr          $ra
    ctx->pc = 0x194710u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x194714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194710u;
            // 0x194714: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193ED0u: goto label_193ed0;
            case 0x193F0Cu: goto label_193f0c;
            case 0x193F28u: goto label_193f28;
            case 0x193F3Cu: goto label_193f3c;
            case 0x193F50u: goto label_193f50;
            case 0x193F64u: goto label_193f64;
            case 0x193F78u: goto label_193f78;
            case 0x193F7Cu: goto label_193f7c;
            case 0x193FB8u: goto label_193fb8;
            case 0x193FCCu: goto label_193fcc;
            case 0x193FD8u: goto label_193fd8;
            case 0x194028u: goto label_194028;
            case 0x194038u: goto label_194038;
            case 0x194068u: goto label_194068;
            case 0x194078u: goto label_194078;
            case 0x1940D4u: goto label_1940d4;
            case 0x1940F0u: goto label_1940f0;
            case 0x19410Cu: goto label_19410c;
            case 0x19411Cu: goto label_19411c;
            case 0x19414Cu: goto label_19414c;
            case 0x19415Cu: goto label_19415c;
            case 0x1941B8u: goto label_1941b8;
            case 0x1941D4u: goto label_1941d4;
            case 0x1941F0u: goto label_1941f0;
            case 0x1941F4u: goto label_1941f4;
            case 0x194238u: goto label_194238;
            case 0x19424Cu: goto label_19424c;
            case 0x194258u: goto label_194258;
            case 0x1942C8u: goto label_1942c8;
            case 0x1942D8u: goto label_1942d8;
            case 0x194338u: goto label_194338;
            case 0x194354u: goto label_194354;
            case 0x1943A0u: goto label_1943a0;
            case 0x1943C0u: goto label_1943c0;
            case 0x194420u: goto label_194420;
            case 0x19443Cu: goto label_19443c;
            case 0x194458u: goto label_194458;
            case 0x19445Cu: goto label_19445c;
            case 0x194498u: goto label_194498;
            case 0x1944ACu: goto label_1944ac;
            case 0x1944B8u: goto label_1944b8;
            case 0x194508u: goto label_194508;
            case 0x194518u: goto label_194518;
            case 0x194578u: goto label_194578;
            case 0x194594u: goto label_194594;
            case 0x1945B0u: goto label_1945b0;
            case 0x1945C0u: goto label_1945c0;
            case 0x194620u: goto label_194620;
            case 0x19463Cu: goto label_19463c;
            case 0x194658u: goto label_194658;
            case 0x194668u: goto label_194668;
            case 0x1946C8u: goto label_1946c8;
            case 0x1946E4u: goto label_1946e4;
            case 0x194700u: goto label_194700;
            case 0x194704u: goto label_194704;
            case 0x19474Cu: goto label_19474c;
            case 0x194760u: goto label_194760;
            case 0x1947B4u: goto label_1947b4;
            case 0x1947DCu: goto label_1947dc;
            case 0x1947ECu: goto label_1947ec;
            case 0x19484Cu: goto label_19484c;
            case 0x194868u: goto label_194868;
            case 0x19488Cu: goto label_19488c;
            case 0x1948B4u: goto label_1948b4;
            case 0x1948C4u: goto label_1948c4;
            case 0x194924u: goto label_194924;
            case 0x194940u: goto label_194940;
            case 0x194964u: goto label_194964;
            case 0x19498Cu: goto label_19498c;
            case 0x19499Cu: goto label_19499c;
            case 0x1949FCu: goto label_1949fc;
            case 0x194A18u: goto label_194a18;
            case 0x194A34u: goto label_194a34;
            case 0x194A38u: goto label_194a38;
            case 0x194A7Cu: goto label_194a7c;
            case 0x194A90u: goto label_194a90;
            case 0x194A9Cu: goto label_194a9c;
            case 0x194AECu: goto label_194aec;
            case 0x194AF8u: goto label_194af8;
            case 0x194B04u: goto label_194b04;
            case 0x194B6Cu: goto label_194b6c;
            case 0x194B88u: goto label_194b88;
            case 0x194BA4u: goto label_194ba4;
            case 0x194BB0u: goto label_194bb0;
            case 0x194BBCu: goto label_194bbc;
            case 0x194C24u: goto label_194c24;
            case 0x194C40u: goto label_194c40;
            case 0x194C5Cu: goto label_194c5c;
            case 0x194C60u: goto label_194c60;
            case 0x194CA4u: goto label_194ca4;
            case 0x194CB8u: goto label_194cb8;
            case 0x194CC4u: goto label_194cc4;
            case 0x194D8Cu: goto label_194d8c;
            case 0x194DA0u: goto label_194da0;
            case 0x194E2Cu: goto label_194e2c;
            case 0x194E48u: goto label_194e48;
            case 0x194EDCu: goto label_194edc;
            case 0x194EF0u: goto label_194ef0;
            case 0x194F80u: goto label_194f80;
            case 0x194F9Cu: goto label_194f9c;
            case 0x194FB8u: goto label_194fb8;
            case 0x194FBCu: goto label_194fbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x194718u;
    // 0x194718: 0x0  nop
    ctx->pc = 0x194718u;
    // NOP
    // 0x19471c: 0x0  nop
    ctx->pc = 0x19471cu;
    // NOP
    // 0x194720: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x194720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x194724: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194724u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194728: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x194728u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19472c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19472cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x194730: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x194730u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x194734: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x194734u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x194738: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x194738u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x19473c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19473Cu;
    {
        const bool branch_taken_0x19473c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x194740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19473Cu;
            // 0x194740: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19473c) {
            ctx->pc = 0x19474Cu;
            goto label_19474c;
        }
    }
    ctx->pc = 0x194744u;
    // 0x194744: 0x100000bc  b           . + 4 + (0xBC << 2)
    ctx->pc = 0x194744u;
    {
        const bool branch_taken_0x194744 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194744u;
            // 0x194748: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194744) {
            ctx->pc = 0x194A38u;
            goto label_194a38;
        }
    }
    ctx->pc = 0x19474Cu;
label_19474c:
    // 0x19474c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x19474cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x194750: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x194750u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x194754: 0x2484ff30  addiu       $a0, $a0, -0xD0
    ctx->pc = 0x194754u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967088));
    // 0x194758: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x194758u;
    SET_GPR_U32(ctx, 31, 0x194760u);
    ctx->pc = 0x19475Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194758u;
            // 0x19475c: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194760u; }
        if (ctx->pc != 0x194760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194760u; }
        if (ctx->pc != 0x194760u) { return; }
    }
    ctx->pc = 0x194760u;
label_194760:
    // 0x194760: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194760u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194764: 0x34028080  ori         $v0, $zero, 0x8080
    ctx->pc = 0x194764u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32896);
    // 0x194768: 0x9427fee8  lhu         $a3, -0x118($at)
    ctx->pc = 0x194768u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294967016)));
    // 0x19476c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x19476cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x194770: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194770u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194774: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x194774u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x194778: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x194778u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x19477c: 0x34428080  ori         $v0, $v0, 0x8080
    ctx->pc = 0x19477cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32896);
    // 0x194780: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x194780u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x194784: 0x24848680  addiu       $a0, $a0, -0x7980
    ctx->pc = 0x194784u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936192));
    // 0x194788: 0x2625000c  addiu       $a1, $s1, 0xC
    ctx->pc = 0x194788u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x19478c: 0x2626000e  addiu       $a2, $s1, 0xE
    ctx->pc = 0x19478cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 14));
    // 0x194790: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194790u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194794: 0x24e3ffff  addiu       $v1, $a3, -0x1
    ctx->pc = 0x194794u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x194798: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x194798u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x19479c: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x19479cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1947a0: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1947a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1947a4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1947a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1947a8: 0x828021  addu        $s0, $a0, $v0
    ctx->pc = 0x1947a8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1947ac: 0xc06628c  jal         func_198A30
    ctx->pc = 0x1947ACu;
    SET_GPR_U32(ctx, 31, 0x1947B4u);
    ctx->pc = 0x1947B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1947ACu;
            // 0x1947b0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A30u;
    if (runtime->hasFunction(0x198A30u)) {
        auto targetFn = runtime->lookupFunction(0x198A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1947B4u; }
        if (ctx->pc != 0x1947B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A30_0x198a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1947B4u; }
        if (ctx->pc != 0x1947B4u) { return; }
    }
    ctx->pc = 0x1947B4u;
label_1947b4:
    // 0x1947b4: 0x8622000e  lh          $v0, 0xE($s1)
    ctx->pc = 0x1947b4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 14)));
    // 0x1947b8: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1947b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1947bc: 0x8623000c  lh          $v1, 0xC($s1)
    ctx->pc = 0x1947bcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1947c0: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1947c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1947c4: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1947c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1947c8: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1947c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1947cc: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1947ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1947d0: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x1947d0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x1947d4: 0xc06629c  jal         func_198A70
    ctx->pc = 0x1947D4u;
    SET_GPR_U32(ctx, 31, 0x1947DCu);
    ctx->pc = 0x1947D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1947D4u;
            // 0x1947d8: 0x86240000  lh          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1947DCu; }
        if (ctx->pc != 0x1947DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1947DCu; }
        if (ctx->pc != 0x1947DCu) { return; }
    }
    ctx->pc = 0x1947DCu;
label_1947dc:
    // 0x1947dc: 0x86240002  lh          $a0, 0x2($s1)
    ctx->pc = 0x1947dcu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1947e0: 0x2943c  dsll32      $s2, $v0, 16
    ctx->pc = 0x1947e0u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1947e4: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x1947E4u;
    SET_GPR_U32(ctx, 31, 0x1947ECu);
    ctx->pc = 0x1947E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1947E4u;
            // 0x1947e8: 0x12943f  dsra32      $s2, $s2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 18, GPR_S64(ctx, 18) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1947ECu; }
        if (ctx->pc != 0x1947ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1947ECu; }
        if (ctx->pc != 0x1947ECu) { return; }
    }
    ctx->pc = 0x1947ECu;
label_1947ec:
    // 0x1947ec: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1947ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1947f0: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1947f0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1947f4: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1947f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1947f8: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1947f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1947fc: 0x12243c  dsll32      $a0, $s2, 16
    ctx->pc = 0x1947fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) << (32 + 16));
    // 0x194800: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x194800u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x194804: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x194804u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x194808: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194808u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19480c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19480cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194810: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x194810u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x194814: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x194814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x194818: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x194818u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x19481c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19481cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194820: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x194820u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x194824: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x194824u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194828: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194828u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x19482c: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x19482cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194830: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x194830u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194834: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194834u;
    {
        const bool branch_taken_0x194834 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194834u;
            // 0x194838: 0x623025  or          $a2, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194834) {
            ctx->pc = 0x19484Cu;
            goto label_19484c;
        }
    }
    ctx->pc = 0x19483Cu;
    // 0x19483c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x19483cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194840: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194840u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194844: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194844u;
    {
        const bool branch_taken_0x194844 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194844u;
            // 0x194848: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194844) {
            ctx->pc = 0x194868u;
            goto label_194868;
        }
    }
    ctx->pc = 0x19484Cu;
label_19484c:
    // 0x19484c: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x19484cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194850: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194850u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194854: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194854u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194858: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194858u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x19485c: 0x0  nop
    ctx->pc = 0x19485cu;
    // NOP
    // 0x194860: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194860u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194864: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194864u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194868:
    // 0x194868: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194868u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x19486c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x19486cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194870: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x194870u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x194874: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194874u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194878: 0x26250010  addiu       $a1, $s1, 0x10
    ctx->pc = 0x194878u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x19487c: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x19487cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x194880: 0x26260012  addiu       $a2, $s1, 0x12
    ctx->pc = 0x194880u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 18));
    // 0x194884: 0xc06628c  jal         func_198A30
    ctx->pc = 0x194884u;
    SET_GPR_U32(ctx, 31, 0x19488Cu);
    ctx->pc = 0x194888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194884u;
            // 0x194888: 0xfc220038  sd          $v0, 0x38($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A30u;
    if (runtime->hasFunction(0x198A30u)) {
        auto targetFn = runtime->lookupFunction(0x198A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19488Cu; }
        if (ctx->pc != 0x19488Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A30_0x198a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19488Cu; }
        if (ctx->pc != 0x19488Cu) { return; }
    }
    ctx->pc = 0x19488Cu;
label_19488c:
    // 0x19488c: 0x86220012  lh          $v0, 0x12($s1)
    ctx->pc = 0x19488cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 18)));
    // 0x194890: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194890u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194894: 0x86230010  lh          $v1, 0x10($s1)
    ctx->pc = 0x194894u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x194898: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194898u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x19489c: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x19489cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1948a0: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1948a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1948a4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1948a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1948a8: 0xfc220040  sd          $v0, 0x40($at)
    ctx->pc = 0x1948a8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
    // 0x1948ac: 0xc06629c  jal         func_198A70
    ctx->pc = 0x1948ACu;
    SET_GPR_U32(ctx, 31, 0x1948B4u);
    ctx->pc = 0x1948B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1948ACu;
            // 0x1948b0: 0x86240004  lh          $a0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1948B4u; }
        if (ctx->pc != 0x1948B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1948B4u; }
        if (ctx->pc != 0x1948B4u) { return; }
    }
    ctx->pc = 0x1948B4u;
label_1948b4:
    // 0x1948b4: 0x86240006  lh          $a0, 0x6($s1)
    ctx->pc = 0x1948b4u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 6)));
    // 0x1948b8: 0x2943c  dsll32      $s2, $v0, 16
    ctx->pc = 0x1948b8u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1948bc: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x1948BCu;
    SET_GPR_U32(ctx, 31, 0x1948C4u);
    ctx->pc = 0x1948C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1948BCu;
            // 0x1948c0: 0x12943f  dsra32      $s2, $s2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 18, GPR_S64(ctx, 18) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1948C4u; }
        if (ctx->pc != 0x1948C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1948C4u; }
        if (ctx->pc != 0x1948C4u) { return; }
    }
    ctx->pc = 0x1948C4u;
label_1948c4:
    // 0x1948c4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1948c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1948c8: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1948c8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1948cc: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1948ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1948d0: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1948d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1948d4: 0x12243c  dsll32      $a0, $s2, 16
    ctx->pc = 0x1948d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) << (32 + 16));
    // 0x1948d8: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1948d8u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1948dc: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1948dcu;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1948e0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1948e0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1948e4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1948e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1948e8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1948e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1948ec: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x1948ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1948f0: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1948f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1948f4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1948f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1948f8: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1948f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1948fc: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1948fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194900: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194900u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194904: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194904u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194908: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x194908u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x19490c: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x19490Cu;
    {
        const bool branch_taken_0x19490c = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19490Cu;
            // 0x194910: 0x623025  or          $a2, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19490c) {
            ctx->pc = 0x194924u;
            goto label_194924;
        }
    }
    ctx->pc = 0x194914u;
    // 0x194914: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194914u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194918: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194918u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x19491c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x19491Cu;
    {
        const bool branch_taken_0x19491c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19491Cu;
            // 0x194920: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19491c) {
            ctx->pc = 0x194940u;
            goto label_194940;
        }
    }
    ctx->pc = 0x194924u;
label_194924:
    // 0x194924: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194924u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194928: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194928u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x19492c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x19492cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194930: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194930u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194934: 0x0  nop
    ctx->pc = 0x194934u;
    // NOP
    // 0x194938: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194938u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x19493c: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x19493cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194940:
    // 0x194940: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194940u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194944: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194944u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194948: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x194948u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19494c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x19494cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194950: 0x26250014  addiu       $a1, $s1, 0x14
    ctx->pc = 0x194950u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 20));
    // 0x194954: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x194954u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x194958: 0x26260016  addiu       $a2, $s1, 0x16
    ctx->pc = 0x194958u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 22));
    // 0x19495c: 0xc06628c  jal         func_198A30
    ctx->pc = 0x19495Cu;
    SET_GPR_U32(ctx, 31, 0x194964u);
    ctx->pc = 0x194960u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19495Cu;
            // 0x194960: 0xfc220048  sd          $v0, 0x48($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 72), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A30u;
    if (runtime->hasFunction(0x198A30u)) {
        auto targetFn = runtime->lookupFunction(0x198A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194964u; }
        if (ctx->pc != 0x194964u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A30_0x198a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194964u; }
        if (ctx->pc != 0x194964u) { return; }
    }
    ctx->pc = 0x194964u;
label_194964:
    // 0x194964: 0x86220016  lh          $v0, 0x16($s1)
    ctx->pc = 0x194964u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 22)));
    // 0x194968: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194968u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x19496c: 0x86230014  lh          $v1, 0x14($s1)
    ctx->pc = 0x19496cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x194970: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194970u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194974: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x194974u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x194978: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194978u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x19497c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x19497cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194980: 0xfc220050  sd          $v0, 0x50($at)
    ctx->pc = 0x194980u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 80), GPR_U64(ctx, 2));
    // 0x194984: 0xc06629c  jal         func_198A70
    ctx->pc = 0x194984u;
    SET_GPR_U32(ctx, 31, 0x19498Cu);
    ctx->pc = 0x194988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194984u;
            // 0x194988: 0x86240008  lh          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19498Cu; }
        if (ctx->pc != 0x19498Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19498Cu; }
        if (ctx->pc != 0x19498Cu) { return; }
    }
    ctx->pc = 0x19498Cu;
label_19498c:
    // 0x19498c: 0x8624000a  lh          $a0, 0xA($s1)
    ctx->pc = 0x19498cu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 10)));
    // 0x194990: 0x2843c  dsll32      $s0, $v0, 16
    ctx->pc = 0x194990u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194994: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x194994u;
    SET_GPR_U32(ctx, 31, 0x19499Cu);
    ctx->pc = 0x194998u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194994u;
            // 0x194998: 0x10843f  dsra32      $s0, $s0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19499Cu; }
        if (ctx->pc != 0x19499Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19499Cu; }
        if (ctx->pc != 0x19499Cu) { return; }
    }
    ctx->pc = 0x19499Cu;
label_19499c:
    // 0x19499c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19499cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1949a0: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1949a0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1949a4: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1949a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1949a8: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1949a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1949ac: 0x10243c  dsll32      $a0, $s0, 16
    ctx->pc = 0x1949acu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1949b0: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1949b0u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1949b4: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1949b4u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1949b8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1949b8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1949bc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1949bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1949c0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1949c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1949c4: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x1949c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1949c8: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1949c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1949cc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1949ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1949d0: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1949d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1949d4: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1949d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1949d8: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1949d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1949dc: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1949dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1949e0: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1949e0u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1949e4: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1949E4u;
    {
        const bool branch_taken_0x1949e4 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1949E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1949E4u;
            // 0x1949e8: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1949e4) {
            ctx->pc = 0x1949FCu;
            goto label_1949fc;
        }
    }
    ctx->pc = 0x1949ECu;
    // 0x1949ec: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1949ecu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1949f0: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1949f0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1949f4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1949F4u;
    {
        const bool branch_taken_0x1949f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1949F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1949F4u;
            // 0x1949f8: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1949f4) {
            ctx->pc = 0x194A18u;
            goto label_194a18;
        }
    }
    ctx->pc = 0x1949FCu;
label_1949fc:
    // 0x1949fc: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1949fcu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194a00: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194a00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194a04: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194a04u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194a08: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194a08u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194a0c: 0x0  nop
    ctx->pc = 0x194a0cu;
    // NOP
    // 0x194a10: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194a10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194a14: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194a14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194a18:
    // 0x194a18: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194a18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194a1c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194a1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194a20: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x194a20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x194a24: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194a24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194a28: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x194a28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x194a2c: 0xc064f88  jal         func_193E20
    ctx->pc = 0x194A2Cu;
    SET_GPR_U32(ctx, 31, 0x194A34u);
    ctx->pc = 0x194A30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194A2Cu;
            // 0x194a30: 0xfc220058  sd          $v0, 0x58($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 88), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194A34u; }
        if (ctx->pc != 0x194A34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194A34u; }
        if (ctx->pc != 0x194A34u) { return; }
    }
    ctx->pc = 0x194A34u;
label_194a34:
    // 0x194a34: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194a34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_194a38:
    // 0x194a38: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x194a38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x194a3c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x194a3cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x194a40: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x194a40u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x194a44: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x194a44u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x194a48: 0x3e00008  jr          $ra
    ctx->pc = 0x194A48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x194A4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194A48u;
            // 0x194a4c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193ED0u: goto label_193ed0;
            case 0x193F0Cu: goto label_193f0c;
            case 0x193F28u: goto label_193f28;
            case 0x193F3Cu: goto label_193f3c;
            case 0x193F50u: goto label_193f50;
            case 0x193F64u: goto label_193f64;
            case 0x193F78u: goto label_193f78;
            case 0x193F7Cu: goto label_193f7c;
            case 0x193FB8u: goto label_193fb8;
            case 0x193FCCu: goto label_193fcc;
            case 0x193FD8u: goto label_193fd8;
            case 0x194028u: goto label_194028;
            case 0x194038u: goto label_194038;
            case 0x194068u: goto label_194068;
            case 0x194078u: goto label_194078;
            case 0x1940D4u: goto label_1940d4;
            case 0x1940F0u: goto label_1940f0;
            case 0x19410Cu: goto label_19410c;
            case 0x19411Cu: goto label_19411c;
            case 0x19414Cu: goto label_19414c;
            case 0x19415Cu: goto label_19415c;
            case 0x1941B8u: goto label_1941b8;
            case 0x1941D4u: goto label_1941d4;
            case 0x1941F0u: goto label_1941f0;
            case 0x1941F4u: goto label_1941f4;
            case 0x194238u: goto label_194238;
            case 0x19424Cu: goto label_19424c;
            case 0x194258u: goto label_194258;
            case 0x1942C8u: goto label_1942c8;
            case 0x1942D8u: goto label_1942d8;
            case 0x194338u: goto label_194338;
            case 0x194354u: goto label_194354;
            case 0x1943A0u: goto label_1943a0;
            case 0x1943C0u: goto label_1943c0;
            case 0x194420u: goto label_194420;
            case 0x19443Cu: goto label_19443c;
            case 0x194458u: goto label_194458;
            case 0x19445Cu: goto label_19445c;
            case 0x194498u: goto label_194498;
            case 0x1944ACu: goto label_1944ac;
            case 0x1944B8u: goto label_1944b8;
            case 0x194508u: goto label_194508;
            case 0x194518u: goto label_194518;
            case 0x194578u: goto label_194578;
            case 0x194594u: goto label_194594;
            case 0x1945B0u: goto label_1945b0;
            case 0x1945C0u: goto label_1945c0;
            case 0x194620u: goto label_194620;
            case 0x19463Cu: goto label_19463c;
            case 0x194658u: goto label_194658;
            case 0x194668u: goto label_194668;
            case 0x1946C8u: goto label_1946c8;
            case 0x1946E4u: goto label_1946e4;
            case 0x194700u: goto label_194700;
            case 0x194704u: goto label_194704;
            case 0x19474Cu: goto label_19474c;
            case 0x194760u: goto label_194760;
            case 0x1947B4u: goto label_1947b4;
            case 0x1947DCu: goto label_1947dc;
            case 0x1947ECu: goto label_1947ec;
            case 0x19484Cu: goto label_19484c;
            case 0x194868u: goto label_194868;
            case 0x19488Cu: goto label_19488c;
            case 0x1948B4u: goto label_1948b4;
            case 0x1948C4u: goto label_1948c4;
            case 0x194924u: goto label_194924;
            case 0x194940u: goto label_194940;
            case 0x194964u: goto label_194964;
            case 0x19498Cu: goto label_19498c;
            case 0x19499Cu: goto label_19499c;
            case 0x1949FCu: goto label_1949fc;
            case 0x194A18u: goto label_194a18;
            case 0x194A34u: goto label_194a34;
            case 0x194A38u: goto label_194a38;
            case 0x194A7Cu: goto label_194a7c;
            case 0x194A90u: goto label_194a90;
            case 0x194A9Cu: goto label_194a9c;
            case 0x194AECu: goto label_194aec;
            case 0x194AF8u: goto label_194af8;
            case 0x194B04u: goto label_194b04;
            case 0x194B6Cu: goto label_194b6c;
            case 0x194B88u: goto label_194b88;
            case 0x194BA4u: goto label_194ba4;
            case 0x194BB0u: goto label_194bb0;
            case 0x194BBCu: goto label_194bbc;
            case 0x194C24u: goto label_194c24;
            case 0x194C40u: goto label_194c40;
            case 0x194C5Cu: goto label_194c5c;
            case 0x194C60u: goto label_194c60;
            case 0x194CA4u: goto label_194ca4;
            case 0x194CB8u: goto label_194cb8;
            case 0x194CC4u: goto label_194cc4;
            case 0x194D8Cu: goto label_194d8c;
            case 0x194DA0u: goto label_194da0;
            case 0x194E2Cu: goto label_194e2c;
            case 0x194E48u: goto label_194e48;
            case 0x194EDCu: goto label_194edc;
            case 0x194EF0u: goto label_194ef0;
            case 0x194F80u: goto label_194f80;
            case 0x194F9Cu: goto label_194f9c;
            case 0x194FB8u: goto label_194fb8;
            case 0x194FBCu: goto label_194fbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x194A50u;
    // 0x194a50: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x194a50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x194a54: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194a54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194a58: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x194a58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x194a5c: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x194a5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x194a60: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x194a60u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x194a64: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x194a64u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x194a68: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x194a68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x194a6c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x194A6Cu;
    {
        const bool branch_taken_0x194a6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x194A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194A6Cu;
            // 0x194a70: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194a6c) {
            ctx->pc = 0x194A7Cu;
            goto label_194a7c;
        }
    }
    ctx->pc = 0x194A74u;
    // 0x194a74: 0x1000007a  b           . + 4 + (0x7A << 2)
    ctx->pc = 0x194A74u;
    {
        const bool branch_taken_0x194a74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194A74u;
            // 0x194a78: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194a74) {
            ctx->pc = 0x194C60u;
            goto label_194c60;
        }
    }
    ctx->pc = 0x194A7Cu;
label_194a7c:
    // 0x194a7c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x194a7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x194a80: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x194a80u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x194a84: 0x2484ff90  addiu       $a0, $a0, -0x70
    ctx->pc = 0x194a84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967184));
    // 0x194a88: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x194A88u;
    SET_GPR_U32(ctx, 31, 0x194A90u);
    ctx->pc = 0x194A8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194A88u;
            // 0x194a8c: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194A90u; }
        if (ctx->pc != 0x194A90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194A90u; }
        if (ctx->pc != 0x194A90u) { return; }
    }
    ctx->pc = 0x194A90u;
label_194a90:
    // 0x194a90: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x194a90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x194a94: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x194A94u;
    SET_GPR_U32(ctx, 31, 0x194A9Cu);
    ctx->pc = 0x194A98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194A94u;
            // 0x194a98: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194A9Cu; }
        if (ctx->pc != 0x194A9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194A9Cu; }
        if (ctx->pc != 0x194A9Cu) { return; }
    }
    ctx->pc = 0x194A9Cu;
label_194a9c:
    // 0x194a9c: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x194a9cu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x194aa0: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x194aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x194aa4: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x194aa4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x194aa8: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x194aa8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x194aac: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x194aacu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x194ab0: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194ab0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194ab4: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194ab4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194ab8: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x194ab8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x194abc: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x194abcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x194ac0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x194ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x194ac4: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x194ac4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194ac8: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194ac8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194acc: 0x9e02000c  lwu         $v0, 0xC($s0)
    ctx->pc = 0x194accu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x194ad0: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x194ad0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x194ad4: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x194ad4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194ad8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194ad8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194adc: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x194adcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x194ae0: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x194ae0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x194ae4: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x194AE4u;
    SET_GPR_U32(ctx, 31, 0x194AECu);
    ctx->pc = 0x194AE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194AE4u;
            // 0x194ae8: 0xc60c0000  lwc1        $f12, 0x0($s0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194AECu; }
        if (ctx->pc != 0x194AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194AECu; }
        if (ctx->pc != 0x194AECu) { return; }
    }
    ctx->pc = 0x194AECu;
label_194aec:
    // 0x194aec: 0xc60c0004  lwc1        $f12, 0x4($s0)
    ctx->pc = 0x194aecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x194af0: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x194AF0u;
    SET_GPR_U32(ctx, 31, 0x194AF8u);
    ctx->pc = 0x194AF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194AF0u;
            // 0x194af4: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194AF8u; }
        if (ctx->pc != 0x194AF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194AF8u; }
        if (ctx->pc != 0x194AF8u) { return; }
    }
    ctx->pc = 0x194AF8u;
label_194af8:
    // 0x194af8: 0xc60c0008  lwc1        $f12, 0x8($s0)
    ctx->pc = 0x194af8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x194afc: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x194AFCu;
    SET_GPR_U32(ctx, 31, 0x194B04u);
    ctx->pc = 0x194B00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194AFCu;
            // 0x194b00: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194B04u; }
        if (ctx->pc != 0x194B04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194B04u; }
        if (ctx->pc != 0x194B04u) { return; }
    }
    ctx->pc = 0x194B04u;
label_194b04:
    // 0x194b04: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194b04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194b08: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194b08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194b0c: 0xc423fd54  lwc1        $f3, -0x2AC($at)
    ctx->pc = 0x194b0cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x194b10: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x194b10u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x194b14: 0x0  nop
    ctx->pc = 0x194b14u;
    // NOP
    // 0x194b18: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x194b18u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194b1c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194b1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194b20: 0xc422fd58  lwc1        $f2, -0x2A8($at)
    ctx->pc = 0x194b20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x194b24: 0x468018e0  cvt.s.w     $f3, $f3
    ctx->pc = 0x194b24u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
    // 0x194b28: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x194b28u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x194b2c: 0x461518c0  add.s       $f3, $f3, $f21
    ctx->pc = 0x194b2cu;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[21]);
    // 0x194b30: 0x46141080  add.s       $f2, $f2, $f20
    ctx->pc = 0x194b30u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[20]);
    // 0x194b34: 0x460018e4  .word       0x460018E4                   # cvt.w.s     $f3, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194b34u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[3]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x194b38: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x194b38u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194b3c: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194b3cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x194b40: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x194b40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194b44: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x194b44u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194b48: 0x0  nop
    ctx->pc = 0x194b48u;
    // NOP
    // 0x194b4c: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194b50: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194b50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194b54: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194B54u;
    {
        const bool branch_taken_0x194b54 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194B58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194B54u;
            // 0x194b58: 0x622025  or          $a0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194b54) {
            ctx->pc = 0x194B6Cu;
            goto label_194b6c;
        }
    }
    ctx->pc = 0x194B5Cu;
    // 0x194b5c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194b5cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x194b60: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x194b60u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194b64: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194B64u;
    {
        const bool branch_taken_0x194b64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194B64u;
            // 0x194b68: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194b64) {
            ctx->pc = 0x194B88u;
            goto label_194b88;
        }
    }
    ctx->pc = 0x194B6Cu;
label_194b6c:
    // 0x194b6c: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x194b6cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x194b70: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194b70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194b74: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194b74u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x194b78: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x194b78u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194b7c: 0x0  nop
    ctx->pc = 0x194b7cu;
    // NOP
    // 0x194b80: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194b80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194b84: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194b84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194b88:
    // 0x194b88: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194b88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194b8c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194b8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194b90: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194b90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194b94: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x194b94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x194b98: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x194b98u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x194b9c: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x194B9Cu;
    SET_GPR_U32(ctx, 31, 0x194BA4u);
    ctx->pc = 0x194BA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194B9Cu;
            // 0x194ba0: 0xc60c0010  lwc1        $f12, 0x10($s0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194BA4u; }
        if (ctx->pc != 0x194BA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194BA4u; }
        if (ctx->pc != 0x194BA4u) { return; }
    }
    ctx->pc = 0x194BA4u;
label_194ba4:
    // 0x194ba4: 0xc60c0014  lwc1        $f12, 0x14($s0)
    ctx->pc = 0x194ba4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x194ba8: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x194BA8u;
    SET_GPR_U32(ctx, 31, 0x194BB0u);
    ctx->pc = 0x194BACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194BA8u;
            // 0x194bac: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194BB0u; }
        if (ctx->pc != 0x194BB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194BB0u; }
        if (ctx->pc != 0x194BB0u) { return; }
    }
    ctx->pc = 0x194BB0u;
label_194bb0:
    // 0x194bb0: 0xc60c0018  lwc1        $f12, 0x18($s0)
    ctx->pc = 0x194bb0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x194bb4: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x194BB4u;
    SET_GPR_U32(ctx, 31, 0x194BBCu);
    ctx->pc = 0x194BB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194BB4u;
            // 0x194bb8: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194BBCu; }
        if (ctx->pc != 0x194BBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194BBCu; }
        if (ctx->pc != 0x194BBCu) { return; }
    }
    ctx->pc = 0x194BBCu;
label_194bbc:
    // 0x194bbc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194bbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194bc0: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194bc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194bc4: 0xc423fd54  lwc1        $f3, -0x2AC($at)
    ctx->pc = 0x194bc4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x194bc8: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x194bc8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x194bcc: 0x0  nop
    ctx->pc = 0x194bccu;
    // NOP
    // 0x194bd0: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x194bd0u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194bd4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194bd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194bd8: 0xc422fd58  lwc1        $f2, -0x2A8($at)
    ctx->pc = 0x194bd8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x194bdc: 0x468018e0  cvt.s.w     $f3, $f3
    ctx->pc = 0x194bdcu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
    // 0x194be0: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x194be0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x194be4: 0x461518c0  add.s       $f3, $f3, $f21
    ctx->pc = 0x194be4u;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[21]);
    // 0x194be8: 0x46141080  add.s       $f2, $f2, $f20
    ctx->pc = 0x194be8u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[20]);
    // 0x194bec: 0x460018e4  .word       0x460018E4                   # cvt.w.s     $f3, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194becu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[3]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x194bf0: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x194bf0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194bf4: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194bf4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x194bf8: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x194bf8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194bfc: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x194bfcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194c00: 0x0  nop
    ctx->pc = 0x194c00u;
    // NOP
    // 0x194c04: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194c04u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194c08: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194c08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194c0c: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194C0Cu;
    {
        const bool branch_taken_0x194c0c = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194C0Cu;
            // 0x194c10: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194c0c) {
            ctx->pc = 0x194C24u;
            goto label_194c24;
        }
    }
    ctx->pc = 0x194C14u;
    // 0x194c14: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194c14u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x194c18: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x194c18u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194c1c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194C1Cu;
    {
        const bool branch_taken_0x194c1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194C20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194C1Cu;
            // 0x194c20: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194c1c) {
            ctx->pc = 0x194C40u;
            goto label_194c40;
        }
    }
    ctx->pc = 0x194C24u;
label_194c24:
    // 0x194c24: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x194c24u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x194c28: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194c28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194c2c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194c2cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x194c30: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x194c30u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194c34: 0x0  nop
    ctx->pc = 0x194c34u;
    // NOP
    // 0x194c38: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194c38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194c3c: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194c3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194c40:
    // 0x194c40: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194c40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194c44: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194c44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194c48: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x194c48u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x194c4c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194c4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194c50: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x194c50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x194c54: 0xc064f88  jal         func_193E20
    ctx->pc = 0x194C54u;
    SET_GPR_U32(ctx, 31, 0x194C5Cu);
    ctx->pc = 0x194C58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194C54u;
            // 0x194c58: 0xfc220038  sd          $v0, 0x38($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194C5Cu; }
        if (ctx->pc != 0x194C5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194C5Cu; }
        if (ctx->pc != 0x194C5Cu) { return; }
    }
    ctx->pc = 0x194C5Cu;
label_194c5c:
    // 0x194c5c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_194c60:
    // 0x194c60: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x194c60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x194c64: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x194c64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x194c68: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x194c68u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x194c6c: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x194c6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x194c70: 0x3e00008  jr          $ra
    ctx->pc = 0x194C70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x194C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194C70u;
            // 0x194c74: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193ED0u: goto label_193ed0;
            case 0x193F0Cu: goto label_193f0c;
            case 0x193F28u: goto label_193f28;
            case 0x193F3Cu: goto label_193f3c;
            case 0x193F50u: goto label_193f50;
            case 0x193F64u: goto label_193f64;
            case 0x193F78u: goto label_193f78;
            case 0x193F7Cu: goto label_193f7c;
            case 0x193FB8u: goto label_193fb8;
            case 0x193FCCu: goto label_193fcc;
            case 0x193FD8u: goto label_193fd8;
            case 0x194028u: goto label_194028;
            case 0x194038u: goto label_194038;
            case 0x194068u: goto label_194068;
            case 0x194078u: goto label_194078;
            case 0x1940D4u: goto label_1940d4;
            case 0x1940F0u: goto label_1940f0;
            case 0x19410Cu: goto label_19410c;
            case 0x19411Cu: goto label_19411c;
            case 0x19414Cu: goto label_19414c;
            case 0x19415Cu: goto label_19415c;
            case 0x1941B8u: goto label_1941b8;
            case 0x1941D4u: goto label_1941d4;
            case 0x1941F0u: goto label_1941f0;
            case 0x1941F4u: goto label_1941f4;
            case 0x194238u: goto label_194238;
            case 0x19424Cu: goto label_19424c;
            case 0x194258u: goto label_194258;
            case 0x1942C8u: goto label_1942c8;
            case 0x1942D8u: goto label_1942d8;
            case 0x194338u: goto label_194338;
            case 0x194354u: goto label_194354;
            case 0x1943A0u: goto label_1943a0;
            case 0x1943C0u: goto label_1943c0;
            case 0x194420u: goto label_194420;
            case 0x19443Cu: goto label_19443c;
            case 0x194458u: goto label_194458;
            case 0x19445Cu: goto label_19445c;
            case 0x194498u: goto label_194498;
            case 0x1944ACu: goto label_1944ac;
            case 0x1944B8u: goto label_1944b8;
            case 0x194508u: goto label_194508;
            case 0x194518u: goto label_194518;
            case 0x194578u: goto label_194578;
            case 0x194594u: goto label_194594;
            case 0x1945B0u: goto label_1945b0;
            case 0x1945C0u: goto label_1945c0;
            case 0x194620u: goto label_194620;
            case 0x19463Cu: goto label_19463c;
            case 0x194658u: goto label_194658;
            case 0x194668u: goto label_194668;
            case 0x1946C8u: goto label_1946c8;
            case 0x1946E4u: goto label_1946e4;
            case 0x194700u: goto label_194700;
            case 0x194704u: goto label_194704;
            case 0x19474Cu: goto label_19474c;
            case 0x194760u: goto label_194760;
            case 0x1947B4u: goto label_1947b4;
            case 0x1947DCu: goto label_1947dc;
            case 0x1947ECu: goto label_1947ec;
            case 0x19484Cu: goto label_19484c;
            case 0x194868u: goto label_194868;
            case 0x19488Cu: goto label_19488c;
            case 0x1948B4u: goto label_1948b4;
            case 0x1948C4u: goto label_1948c4;
            case 0x194924u: goto label_194924;
            case 0x194940u: goto label_194940;
            case 0x194964u: goto label_194964;
            case 0x19498Cu: goto label_19498c;
            case 0x19499Cu: goto label_19499c;
            case 0x1949FCu: goto label_1949fc;
            case 0x194A18u: goto label_194a18;
            case 0x194A34u: goto label_194a34;
            case 0x194A38u: goto label_194a38;
            case 0x194A7Cu: goto label_194a7c;
            case 0x194A90u: goto label_194a90;
            case 0x194A9Cu: goto label_194a9c;
            case 0x194AECu: goto label_194aec;
            case 0x194AF8u: goto label_194af8;
            case 0x194B04u: goto label_194b04;
            case 0x194B6Cu: goto label_194b6c;
            case 0x194B88u: goto label_194b88;
            case 0x194BA4u: goto label_194ba4;
            case 0x194BB0u: goto label_194bb0;
            case 0x194BBCu: goto label_194bbc;
            case 0x194C24u: goto label_194c24;
            case 0x194C40u: goto label_194c40;
            case 0x194C5Cu: goto label_194c5c;
            case 0x194C60u: goto label_194c60;
            case 0x194CA4u: goto label_194ca4;
            case 0x194CB8u: goto label_194cb8;
            case 0x194CC4u: goto label_194cc4;
            case 0x194D8Cu: goto label_194d8c;
            case 0x194DA0u: goto label_194da0;
            case 0x194E2Cu: goto label_194e2c;
            case 0x194E48u: goto label_194e48;
            case 0x194EDCu: goto label_194edc;
            case 0x194EF0u: goto label_194ef0;
            case 0x194F80u: goto label_194f80;
            case 0x194F9Cu: goto label_194f9c;
            case 0x194FB8u: goto label_194fb8;
            case 0x194FBCu: goto label_194fbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x194C78u;
    // 0x194c78: 0x0  nop
    ctx->pc = 0x194c78u;
    // NOP
    // 0x194c7c: 0x0  nop
    ctx->pc = 0x194c7cu;
    // NOP
    // 0x194c80: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x194c80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x194c84: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194c84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194c88: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x194c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x194c8c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x194c8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x194c90: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x194c90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x194c94: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x194C94u;
    {
        const bool branch_taken_0x194c94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x194C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194C94u;
            // 0x194c98: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194c94) {
            ctx->pc = 0x194CA4u;
            goto label_194ca4;
        }
    }
    ctx->pc = 0x194C9Cu;
    // 0x194c9c: 0x100000c7  b           . + 4 + (0xC7 << 2)
    ctx->pc = 0x194C9Cu;
    {
        const bool branch_taken_0x194c9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194CA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194C9Cu;
            // 0x194ca0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194c9c) {
            ctx->pc = 0x194FBCu;
            goto label_194fbc;
        }
    }
    ctx->pc = 0x194CA4u;
label_194ca4:
    // 0x194ca4: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x194ca4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x194ca8: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x194ca8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x194cac: 0x2484ffd0  addiu       $a0, $a0, -0x30
    ctx->pc = 0x194cacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967248));
    // 0x194cb0: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x194CB0u;
    SET_GPR_U32(ctx, 31, 0x194CB8u);
    ctx->pc = 0x194CB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194CB0u;
            // 0x194cb4: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194CB8u; }
        if (ctx->pc != 0x194CB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194CB8u; }
        if (ctx->pc != 0x194CB8u) { return; }
    }
    ctx->pc = 0x194CB8u;
label_194cb8:
    // 0x194cb8: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x194cb8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x194cbc: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x194CBCu;
    SET_GPR_U32(ctx, 31, 0x194CC4u);
    ctx->pc = 0x194CC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194CBCu;
            // 0x194cc0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194CC4u; }
        if (ctx->pc != 0x194CC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194CC4u; }
        if (ctx->pc != 0x194CC4u) { return; }
    }
    ctx->pc = 0x194CC4u;
label_194cc4:
    // 0x194cc4: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x194cc4u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x194cc8: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x194cc8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x194ccc: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x194cccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x194cd0: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x194cd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x194cd4: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x194cd4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x194cd8: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194cd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194cdc: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194cdcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194ce0: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x194ce0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x194ce4: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x194ce4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x194ce8: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x194ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x194cec: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x194cecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194cf0: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194cf0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194cf4: 0x9e02000c  lwu         $v0, 0xC($s0)
    ctx->pc = 0x194cf4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x194cf8: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x194cf8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x194cfc: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x194cfcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194d00: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194d00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194d04: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x194d04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x194d08: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x194d08u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x194d0c: 0xc6010024  lwc1        $f1, 0x24($s0)
    ctx->pc = 0x194d0cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194d10: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194d10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194d14: 0xc600000c  lwc1        $f0, 0xC($s0)
    ctx->pc = 0x194d14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194d18: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x194d18u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x194d1c: 0xe7a0002c  swc1        $f0, 0x2C($sp)
    ctx->pc = 0x194d1cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 44), bits); }
    // 0x194d20: 0xc6010028  lwc1        $f1, 0x28($s0)
    ctx->pc = 0x194d20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194d24: 0x9fa3002c  lwu         $v1, 0x2C($sp)
    ctx->pc = 0x194d24u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x194d28: 0xc600000c  lwc1        $f0, 0xC($s0)
    ctx->pc = 0x194d28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194d2c: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x194d2cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x194d30: 0xe7a00028  swc1        $f0, 0x28($sp)
    ctx->pc = 0x194d30u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x194d34: 0x9fa20028  lwu         $v0, 0x28($sp)
    ctx->pc = 0x194d34u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x194d38: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194d38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194d3c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x194d3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194d40: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x194d40u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x194d44: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194d44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194d48: 0xc420fd5c  lwc1        $f0, -0x2A4($at)
    ctx->pc = 0x194d48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966620)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194d4c: 0xc6010000  lwc1        $f1, 0x0($s0)
    ctx->pc = 0x194d4cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194d50: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x194d50u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x194d54: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194d54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194d58: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x194d58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x194d5c: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x194D5Cu;
    {
        const bool branch_taken_0x194d5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x194D60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194D5Cu;
            // 0x194d60: 0x46000a01  sub.s       $f8, $f1, $f0 (Delay Slot)
        ctx->f[8] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x194d5c) {
            ctx->pc = 0x194D8Cu;
            goto label_194d8c;
        }
    }
    ctx->pc = 0x194D64u;
    // 0x194d64: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194d64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194d68: 0x3c023f00  lui         $v0, 0x3F00
    ctx->pc = 0x194d68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16128 << 16));
    // 0x194d6c: 0xc421fd60  lwc1        $f1, -0x2A0($at)
    ctx->pc = 0x194d6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966624)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194d70: 0xc6020004  lwc1        $f2, 0x4($s0)
    ctx->pc = 0x194d70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x194d74: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194d74u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194d78: 0x0  nop
    ctx->pc = 0x194d78u;
    // NOP
    // 0x194d7c: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x194d7cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x194d80: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x194d80u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x194d84: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x194D84u;
    {
        const bool branch_taken_0x194d84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194D84u;
            // 0x194d88: 0x460101c2  mul.s       $f7, $f0, $f1 (Delay Slot)
        ctx->f[7] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x194d84) {
            ctx->pc = 0x194DA0u;
            goto label_194da0;
        }
    }
    ctx->pc = 0x194D8Cu;
label_194d8c:
    // 0x194d8c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194d8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194d90: 0xc420fd60  lwc1        $f0, -0x2A0($at)
    ctx->pc = 0x194d90u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966624)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194d94: 0xc6010004  lwc1        $f1, 0x4($s0)
    ctx->pc = 0x194d94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194d98: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x194d98u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x194d9c: 0x460009c1  sub.s       $f7, $f1, $f0
    ctx->pc = 0x194d9cu;
    ctx->f[7] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
label_194da0:
    // 0x194da0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194da0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194da4: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x194da4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x194da8: 0xc426fd58  lwc1        $f6, -0x2A8($at)
    ctx->pc = 0x194da8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[6] = f; }
    // 0x194dac: 0x44821800  mtc1        $v0, $f3
    ctx->pc = 0x194dacu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x194db0: 0xc6040008  lwc1        $f4, 0x8($s0)
    ctx->pc = 0x194db0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x194db4: 0x3c02bf00  lui         $v0, 0xBF00
    ctx->pc = 0x194db4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48896 << 16));
    // 0x194db8: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x194db8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x194dbc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194dbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194dc0: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194dc4: 0xc425fd54  lwc1        $f5, -0x2AC($at)
    ctx->pc = 0x194dc4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x194dc8: 0x460320c1  sub.s       $f3, $f4, $f3
    ctx->pc = 0x194dc8u;
    ctx->f[3] = FPU_SUB_S(ctx->f[4], ctx->f[3]);
    // 0x194dcc: 0x468031a0  cvt.s.w     $f6, $f6
    ctx->pc = 0x194dccu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[6], sizeof(tmp)); ctx->f[6] = FPU_CVT_S_W(tmp); }
    // 0x194dd0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194dd0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194dd4: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x194dd4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194dd8: 0x46031082  mul.s       $f2, $f2, $f3
    ctx->pc = 0x194dd8u;
    ctx->f[2] = FPU_MUL_S(ctx->f[2], ctx->f[3]);
    // 0x194ddc: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x194ddcu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x194de0: 0x46073180  add.s       $f6, $f6, $f7
    ctx->pc = 0x194de0u;
    ctx->f[6] = FPU_ADD_S(ctx->f[6], ctx->f[7]);
    // 0x194de4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194de4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194de8: 0x460030a4  .word       0x460030A4                   # cvt.w.s     $f2, $f6 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194de8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[6]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x194dec: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x194decu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194df0: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x194df0u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194df4: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194df4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194df8: 0x468028a0  cvt.s.w     $f2, $f5
    ctx->pc = 0x194df8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[5], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x194dfc: 0x21c38  dsll        $v1, $v0, 16
    ctx->pc = 0x194dfcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 16);
    // 0x194e00: 0x46081080  add.s       $f2, $f2, $f8
    ctx->pc = 0x194e00u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[8]);
    // 0x194e04: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194e04u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x194e08: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x194e08u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194e0c: 0x0  nop
    ctx->pc = 0x194e0cu;
    // NOP
    // 0x194e10: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194e10u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194e14: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194E14u;
    {
        const bool branch_taken_0x194e14 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194E18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194E14u;
            // 0x194e18: 0x432025  or          $a0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194e14) {
            ctx->pc = 0x194E2Cu;
            goto label_194e2c;
        }
    }
    ctx->pc = 0x194E1Cu;
    // 0x194e1c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194e1cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194e20: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194e20u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194e24: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194E24u;
    {
        const bool branch_taken_0x194e24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194E28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194E24u;
            // 0x194e28: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194e24) {
            ctx->pc = 0x194E48u;
            goto label_194e48;
        }
    }
    ctx->pc = 0x194E2Cu;
label_194e2c:
    // 0x194e2c: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194e2cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194e30: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194e30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194e34: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194e34u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194e38: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194e38u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194e3c: 0x0  nop
    ctx->pc = 0x194e3cu;
    // NOP
    // 0x194e40: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194e40u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194e44: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194e44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194e48:
    // 0x194e48: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194e48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194e4c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194e4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194e50: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194e50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194e54: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x194e54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x194e58: 0xfc220038  sd          $v0, 0x38($at)
    ctx->pc = 0x194e58u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
    // 0x194e5c: 0xc601002c  lwc1        $f1, 0x2C($s0)
    ctx->pc = 0x194e5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194e60: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194e60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194e64: 0xc600001c  lwc1        $f0, 0x1C($s0)
    ctx->pc = 0x194e64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194e68: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x194e68u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x194e6c: 0xe7a0002c  swc1        $f0, 0x2C($sp)
    ctx->pc = 0x194e6cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 44), bits); }
    // 0x194e70: 0xc6010030  lwc1        $f1, 0x30($s0)
    ctx->pc = 0x194e70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194e74: 0x9fa3002c  lwu         $v1, 0x2C($sp)
    ctx->pc = 0x194e74u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x194e78: 0xc600001c  lwc1        $f0, 0x1C($s0)
    ctx->pc = 0x194e78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194e7c: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x194e7cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x194e80: 0xe7a00028  swc1        $f0, 0x28($sp)
    ctx->pc = 0x194e80u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x194e84: 0x9fa20028  lwu         $v0, 0x28($sp)
    ctx->pc = 0x194e84u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x194e88: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194e88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194e8c: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x194e8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194e90: 0xfc220040  sd          $v0, 0x40($at)
    ctx->pc = 0x194e90u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
    // 0x194e94: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194e94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194e98: 0xc420fd5c  lwc1        $f0, -0x2A4($at)
    ctx->pc = 0x194e98u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966620)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194e9c: 0xc6010010  lwc1        $f1, 0x10($s0)
    ctx->pc = 0x194e9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194ea0: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x194ea0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x194ea4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194ea4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194ea8: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x194ea8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x194eac: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x194EACu;
    {
        const bool branch_taken_0x194eac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x194EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194EACu;
            // 0x194eb0: 0x46000a01  sub.s       $f8, $f1, $f0 (Delay Slot)
        ctx->f[8] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x194eac) {
            ctx->pc = 0x194EDCu;
            goto label_194edc;
        }
    }
    ctx->pc = 0x194EB4u;
    // 0x194eb4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194eb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194eb8: 0x3c023f00  lui         $v0, 0x3F00
    ctx->pc = 0x194eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16128 << 16));
    // 0x194ebc: 0xc421fd60  lwc1        $f1, -0x2A0($at)
    ctx->pc = 0x194ebcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966624)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194ec0: 0xc6020014  lwc1        $f2, 0x14($s0)
    ctx->pc = 0x194ec0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x194ec4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194ec4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194ec8: 0x0  nop
    ctx->pc = 0x194ec8u;
    // NOP
    // 0x194ecc: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x194eccu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x194ed0: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x194ed0u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x194ed4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x194ED4u;
    {
        const bool branch_taken_0x194ed4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194ED4u;
            // 0x194ed8: 0x460101c2  mul.s       $f7, $f0, $f1 (Delay Slot)
        ctx->f[7] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x194ed4) {
            ctx->pc = 0x194EF0u;
            goto label_194ef0;
        }
    }
    ctx->pc = 0x194EDCu;
label_194edc:
    // 0x194edc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194edcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194ee0: 0xc420fd60  lwc1        $f0, -0x2A0($at)
    ctx->pc = 0x194ee0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966624)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x194ee4: 0xc6010014  lwc1        $f1, 0x14($s0)
    ctx->pc = 0x194ee4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194ee8: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x194ee8u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x194eec: 0x460009c1  sub.s       $f7, $f1, $f0
    ctx->pc = 0x194eecu;
    ctx->f[7] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
label_194ef0:
    // 0x194ef0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194ef0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194ef4: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x194ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x194ef8: 0xc426fd58  lwc1        $f6, -0x2A8($at)
    ctx->pc = 0x194ef8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[6] = f; }
    // 0x194efc: 0x44821800  mtc1        $v0, $f3
    ctx->pc = 0x194efcu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x194f00: 0xc6040018  lwc1        $f4, 0x18($s0)
    ctx->pc = 0x194f00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x194f04: 0x3c02bf00  lui         $v0, 0xBF00
    ctx->pc = 0x194f04u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48896 << 16));
    // 0x194f08: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x194f08u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x194f0c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194f0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194f10: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194f10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194f14: 0xc425fd54  lwc1        $f5, -0x2AC($at)
    ctx->pc = 0x194f14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x194f18: 0x460320c1  sub.s       $f3, $f4, $f3
    ctx->pc = 0x194f18u;
    ctx->f[3] = FPU_SUB_S(ctx->f[4], ctx->f[3]);
    // 0x194f1c: 0x46031082  mul.s       $f2, $f2, $f3
    ctx->pc = 0x194f1cu;
    ctx->f[2] = FPU_MUL_S(ctx->f[2], ctx->f[3]);
    // 0x194f20: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194f20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194f24: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x194f24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194f28: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194f28u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194f2c: 0x0  nop
    ctx->pc = 0x194f2cu;
    // NOP
    // 0x194f30: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x194f30u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x194f34: 0x468030a0  cvt.s.w     $f2, $f6
    ctx->pc = 0x194f34u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[6], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x194f38: 0x46071080  add.s       $f2, $f2, $f7
    ctx->pc = 0x194f38u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[7]);
    // 0x194f3c: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194f3cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x194f40: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x194f40u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194f44: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x194f44u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194f48: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194f48u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194f4c: 0x468028a0  cvt.s.w     $f2, $f5
    ctx->pc = 0x194f4cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[5], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x194f50: 0x21c38  dsll        $v1, $v0, 16
    ctx->pc = 0x194f50u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 16);
    // 0x194f54: 0x46081080  add.s       $f2, $f2, $f8
    ctx->pc = 0x194f54u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[8]);
    // 0x194f58: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194f58u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x194f5c: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x194f5cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194f60: 0x0  nop
    ctx->pc = 0x194f60u;
    // NOP
    // 0x194f64: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194f64u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194f68: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194F68u;
    {
        const bool branch_taken_0x194f68 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194F68u;
            // 0x194f6c: 0x432825  or          $a1, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194f68) {
            ctx->pc = 0x194F80u;
            goto label_194f80;
        }
    }
    ctx->pc = 0x194F70u;
    // 0x194f70: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194f70u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194f74: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194f74u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194f78: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194F78u;
    {
        const bool branch_taken_0x194f78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194F7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194F78u;
            // 0x194f7c: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194f78) {
            ctx->pc = 0x194F9Cu;
            goto label_194f9c;
        }
    }
    ctx->pc = 0x194F80u;
label_194f80:
    // 0x194f80: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194f80u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194f84: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194f84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194f88: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194f88u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194f8c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194f8cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194f90: 0x0  nop
    ctx->pc = 0x194f90u;
    // NOP
    // 0x194f94: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194f94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194f98: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194f98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194f9c:
    // 0x194f9c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194f9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194fa0: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194fa0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194fa4: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x194fa4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x194fa8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194fa8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194fac: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x194facu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x194fb0: 0xc064f88  jal         func_193E20
    ctx->pc = 0x194FB0u;
    SET_GPR_U32(ctx, 31, 0x194FB8u);
    ctx->pc = 0x194FB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194FB0u;
            // 0x194fb4: 0xfc220048  sd          $v0, 0x48($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 72), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194FB8u; }
        if (ctx->pc != 0x194FB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194FB8u; }
        if (ctx->pc != 0x194FB8u) { return; }
    }
    ctx->pc = 0x194FB8u;
label_194fb8:
    // 0x194fb8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194fb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_194fbc:
    // 0x194fbc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x194fbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x194fc0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x194fc0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x194fc4: 0x3e00008  jr          $ra
    ctx->pc = 0x194FC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x194FC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194FC4u;
            // 0x194fc8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193ED0u: goto label_193ed0;
            case 0x193F0Cu: goto label_193f0c;
            case 0x193F28u: goto label_193f28;
            case 0x193F3Cu: goto label_193f3c;
            case 0x193F50u: goto label_193f50;
            case 0x193F64u: goto label_193f64;
            case 0x193F78u: goto label_193f78;
            case 0x193F7Cu: goto label_193f7c;
            case 0x193FB8u: goto label_193fb8;
            case 0x193FCCu: goto label_193fcc;
            case 0x193FD8u: goto label_193fd8;
            case 0x194028u: goto label_194028;
            case 0x194038u: goto label_194038;
            case 0x194068u: goto label_194068;
            case 0x194078u: goto label_194078;
            case 0x1940D4u: goto label_1940d4;
            case 0x1940F0u: goto label_1940f0;
            case 0x19410Cu: goto label_19410c;
            case 0x19411Cu: goto label_19411c;
            case 0x19414Cu: goto label_19414c;
            case 0x19415Cu: goto label_19415c;
            case 0x1941B8u: goto label_1941b8;
            case 0x1941D4u: goto label_1941d4;
            case 0x1941F0u: goto label_1941f0;
            case 0x1941F4u: goto label_1941f4;
            case 0x194238u: goto label_194238;
            case 0x19424Cu: goto label_19424c;
            case 0x194258u: goto label_194258;
            case 0x1942C8u: goto label_1942c8;
            case 0x1942D8u: goto label_1942d8;
            case 0x194338u: goto label_194338;
            case 0x194354u: goto label_194354;
            case 0x1943A0u: goto label_1943a0;
            case 0x1943C0u: goto label_1943c0;
            case 0x194420u: goto label_194420;
            case 0x19443Cu: goto label_19443c;
            case 0x194458u: goto label_194458;
            case 0x19445Cu: goto label_19445c;
            case 0x194498u: goto label_194498;
            case 0x1944ACu: goto label_1944ac;
            case 0x1944B8u: goto label_1944b8;
            case 0x194508u: goto label_194508;
            case 0x194518u: goto label_194518;
            case 0x194578u: goto label_194578;
            case 0x194594u: goto label_194594;
            case 0x1945B0u: goto label_1945b0;
            case 0x1945C0u: goto label_1945c0;
            case 0x194620u: goto label_194620;
            case 0x19463Cu: goto label_19463c;
            case 0x194658u: goto label_194658;
            case 0x194668u: goto label_194668;
            case 0x1946C8u: goto label_1946c8;
            case 0x1946E4u: goto label_1946e4;
            case 0x194700u: goto label_194700;
            case 0x194704u: goto label_194704;
            case 0x19474Cu: goto label_19474c;
            case 0x194760u: goto label_194760;
            case 0x1947B4u: goto label_1947b4;
            case 0x1947DCu: goto label_1947dc;
            case 0x1947ECu: goto label_1947ec;
            case 0x19484Cu: goto label_19484c;
            case 0x194868u: goto label_194868;
            case 0x19488Cu: goto label_19488c;
            case 0x1948B4u: goto label_1948b4;
            case 0x1948C4u: goto label_1948c4;
            case 0x194924u: goto label_194924;
            case 0x194940u: goto label_194940;
            case 0x194964u: goto label_194964;
            case 0x19498Cu: goto label_19498c;
            case 0x19499Cu: goto label_19499c;
            case 0x1949FCu: goto label_1949fc;
            case 0x194A18u: goto label_194a18;
            case 0x194A34u: goto label_194a34;
            case 0x194A38u: goto label_194a38;
            case 0x194A7Cu: goto label_194a7c;
            case 0x194A90u: goto label_194a90;
            case 0x194A9Cu: goto label_194a9c;
            case 0x194AECu: goto label_194aec;
            case 0x194AF8u: goto label_194af8;
            case 0x194B04u: goto label_194b04;
            case 0x194B6Cu: goto label_194b6c;
            case 0x194B88u: goto label_194b88;
            case 0x194BA4u: goto label_194ba4;
            case 0x194BB0u: goto label_194bb0;
            case 0x194BBCu: goto label_194bbc;
            case 0x194C24u: goto label_194c24;
            case 0x194C40u: goto label_194c40;
            case 0x194C5Cu: goto label_194c5c;
            case 0x194C60u: goto label_194c60;
            case 0x194CA4u: goto label_194ca4;
            case 0x194CB8u: goto label_194cb8;
            case 0x194CC4u: goto label_194cc4;
            case 0x194D8Cu: goto label_194d8c;
            case 0x194DA0u: goto label_194da0;
            case 0x194E2Cu: goto label_194e2c;
            case 0x194E48u: goto label_194e48;
            case 0x194EDCu: goto label_194edc;
            case 0x194EF0u: goto label_194ef0;
            case 0x194F80u: goto label_194f80;
            case 0x194F9Cu: goto label_194f9c;
            case 0x194FB8u: goto label_194fb8;
            case 0x194FBCu: goto label_194fbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x194FCCu;
    // 0x194fcc: 0x0  nop
    ctx->pc = 0x194fccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
