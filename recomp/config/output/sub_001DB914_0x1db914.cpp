#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DB914
// Address: 0x1db914 - 0x1dc1e8
void sub_001DB914_0x1db914(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DB914_0x1db914");
#endif

    switch (ctx->pc) {
        case 0x1db944u: goto label_1db944;
        case 0x1db974u: goto label_1db974;
        case 0x1db994u: goto label_1db994;
        case 0x1db9b8u: goto label_1db9b8;
        case 0x1db9ccu: goto label_1db9cc;
        case 0x1db9d0u: goto label_1db9d0;
        case 0x1db9ecu: goto label_1db9ec;
        case 0x1dba0cu: goto label_1dba0c;
        case 0x1dba28u: goto label_1dba28;
        case 0x1dba50u: goto label_1dba50;
        case 0x1dba64u: goto label_1dba64;
        case 0x1dba74u: goto label_1dba74;
        case 0x1dba84u: goto label_1dba84;
        case 0x1dba94u: goto label_1dba94;
        case 0x1dbaa4u: goto label_1dbaa4;
        case 0x1dbac8u: goto label_1dbac8;
        case 0x1dbaf8u: goto label_1dbaf8;
        case 0x1dbb24u: goto label_1dbb24;
        case 0x1dbb48u: goto label_1dbb48;
        case 0x1dbb5cu: goto label_1dbb5c;
        case 0x1dbb70u: goto label_1dbb70;
        case 0x1dbb84u: goto label_1dbb84;
        case 0x1dbb94u: goto label_1dbb94;
        case 0x1dbba4u: goto label_1dbba4;
        case 0x1dbbc0u: goto label_1dbbc0;
        case 0x1dbbf0u: goto label_1dbbf0;
        case 0x1dbc24u: goto label_1dbc24;
        case 0x1dbc3cu: goto label_1dbc3c;
        case 0x1dbc70u: goto label_1dbc70;
        case 0x1dbc84u: goto label_1dbc84;
        case 0x1dbca4u: goto label_1dbca4;
        case 0x1dbcc4u: goto label_1dbcc4;
        case 0x1dbce4u: goto label_1dbce4;
        case 0x1dbcfcu: goto label_1dbcfc;
        case 0x1dbd14u: goto label_1dbd14;
        case 0x1dbd34u: goto label_1dbd34;
        case 0x1dbd50u: goto label_1dbd50;
        case 0x1dbd78u: goto label_1dbd78;
        case 0x1dbd88u: goto label_1dbd88;
        case 0x1dbdb0u: goto label_1dbdb0;
        case 0x1dbdd8u: goto label_1dbdd8;
        case 0x1dbdecu: goto label_1dbdec;
        case 0x1dbe08u: goto label_1dbe08;
        case 0x1dbe38u: goto label_1dbe38;
        case 0x1dbe54u: goto label_1dbe54;
        case 0x1dbe64u: goto label_1dbe64;
        case 0x1dbe84u: goto label_1dbe84;
        case 0x1dbeacu: goto label_1dbeac;
        case 0x1dbed8u: goto label_1dbed8;
        case 0x1dbf10u: goto label_1dbf10;
        case 0x1dbf40u: goto label_1dbf40;
        case 0x1dbf60u: goto label_1dbf60;
        case 0x1dbf80u: goto label_1dbf80;
        case 0x1dbfa0u: goto label_1dbfa0;
        case 0x1dbfc0u: goto label_1dbfc0;
        case 0x1dbfd8u: goto label_1dbfd8;
        case 0x1dbff0u: goto label_1dbff0;
        case 0x1dc010u: goto label_1dc010;
        case 0x1dc028u: goto label_1dc028;
        case 0x1dc040u: goto label_1dc040;
        case 0x1dc06cu: goto label_1dc06c;
        case 0x1dc0bcu: goto label_1dc0bc;
        case 0x1dc0ecu: goto label_1dc0ec;
        case 0x1dc118u: goto label_1dc118;
        case 0x1dc12cu: goto label_1dc12c;
        case 0x1dc14cu: goto label_1dc14c;
        case 0x1dc164u: goto label_1dc164;
        case 0x1dc17cu: goto label_1dc17c;
        case 0x1dc194u: goto label_1dc194;
        case 0x1dc1b0u: goto label_1dc1b0;
        default: break;
    }

    ctx->pc = 0x1db914u;

    // 0x1db914: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1db914u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1db918: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x1db918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1db91c: 0xffbe0028  sd          $fp, 0x28($sp)
    ctx->pc = 0x1db91cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 30));
    // 0x1db920: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1db920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1db924: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1db924u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db928: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1db928u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1db92c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1db92cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db930: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1db930u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1db934: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1db934u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1db938: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1db938u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db93c: 0xc07c441  jal         func_1F1104
    ctx->pc = 0x1DB93Cu;
    SET_GPR_U32(ctx, 31, 0x1DB944u);
    ctx->pc = 0x1F1104u;
    if (runtime->hasFunction(0x1F1104u)) {
        auto targetFn = runtime->lookupFunction(0x1F1104u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB944u; }
        if (ctx->pc != 0x1DB944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1104_0x1f1104(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB944u; }
        if (ctx->pc != 0x1DB944u) { return; }
    }
    ctx->pc = 0x1DB944u;
label_1db944:
    // 0x1db944: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x1db944u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x1db948: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DB948u;
    {
        const bool branch_taken_0x1db948 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db948) {
            ctx->pc = 0x1DB95Cu;
            goto label_1db95c;
        }
    }
    ctx->pc = 0x1DB950u;
    // 0x1db950: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1db950u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db954: 0x1000021d  b           . + 4 + (0x21D << 2)
    ctx->pc = 0x1DB954u;
    {
        const bool branch_taken_0x1db954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db954) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DB95Cu;
label_1db95c:
    // 0x1db95c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1db95cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db960: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1db960u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1db964: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1db964u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1db968: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1db968u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db96c: 0xc07c6e1  jal         func_1F1B84
    ctx->pc = 0x1DB96Cu;
    SET_GPR_U32(ctx, 31, 0x1DB974u);
    ctx->pc = 0x1F1B84u;
    if (runtime->hasFunction(0x1F1B84u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B84u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB974u; }
        if (ctx->pc != 0x1DB974u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B84_0x1f1b84(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB974u; }
        if (ctx->pc != 0x1DB974u) { return; }
    }
    ctx->pc = 0x1DB974u;
label_1db974:
    // 0x1db974: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db974u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1db978: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1db978u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db97c: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1db97cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1db980: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1db980u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1db984: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1db984u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db988: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1db988u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db98c: 0xc07c5a2  jal         func_1F1688
    ctx->pc = 0x1DB98Cu;
    SET_GPR_U32(ctx, 31, 0x1DB994u);
    ctx->pc = 0x1F1688u;
    if (runtime->hasFunction(0x1F1688u)) {
        auto targetFn = runtime->lookupFunction(0x1F1688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB994u; }
        if (ctx->pc != 0x1DB994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1688_0x1f1688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB994u; }
        if (ctx->pc != 0x1DB994u) { return; }
    }
    ctx->pc = 0x1DB994u;
label_1db994:
    // 0x1db994: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DB994u;
    {
        const bool branch_taken_0x1db994 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db994) {
            ctx->pc = 0x1DB9A8u;
            goto label_1db9a8;
        }
    }
    ctx->pc = 0x1DB99Cu;
    // 0x1db99c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1db99cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db9a0: 0x1000020a  b           . + 4 + (0x20A << 2)
    ctx->pc = 0x1DB9A0u;
    {
        const bool branch_taken_0x1db9a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db9a0) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DB9A8u;
label_1db9a8:
    // 0x1db9a8: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1db9a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db9ac: 0x24051000  addiu       $a1, $zero, 0x1000
    ctx->pc = 0x1db9acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1db9b0: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DB9B0u;
    SET_GPR_U32(ctx, 31, 0x1DB9B8u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB9B8u; }
        if (ctx->pc != 0x1DB9B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB9B8u; }
        if (ctx->pc != 0x1DB9B8u) { return; }
    }
    ctx->pc = 0x1DB9B8u;
label_1db9b8:
    // 0x1db9b8: 0x14400056  bnez        $v0, . + 4 + (0x56 << 2)
    ctx->pc = 0x1DB9B8u;
    {
        const bool branch_taken_0x1db9b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db9b8) {
            ctx->pc = 0x1DBB14u;
            goto label_1dbb14;
        }
    }
    ctx->pc = 0x1DB9C0u;
    // 0x1db9c0: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1db9c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db9c4: 0xc07c6eb  jal         func_1F1BAC
    ctx->pc = 0x1DB9C4u;
    SET_GPR_U32(ctx, 31, 0x1DB9CCu);
    ctx->pc = 0x1F1BACu;
    if (runtime->hasFunction(0x1F1BACu)) {
        auto targetFn = runtime->lookupFunction(0x1F1BACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB9CCu; }
        if (ctx->pc != 0x1DB9CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1BAC_0x1f1bac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB9CCu; }
        if (ctx->pc != 0x1DB9CCu) { return; }
    }
    ctx->pc = 0x1DB9CCu;
label_1db9cc:
    // 0x1db9cc: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1db9ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
