#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DA51C
// Address: 0x1da51c - 0x1dab54
void sub_001DA51C_0x1da51c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DA51C_0x1da51c");
#endif

    switch (ctx->pc) {
        case 0x1da54cu: goto label_1da54c;
        case 0x1da558u: goto label_1da558;
        case 0x1da58cu: goto label_1da58c;
        case 0x1da5a4u: goto label_1da5a4;
        case 0x1da5c0u: goto label_1da5c0;
        case 0x1da68cu: goto label_1da68c;
        case 0x1da6a8u: goto label_1da6a8;
        case 0x1da6c8u: goto label_1da6c8;
        case 0x1da6d4u: goto label_1da6d4;
        case 0x1da6f4u: goto label_1da6f4;
        case 0x1da700u: goto label_1da700;
        case 0x1da718u: goto label_1da718;
        case 0x1da73cu: goto label_1da73c;
        case 0x1da74cu: goto label_1da74c;
        case 0x1da758u: goto label_1da758;
        case 0x1da770u: goto label_1da770;
        case 0x1da794u: goto label_1da794;
        case 0x1da7a8u: goto label_1da7a8;
        case 0x1da7b8u: goto label_1da7b8;
        case 0x1da7c4u: goto label_1da7c4;
        case 0x1da7e8u: goto label_1da7e8;
        case 0x1da80cu: goto label_1da80c;
        case 0x1da820u: goto label_1da820;
        case 0x1da834u: goto label_1da834;
        case 0x1da844u: goto label_1da844;
        case 0x1da850u: goto label_1da850;
        case 0x1da870u: goto label_1da870;
        case 0x1da89cu: goto label_1da89c;
        case 0x1da8b0u: goto label_1da8b0;
        case 0x1da8c4u: goto label_1da8c4;
        case 0x1da8d4u: goto label_1da8d4;
        case 0x1da8e0u: goto label_1da8e0;
        case 0x1da8f4u: goto label_1da8f4;
        case 0x1da908u: goto label_1da908;
        case 0x1da918u: goto label_1da918;
        case 0x1da940u: goto label_1da940;
        case 0x1da988u: goto label_1da988;
        case 0x1da9d4u: goto label_1da9d4;
        case 0x1daa1cu: goto label_1daa1c;
        case 0x1daa48u: goto label_1daa48;
        case 0x1daa80u: goto label_1daa80;
        case 0x1daaacu: goto label_1daaac;
        default: break;
    }

    ctx->pc = 0x1da51cu;

    // 0x1da51c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1da51cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1da520: 0xffbe0030  sd          $fp, 0x30($sp)
    ctx->pc = 0x1da520u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 30));
    // 0x1da524: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1da524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1da528: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1da528u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da52c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1da52cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1da530: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1da530u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da534: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1da534u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1da538: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1da538u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1da53c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1da53cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1da540: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1da540u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1da544: 0xc079eee  jal         func_1E7BB8
    ctx->pc = 0x1DA544u;
    SET_GPR_U32(ctx, 31, 0x1DA54Cu);
    ctx->pc = 0x1E7BB8u;
    if (runtime->hasFunction(0x1E7BB8u)) {
        auto targetFn = runtime->lookupFunction(0x1E7BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA54Cu; }
        if (ctx->pc != 0x1DA54Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7BB8_0x1e7bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA54Cu; }
        if (ctx->pc != 0x1DA54Cu) { return; }
    }
    ctx->pc = 0x1DA54Cu;
label_1da54c:
    // 0x1da54c: 0x24040624  addiu       $a0, $zero, 0x624
    ctx->pc = 0x1da54cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1572));
    // 0x1da550: 0xc079f1f  jal         func_1E7C7C
    ctx->pc = 0x1DA550u;
    SET_GPR_U32(ctx, 31, 0x1DA558u);
    ctx->pc = 0x1E7C7Cu;
    if (runtime->hasFunction(0x1E7C7Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E7C7Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA558u; }
        if (ctx->pc != 0x1DA558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7C7C_0x1e7c7c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA558u; }
        if (ctx->pc != 0x1DA558u) { return; }
    }
    ctx->pc = 0x1DA558u;
label_1da558:
    // 0x1da558: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1da558u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1da55c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da55cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da560: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1da560u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1da564: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DA564u;
    {
        const bool branch_taken_0x1da564 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1da564) {
            ctx->pc = 0x1DA578u;
            goto label_1da578;
        }
    }
    ctx->pc = 0x1DA56Cu;
    // 0x1da56c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1da56cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da570: 0x10000172  b           . + 4 + (0x172 << 2)
    ctx->pc = 0x1DA570u;
    {
        const bool branch_taken_0x1da570 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1da570) {
            ctx->pc = 0x1DAB3Cu;
            goto label_1dab3c;
        }
    }
    ctx->pc = 0x1DA578u;
label_1da578:
    // 0x1da578: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da578u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da57c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1da57cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da580: 0x24060624  addiu       $a2, $zero, 0x624
    ctx->pc = 0x1da580u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1572));
    // 0x1da584: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1DA584u;
    SET_GPR_U32(ctx, 31, 0x1DA58Cu);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA58Cu; }
        if (ctx->pc != 0x1DA58Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA58Cu; }
        if (ctx->pc != 0x1DA58Cu) { return; }
    }
    ctx->pc = 0x1DA58Cu;
label_1da58c:
    // 0x1da58c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da58cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da590: 0x24420014  addiu       $v0, $v0, 0x14
    ctx->pc = 0x1da590u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1da594: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1da594u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da598: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1da598u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1da59c: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1DA59Cu;
    SET_GPR_U32(ctx, 31, 0x1DA5A4u);
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA5A4u; }
        if (ctx->pc != 0x1DA5A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA5A4u; }
        if (ctx->pc != 0x1DA5A4u) { return; }
    }
    ctx->pc = 0x1DA5A4u;