label_1db9d0:
    // 0x1db9d0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1db9d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db9d4: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1db9d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1db9d8: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1db9d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1db9dc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1db9dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db9e0: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1db9e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1db9e4: 0xc07c5a2  jal         func_1F1688
    ctx->pc = 0x1DB9E4u;
    SET_GPR_U32(ctx, 31, 0x1DB9ECu);
    ctx->pc = 0x1F1688u;
    if (runtime->hasFunction(0x1F1688u)) {
        auto targetFn = runtime->lookupFunction(0x1F1688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB9ECu; }
        if (ctx->pc != 0x1DB9ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1688_0x1f1688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB9ECu; }
        if (ctx->pc != 0x1DB9ECu) { return; }
    }
    ctx->pc = 0x1DB9ECu;
label_1db9ec:
    // 0x1db9ec: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DB9ECu;
    {
        const bool branch_taken_0x1db9ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db9ec) {
            ctx->pc = 0x1DB9FCu;
            goto label_1db9fc;
        }
    }
    ctx->pc = 0x1DB9F4u;
    // 0x1db9f4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1DB9F4u;
    {
        const bool branch_taken_0x1db9f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db9f4) {
            ctx->pc = 0x1DBA34u;
            goto label_1dba34;
        }
    }
    ctx->pc = 0x1DB9FCu;
label_1db9fc:
    // 0x1db9fc: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1db9fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dba00: 0x24051000  addiu       $a1, $zero, 0x1000
    ctx->pc = 0x1dba00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1dba04: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBA04u;
    SET_GPR_U32(ctx, 31, 0x1DBA0Cu);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA0Cu; }
        if (ctx->pc != 0x1DBA0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA0Cu; }
        if (ctx->pc != 0x1DBA0Cu) { return; }
    }
    ctx->pc = 0x1DBA0Cu;
label_1dba0c:
    // 0x1dba0c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DBA0Cu;
    {
        const bool branch_taken_0x1dba0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dba0c) {
            ctx->pc = 0x1DBA1Cu;
            goto label_1dba1c;
        }
    }
    ctx->pc = 0x1DBA14u;
    // 0x1dba14: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1DBA14u;
    {
        const bool branch_taken_0x1dba14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dba14) {
            ctx->pc = 0x1DBA34u;
            goto label_1dba34;
        }
    }
    ctx->pc = 0x1DBA1Cu;
label_1dba1c:
    // 0x1dba1c: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dba1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dba20: 0xc07c6eb  jal         func_1F1BAC
    ctx->pc = 0x1DBA20u;
    SET_GPR_U32(ctx, 31, 0x1DBA28u);
    ctx->pc = 0x1F1BACu;
    if (runtime->hasFunction(0x1F1BACu)) {
        auto targetFn = runtime->lookupFunction(0x1F1BACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA28u; }
        if (ctx->pc != 0x1DBA28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1BAC_0x1f1bac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA28u; }
        if (ctx->pc != 0x1DBA28u) { return; }
    }
    ctx->pc = 0x1DBA28u;
label_1dba28:
    // 0x1dba28: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dba28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dba2c: 0x1000ffe8  b           . + 4 + (-0x18 << 2)
    ctx->pc = 0x1DBA2Cu;
    {
        const bool branch_taken_0x1dba2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dba2c) {
            ctx->pc = 0x1DB9D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1db9d0;
        }
    }
    ctx->pc = 0x1DBA34u;
label_1dba34:
    // 0x1dba34: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dba34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dba38: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1dba38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dba3c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1dba3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dba40: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dba40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dba44: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1dba44u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dba48: 0xc07c5a2  jal         func_1F1688
    ctx->pc = 0x1DBA48u;
    SET_GPR_U32(ctx, 31, 0x1DBA50u);
    ctx->pc = 0x1F1688u;
    if (runtime->hasFunction(0x1F1688u)) {
        auto targetFn = runtime->lookupFunction(0x1F1688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA50u; }
        if (ctx->pc != 0x1DBA50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1688_0x1f1688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA50u; }
        if (ctx->pc != 0x1DBA50u) { return; }
    }
    ctx->pc = 0x1DBA50u;
label_1dba50:
    // 0x1dba50: 0x14400030  bnez        $v0, . + 4 + (0x30 << 2)
    ctx->pc = 0x1DBA50u;
    {
        const bool branch_taken_0x1dba50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dba50) {
            ctx->pc = 0x1DBB14u;
            goto label_1dbb14;
        }
    }
    ctx->pc = 0x1DBA58u;
    // 0x1dba58: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dba58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dba5c: 0xc07cd0f  jal         func_1F343C
    ctx->pc = 0x1DBA5Cu;
    SET_GPR_U32(ctx, 31, 0x1DBA64u);
    ctx->pc = 0x1F343Cu;
    if (runtime->hasFunction(0x1F343Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F343Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA64u; }
        if (ctx->pc != 0x1DBA64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F343C_0x1f343c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA64u; }
        if (ctx->pc != 0x1DBA64u) { return; }
    }
    ctx->pc = 0x1DBA64u;
label_1dba64:
    // 0x1dba64: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dba64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dba68: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1dba68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dba6c: 0xc07cd19  jal         func_1F3464
    ctx->pc = 0x1DBA6Cu;
    SET_GPR_U32(ctx, 31, 0x1DBA74u);
    ctx->pc = 0x1F3464u;
    if (runtime->hasFunction(0x1F3464u)) {
        auto targetFn = runtime->lookupFunction(0x1F3464u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA74u; }
        if (ctx->pc != 0x1DBA74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3464_0x1f3464(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA74u; }
        if (ctx->pc != 0x1DBA74u) { return; }
    }
    ctx->pc = 0x1DBA74u;
label_1dba74:
    // 0x1dba74: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dba74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dba78: 0x24051000  addiu       $a1, $zero, 0x1000
    ctx->pc = 0x1dba78u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1dba7c: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1DBA7Cu;
    SET_GPR_U32(ctx, 31, 0x1DBA84u);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA84u; }
        if (ctx->pc != 0x1DBA84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA84u; }
        if (ctx->pc != 0x1DBA84u) { return; }
    }
    ctx->pc = 0x1DBA84u;
label_1dba84:
    // 0x1dba84: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dba84u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dba88: 0x24051000  addiu       $a1, $zero, 0x1000
    ctx->pc = 0x1dba88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1dba8c: 0xc07c690  jal         func_1F1A40
    ctx->pc = 0x1DBA8Cu;
    SET_GPR_U32(ctx, 31, 0x1DBA94u);
    ctx->pc = 0x1F1A40u;
    if (runtime->hasFunction(0x1F1A40u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA94u; }
        if (ctx->pc != 0x1DBA94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A40_0x1f1a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBA94u; }
        if (ctx->pc != 0x1DBA94u) { return; }
    }
    ctx->pc = 0x1DBA94u;
label_1dba94:
    // 0x1dba94: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dba94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dba98: 0x24050200  addiu       $a1, $zero, 0x200
    ctx->pc = 0x1dba98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x1dba9c: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBA9Cu;
    SET_GPR_U32(ctx, 31, 0x1DBAA4u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBAA4u; }
        if (ctx->pc != 0x1DBAA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBAA4u; }
        if (ctx->pc != 0x1DBAA4u) { return; }
    }
    ctx->pc = 0x1DBAA4u;
label_1dbaa4:
    // 0x1dbaa4: 0x1040001b  beqz        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1DBAA4u;
    {
        const bool branch_taken_0x1dbaa4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbaa4) {
            ctx->pc = 0x1DBB14u;
            goto label_1dbb14;
        }
    }
    ctx->pc = 0x1DBAACu;
    // 0x1dbaac: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dbaacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dbab0: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1dbab0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dbab4: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1dbab4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dbab8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dbab8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbabc: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1dbabcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbac0: 0xc07c4c3  jal         func_1F130C
    ctx->pc = 0x1DBAC0u;
    SET_GPR_U32(ctx, 31, 0x1DBAC8u);
    ctx->pc = 0x1F130Cu;
    if (runtime->hasFunction(0x1F130Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F130Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBAC8u; }
        if (ctx->pc != 0x1DBAC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F130C_0x1f130c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBAC8u; }
        if (ctx->pc != 0x1DBAC8u) { return; }
    }
    ctx->pc = 0x1DBAC8u;
label_1dbac8:
    // 0x1dbac8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1dbac8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1dbacc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbaccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbad0: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DBAD0u;
    {
        const bool branch_taken_0x1dbad0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbad0) {
            ctx->pc = 0x1DBAE4u;
            goto label_1dbae4;
        }
    }
    ctx->pc = 0x1DBAD8u;
    // 0x1dbad8: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbad8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbadc: 0x100001bb  b           . + 4 + (0x1BB << 2)
    ctx->pc = 0x1DBADCu;
    {
        const bool branch_taken_0x1dbadc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbadc) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DBAE4u;
label_1dbae4:
    // 0x1dbae4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dbae4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dbae8: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dbae8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dbaec: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1dbaecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbaf0: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1DBAF0u;
    SET_GPR_U32(ctx, 31, 0x1DBAF8u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBAF8u; }
        if (ctx->pc != 0x1DBAF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBAF8u; }
        if (ctx->pc != 0x1DBAF8u) { return; }
    }
    ctx->pc = 0x1DBAF8u;
label_1dbaf8:
    // 0x1dbaf8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1dbaf8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1dbafc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbafcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbb00: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DBB00u;
    {
        const bool branch_taken_0x1dbb00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbb00) {
            ctx->pc = 0x1DBB14u;
            goto label_1dbb14;
        }
    }
    ctx->pc = 0x1DBB08u;
    // 0x1dbb08: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbb08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbb0c: 0x100001af  b           . + 4 + (0x1AF << 2)
    ctx->pc = 0x1DBB0Cu;
    {
        const bool branch_taken_0x1dbb0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbb0c) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DBB14u;
label_1dbb14:
    // 0x1dbb14: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbb14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbb18: 0x24052000  addiu       $a1, $zero, 0x2000
    ctx->pc = 0x1dbb18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1dbb1c: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBB1Cu;
    SET_GPR_U32(ctx, 31, 0x1DBB24u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBB24u; }
        if (ctx->pc != 0x1DBB24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBB24u; }
        if (ctx->pc != 0x1DBB24u) { return; }
    }
    ctx->pc = 0x1DBB24u;
label_1dbb24:
    // 0x1dbb24: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DBB24u;
    {
        const bool branch_taken_0x1dbb24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbb24) {
            ctx->pc = 0x1DBB38u;
            goto label_1dbb38;
        }
    }
    ctx->pc = 0x1DBB2Cu;
    // 0x1dbb2c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1dbb2cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbb30: 0x100001a6  b           . + 4 + (0x1A6 << 2)
    ctx->pc = 0x1DBB30u;
    {
        const bool branch_taken_0x1dbb30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbb30) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DBB38u;
label_1dbb38:
    // 0x1dbb38: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbb38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbb3c: 0x24050200  addiu       $a1, $zero, 0x200
    ctx->pc = 0x1dbb3cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x1dbb40: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBB40u;
    SET_GPR_U32(ctx, 31, 0x1DBB48u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBB48u; }
        if (ctx->pc != 0x1DBB48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBB48u; }
        if (ctx->pc != 0x1DBB48u) { return; }
    }
    ctx->pc = 0x1DBB48u;
label_1dbb48:
    // 0x1dbb48: 0x10400032  beqz        $v0, . + 4 + (0x32 << 2)
    ctx->pc = 0x1DBB48u;
    {
        const bool branch_taken_0x1dbb48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbb48) {
            ctx->pc = 0x1DBC14u;
            goto label_1dbc14;
        }
    }
    ctx->pc = 0x1DBB50u;
    // 0x1dbb50: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbb50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbb54: 0xc07c6eb  jal         func_1F1BAC
    ctx->pc = 0x1DBB54u;
    SET_GPR_U32(ctx, 31, 0x1DBB5Cu);
    ctx->pc = 0x1F1BACu;
    if (runtime->hasFunction(0x1F1BACu)) {
        auto targetFn = runtime->lookupFunction(0x1F1BACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBB5Cu; }
        if (ctx->pc != 0x1DBB5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1BAC_0x1f1bac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBB5Cu; }
        if (ctx->pc != 0x1DBB5Cu) { return; }
    }
    ctx->pc = 0x1DBB5Cu;
label_1dbb5c:
    // 0x1dbb5c: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dbb5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dbb60: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbb60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbb64: 0x24051000  addiu       $a1, $zero, 0x1000
    ctx->pc = 0x1dbb64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1dbb68: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBB68u;
    SET_GPR_U32(ctx, 31, 0x1DBB70u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBB70u; }
        if (ctx->pc != 0x1DBB70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBB70u; }
        if (ctx->pc != 0x1DBB70u) { return; }
    }
    ctx->pc = 0x1DBB70u;
label_1dbb70:
    // 0x1dbb70: 0x14400028  bnez        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x1DBB70u;
    {
        const bool branch_taken_0x1dbb70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dbb70) {
            ctx->pc = 0x1DBC14u;
            goto label_1dbc14;
        }
    }
    ctx->pc = 0x1DBB78u;
    // 0x1dbb78: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbb78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbb7c: 0xc07cd0f  jal         func_1F343C
    ctx->pc = 0x1DBB7Cu;
    SET_GPR_U32(ctx, 31, 0x1DBB84u);
    ctx->pc = 0x1F343Cu;
    if (runtime->hasFunction(0x1F343Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F343Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBB84u; }
        if (ctx->pc != 0x1DBB84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F343C_0x1f343c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBB84u; }
        if (ctx->pc != 0x1DBB84u) { return; }
    }
    ctx->pc = 0x1DBB84u;
label_1dbb84:
    // 0x1dbb84: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbb84u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbb88: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1dbb88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbb8c: 0xc07cd19  jal         func_1F3464
    ctx->pc = 0x1DBB8Cu;
    SET_GPR_U32(ctx, 31, 0x1DBB94u);
    ctx->pc = 0x1F3464u;
    if (runtime->hasFunction(0x1F3464u)) {
        auto targetFn = runtime->lookupFunction(0x1F3464u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBB94u; }
        if (ctx->pc != 0x1DBB94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3464_0x1f3464(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBB94u; }
        if (ctx->pc != 0x1DBB94u) { return; }
    }
    ctx->pc = 0x1DBB94u;
label_1dbb94:
    // 0x1dbb94: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbb94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbb98: 0x24051000  addiu       $a1, $zero, 0x1000
    ctx->pc = 0x1dbb98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1dbb9c: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1DBB9Cu;
    SET_GPR_U32(ctx, 31, 0x1DBBA4u);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBBA4u; }
        if (ctx->pc != 0x1DBBA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBBA4u; }
        if (ctx->pc != 0x1DBBA4u) { return; }
    }
    ctx->pc = 0x1DBBA4u;
label_1dbba4:
    // 0x1dbba4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dbba4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dbba8: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1dbba8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dbbac: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1dbbacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dbbb0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dbbb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbbb4: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1dbbb4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbbb8: 0xc07c4c3  jal         func_1F130C
    ctx->pc = 0x1DBBB8u;
    SET_GPR_U32(ctx, 31, 0x1DBBC0u);
    ctx->pc = 0x1F130Cu;
    if (runtime->hasFunction(0x1F130Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F130Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBBC0u; }
        if (ctx->pc != 0x1DBBC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F130C_0x1f130c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBBC0u; }
        if (ctx->pc != 0x1DBBC0u) { return; }
    }
    ctx->pc = 0x1DBBC0u;
label_1dbbc0:
    // 0x1dbbc0: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1dbbc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1dbbc4: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbbc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbbc8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DBBC8u;
    {
        const bool branch_taken_0x1dbbc8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbbc8) {
            ctx->pc = 0x1DBBDCu;
            goto label_1dbbdc;
        }
    }
    ctx->pc = 0x1DBBD0u;
    // 0x1dbbd0: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbbd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbbd4: 0x1000017d  b           . + 4 + (0x17D << 2)
    ctx->pc = 0x1DBBD4u;
    {
        const bool branch_taken_0x1dbbd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbbd4) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DBBDCu;
label_1dbbdc:
    // 0x1dbbdc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dbbdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dbbe0: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dbbe0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dbbe4: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1dbbe4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbbe8: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1DBBE8u;
    SET_GPR_U32(ctx, 31, 0x1DBBF0u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBBF0u; }
        if (ctx->pc != 0x1DBBF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBBF0u; }
        if (ctx->pc != 0x1DBBF0u) { return; }
    }
    ctx->pc = 0x1DBBF0u;
label_1dbbf0:
    // 0x1dbbf0: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1dbbf0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1dbbf4: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbbf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbbf8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DBBF8u;
    {
        const bool branch_taken_0x1dbbf8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbbf8) {
            ctx->pc = 0x1DBC0Cu;
            goto label_1dbc0c;
        }
    }
    ctx->pc = 0x1DBC00u;
    // 0x1dbc00: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbc00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbc04: 0x10000171  b           . + 4 + (0x171 << 2)
    ctx->pc = 0x1DBC04u;
    {
        const bool branch_taken_0x1dbc04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbc04) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DBC0Cu;
label_1dbc0c:
    // 0x1dbc0c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dbc0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbc10: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1dbc10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1dbc14:
    // 0x1dbc14: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbc14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbc18: 0x24052000  addiu       $a1, $zero, 0x2000
    ctx->pc = 0x1dbc18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1dbc1c: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBC1Cu;
    SET_GPR_U32(ctx, 31, 0x1DBC24u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBC24u; }
        if (ctx->pc != 0x1DBC24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBC24u; }
        if (ctx->pc != 0x1DBC24u) { return; }
    }
    ctx->pc = 0x1DBC24u;
label_1dbc24:
    // 0x1dbc24: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DBC24u;
    {
        const bool branch_taken_0x1dbc24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dbc24) {
            ctx->pc = 0x1DBC4Cu;
            goto label_1dbc4c;
        }
    }
    ctx->pc = 0x1DBC2Cu;
    // 0x1dbc2c: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbc2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbc30: 0x24050200  addiu       $a1, $zero, 0x200
    ctx->pc = 0x1dbc30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x1dbc34: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBC34u;
    SET_GPR_U32(ctx, 31, 0x1DBC3Cu);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBC3Cu; }
        if (ctx->pc != 0x1DBC3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBC3Cu; }
        if (ctx->pc != 0x1DBC3Cu) { return; }
    }
    ctx->pc = 0x1DBC3Cu;