label_1da5a4:
    // 0x1da5a4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da5a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da5a8: 0xa4400008  sh          $zero, 0x8($v0)
    ctx->pc = 0x1da5a8u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1da5ac: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da5acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da5b0: 0xac40000c  sw          $zero, 0xC($v0)
    ctx->pc = 0x1da5b0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 0));
    // 0x1da5b4: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1da5b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1da5b8: 0xc07a1d6  jal         func_1E8758
    ctx->pc = 0x1DA5B8u;
    SET_GPR_U32(ctx, 31, 0x1DA5C0u);
    ctx->pc = 0x1E8758u;
    if (runtime->hasFunction(0x1E8758u)) {
        auto targetFn = runtime->lookupFunction(0x1E8758u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA5C0u; }
        if (ctx->pc != 0x1DA5C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8758_0x1e8758(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA5C0u; }
        if (ctx->pc != 0x1DA5C0u) { return; }
    }
    ctx->pc = 0x1DA5C0u;
label_1da5c0:
    // 0x1da5c0: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da5c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da5c4: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1da5c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1da5c8: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1da5c8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1da5cc: 0xac62003c  sw          $v0, 0x3C($v1)
    ctx->pc = 0x1da5ccu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 60), GPR_U32(ctx, 2));
    // 0x1da5d0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da5d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da5d4: 0xac40050c  sw          $zero, 0x50C($v0)
    ctx->pc = 0x1da5d4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1292), GPR_U32(ctx, 0));
    // 0x1da5d8: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da5d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da5dc: 0x240207d0  addiu       $v0, $zero, 0x7D0
    ctx->pc = 0x1da5dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2000));
    // 0x1da5e0: 0xa462000a  sh          $v0, 0xA($v1)
    ctx->pc = 0x1da5e0u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 10), (uint16_t)GPR_U32(ctx, 2));
    // 0x1da5e4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da5e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da5e8: 0xac400010  sw          $zero, 0x10($v0)
    ctx->pc = 0x1da5e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 0));
    // 0x1da5ec: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da5ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da5f0: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1da5f0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1da5f4: 0xac620040  sw          $v0, 0x40($v1)
    ctx->pc = 0x1da5f4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 64), GPR_U32(ctx, 2));
    // 0x1da5f8: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da5f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da5fc: 0x24020053  addiu       $v0, $zero, 0x53
    ctx->pc = 0x1da5fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 83));
    // 0x1da600: 0xa06204d4  sb          $v0, 0x4D4($v1)
    ctx->pc = 0x1da600u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1236), (uint8_t)GPR_U32(ctx, 2));
    // 0x1da604: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da604u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da608: 0x2402004e  addiu       $v0, $zero, 0x4E
    ctx->pc = 0x1da608u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 78));
    // 0x1da60c: 0xa06204d5  sb          $v0, 0x4D5($v1)
    ctx->pc = 0x1da60cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1237), (uint8_t)GPR_U32(ctx, 2));
    // 0x1da610: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da610u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da614: 0x24020041  addiu       $v0, $zero, 0x41
    ctx->pc = 0x1da614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x1da618: 0xa06204d6  sb          $v0, 0x4D6($v1)
    ctx->pc = 0x1da618u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1238), (uint8_t)GPR_U32(ctx, 2));
    // 0x1da61c: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da61cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da620: 0x24020050  addiu       $v0, $zero, 0x50
    ctx->pc = 0x1da620u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1da624: 0xa06204d7  sb          $v0, 0x4D7($v1)
    ctx->pc = 0x1da624u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1239), (uint8_t)GPR_U32(ctx, 2));
    // 0x1da628: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da628u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da62c: 0x2402002d  addiu       $v0, $zero, 0x2D
    ctx->pc = 0x1da62cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x1da630: 0xa06204d8  sb          $v0, 0x4D8($v1)
    ctx->pc = 0x1da630u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1240), (uint8_t)GPR_U32(ctx, 2));
    // 0x1da634: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da634u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da638: 0x24020053  addiu       $v0, $zero, 0x53
    ctx->pc = 0x1da638u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 83));
    // 0x1da63c: 0xa06204d9  sb          $v0, 0x4D9($v1)
    ctx->pc = 0x1da63cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1241), (uint8_t)GPR_U32(ctx, 2));
    // 0x1da640: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da640u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da644: 0x24020057  addiu       $v0, $zero, 0x57
    ctx->pc = 0x1da644u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 87));
    // 0x1da648: 0xa06204da  sb          $v0, 0x4DA($v1)
    ctx->pc = 0x1da648u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1242), (uint8_t)GPR_U32(ctx, 2));
    // 0x1da64c: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da64cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da650: 0x24020041  addiu       $v0, $zero, 0x41
    ctx->pc = 0x1da650u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x1da654: 0xa06204db  sb          $v0, 0x4DB($v1)
    ctx->pc = 0x1da654u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1243), (uint8_t)GPR_U32(ctx, 2));
    // 0x1da658: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da658u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da65c: 0x2402004e  addiu       $v0, $zero, 0x4E
    ctx->pc = 0x1da65cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 78));
    // 0x1da660: 0xa06204dc  sb          $v0, 0x4DC($v1)
    ctx->pc = 0x1da660u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 1244), (uint8_t)GPR_U32(ctx, 2));
    // 0x1da664: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da664u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da668: 0xa04004dd  sb          $zero, 0x4DD($v0)
    ctx->pc = 0x1da668u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 1245), (uint8_t)GPR_U32(ctx, 0));
    // 0x1da66c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da66cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da670: 0x24420520  addiu       $v0, $v0, 0x520
    ctx->pc = 0x1da670u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1312));
    // 0x1da674: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1da674u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da678: 0x2405006e  addiu       $a1, $zero, 0x6E
    ctx->pc = 0x1da678u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 110));
    // 0x1da67c: 0x2406000f  addiu       $a2, $zero, 0xF
    ctx->pc = 0x1da67cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1da680: 0x2407000a  addiu       $a3, $zero, 0xA
    ctx->pc = 0x1da680u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1da684: 0xc07c740  jal         func_1F1D00
    ctx->pc = 0x1DA684u;
    SET_GPR_U32(ctx, 31, 0x1DA68Cu);
    ctx->pc = 0x1F1D00u;
    if (runtime->hasFunction(0x1F1D00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA68Cu; }
        if (ctx->pc != 0x1DA68Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1D00_0x1f1d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA68Cu; }
        if (ctx->pc != 0x1DA68Cu) { return; }
    }
    ctx->pc = 0x1DA68Cu;
label_1da68c:
    // 0x1da68c: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1da68cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1da690: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1da690u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1da694: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1DA694u;
    {
        const bool branch_taken_0x1da694 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1da694) {
            ctx->pc = 0x1DA6B4u;
            goto label_1da6b4;
        }
    }
    ctx->pc = 0x1DA69Cu;
    // 0x1da69c: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da69cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da6a0: 0xc079f90  jal         func_1E7E40
    ctx->pc = 0x1DA6A0u;
    SET_GPR_U32(ctx, 31, 0x1DA6A8u);
    ctx->pc = 0x1E7E40u;
    if (runtime->hasFunction(0x1E7E40u)) {
        auto targetFn = runtime->lookupFunction(0x1E7E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA6A8u; }
        if (ctx->pc != 0x1DA6A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7E40_0x1e7e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA6A8u; }
        if (ctx->pc != 0x1DA6A8u) { return; }
    }
    ctx->pc = 0x1DA6A8u;