label_1dbc3c:
    // 0x1dbc3c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DBC3Cu;
    {
        const bool branch_taken_0x1dbc3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dbc3c) {
            ctx->pc = 0x1DBC4Cu;
            goto label_1dbc4c;
        }
    }
    ctx->pc = 0x1DBC44u;
    // 0x1dbc44: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1DBC44u;
    {
        const bool branch_taken_0x1dbc44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbc44) {
            ctx->pc = 0x1DBC58u;
            goto label_1dbc58;
        }
    }
    ctx->pc = 0x1DBC4Cu;
label_1dbc4c:
    // 0x1dbc4c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1dbc4cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbc50: 0x1000015e  b           . + 4 + (0x15E << 2)
    ctx->pc = 0x1DBC50u;
    {
        const bool branch_taken_0x1dbc50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbc50) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DBC58u;
label_1dbc58:
    // 0x1dbc58: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dbc58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbc5c: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dbc5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dbc60: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbc60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbc64: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1dbc64u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbc68: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1DBC68u;
    SET_GPR_U32(ctx, 31, 0x1DBC70u);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBC70u; }
        if (ctx->pc != 0x1DBC70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBC70u; }
        if (ctx->pc != 0x1DBC70u) { return; }
    }
    ctx->pc = 0x1DBC70u;
label_1dbc70:
    // 0x1dbc70: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1dbc70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1dbc74: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1dbc74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1dbc78: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1dbc78u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1dbc7c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1dbc7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dbc80: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1dbc80u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
label_1dbc84:
    // 0x1dbc84: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1dbc84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dbc88: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DBC88u;
    {
        const bool branch_taken_0x1dbc88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dbc88) {
            ctx->pc = 0x1DBC98u;
            goto label_1dbc98;
        }
    }
    ctx->pc = 0x1DBC90u;
    // 0x1dbc90: 0x1000004c  b           . + 4 + (0x4C << 2)
    ctx->pc = 0x1DBC90u;
    {
        const bool branch_taken_0x1dbc90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbc90) {
            ctx->pc = 0x1DBDC4u;
            goto label_1dbdc4;
        }
    }
    ctx->pc = 0x1DBC98u;
label_1dbc98:
    // 0x1dbc98: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbc98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbc9c: 0xc07c6eb  jal         func_1F1BAC
    ctx->pc = 0x1DBC9Cu;
    SET_GPR_U32(ctx, 31, 0x1DBCA4u);
    ctx->pc = 0x1F1BACu;
    if (runtime->hasFunction(0x1F1BACu)) {
        auto targetFn = runtime->lookupFunction(0x1F1BACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBCA4u; }
        if (ctx->pc != 0x1DBCA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1BAC_0x1f1bac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBCA4u; }
        if (ctx->pc != 0x1DBCA4u) { return; }
    }
    ctx->pc = 0x1DBCA4u;
label_1dbca4:
    // 0x1dbca4: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dbca4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dbca8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dbca8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dbcac: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1dbcacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dbcb0: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1dbcb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dbcb4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dbcb4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbcb8: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1dbcb8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbcbc: 0xc07c5a2  jal         func_1F1688
    ctx->pc = 0x1DBCBCu;
    SET_GPR_U32(ctx, 31, 0x1DBCC4u);
    ctx->pc = 0x1F1688u;
    if (runtime->hasFunction(0x1F1688u)) {
        auto targetFn = runtime->lookupFunction(0x1F1688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBCC4u; }
        if (ctx->pc != 0x1DBCC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1688_0x1f1688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBCC4u; }
        if (ctx->pc != 0x1DBCC4u) { return; }
    }
    ctx->pc = 0x1DBCC4u;
label_1dbcc4:
    // 0x1dbcc4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DBCC4u;
    {
        const bool branch_taken_0x1dbcc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbcc4) {
            ctx->pc = 0x1DBCD4u;
            goto label_1dbcd4;
        }
    }
    ctx->pc = 0x1DBCCCu;
    // 0x1dbccc: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x1DBCCCu;
    {
        const bool branch_taken_0x1dbccc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbccc) {
            ctx->pc = 0x1DBDC4u;
            goto label_1dbdc4;
        }
    }
    ctx->pc = 0x1DBCD4u;
label_1dbcd4:
    // 0x1dbcd4: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbcd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbcd8: 0x24050200  addiu       $a1, $zero, 0x200
    ctx->pc = 0x1dbcd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x1dbcdc: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBCDCu;
    SET_GPR_U32(ctx, 31, 0x1DBCE4u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBCE4u; }
        if (ctx->pc != 0x1DBCE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBCE4u; }
        if (ctx->pc != 0x1DBCE4u) { return; }
    }
    ctx->pc = 0x1DBCE4u;
label_1dbce4:
    // 0x1dbce4: 0x1440ffe7  bnez        $v0, . + 4 + (-0x19 << 2)
    ctx->pc = 0x1DBCE4u;
    {
        const bool branch_taken_0x1dbce4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dbce4) {
            ctx->pc = 0x1DBC84u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1dbc84;
        }
    }
    ctx->pc = 0x1DBCECu;
    // 0x1dbcec: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbcecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbcf0: 0x24052000  addiu       $a1, $zero, 0x2000
    ctx->pc = 0x1dbcf0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1dbcf4: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBCF4u;
    SET_GPR_U32(ctx, 31, 0x1DBCFCu);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBCFCu; }
        if (ctx->pc != 0x1DBCFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBCFCu; }
        if (ctx->pc != 0x1DBCFCu) { return; }
    }
    ctx->pc = 0x1DBCFCu;
label_1dbcfc:
    // 0x1dbcfc: 0x1440ffe1  bnez        $v0, . + 4 + (-0x1F << 2)
    ctx->pc = 0x1DBCFCu;
    {
        const bool branch_taken_0x1dbcfc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dbcfc) {
            ctx->pc = 0x1DBC84u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1dbc84;
        }
    }
    ctx->pc = 0x1DBD04u;
    // 0x1dbd04: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbd04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbd08: 0x24051000  addiu       $a1, $zero, 0x1000
    ctx->pc = 0x1dbd08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1dbd0c: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBD0Cu;
    SET_GPR_U32(ctx, 31, 0x1DBD14u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBD14u; }
        if (ctx->pc != 0x1DBD14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBD14u; }
        if (ctx->pc != 0x1DBD14u) { return; }
    }
    ctx->pc = 0x1DBD14u;
label_1dbd14:
    // 0x1dbd14: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DBD14u;
    {
        const bool branch_taken_0x1dbd14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbd14) {
            ctx->pc = 0x1DBD24u;
            goto label_1dbd24;
        }
    }
    ctx->pc = 0x1DBD1Cu;
    // 0x1dbd1c: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1DBD1Cu;
    {
        const bool branch_taken_0x1dbd1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbd1c) {
            ctx->pc = 0x1DBDC4u;
            goto label_1dbdc4;
        }
    }
    ctx->pc = 0x1DBD24u;
label_1dbd24:
    // 0x1dbd24: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbd24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbd28: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1dbd28u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbd2c: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1DBD2Cu;
    SET_GPR_U32(ctx, 31, 0x1DBD34u);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBD34u; }
        if (ctx->pc != 0x1DBD34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBD34u; }
        if (ctx->pc != 0x1DBD34u) { return; }
    }
    ctx->pc = 0x1DBD34u;
label_1dbd34:
    // 0x1dbd34: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1dbd34u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1dbd38: 0x21c03  sra         $v1, $v0, 16
    ctx->pc = 0x1dbd38u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1dbd3c: 0x87c20014  lh          $v0, 0x14($fp)
    ctx->pc = 0x1dbd3cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dbd40: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dbd40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbd44: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1dbd44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbd48: 0xc076d66  jal         func_1DB598
    ctx->pc = 0x1DBD48u;
    SET_GPR_U32(ctx, 31, 0x1DBD50u);
    ctx->pc = 0x1DB598u;
    if (runtime->hasFunction(0x1DB598u)) {
        auto targetFn = runtime->lookupFunction(0x1DB598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBD50u; }
        if (ctx->pc != 0x1DBD50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB598_0x1db598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBD50u; }
        if (ctx->pc != 0x1DBD50u) { return; }
    }
    ctx->pc = 0x1DBD50u;
label_1dbd50:
    // 0x1dbd50: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1dbd50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1dbd54: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1dbd54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dbd58: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1dbd58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1dbd5c: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DBD5Cu;
    {
        const bool branch_taken_0x1dbd5c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1dbd5c) {
            ctx->pc = 0x1DBD6Cu;
            goto label_1dbd6c;
        }
    }
    ctx->pc = 0x1DBD64u;
    // 0x1dbd64: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1DBD64u;
    {
        const bool branch_taken_0x1dbd64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbd64) {
            ctx->pc = 0x1DBDC4u;
            goto label_1dbdc4;
        }
    }
    ctx->pc = 0x1DBD6Cu;
label_1dbd6c:
    // 0x1dbd6c: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbd6cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbd70: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1DBD70u;
    SET_GPR_U32(ctx, 31, 0x1DBD78u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBD78u; }
        if (ctx->pc != 0x1DBD78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBD78u; }
        if (ctx->pc != 0x1DBD78u) { return; }
    }
    ctx->pc = 0x1DBD78u;