label_1da6a8:
    // 0x1da6a8: 0x2402ff9d  addiu       $v0, $zero, -0x63
    ctx->pc = 0x1da6a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967197));
    // 0x1da6ac: 0x10000123  b           . + 4 + (0x123 << 2)
    ctx->pc = 0x1DA6ACu;
    {
        const bool branch_taken_0x1da6ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1da6ac) {
            ctx->pc = 0x1DAB3Cu;
            goto label_1dab3c;
        }
    }
    ctx->pc = 0x1DA6B4u;
label_1da6b4:
    // 0x1da6b4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da6b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da6b8: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1da6b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1da6bc: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1da6bcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1da6c0: 0xc07a110  jal         func_1E8440
    ctx->pc = 0x1DA6C0u;
    SET_GPR_U32(ctx, 31, 0x1DA6C8u);
    ctx->pc = 0x1E8440u;
    if (runtime->hasFunction(0x1E8440u)) {
        auto targetFn = runtime->lookupFunction(0x1E8440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA6C8u; }
        if (ctx->pc != 0x1DA6C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8440_0x1e8440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA6C8u; }
        if (ctx->pc != 0x1DA6C8u) { return; }
    }
    ctx->pc = 0x1DA6C8u;
label_1da6c8:
    // 0x1da6c8: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x1da6c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1da6cc: 0xc079ca6  jal         func_1E7298
    ctx->pc = 0x1DA6CCu;
    SET_GPR_U32(ctx, 31, 0x1DA6D4u);
    ctx->pc = 0x1E7298u;
    if (runtime->hasFunction(0x1E7298u)) {
        auto targetFn = runtime->lookupFunction(0x1E7298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA6D4u; }
        if (ctx->pc != 0x1DA6D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7298_0x1e7298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA6D4u; }
        if (ctx->pc != 0x1DA6D4u) { return; }
    }
    ctx->pc = 0x1DA6D4u;
label_1da6d4:
    // 0x1da6d4: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da6d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da6d8: 0xac620058  sw          $v0, 0x58($v1)
    ctx->pc = 0x1da6d8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 88), GPR_U32(ctx, 2));
    // 0x1da6dc: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1DA6DCu;
    {
        const bool branch_taken_0x1da6dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1da6dc) {
            ctx->pc = 0x1DA70Cu;
            goto label_1da70c;
        }
    }
    ctx->pc = 0x1DA6E4u;
    // 0x1da6e4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da6e8: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1da6e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1da6ec: 0xc07cafc  jal         func_1F2BF0
    ctx->pc = 0x1DA6ECu;
    SET_GPR_U32(ctx, 31, 0x1DA6F4u);
    ctx->pc = 0x1F2BF0u;
    if (runtime->hasFunction(0x1F2BF0u)) {
        auto targetFn = runtime->lookupFunction(0x1F2BF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA6F4u; }
        if (ctx->pc != 0x1DA6F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2BF0_0x1f2bf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA6F4u; }
        if (ctx->pc != 0x1DA6F4u) { return; }
    }
    ctx->pc = 0x1DA6F4u;
label_1da6f4:
    // 0x1da6f4: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da6f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da6f8: 0xc079f90  jal         func_1E7E40
    ctx->pc = 0x1DA6F8u;
    SET_GPR_U32(ctx, 31, 0x1DA700u);
    ctx->pc = 0x1E7E40u;
    if (runtime->hasFunction(0x1E7E40u)) {
        auto targetFn = runtime->lookupFunction(0x1E7E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA700u; }
        if (ctx->pc != 0x1DA700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7E40_0x1e7e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA700u; }
        if (ctx->pc != 0x1DA700u) { return; }
    }
    ctx->pc = 0x1DA700u;
label_1da700:
    // 0x1da700: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x1da700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1da704: 0x1000010d  b           . + 4 + (0x10D << 2)
    ctx->pc = 0x1DA704u;
    {
        const bool branch_taken_0x1da704 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1da704) {
            ctx->pc = 0x1DAB3Cu;
            goto label_1dab3c;
        }
    }
    ctx->pc = 0x1DA70Cu;
label_1da70c:
    // 0x1da70c: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x1da70cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1da710: 0xc079cf0  jal         func_1E73C0
    ctx->pc = 0x1DA710u;
    SET_GPR_U32(ctx, 31, 0x1DA718u);
    ctx->pc = 0x1E73C0u;
    if (runtime->hasFunction(0x1E73C0u)) {
        auto targetFn = runtime->lookupFunction(0x1E73C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA718u; }
        if (ctx->pc != 0x1DA718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E73C0_0x1e73c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA718u; }
        if (ctx->pc != 0x1DA718u) { return; }
    }
    ctx->pc = 0x1DA718u;
label_1da718:
    // 0x1da718: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da718u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da71c: 0xac62005c  sw          $v0, 0x5C($v1)
    ctx->pc = 0x1da71cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 92), GPR_U32(ctx, 2));
    // 0x1da720: 0x14400010  bnez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1DA720u;
    {
        const bool branch_taken_0x1da720 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1da720) {
            ctx->pc = 0x1DA764u;
            goto label_1da764;
        }
    }
    ctx->pc = 0x1DA728u;
    // 0x1da728: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da728u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da72c: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da72cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da730: 0x8c450058  lw          $a1, 0x58($v0)
    ctx->pc = 0x1da730u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 88)));
    // 0x1da734: 0xc079cc6  jal         func_1E7318
    ctx->pc = 0x1DA734u;
    SET_GPR_U32(ctx, 31, 0x1DA73Cu);
    ctx->pc = 0x1E7318u;
    if (runtime->hasFunction(0x1E7318u)) {
        auto targetFn = runtime->lookupFunction(0x1E7318u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA73Cu; }
        if (ctx->pc != 0x1DA73Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7318_0x1e7318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA73Cu; }
        if (ctx->pc != 0x1DA73Cu) { return; }
    }
    ctx->pc = 0x1DA73Cu;
label_1da73c:
    // 0x1da73c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da73cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da740: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1da740u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1da744: 0xc07cafc  jal         func_1F2BF0
    ctx->pc = 0x1DA744u;
    SET_GPR_U32(ctx, 31, 0x1DA74Cu);
    ctx->pc = 0x1F2BF0u;
    if (runtime->hasFunction(0x1F2BF0u)) {
        auto targetFn = runtime->lookupFunction(0x1F2BF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA74Cu; }
        if (ctx->pc != 0x1DA74Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2BF0_0x1f2bf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA74Cu; }
        if (ctx->pc != 0x1DA74Cu) { return; }
    }
    ctx->pc = 0x1DA74Cu;
label_1da74c:
    // 0x1da74c: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da74cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da750: 0xc079f90  jal         func_1E7E40
    ctx->pc = 0x1DA750u;
    SET_GPR_U32(ctx, 31, 0x1DA758u);
    ctx->pc = 0x1E7E40u;
    if (runtime->hasFunction(0x1E7E40u)) {
        auto targetFn = runtime->lookupFunction(0x1E7E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA758u; }
        if (ctx->pc != 0x1DA758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7E40_0x1e7e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA758u; }
        if (ctx->pc != 0x1DA758u) { return; }
    }
    ctx->pc = 0x1DA758u;
label_1da758:
    // 0x1da758: 0x2402fffd  addiu       $v0, $zero, -0x3
    ctx->pc = 0x1da758u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x1da75c: 0x100000f7  b           . + 4 + (0xF7 << 2)
    ctx->pc = 0x1DA75Cu;
    {
        const bool branch_taken_0x1da75c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1da75c) {
            ctx->pc = 0x1DAB3Cu;
            goto label_1dab3c;
        }
    }
    ctx->pc = 0x1DA764u;
label_1da764:
    // 0x1da764: 0x24040024  addiu       $a0, $zero, 0x24
    ctx->pc = 0x1da764u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x1da768: 0xc076c04  jal         func_1DB010
    ctx->pc = 0x1DA768u;
    SET_GPR_U32(ctx, 31, 0x1DA770u);
    ctx->pc = 0x1DB010u;
    if (runtime->hasFunction(0x1DB010u)) {
        auto targetFn = runtime->lookupFunction(0x1DB010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA770u; }
        if (ctx->pc != 0x1DA770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB010_0x1db010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA770u; }
        if (ctx->pc != 0x1DA770u) { return; }
    }
    ctx->pc = 0x1DA770u;
label_1da770:
    // 0x1da770: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da770u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da774: 0xac620060  sw          $v0, 0x60($v1)
    ctx->pc = 0x1da774u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 96), GPR_U32(ctx, 2));
    // 0x1da778: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1DA778u;
    {
        const bool branch_taken_0x1da778 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1da778) {
            ctx->pc = 0x1DA7D0u;
            goto label_1da7d0;
        }
    }
    ctx->pc = 0x1DA780u;
    // 0x1da780: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da780u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da784: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da784u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da788: 0x8c450058  lw          $a1, 0x58($v0)
    ctx->pc = 0x1da788u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 88)));
    // 0x1da78c: 0xc079cc6  jal         func_1E7318
    ctx->pc = 0x1DA78Cu;
    SET_GPR_U32(ctx, 31, 0x1DA794u);
    ctx->pc = 0x1E7318u;
    if (runtime->hasFunction(0x1E7318u)) {
        auto targetFn = runtime->lookupFunction(0x1E7318u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA794u; }
        if (ctx->pc != 0x1DA794u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7318_0x1e7318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA794u; }
        if (ctx->pc != 0x1DA794u) { return; }
    }
    ctx->pc = 0x1DA794u;
label_1da794:
    // 0x1da794: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da794u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da798: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da798u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da79c: 0x8c45005c  lw          $a1, 0x5C($v0)
    ctx->pc = 0x1da79cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1da7a0: 0xc079d0e  jal         func_1E7438
    ctx->pc = 0x1DA7A0u;
    SET_GPR_U32(ctx, 31, 0x1DA7A8u);
    ctx->pc = 0x1E7438u;
    if (runtime->hasFunction(0x1E7438u)) {
        auto targetFn = runtime->lookupFunction(0x1E7438u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA7A8u; }
        if (ctx->pc != 0x1DA7A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7438_0x1e7438(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA7A8u; }
        if (ctx->pc != 0x1DA7A8u) { return; }
    }
    ctx->pc = 0x1DA7A8u;
label_1da7a8:
    // 0x1da7a8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da7a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da7ac: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1da7acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1da7b0: 0xc07cafc  jal         func_1F2BF0
    ctx->pc = 0x1DA7B0u;
    SET_GPR_U32(ctx, 31, 0x1DA7B8u);
    ctx->pc = 0x1F2BF0u;
    if (runtime->hasFunction(0x1F2BF0u)) {
        auto targetFn = runtime->lookupFunction(0x1F2BF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA7B8u; }
        if (ctx->pc != 0x1DA7B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2BF0_0x1f2bf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA7B8u; }
        if (ctx->pc != 0x1DA7B8u) { return; }
    }
    ctx->pc = 0x1DA7B8u;
label_1da7b8:
    // 0x1da7b8: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da7b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da7bc: 0xc079f90  jal         func_1E7E40
    ctx->pc = 0x1DA7BCu;
    SET_GPR_U32(ctx, 31, 0x1DA7C4u);
    ctx->pc = 0x1E7E40u;
    if (runtime->hasFunction(0x1E7E40u)) {
        auto targetFn = runtime->lookupFunction(0x1E7E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA7C4u; }
        if (ctx->pc != 0x1DA7C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7E40_0x1e7e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA7C4u; }
        if (ctx->pc != 0x1DA7C4u) { return; }
    }
    ctx->pc = 0x1DA7C4u;
label_1da7c4:
    // 0x1da7c4: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x1da7c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1da7c8: 0x100000dc  b           . + 4 + (0xDC << 2)
    ctx->pc = 0x1DA7C8u;
    {
        const bool branch_taken_0x1da7c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1da7c8) {
            ctx->pc = 0x1DAB3Cu;
            goto label_1dab3c;
        }
    }
    ctx->pc = 0x1DA7D0u;
label_1da7d0:
    // 0x1da7d0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da7d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da7d4: 0x24420068  addiu       $v0, $v0, 0x68
    ctx->pc = 0x1da7d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 104));
    // 0x1da7d8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1da7d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da7dc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1da7dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da7e0: 0xc07c417  jal         func_1F105C
    ctx->pc = 0x1DA7E0u;
    SET_GPR_U32(ctx, 31, 0x1DA7E8u);
    ctx->pc = 0x1F105Cu;
    if (runtime->hasFunction(0x1F105Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F105Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA7E8u; }
        if (ctx->pc != 0x1DA7E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F105C_0x1f105c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA7E8u; }
        if (ctx->pc != 0x1DA7E8u) { return; }
    }
    ctx->pc = 0x1DA7E8u;
label_1da7e8:
    // 0x1da7e8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1da7e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1da7ec: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1da7ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1da7f0: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1DA7F0u;
    {
        const bool branch_taken_0x1da7f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1da7f0) {
            ctx->pc = 0x1DA85Cu;
            goto label_1da85c;
        }
    }
    ctx->pc = 0x1DA7F8u;
    // 0x1da7f8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da7f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da7fc: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da7fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da800: 0x8c450060  lw          $a1, 0x60($v0)
    ctx->pc = 0x1da800u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1da804: 0xc076bda  jal         func_1DAF68
    ctx->pc = 0x1DA804u;
    SET_GPR_U32(ctx, 31, 0x1DA80Cu);
    ctx->pc = 0x1DAF68u;
    if (runtime->hasFunction(0x1DAF68u)) {
        auto targetFn = runtime->lookupFunction(0x1DAF68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA80Cu; }
        if (ctx->pc != 0x1DA80Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAF68_0x1daf68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA80Cu; }
        if (ctx->pc != 0x1DA80Cu) { return; }
    }
    ctx->pc = 0x1DA80Cu;