label_1dbd78:
    // 0x1dbd78: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1dbd78u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbd7c: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbd7cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbd80: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1DBD80u;
    SET_GPR_U32(ctx, 31, 0x1DBD88u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBD88u; }
        if (ctx->pc != 0x1DBD88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBD88u; }
        if (ctx->pc != 0x1DBD88u) { return; }
    }
    ctx->pc = 0x1DBD88u;
label_1dbd88:
    // 0x1dbd88: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1dbd88u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbd8c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1dbd8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1dbd90: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1dbd90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1dbd94: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1dbd94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dbd98: 0x28420380  slti        $v0, $v0, 0x380
    ctx->pc = 0x1dbd98u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)896) ? 1 : 0);
    // 0x1dbd9c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DBD9Cu;
    {
        const bool branch_taken_0x1dbd9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbd9c) {
            ctx->pc = 0x1DBDC4u;
            goto label_1dbdc4;
        }
    }
    ctx->pc = 0x1DBDA4u;
    // 0x1dbda4: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbda4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbda8: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1DBDA8u;
    SET_GPR_U32(ctx, 31, 0x1DBDB0u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBDB0u; }
        if (ctx->pc != 0x1DBDB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBDB0u; }
        if (ctx->pc != 0x1DBDB0u) { return; }
    }
    ctx->pc = 0x1DBDB0u;
label_1dbdb0:
    // 0x1dbdb0: 0x8fc3001c  lw          $v1, 0x1C($fp)
    ctx->pc = 0x1dbdb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1dbdb4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1dbdb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dbdb8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1dbdb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1dbdbc: 0x1000ffb1  b           . + 4 + (-0x4F << 2)
    ctx->pc = 0x1DBDBCu;
    {
        const bool branch_taken_0x1dbdbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbdbc) {
            ctx->pc = 0x1DBC84u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1dbc84;
        }
    }
    ctx->pc = 0x1DBDC4u;
label_1dbdc4:
    // 0x1dbdc4: 0x97c2001c  lhu         $v0, 0x1C($fp)
    ctx->pc = 0x1dbdc4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1dbdc8: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbdc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbdcc: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1dbdccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbdd0: 0xc07cc64  jal         func_1F3190
    ctx->pc = 0x1DBDD0u;
    SET_GPR_U32(ctx, 31, 0x1DBDD8u);
    ctx->pc = 0x1F3190u;
    if (runtime->hasFunction(0x1F3190u)) {
        auto targetFn = runtime->lookupFunction(0x1F3190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBDD8u; }
        if (ctx->pc != 0x1DBDD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3190_0x1f3190(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBDD8u; }
        if (ctx->pc != 0x1DBDD8u) { return; }
    }
    ctx->pc = 0x1DBDD8u;
label_1dbdd8:
    // 0x1dbdd8: 0x1440005b  bnez        $v0, . + 4 + (0x5B << 2)
    ctx->pc = 0x1DBDD8u;
    {
        const bool branch_taken_0x1dbdd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dbdd8) {
            ctx->pc = 0x1DBF48u;
            goto label_1dbf48;
        }
    }
    ctx->pc = 0x1DBDE0u;
    // 0x1dbde0: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbde0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbde4: 0xc07c69f  jal         func_1F1A7C
    ctx->pc = 0x1DBDE4u;
    SET_GPR_U32(ctx, 31, 0x1DBDECu);
    ctx->pc = 0x1F1A7Cu;
    if (runtime->hasFunction(0x1F1A7Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F1A7Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBDECu; }
        if (ctx->pc != 0x1DBDECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A7C_0x1f1a7c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBDECu; }
        if (ctx->pc != 0x1DBDECu) { return; }
    }
    ctx->pc = 0x1DBDECu;
label_1dbdec:
    // 0x1dbdec: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1dbdecu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbdf0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1dbdf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1dbdf4: 0x10620054  beq         $v1, $v0, . + 4 + (0x54 << 2)
    ctx->pc = 0x1DBDF4u;
    {
        const bool branch_taken_0x1dbdf4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1dbdf4) {
            ctx->pc = 0x1DBF48u;
            goto label_1dbf48;
        }
    }
    ctx->pc = 0x1DBDFCu;
    // 0x1dbdfc: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbdfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbe00: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1DBE00u;
    SET_GPR_U32(ctx, 31, 0x1DBE08u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBE08u; }
        if (ctx->pc != 0x1DBE08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBE08u; }
        if (ctx->pc != 0x1DBE08u) { return; }
    }
    ctx->pc = 0x1DBE08u;
label_1dbe08:
    // 0x1dbe08: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1dbe08u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbe0c: 0x97c2001c  lhu         $v0, 0x1C($fp)
    ctx->pc = 0x1dbe0cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1dbe10: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1dbe10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dbe14: 0x3046ffff  andi        $a2, $v0, 0xFFFF
    ctx->pc = 0x1dbe14u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1dbe18: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dbe18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dbe1c: 0x27c30008  addiu       $v1, $fp, 0x8
    ctx->pc = 0x1dbe1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1dbe20: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dbe20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dbe24: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1dbe24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbe28: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1dbe28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dbe2c: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1dbe2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dbe30: 0xc07c80a  jal         func_1F2028
    ctx->pc = 0x1DBE30u;
    SET_GPR_U32(ctx, 31, 0x1DBE38u);
    ctx->pc = 0x1F2028u;
    if (runtime->hasFunction(0x1F2028u)) {
        auto targetFn = runtime->lookupFunction(0x1F2028u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBE38u; }
        if (ctx->pc != 0x1DBE38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2028_0x1f2028(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBE38u; }
        if (ctx->pc != 0x1DBE38u) { return; }
    }
    ctx->pc = 0x1DBE38u;
label_1dbe38:
    // 0x1dbe38: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1dbe38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1dbe3c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbe3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbe40: 0x14400041  bnez        $v0, . + 4 + (0x41 << 2)
    ctx->pc = 0x1DBE40u;
    {
        const bool branch_taken_0x1dbe40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dbe40) {
            ctx->pc = 0x1DBF48u;
            goto label_1dbf48;
        }
    }
    ctx->pc = 0x1DBE48u;
    // 0x1dbe48: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbe48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbe4c: 0xc07c6cd  jal         func_1F1B34
    ctx->pc = 0x1DBE4Cu;
    SET_GPR_U32(ctx, 31, 0x1DBE54u);
    ctx->pc = 0x1F1B34u;
    if (runtime->hasFunction(0x1F1B34u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B34u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBE54u; }
        if (ctx->pc != 0x1DBE54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B34_0x1f1b34(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBE54u; }
        if (ctx->pc != 0x1DBE54u) { return; }
    }
    ctx->pc = 0x1DBE54u;
label_1dbe54:
    // 0x1dbe54: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1dbe54u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbe58: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbe58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbe5c: 0xc07c6cd  jal         func_1F1B34
    ctx->pc = 0x1DBE5Cu;
    SET_GPR_U32(ctx, 31, 0x1DBE64u);
    ctx->pc = 0x1F1B34u;
    if (runtime->hasFunction(0x1F1B34u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B34u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBE64u; }
        if (ctx->pc != 0x1DBE64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B34_0x1f1b34(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBE64u; }
        if (ctx->pc != 0x1DBE64u) { return; }
    }
    ctx->pc = 0x1DBE64u;
label_1dbe64:
    // 0x1dbe64: 0x202102b  sltu        $v0, $s0, $v0
    ctx->pc = 0x1dbe64u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1dbe68: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DBE68u;
    {
        const bool branch_taken_0x1dbe68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dbe68) {
            ctx->pc = 0x1DBE8Cu;
            goto label_1dbe8c;
        }
    }
    ctx->pc = 0x1DBE70u;
    // 0x1dbe70: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dbe70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dbe74: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dbe74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dbe78: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1dbe78u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbe7c: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1DBE7Cu;
    SET_GPR_U32(ctx, 31, 0x1DBE84u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBE84u; }
        if (ctx->pc != 0x1DBE84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBE84u; }
        if (ctx->pc != 0x1DBE84u) { return; }
    }
    ctx->pc = 0x1DBE84u;
label_1dbe84:
    // 0x1dbe84: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1DBE84u;
    {
        const bool branch_taken_0x1dbe84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbe84) {
            ctx->pc = 0x1DBF48u;
            goto label_1dbf48;
        }
    }
    ctx->pc = 0x1DBE8Cu;
label_1dbe8c:
    // 0x1dbe8c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dbe8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dbe90: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1dbe90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dbe94: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1dbe94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dbe98: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dbe98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbe9c: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1dbe9cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbea0: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1dbea0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbea4: 0xc07c4f7  jal         func_1F13DC
    ctx->pc = 0x1DBEA4u;
    SET_GPR_U32(ctx, 31, 0x1DBEACu);
    ctx->pc = 0x1F13DCu;
    if (runtime->hasFunction(0x1F13DCu)) {
        auto targetFn = runtime->lookupFunction(0x1F13DCu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBEACu; }
        if (ctx->pc != 0x1DBEACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F13DC_0x1f13dc(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBEACu; }
        if (ctx->pc != 0x1DBEACu) { return; }
    }
    ctx->pc = 0x1DBEACu;
label_1dbeac:
    // 0x1dbeac: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1dbeacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1dbeb0: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbeb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbeb4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DBEB4u;
    {
        const bool branch_taken_0x1dbeb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbeb4) {
            ctx->pc = 0x1DBEC8u;
            goto label_1dbec8;
        }
    }
    ctx->pc = 0x1DBEBCu;
    // 0x1dbebc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbebcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbec0: 0x100000c2  b           . + 4 + (0xC2 << 2)
    ctx->pc = 0x1DBEC0u;
    {
        const bool branch_taken_0x1dbec0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbec0) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DBEC8u;