label_1da80c:
    // 0x1da80c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da80cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da810: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da810u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da814: 0x8c450058  lw          $a1, 0x58($v0)
    ctx->pc = 0x1da814u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 88)));
    // 0x1da818: 0xc079cc6  jal         func_1E7318
    ctx->pc = 0x1DA818u;
    SET_GPR_U32(ctx, 31, 0x1DA820u);
    ctx->pc = 0x1E7318u;
    if (runtime->hasFunction(0x1E7318u)) {
        auto targetFn = runtime->lookupFunction(0x1E7318u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA820u; }
        if (ctx->pc != 0x1DA820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7318_0x1e7318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA820u; }
        if (ctx->pc != 0x1DA820u) { return; }
    }
    ctx->pc = 0x1DA820u;
label_1da820:
    // 0x1da820: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da820u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da824: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da824u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da828: 0x8c45005c  lw          $a1, 0x5C($v0)
    ctx->pc = 0x1da828u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1da82c: 0xc079d0e  jal         func_1E7438
    ctx->pc = 0x1DA82Cu;
    SET_GPR_U32(ctx, 31, 0x1DA834u);
    ctx->pc = 0x1E7438u;
    if (runtime->hasFunction(0x1E7438u)) {
        auto targetFn = runtime->lookupFunction(0x1E7438u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA834u; }
        if (ctx->pc != 0x1DA834u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7438_0x1e7438(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA834u; }
        if (ctx->pc != 0x1DA834u) { return; }
    }
    ctx->pc = 0x1DA834u;
label_1da834:
    // 0x1da834: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da834u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da838: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1da838u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1da83c: 0xc07cafc  jal         func_1F2BF0
    ctx->pc = 0x1DA83Cu;
    SET_GPR_U32(ctx, 31, 0x1DA844u);
    ctx->pc = 0x1F2BF0u;
    if (runtime->hasFunction(0x1F2BF0u)) {
        auto targetFn = runtime->lookupFunction(0x1F2BF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA844u; }
        if (ctx->pc != 0x1DA844u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2BF0_0x1f2bf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA844u; }
        if (ctx->pc != 0x1DA844u) { return; }
    }
    ctx->pc = 0x1DA844u;
label_1da844:
    // 0x1da844: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da844u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da848: 0xc079f90  jal         func_1E7E40
    ctx->pc = 0x1DA848u;
    SET_GPR_U32(ctx, 31, 0x1DA850u);
    ctx->pc = 0x1E7E40u;
    if (runtime->hasFunction(0x1E7E40u)) {
        auto targetFn = runtime->lookupFunction(0x1E7E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA850u; }
        if (ctx->pc != 0x1DA850u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7E40_0x1e7e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA850u; }
        if (ctx->pc != 0x1DA850u) { return; }
    }
    ctx->pc = 0x1DA850u;
label_1da850:
    // 0x1da850: 0x2402fffb  addiu       $v0, $zero, -0x5
    ctx->pc = 0x1da850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
    // 0x1da854: 0x100000b9  b           . + 4 + (0xB9 << 2)
    ctx->pc = 0x1DA854u;
    {
        const bool branch_taken_0x1da854 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1da854) {
            ctx->pc = 0x1DAB3Cu;
            goto label_1dab3c;
        }
    }
    ctx->pc = 0x1DA85Cu;
label_1da85c:
    // 0x1da85c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1da85cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1da860: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1da860u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1da864: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1da864u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da868: 0xc07a14f  jal         func_1E853C
    ctx->pc = 0x1DA868u;
    SET_GPR_U32(ctx, 31, 0x1DA870u);
    ctx->pc = 0x1E853Cu;
    if (runtime->hasFunction(0x1E853Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E853Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA870u; }
        if (ctx->pc != 0x1DA870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E853C_0x1e853c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA870u; }
        if (ctx->pc != 0x1DA870u) { return; }
    }
    ctx->pc = 0x1DA870u;
label_1da870:
    // 0x1da870: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da870u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da874: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1da874u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da878: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1da878u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x1da87c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1da87cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1da880: 0x1482001a  bne         $a0, $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1DA880u;
    {
        const bool branch_taken_0x1da880 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x1da880) {
            ctx->pc = 0x1DA8ECu;
            goto label_1da8ec;
        }
    }
    ctx->pc = 0x1DA888u;
    // 0x1da888: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da888u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da88c: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da88cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da890: 0x8c450060  lw          $a1, 0x60($v0)
    ctx->pc = 0x1da890u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1da894: 0xc076bda  jal         func_1DAF68
    ctx->pc = 0x1DA894u;
    SET_GPR_U32(ctx, 31, 0x1DA89Cu);
    ctx->pc = 0x1DAF68u;
    if (runtime->hasFunction(0x1DAF68u)) {
        auto targetFn = runtime->lookupFunction(0x1DAF68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA89Cu; }
        if (ctx->pc != 0x1DA89Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAF68_0x1daf68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA89Cu; }
        if (ctx->pc != 0x1DA89Cu) { return; }
    }
    ctx->pc = 0x1DA89Cu;
label_1da89c:
    // 0x1da89c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da89cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da8a0: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da8a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da8a4: 0x8c450058  lw          $a1, 0x58($v0)
    ctx->pc = 0x1da8a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 88)));
    // 0x1da8a8: 0xc079cc6  jal         func_1E7318
    ctx->pc = 0x1DA8A8u;
    SET_GPR_U32(ctx, 31, 0x1DA8B0u);
    ctx->pc = 0x1E7318u;
    if (runtime->hasFunction(0x1E7318u)) {
        auto targetFn = runtime->lookupFunction(0x1E7318u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA8B0u; }
        if (ctx->pc != 0x1DA8B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7318_0x1e7318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA8B0u; }
        if (ctx->pc != 0x1DA8B0u) { return; }
    }
    ctx->pc = 0x1DA8B0u;
label_1da8b0:
    // 0x1da8b0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da8b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da8b4: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da8b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da8b8: 0x8c45005c  lw          $a1, 0x5C($v0)
    ctx->pc = 0x1da8b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1da8bc: 0xc079d0e  jal         func_1E7438
    ctx->pc = 0x1DA8BCu;
    SET_GPR_U32(ctx, 31, 0x1DA8C4u);
    ctx->pc = 0x1E7438u;
    if (runtime->hasFunction(0x1E7438u)) {
        auto targetFn = runtime->lookupFunction(0x1E7438u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA8C4u; }
        if (ctx->pc != 0x1DA8C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7438_0x1e7438(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA8C4u; }
        if (ctx->pc != 0x1DA8C4u) { return; }
    }
    ctx->pc = 0x1DA8C4u;
label_1da8c4:
    // 0x1da8c4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da8c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da8c8: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1da8c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1da8cc: 0xc07cafc  jal         func_1F2BF0
    ctx->pc = 0x1DA8CCu;
    SET_GPR_U32(ctx, 31, 0x1DA8D4u);
    ctx->pc = 0x1F2BF0u;
    if (runtime->hasFunction(0x1F2BF0u)) {
        auto targetFn = runtime->lookupFunction(0x1F2BF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA8D4u; }
        if (ctx->pc != 0x1DA8D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2BF0_0x1f2bf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA8D4u; }
        if (ctx->pc != 0x1DA8D4u) { return; }
    }
    ctx->pc = 0x1DA8D4u;
label_1da8d4:
    // 0x1da8d4: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da8d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da8d8: 0xc079f90  jal         func_1E7E40
    ctx->pc = 0x1DA8D8u;
    SET_GPR_U32(ctx, 31, 0x1DA8E0u);
    ctx->pc = 0x1E7E40u;
    if (runtime->hasFunction(0x1E7E40u)) {
        auto targetFn = runtime->lookupFunction(0x1E7E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA8E0u; }
        if (ctx->pc != 0x1DA8E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7E40_0x1e7e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA8E0u; }
        if (ctx->pc != 0x1DA8E0u) { return; }
    }
    ctx->pc = 0x1DA8E0u;
label_1da8e0:
    // 0x1da8e0: 0x2402fff8  addiu       $v0, $zero, -0x8
    ctx->pc = 0x1da8e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967288));
    // 0x1da8e4: 0x10000095  b           . + 4 + (0x95 << 2)
    ctx->pc = 0x1DA8E4u;
    {
        const bool branch_taken_0x1da8e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1da8e4) {
            ctx->pc = 0x1DAB3Cu;
            goto label_1dab3c;
        }
    }
    ctx->pc = 0x1DA8ECu;
label_1da8ec:
    // 0x1da8ec: 0x240207d0  addiu       $v0, $zero, 0x7D0
    ctx->pc = 0x1da8ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2000));
    // 0x1da8f0: 0xa7c20020  sh          $v0, 0x20($fp)
    ctx->pc = 0x1da8f0u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 32), (uint16_t)GPR_U32(ctx, 2));
label_1da8f4:
    // 0x1da8f4: 0x27c20010  addiu       $v0, $fp, 0x10
    ctx->pc = 0x1da8f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1da8f8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1da8f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da8fc: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1da8fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1da900: 0xc040e26  jal         func_103898
    ctx->pc = 0x1DA900u;
    SET_GPR_U32(ctx, 31, 0x1DA908u);
    ctx->pc = 0x103898u;
    if (runtime->hasFunction(0x103898u)) {
        auto targetFn = runtime->lookupFunction(0x103898u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA908u; }
        if (ctx->pc != 0x1DA908u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103898_0x103898(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA908u; }
        if (ctx->pc != 0x1DA908u) { return; }
    }
    ctx->pc = 0x1DA908u;
label_1da908:
    // 0x1da908: 0x97c20020  lhu         $v0, 0x20($fp)
    ctx->pc = 0x1da908u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1da90c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1da90cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da910: 0xc07a05f  jal         func_1E817C
    ctx->pc = 0x1DA910u;
    SET_GPR_U32(ctx, 31, 0x1DA918u);
    ctx->pc = 0x1E817Cu;
    if (runtime->hasFunction(0x1E817Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E817Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA918u; }
        if (ctx->pc != 0x1DA918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E817C_0x1e817c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA918u; }
        if (ctx->pc != 0x1DA918u) { return; }
    }
    ctx->pc = 0x1DA918u;
label_1da918:
    // 0x1da918: 0xa7c20012  sh          $v0, 0x12($fp)
    ctx->pc = 0x1da918u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 18), (uint16_t)GPR_U32(ctx, 2));
    // 0x1da91c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1da91cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1da920: 0xa7c20010  sh          $v0, 0x10($fp)
    ctx->pc = 0x1da920u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 16), (uint16_t)GPR_U32(ctx, 2));
    // 0x1da924: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da924u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da928: 0x27c30010  addiu       $v1, $fp, 0x10
    ctx->pc = 0x1da928u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1da92c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1da92cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1da930: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1da930u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da934: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1da934u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1da938: 0xc07a3cc  jal         func_1E8F30
    ctx->pc = 0x1DA938u;
    SET_GPR_U32(ctx, 31, 0x1DA940u);
    ctx->pc = 0x1E8F30u;
    if (runtime->hasFunction(0x1E8F30u)) {
        auto targetFn = runtime->lookupFunction(0x1E8F30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA940u; }
        if (ctx->pc != 0x1DA940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8F30_0x1e8f30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA940u; }
        if (ctx->pc != 0x1DA940u) { return; }
    }
    ctx->pc = 0x1DA940u;
label_1da940:
    // 0x1da940: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1DA940u;
    {
        const bool branch_taken_0x1da940 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1da940) {
            ctx->pc = 0x1DA95Cu;
            goto label_1da95c;
        }
    }
    ctx->pc = 0x1DA948u;
    // 0x1da948: 0x97c20020  lhu         $v0, 0x20($fp)
    ctx->pc = 0x1da948u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1da94c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1da94cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1da950: 0xa7c20020  sh          $v0, 0x20($fp)
    ctx->pc = 0x1da950u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 32), (uint16_t)GPR_U32(ctx, 2));
    // 0x1da954: 0x1000ffe7  b           . + 4 + (-0x19 << 2)
    ctx->pc = 0x1DA954u;
    {
        const bool branch_taken_0x1da954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1da954) {
            ctx->pc = 0x1DA8F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1da8f4;
        }
    }
    ctx->pc = 0x1DA95Cu;
label_1da95c:
    // 0x1da95c: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da95cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da960: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da960u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da964: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1da964u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1da968: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1da968u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1da96c: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da96cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da970: 0x97c20020  lhu         $v0, 0x20($fp)
    ctx->pc = 0x1da970u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1da974: 0xa462000a  sh          $v0, 0xA($v1)
    ctx->pc = 0x1da974u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 10), (uint16_t)GPR_U32(ctx, 2));
    // 0x1da978: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da978u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da97c: 0x8c44003c  lw          $a0, 0x3C($v0)
    ctx->pc = 0x1da97cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 60)));
    // 0x1da980: 0xc07a071  jal         func_1E81C4
    ctx->pc = 0x1DA980u;
    SET_GPR_U32(ctx, 31, 0x1DA988u);
    ctx->pc = 0x1E81C4u;
    if (runtime->hasFunction(0x1E81C4u)) {
        auto targetFn = runtime->lookupFunction(0x1E81C4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA988u; }
        if (ctx->pc != 0x1DA988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E81C4_0x1e81c4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA988u; }
        if (ctx->pc != 0x1DA988u) { return; }
    }
    ctx->pc = 0x1DA988u;