label_1dbec8:
    // 0x1dbec8: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dbec8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbecc: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1dbeccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbed0: 0xc07cdd5  jal         func_1F3754
    ctx->pc = 0x1DBED0u;
    SET_GPR_U32(ctx, 31, 0x1DBED8u);
    ctx->pc = 0x1F3754u;
    if (runtime->hasFunction(0x1F3754u)) {
        auto targetFn = runtime->lookupFunction(0x1F3754u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBED8u; }
        if (ctx->pc != 0x1DBED8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3754_0x1f3754(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBED8u; }
        if (ctx->pc != 0x1DBED8u) { return; }
    }
    ctx->pc = 0x1DBED8u;
label_1dbed8:
    // 0x1dbed8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1dbed8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1dbedc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbedcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbee0: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DBEE0u;
    {
        const bool branch_taken_0x1dbee0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbee0) {
            ctx->pc = 0x1DBEF4u;
            goto label_1dbef4;
        }
    }
    ctx->pc = 0x1DBEE8u;
    // 0x1dbee8: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbee8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbeec: 0x100000b7  b           . + 4 + (0xB7 << 2)
    ctx->pc = 0x1DBEECu;
    {
        const bool branch_taken_0x1dbeec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbeec) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DBEF4u;
label_1dbef4:
    // 0x1dbef4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dbef4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dbef8: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1dbef8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dbefc: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1dbefcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dbf00: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dbf00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbf04: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1dbf04u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbf08: 0xc07c4c3  jal         func_1F130C
    ctx->pc = 0x1DBF08u;
    SET_GPR_U32(ctx, 31, 0x1DBF10u);
    ctx->pc = 0x1F130Cu;
    if (runtime->hasFunction(0x1F130Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F130Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBF10u; }
        if (ctx->pc != 0x1DBF10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F130C_0x1f130c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBF10u; }
        if (ctx->pc != 0x1DBF10u) { return; }
    }
    ctx->pc = 0x1DBF10u;
label_1dbf10:
    // 0x1dbf10: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1dbf10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1dbf14: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbf14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbf18: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DBF18u;
    {
        const bool branch_taken_0x1dbf18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbf18) {
            ctx->pc = 0x1DBF2Cu;
            goto label_1dbf2c;
        }
    }
    ctx->pc = 0x1DBF20u;
    // 0x1dbf20: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dbf20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dbf24: 0x100000a9  b           . + 4 + (0xA9 << 2)
    ctx->pc = 0x1DBF24u;
    {
        const bool branch_taken_0x1dbf24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbf24) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DBF2Cu;
label_1dbf2c:
    // 0x1dbf2c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dbf2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dbf30: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dbf30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dbf34: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1dbf34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbf38: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1DBF38u;
    SET_GPR_U32(ctx, 31, 0x1DBF40u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBF40u; }
        if (ctx->pc != 0x1DBF40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBF40u; }
        if (ctx->pc != 0x1DBF40u) { return; }
    }
    ctx->pc = 0x1DBF40u;
label_1dbf40:
    // 0x1dbf40: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dbf40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbf44: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1dbf44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
label_1dbf48:
    // 0x1dbf48: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dbf48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dbf4c: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dbf4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dbf50: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1dbf50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1dbf54: 0x28420001  slti        $v0, $v0, 0x1
    ctx->pc = 0x1dbf54u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)1) ? 1 : 0);
    // 0x1dbf58: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1dbf58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1dbf5c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1dbf5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
label_1dbf60:
    // 0x1dbf60: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1dbf60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dbf64: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DBF64u;
    {
        const bool branch_taken_0x1dbf64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dbf64) {
            ctx->pc = 0x1DBF74u;
            goto label_1dbf74;
        }
    }
    ctx->pc = 0x1DBF6Cu;
    // 0x1dbf6c: 0x10000073  b           . + 4 + (0x73 << 2)
    ctx->pc = 0x1DBF6Cu;
    {
        const bool branch_taken_0x1dbf6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbf6c) {
            ctx->pc = 0x1DC13Cu;
            goto label_1dc13c;
        }
    }
    ctx->pc = 0x1DBF74u;
label_1dbf74:
    // 0x1dbf74: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbf74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbf78: 0xc07c6eb  jal         func_1F1BAC
    ctx->pc = 0x1DBF78u;
    SET_GPR_U32(ctx, 31, 0x1DBF80u);
    ctx->pc = 0x1F1BACu;
    if (runtime->hasFunction(0x1F1BACu)) {
        auto targetFn = runtime->lookupFunction(0x1F1BACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBF80u; }
        if (ctx->pc != 0x1DBF80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1BAC_0x1f1bac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBF80u; }
        if (ctx->pc != 0x1DBF80u) { return; }
    }
    ctx->pc = 0x1DBF80u;
label_1dbf80:
    // 0x1dbf80: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dbf80u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dbf84: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dbf84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dbf88: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1dbf88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dbf8c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1dbf8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dbf90: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dbf90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dbf94: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1dbf94u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbf98: 0xc07c5a2  jal         func_1F1688
    ctx->pc = 0x1DBF98u;
    SET_GPR_U32(ctx, 31, 0x1DBFA0u);
    ctx->pc = 0x1F1688u;
    if (runtime->hasFunction(0x1F1688u)) {
        auto targetFn = runtime->lookupFunction(0x1F1688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBFA0u; }
        if (ctx->pc != 0x1DBFA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1688_0x1f1688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBFA0u; }
        if (ctx->pc != 0x1DBFA0u) { return; }
    }
    ctx->pc = 0x1DBFA0u;
label_1dbfa0:
    // 0x1dbfa0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DBFA0u;
    {
        const bool branch_taken_0x1dbfa0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbfa0) {
            ctx->pc = 0x1DBFB0u;
            goto label_1dbfb0;
        }
    }
    ctx->pc = 0x1DBFA8u;
    // 0x1dbfa8: 0x10000064  b           . + 4 + (0x64 << 2)
    ctx->pc = 0x1DBFA8u;
    {
        const bool branch_taken_0x1dbfa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbfa8) {
            ctx->pc = 0x1DC13Cu;
            goto label_1dc13c;
        }
    }
    ctx->pc = 0x1DBFB0u;
label_1dbfb0:
    // 0x1dbfb0: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbfb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbfb4: 0x24050200  addiu       $a1, $zero, 0x200
    ctx->pc = 0x1dbfb4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x1dbfb8: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBFB8u;
    SET_GPR_U32(ctx, 31, 0x1DBFC0u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBFC0u; }
        if (ctx->pc != 0x1DBFC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBFC0u; }
        if (ctx->pc != 0x1DBFC0u) { return; }
    }
    ctx->pc = 0x1DBFC0u;
label_1dbfc0:
    // 0x1dbfc0: 0x1440ffe7  bnez        $v0, . + 4 + (-0x19 << 2)
    ctx->pc = 0x1DBFC0u;
    {
        const bool branch_taken_0x1dbfc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dbfc0) {
            ctx->pc = 0x1DBF60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1dbf60;
        }
    }
    ctx->pc = 0x1DBFC8u;
    // 0x1dbfc8: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbfc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbfcc: 0x24052000  addiu       $a1, $zero, 0x2000
    ctx->pc = 0x1dbfccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1dbfd0: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBFD0u;
    SET_GPR_U32(ctx, 31, 0x1DBFD8u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBFD8u; }
        if (ctx->pc != 0x1DBFD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBFD8u; }
        if (ctx->pc != 0x1DBFD8u) { return; }
    }
    ctx->pc = 0x1DBFD8u;
label_1dbfd8:
    // 0x1dbfd8: 0x1440ffe1  bnez        $v0, . + 4 + (-0x1F << 2)
    ctx->pc = 0x1DBFD8u;
    {
        const bool branch_taken_0x1dbfd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dbfd8) {
            ctx->pc = 0x1DBF60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1dbf60;
        }
    }
    ctx->pc = 0x1DBFE0u;
    // 0x1dbfe0: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dbfe0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dbfe4: 0x24051000  addiu       $a1, $zero, 0x1000
    ctx->pc = 0x1dbfe4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1dbfe8: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DBFE8u;
    SET_GPR_U32(ctx, 31, 0x1DBFF0u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBFF0u; }
        if (ctx->pc != 0x1DBFF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DBFF0u; }
        if (ctx->pc != 0x1DBFF0u) { return; }
    }
    ctx->pc = 0x1DBFF0u;
label_1dbff0:
    // 0x1dbff0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DBFF0u;
    {
        const bool branch_taken_0x1dbff0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbff0) {
            ctx->pc = 0x1DC000u;
            goto label_1dc000;
        }
    }
    ctx->pc = 0x1DBFF8u;
    // 0x1dbff8: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1DBFF8u;
    {
        const bool branch_taken_0x1dbff8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dbff8) {
            ctx->pc = 0x1DC13Cu;
            goto label_1dc13c;
        }
    }
    ctx->pc = 0x1DC000u;