label_1da988:
    // 0x1da988: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1da988u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da98c: 0x21c00  sll         $v1, $v0, 16
    ctx->pc = 0x1da98cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1da990: 0x97c20020  lhu         $v0, 0x20($fp)
    ctx->pc = 0x1da990u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1da994: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1da994u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1da998: 0xac820044  sw          $v0, 0x44($a0)
    ctx->pc = 0x1da998u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 2));
    // 0x1da99c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da99cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da9a0: 0xac400508  sw          $zero, 0x508($v0)
    ctx->pc = 0x1da9a0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1288), GPR_U32(ctx, 0));
    // 0x1da9a4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1da9a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da9a8: 0xaf82801c  sw          $v0, -0x7FE4($gp)
    ctx->pc = 0x1da9a8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934556), GPR_U32(ctx, 2));
    // 0x1da9ac: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da9acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da9b0: 0x24020022  addiu       $v0, $zero, 0x22
    ctx->pc = 0x1da9b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1da9b4: 0xac620514  sw          $v0, 0x514($v1)
    ctx->pc = 0x1da9b4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1300), GPR_U32(ctx, 2));
    // 0x1da9b8: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1da9b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1da9bc: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1da9bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1da9c0: 0xac620518  sw          $v0, 0x518($v1)
    ctx->pc = 0x1da9c0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1304), GPR_U32(ctx, 2));
    // 0x1da9c4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1da9c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1da9c8: 0x10400045  beqz        $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x1DA9C8u;
    {
        const bool branch_taken_0x1da9c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1da9c8) {
            ctx->pc = 0x1DAAE0u;
            goto label_1daae0;
        }
    }
    ctx->pc = 0x1DA9D0u;
    // 0x1da9d0: 0xafc0002c  sw          $zero, 0x2C($fp)
    ctx->pc = 0x1da9d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 0));
label_1da9d4:
    // 0x1da9d4: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1da9d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1da9d8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1da9d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1da9dc: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1da9dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1da9e0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1da9e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1da9e4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1da9e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1da9e8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DA9E8u;
    {
        const bool branch_taken_0x1da9e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1da9e8) {
            ctx->pc = 0x1DA9F8u;
            goto label_1da9f8;
        }
    }
    ctx->pc = 0x1DA9F0u;
    // 0x1da9f0: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1DA9F0u;
    {
        const bool branch_taken_0x1da9f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1da9f0) {
            ctx->pc = 0x1DAAE0u;
            goto label_1daae0;
        }
    }
    ctx->pc = 0x1DA9F8u;
label_1da9f8:
    // 0x1da9f8: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1da9f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1da9fc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1da9fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1daa00: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1daa00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1daa04: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1daa04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1daa08: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1daa08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1daa0c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1daa0cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1daa10: 0x24a57cc8  addiu       $a1, $a1, 0x7CC8
    ctx->pc = 0x1daa10u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 31944));
    // 0x1daa14: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1DAA14u;
    SET_GPR_U32(ctx, 31, 0x1DAA1Cu);
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAA1Cu; }
        if (ctx->pc != 0x1DAA1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAA1Cu; }
        if (ctx->pc != 0x1DAA1Cu) { return; }
    }
    ctx->pc = 0x1DAA1Cu;
label_1daa1c:
    // 0x1daa1c: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1DAA1Cu;
    {
        const bool branch_taken_0x1daa1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1daa1c) {
            ctx->pc = 0x1DAA5Cu;
            goto label_1daa5c;
        }
    }
    ctx->pc = 0x1DAA24u;
    // 0x1daa24: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1daa24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1daa28: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1daa28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1daa2c: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1daa2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1daa30: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1daa30u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1daa34: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1daa34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1daa38: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1daa38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1daa3c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1daa3cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1daa40: 0xc040de0  jal         func_103780
    ctx->pc = 0x1DAA40u;
    SET_GPR_U32(ctx, 31, 0x1DAA48u);
    ctx->pc = 0x103780u;
    if (runtime->hasFunction(0x103780u)) {
        auto targetFn = runtime->lookupFunction(0x103780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAA48u; }
        if (ctx->pc != 0x1DAA48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103780_0x103780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAA48u; }
        if (ctx->pc != 0x1DAA48u) { return; }
    }
    ctx->pc = 0x1DAA48u;
label_1daa48:
    // 0x1daa48: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1daa48u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1daa4c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1daa4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1daa50: 0xac430514  sw          $v1, 0x514($v0)
    ctx->pc = 0x1daa50u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1300), GPR_U32(ctx, 3));
    // 0x1daa54: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1DAA54u;
    {
        const bool branch_taken_0x1daa54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1daa54) {
            ctx->pc = 0x1DAACCu;
            goto label_1daacc;
        }
    }
    ctx->pc = 0x1DAA5Cu;
label_1daa5c:
    // 0x1daa5c: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1daa5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1daa60: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1daa60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1daa64: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1daa64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1daa68: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1daa68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1daa6c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1daa6cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1daa70: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1daa70u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1daa74: 0x24a57cd8  addiu       $a1, $a1, 0x7CD8
    ctx->pc = 0x1daa74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 31960));
    // 0x1daa78: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1DAA78u;
    SET_GPR_U32(ctx, 31, 0x1DAA80u);
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAA80u; }
        if (ctx->pc != 0x1DAA80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAA80u; }
        if (ctx->pc != 0x1DAA80u) { return; }
    }
    ctx->pc = 0x1DAA80u;
label_1daa80:
    // 0x1daa80: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1DAA80u;
    {
        const bool branch_taken_0x1daa80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1daa80) {
            ctx->pc = 0x1DAAC0u;
            goto label_1daac0;
        }
    }
    ctx->pc = 0x1DAA88u;
    // 0x1daa88: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1daa88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1daa8c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1daa8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1daa90: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1daa90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1daa94: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1daa94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1daa98: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1daa98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1daa9c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1daa9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1daaa0: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1daaa0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1daaa4: 0xc040de0  jal         func_103780
    ctx->pc = 0x1DAAA4u;
    SET_GPR_U32(ctx, 31, 0x1DAAACu);
    ctx->pc = 0x103780u;
    if (runtime->hasFunction(0x103780u)) {
        auto targetFn = runtime->lookupFunction(0x103780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAAACu; }
        if (ctx->pc != 0x1DAAACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103780_0x103780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAAACu; }
        if (ctx->pc != 0x1DAAACu) { return; }
    }
    ctx->pc = 0x1DAAACu;
label_1daaac:
    // 0x1daaac: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1daaacu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1daab0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1daab0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1daab4: 0xac430518  sw          $v1, 0x518($v0)
    ctx->pc = 0x1daab4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1304), GPR_U32(ctx, 3));
    // 0x1daab8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1DAAB8u;
    {
        const bool branch_taken_0x1daab8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1daab8) {
            ctx->pc = 0x1DAACCu;
            goto label_1daacc;
        }
    }
    ctx->pc = 0x1DAAC0u;
label_1daac0:
    // 0x1daac0: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1daac0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1daac4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1daac4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1daac8: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1daac8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
label_1daacc:
    // 0x1daacc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1daaccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1daad0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1daad0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1daad4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1daad4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1daad8: 0x1000ffbe  b           . + 4 + (-0x42 << 2)
    ctx->pc = 0x1DAAD8u;
    {
        const bool branch_taken_0x1daad8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1daad8) {
            ctx->pc = 0x1DA9D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1da9d4;
        }
    }
    ctx->pc = 0x1DAAE0u;
label_1daae0:
    // 0x1daae0: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1daae0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1daae4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1daae4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1daae8: 0x8c420514  lw          $v0, 0x514($v0)
    ctx->pc = 0x1daae8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1300)));
    // 0x1daaec: 0xac620510  sw          $v0, 0x510($v1)
    ctx->pc = 0x1daaecu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1296), GPR_U32(ctx, 2));
    // 0x1daaf0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1daaf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1daaf4: 0xac400524  sw          $zero, 0x524($v0)
    ctx->pc = 0x1daaf4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1316), GPR_U32(ctx, 0));
    // 0x1daaf8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1daaf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1daafc: 0xac400528  sw          $zero, 0x528($v0)
    ctx->pc = 0x1daafcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1320), GPR_U32(ctx, 0));
    // 0x1dab00: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1dab00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dab04: 0xac40052c  sw          $zero, 0x52C($v0)
    ctx->pc = 0x1dab04u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1324), GPR_U32(ctx, 0));
    // 0x1dab08: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1dab08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dab0c: 0xac400530  sw          $zero, 0x530($v0)
    ctx->pc = 0x1dab0cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1328), GPR_U32(ctx, 0));
    // 0x1dab10: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1dab10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dab14: 0xac400534  sw          $zero, 0x534($v0)
    ctx->pc = 0x1dab14u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1332), GPR_U32(ctx, 0));
    // 0x1dab18: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1dab18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dab1c: 0xac400538  sw          $zero, 0x538($v0)
    ctx->pc = 0x1dab1cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1336), GPR_U32(ctx, 0));
    // 0x1dab20: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1dab20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dab24: 0xac40053c  sw          $zero, 0x53C($v0)
    ctx->pc = 0x1dab24u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1340), GPR_U32(ctx, 0));
    // 0x1dab28: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1dab28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dab2c: 0xac400540  sw          $zero, 0x540($v0)
    ctx->pc = 0x1dab2cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1344), GPR_U32(ctx, 0));
    // 0x1dab30: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1dab30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dab34: 0xac400544  sw          $zero, 0x544($v0)
    ctx->pc = 0x1dab34u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1348), GPR_U32(ctx, 0));
    // 0x1dab38: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1dab38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1dab3c:
    // 0x1dab3c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dab3cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dab40: 0xdfbe0030  ld          $fp, 0x30($sp)
    ctx->pc = 0x1dab40u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1dab44: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1dab44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1dab48: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1dab48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1dab4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1DAB4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DA54Cu: goto label_1da54c;
            case 0x1DA558u: goto label_1da558;
            case 0x1DA578u: goto label_1da578;
            case 0x1DA58Cu: goto label_1da58c;
            case 0x1DA5A4u: goto label_1da5a4;
            case 0x1DA5C0u: goto label_1da5c0;
            case 0x1DA68Cu: goto label_1da68c;
            case 0x1DA6A8u: goto label_1da6a8;
            case 0x1DA6B4u: goto label_1da6b4;
            case 0x1DA6C8u: goto label_1da6c8;
            case 0x1DA6D4u: goto label_1da6d4;
            case 0x1DA6F4u: goto label_1da6f4;
            case 0x1DA700u: goto label_1da700;
            case 0x1DA70Cu: goto label_1da70c;
            case 0x1DA718u: goto label_1da718;
            case 0x1DA73Cu: goto label_1da73c;
            case 0x1DA74Cu: goto label_1da74c;
            case 0x1DA758u: goto label_1da758;
            case 0x1DA764u: goto label_1da764;
            case 0x1DA770u: goto label_1da770;
            case 0x1DA794u: goto label_1da794;
            case 0x1DA7A8u: goto label_1da7a8;
            case 0x1DA7B8u: goto label_1da7b8;
            case 0x1DA7C4u: goto label_1da7c4;
            case 0x1DA7D0u: goto label_1da7d0;
            case 0x1DA7E8u: goto label_1da7e8;
            case 0x1DA80Cu: goto label_1da80c;
            case 0x1DA820u: goto label_1da820;
            case 0x1DA834u: goto label_1da834;
            case 0x1DA844u: goto label_1da844;
            case 0x1DA850u: goto label_1da850;
            case 0x1DA85Cu: goto label_1da85c;
            case 0x1DA870u: goto label_1da870;
            case 0x1DA89Cu: goto label_1da89c;
            case 0x1DA8B0u: goto label_1da8b0;
            case 0x1DA8C4u: goto label_1da8c4;
            case 0x1DA8D4u: goto label_1da8d4;
            case 0x1DA8E0u: goto label_1da8e0;
            case 0x1DA8ECu: goto label_1da8ec;
            case 0x1DA8F4u: goto label_1da8f4;
            case 0x1DA908u: goto label_1da908;
            case 0x1DA918u: goto label_1da918;
            case 0x1DA940u: goto label_1da940;
            case 0x1DA95Cu: goto label_1da95c;
            case 0x1DA988u: goto label_1da988;
            case 0x1DA9D4u: goto label_1da9d4;
            case 0x1DA9F8u: goto label_1da9f8;
            case 0x1DAA1Cu: goto label_1daa1c;
            case 0x1DAA48u: goto label_1daa48;
            case 0x1DAA5Cu: goto label_1daa5c;
            case 0x1DAA80u: goto label_1daa80;
            case 0x1DAAACu: goto label_1daaac;
            case 0x1DAAC0u: goto label_1daac0;
            case 0x1DAACCu: goto label_1daacc;
            case 0x1DAAE0u: goto label_1daae0;
            case 0x1DAB3Cu: goto label_1dab3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DAB54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