label_1dc000:
    // 0x1dc000: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dc000u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc004: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1dc004u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dc008: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1DC008u;
    SET_GPR_U32(ctx, 31, 0x1DC010u);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC010u; }
        if (ctx->pc != 0x1DC010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC010u; }
        if (ctx->pc != 0x1DC010u) { return; }
    }
    ctx->pc = 0x1DC010u;
label_1dc010:
    // 0x1dc010: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1dc010u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1dc014: 0x28403  sra         $s0, $v0, 16
    ctx->pc = 0x1dc014u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1dc018: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dc018u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dc01c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1dc01cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dc020: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1DC020u;
    SET_GPR_U32(ctx, 31, 0x1DC028u);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC028u; }
        if (ctx->pc != 0x1DC028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC028u; }
        if (ctx->pc != 0x1DC028u) { return; }
    }
    ctx->pc = 0x1DC028u;
label_1dc028:
    // 0x1dc028: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x1dc028u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1dc02c: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1dc02cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1dc030: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1dc030u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dc034: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1dc034u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dc038: 0xc076d66  jal         func_1DB598
    ctx->pc = 0x1DC038u;
    SET_GPR_U32(ctx, 31, 0x1DC040u);
    ctx->pc = 0x1DB598u;
    if (runtime->hasFunction(0x1DB598u)) {
        auto targetFn = runtime->lookupFunction(0x1DB598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC040u; }
        if (ctx->pc != 0x1DC040u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB598_0x1db598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC040u; }
        if (ctx->pc != 0x1DC040u) { return; }
    }
    ctx->pc = 0x1DC040u;
label_1dc040:
    // 0x1dc040: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1dc040u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1dc044: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1dc044u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dc048: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1dc048u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1dc04c: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DC04Cu;
    {
        const bool branch_taken_0x1dc04c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1dc04c) {
            ctx->pc = 0x1DC05Cu;
            goto label_1dc05c;
        }
    }
    ctx->pc = 0x1DC054u;
    // 0x1dc054: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x1DC054u;
    {
        const bool branch_taken_0x1dc054 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc054) {
            ctx->pc = 0x1DC13Cu;
            goto label_1dc13c;
        }
    }
    ctx->pc = 0x1DC05Cu;
label_1dc05c:
    // 0x1dc05c: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dc05cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc060: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1dc060u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dc064: 0xc07cda5  jal         func_1F3694
    ctx->pc = 0x1DC064u;
    SET_GPR_U32(ctx, 31, 0x1DC06Cu);
    ctx->pc = 0x1F3694u;
    if (runtime->hasFunction(0x1F3694u)) {
        auto targetFn = runtime->lookupFunction(0x1F3694u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC06Cu; }
        if (ctx->pc != 0x1DC06Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3694_0x1f3694(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC06Cu; }
        if (ctx->pc != 0x1DC06Cu) { return; }
    }
    ctx->pc = 0x1DC06Cu;
label_1dc06c:
    // 0x1dc06c: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1dc06cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1dc070: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1dc070u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dc074: 0x2402e0c2  addiu       $v0, $zero, -0x1F3E
    ctx->pc = 0x1dc074u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294959298));
    // 0x1dc078: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DC078u;
    {
        const bool branch_taken_0x1dc078 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1dc078) {
            ctx->pc = 0x1DC088u;
            goto label_1dc088;
        }
    }
    ctx->pc = 0x1DC080u;
    // 0x1dc080: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1DC080u;
    {
        const bool branch_taken_0x1dc080 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc080) {
            ctx->pc = 0x1DC13Cu;
            goto label_1dc13c;
        }
    }
    ctx->pc = 0x1DC088u;
label_1dc088:
    // 0x1dc088: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dc088u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dc08c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DC08Cu;
    {
        const bool branch_taken_0x1dc08c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc08c) {
            ctx->pc = 0x1DC0A0u;
            goto label_1dc0a0;
        }
    }
    ctx->pc = 0x1DC094u;
    // 0x1dc094: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dc094u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dc098: 0x1000004c  b           . + 4 + (0x4C << 2)
    ctx->pc = 0x1DC098u;
    {
        const bool branch_taken_0x1dc098 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc098) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DC0A0u;
label_1dc0a0:
    // 0x1dc0a0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dc0a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc0a4: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1dc0a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dc0a8: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1dc0a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dc0ac: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dc0acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dc0b0: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1dc0b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dc0b4: 0xc07c4c3  jal         func_1F130C
    ctx->pc = 0x1DC0B4u;
    SET_GPR_U32(ctx, 31, 0x1DC0BCu);
    ctx->pc = 0x1F130Cu;
    if (runtime->hasFunction(0x1F130Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F130Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC0BCu; }
        if (ctx->pc != 0x1DC0BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F130C_0x1f130c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC0BCu; }
        if (ctx->pc != 0x1DC0BCu) { return; }
    }
    ctx->pc = 0x1DC0BCu;
label_1dc0bc:
    // 0x1dc0bc: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1dc0bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1dc0c0: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dc0c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dc0c4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DC0C4u;
    {
        const bool branch_taken_0x1dc0c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc0c4) {
            ctx->pc = 0x1DC0D8u;
            goto label_1dc0d8;
        }
    }
    ctx->pc = 0x1DC0CCu;
    // 0x1dc0cc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dc0ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dc0d0: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x1DC0D0u;
    {
        const bool branch_taken_0x1dc0d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc0d0) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DC0D8u;
label_1dc0d8:
    // 0x1dc0d8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dc0d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc0dc: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dc0dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dc0e0: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1dc0e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dc0e4: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1DC0E4u;
    SET_GPR_U32(ctx, 31, 0x1DC0ECu);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC0ECu; }
        if (ctx->pc != 0x1DC0ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC0ECu; }
        if (ctx->pc != 0x1DC0ECu) { return; }
    }
    ctx->pc = 0x1DC0ECu;
label_1dc0ec:
    // 0x1dc0ec: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1dc0ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1dc0f0: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dc0f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dc0f4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DC0F4u;
    {
        const bool branch_taken_0x1dc0f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc0f4) {
            ctx->pc = 0x1DC108u;
            goto label_1dc108;
        }
    }
    ctx->pc = 0x1DC0FCu;
    // 0x1dc0fc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1dc0fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1dc100: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1DC100u;
    {
        const bool branch_taken_0x1dc100 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc100) {
            ctx->pc = 0x1DC1CCu;
            goto label_1dc1cc;
        }
    }
    ctx->pc = 0x1DC108u;
label_1dc108:
    // 0x1dc108: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dc108u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc10c: 0x2405003f  addiu       $a1, $zero, 0x3F
    ctx->pc = 0x1dc10cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x1dc110: 0xc07c690  jal         func_1F1A40
    ctx->pc = 0x1DC110u;
    SET_GPR_U32(ctx, 31, 0x1DC118u);
    ctx->pc = 0x1F1A40u;
    if (runtime->hasFunction(0x1F1A40u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC118u; }
        if (ctx->pc != 0x1DC118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A40_0x1f1a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC118u; }
        if (ctx->pc != 0x1DC118u) { return; }
    }
    ctx->pc = 0x1DC118u;
label_1dc118:
    // 0x1dc118: 0x97c20014  lhu         $v0, 0x14($fp)
    ctx->pc = 0x1dc118u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dc11c: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dc11cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc120: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1dc120u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dc124: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1DC124u;
    SET_GPR_U32(ctx, 31, 0x1DC12Cu);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC12Cu; }
        if (ctx->pc != 0x1DC12Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC12Cu; }
        if (ctx->pc != 0x1DC12Cu) { return; }
    }
    ctx->pc = 0x1DC12Cu;
label_1dc12c:
    // 0x1dc12c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dc12cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc130: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dc130u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dc134: 0x1000ff8a  b           . + 4 + (-0x76 << 2)
    ctx->pc = 0x1DC134u;
    {
        const bool branch_taken_0x1dc134 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc134) {
            ctx->pc = 0x1DBF60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1dbf60;
        }
    }
    ctx->pc = 0x1DC13Cu;
label_1dc13c:
    // 0x1dc13c: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dc13cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc140: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x1dc140u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1dc144: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DC144u;
    SET_GPR_U32(ctx, 31, 0x1DC14Cu);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC14Cu; }
        if (ctx->pc != 0x1DC14Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC14Cu; }
        if (ctx->pc != 0x1DC14Cu) { return; }
    }
    ctx->pc = 0x1DC14Cu;
label_1dc14c:
    // 0x1dc14c: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1DC14Cu;
    {
        const bool branch_taken_0x1dc14c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dc14c) {
            ctx->pc = 0x1DC1A4u;
            goto label_1dc1a4;
        }
    }
    ctx->pc = 0x1DC154u;
    // 0x1dc154: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dc154u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc158: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1dc158u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1dc15c: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DC15Cu;
    SET_GPR_U32(ctx, 31, 0x1DC164u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC164u; }
        if (ctx->pc != 0x1DC164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC164u; }
        if (ctx->pc != 0x1DC164u) { return; }
    }
    ctx->pc = 0x1DC164u;
label_1dc164:
    // 0x1dc164: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1DC164u;
    {
        const bool branch_taken_0x1dc164 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dc164) {
            ctx->pc = 0x1DC1A4u;
            goto label_1dc1a4;
        }
    }
    ctx->pc = 0x1DC16Cu;
    // 0x1dc16c: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dc16cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc170: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x1dc170u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1dc174: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DC174u;
    SET_GPR_U32(ctx, 31, 0x1DC17Cu);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC17Cu; }
        if (ctx->pc != 0x1DC17Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC17Cu; }
        if (ctx->pc != 0x1DC17Cu) { return; }
    }
    ctx->pc = 0x1DC17Cu;
label_1dc17c:
    // 0x1dc17c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DC17Cu;
    {
        const bool branch_taken_0x1dc17c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dc17c) {
            ctx->pc = 0x1DC1A4u;
            goto label_1dc1a4;
        }
    }
    ctx->pc = 0x1DC184u;
    // 0x1dc184: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dc184u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc188: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1dc188u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1dc18c: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1DC18Cu;
    SET_GPR_U32(ctx, 31, 0x1DC194u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC194u; }
        if (ctx->pc != 0x1DC194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC194u; }
        if (ctx->pc != 0x1DC194u) { return; }
    }
    ctx->pc = 0x1DC194u;
label_1dc194:
    // 0x1dc194: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DC194u;
    {
        const bool branch_taken_0x1dc194 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dc194) {
            ctx->pc = 0x1DC1A4u;
            goto label_1dc1a4;
        }
    }
    ctx->pc = 0x1DC19Cu;
    // 0x1dc19c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1DC19Cu;
    {
        const bool branch_taken_0x1dc19c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc19c) {
            ctx->pc = 0x1DC1C8u;
            goto label_1dc1c8;
        }
    }
    ctx->pc = 0x1DC1A4u;
label_1dc1a4:
    // 0x1dc1a4: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dc1a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc1a8: 0xc07cd3b  jal         func_1F34EC
    ctx->pc = 0x1DC1A8u;
    SET_GPR_U32(ctx, 31, 0x1DC1B0u);
    ctx->pc = 0x1F34ECu;
    if (runtime->hasFunction(0x1F34ECu)) {
        auto targetFn = runtime->lookupFunction(0x1F34ECu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC1B0u; }
        if (ctx->pc != 0x1DC1B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F34EC_0x1f34ec(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC1B0u; }
        if (ctx->pc != 0x1DC1B0u) { return; }
    }
    ctx->pc = 0x1DC1B0u;
label_1dc1b0:
    // 0x1dc1b0: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1dc1b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1dc1b4: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1dc1b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dc1b8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1dc1b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dc1bc: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1dc1bcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dc1c0: 0x34420800  ori         $v0, $v0, 0x800
    ctx->pc = 0x1dc1c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2048);
    // 0x1dc1c4: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x1dc1c4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
label_1dc1c8:
    // 0x1dc1c8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1dc1c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1dc1cc:
    // 0x1dc1cc: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dc1ccu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dc1d0: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1dc1d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1dc1d4: 0xdfbe0028  ld          $fp, 0x28($sp)
    ctx->pc = 0x1dc1d4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1dc1d8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1dc1d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1dc1dc: 0x27bd0040  addiu       $sp, $sp, 0x40
    ctx->pc = 0x1dc1dcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1dc1e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1DC1E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DB944u: goto label_1db944;
            case 0x1DB95Cu: goto label_1db95c;
            case 0x1DB974u: goto label_1db974;
            case 0x1DB994u: goto label_1db994;
            case 0x1DB9A8u: goto label_1db9a8;
            case 0x1DB9B8u: goto label_1db9b8;
            case 0x1DB9CCu: goto label_1db9cc;
            case 0x1DB9D0u: goto label_1db9d0;
            case 0x1DB9ECu: goto label_1db9ec;
            case 0x1DB9FCu: goto label_1db9fc;
            case 0x1DBA0Cu: goto label_1dba0c;
            case 0x1DBA1Cu: goto label_1dba1c;
            case 0x1DBA28u: goto label_1dba28;
            case 0x1DBA34u: goto label_1dba34;
            case 0x1DBA50u: goto label_1dba50;
            case 0x1DBA64u: goto label_1dba64;
            case 0x1DBA74u: goto label_1dba74;
            case 0x1DBA84u: goto label_1dba84;
            case 0x1DBA94u: goto label_1dba94;
            case 0x1DBAA4u: goto label_1dbaa4;
            case 0x1DBAC8u: goto label_1dbac8;
            case 0x1DBAE4u: goto label_1dbae4;
            case 0x1DBAF8u: goto label_1dbaf8;
            case 0x1DBB14u: goto label_1dbb14;
            case 0x1DBB24u: goto label_1dbb24;
            case 0x1DBB38u: goto label_1dbb38;
            case 0x1DBB48u: goto label_1dbb48;
            case 0x1DBB5Cu: goto label_1dbb5c;
            case 0x1DBB70u: goto label_1dbb70;
            case 0x1DBB84u: goto label_1dbb84;
            case 0x1DBB94u: goto label_1dbb94;
            case 0x1DBBA4u: goto label_1dbba4;
            case 0x1DBBC0u: goto label_1dbbc0;
            case 0x1DBBDCu: goto label_1dbbdc;
            case 0x1DBBF0u: goto label_1dbbf0;
            case 0x1DBC0Cu: goto label_1dbc0c;
            case 0x1DBC14u: goto label_1dbc14;
            case 0x1DBC24u: goto label_1dbc24;
            case 0x1DBC3Cu: goto label_1dbc3c;
            case 0x1DBC4Cu: goto label_1dbc4c;
            case 0x1DBC58u: goto label_1dbc58;
            case 0x1DBC70u: goto label_1dbc70;
            case 0x1DBC84u: goto label_1dbc84;
            case 0x1DBC98u: goto label_1dbc98;
            case 0x1DBCA4u: goto label_1dbca4;
            case 0x1DBCC4u: goto label_1dbcc4;
            case 0x1DBCD4u: goto label_1dbcd4;
            case 0x1DBCE4u: goto label_1dbce4;
            case 0x1DBCFCu: goto label_1dbcfc;
            case 0x1DBD14u: goto label_1dbd14;
            case 0x1DBD24u: goto label_1dbd24;
            case 0x1DBD34u: goto label_1dbd34;
            case 0x1DBD50u: goto label_1dbd50;
            case 0x1DBD6Cu: goto label_1dbd6c;
            case 0x1DBD78u: goto label_1dbd78;
            case 0x1DBD88u: goto label_1dbd88;
            case 0x1DBDB0u: goto label_1dbdb0;
            case 0x1DBDC4u: goto label_1dbdc4;
            case 0x1DBDD8u: goto label_1dbdd8;
            case 0x1DBDECu: goto label_1dbdec;
            case 0x1DBE08u: goto label_1dbe08;
            case 0x1DBE38u: goto label_1dbe38;
            case 0x1DBE54u: goto label_1dbe54;
            case 0x1DBE64u: goto label_1dbe64;
            case 0x1DBE84u: goto label_1dbe84;
            case 0x1DBE8Cu: goto label_1dbe8c;
            case 0x1DBEACu: goto label_1dbeac;
            case 0x1DBEC8u: goto label_1dbec8;
            case 0x1DBED8u: goto label_1dbed8;
            case 0x1DBEF4u: goto label_1dbef4;
            case 0x1DBF10u: goto label_1dbf10;
            case 0x1DBF2Cu: goto label_1dbf2c;
            case 0x1DBF40u: goto label_1dbf40;
            case 0x1DBF48u: goto label_1dbf48;
            case 0x1DBF60u: goto label_1dbf60;
            case 0x1DBF74u: goto label_1dbf74;
            case 0x1DBF80u: goto label_1dbf80;
            case 0x1DBFA0u: goto label_1dbfa0;
            case 0x1DBFB0u: goto label_1dbfb0;
            case 0x1DBFC0u: goto label_1dbfc0;
            case 0x1DBFD8u: goto label_1dbfd8;
            case 0x1DBFF0u: goto label_1dbff0;
            case 0x1DC000u: goto label_1dc000;
            case 0x1DC010u: goto label_1dc010;
            case 0x1DC028u: goto label_1dc028;
            case 0x1DC040u: goto label_1dc040;
            case 0x1DC05Cu: goto label_1dc05c;
            case 0x1DC06Cu: goto label_1dc06c;
            case 0x1DC088u: goto label_1dc088;
            case 0x1DC0A0u: goto label_1dc0a0;
            case 0x1DC0BCu: goto label_1dc0bc;
            case 0x1DC0D8u: goto label_1dc0d8;
            case 0x1DC0ECu: goto label_1dc0ec;
            case 0x1DC108u: goto label_1dc108;
            case 0x1DC118u: goto label_1dc118;
            case 0x1DC12Cu: goto label_1dc12c;
            case 0x1DC13Cu: goto label_1dc13c;
            case 0x1DC14Cu: goto label_1dc14c;
            case 0x1DC164u: goto label_1dc164;
            case 0x1DC17Cu: goto label_1dc17c;
            case 0x1DC194u: goto label_1dc194;
            case 0x1DC1A4u: goto label_1dc1a4;
            case 0x1DC1B0u: goto label_1dc1b0;
            case 0x1DC1C8u: goto label_1dc1c8;
            case 0x1DC1CCu: goto label_1dc1cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DC1E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
