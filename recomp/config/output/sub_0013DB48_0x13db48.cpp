#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013DB48
// Address: 0x13db48 - 0x13de40
void sub_0013DB48_0x13db48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013DB48_0x13db48");
#endif

    switch (ctx->pc) {
        case 0x13dbccu: goto label_13dbcc;
        case 0x13dbe8u: goto label_13dbe8;
        case 0x13dc24u: goto label_13dc24;
        case 0x13dc5cu: goto label_13dc5c;
        case 0x13dc80u: goto label_13dc80;
        case 0x13dca0u: goto label_13dca0;
        case 0x13dcd4u: goto label_13dcd4;
        case 0x13dd04u: goto label_13dd04;
        case 0x13dd08u: goto label_13dd08;
        case 0x13dd38u: goto label_13dd38;
        case 0x13dd60u: goto label_13dd60;
        case 0x13dd7cu: goto label_13dd7c;
        case 0x13dd80u: goto label_13dd80;
        case 0x13ddbcu: goto label_13ddbc;
        case 0x13ddccu: goto label_13ddcc;
        case 0x13dddcu: goto label_13dddc;
        case 0x13dde0u: goto label_13dde0;
        default: break;
    }

    ctx->pc = 0x13db48u;

    // 0x13db48: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13db48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13db4c: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x13db4cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x13db50: 0x8c431440  lw          $v1, 0x1440($v0)
    ctx->pc = 0x13db50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5184)));
    // 0x13db54: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13db54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13db58: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13db58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13db5c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13db5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13db60: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13db60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13db64: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13db64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13db68: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x13db68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x13db6c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x13db6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x13db70: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x13db70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x13db74: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x13db74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x13db78: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x13DB78u;
    {
        const bool branch_taken_0x13db78 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13DB7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DB78u;
            // 0x13db7c: 0xffbf0048  sd          $ra, 0x48($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13db78) {
            ctx->pc = 0x13DBA0u;
            goto label_13dba0;
        }
    }
    ctx->pc = 0x13DB80u;
    // 0x13db80: 0x3c020004  lui         $v0, 0x4
    ctx->pc = 0x13db80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
    // 0x13db84: 0x3c150022  lui         $s5, 0x22
    ctx->pc = 0x13db84u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)34 << 16));
    // 0x13db88: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x13db88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x13db8c: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13db8cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13db90: 0x34421000  ori         $v0, $v0, 0x1000
    ctx->pc = 0x13db90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4096);
    // 0x13db94: 0xaea31438  sw          $v1, 0x1438($s5)
    ctx->pc = 0x13db94u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 5176), GPR_U32(ctx, 3));
    // 0x13db98: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x13DB98u;
    {
        const bool branch_taken_0x13db98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13DB9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DB98u;
            // 0x13db9c: 0xac82143c  sw          $v0, 0x143C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 5180), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13db98) {
            ctx->pc = 0x13DBA4u;
            goto label_13dba4;
        }
    }
    ctx->pc = 0x13DBA0u;
label_13dba0:
    // 0x13dba0: 0x3c150022  lui         $s5, 0x22
    ctx->pc = 0x13dba0u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)34 << 16));
label_13dba4:
    // 0x13dba4: 0x3c130022  lui         $s3, 0x22
    ctx->pc = 0x13dba4u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
    // 0x13dba8: 0x26701444  addiu       $s0, $s3, 0x1444
    ctx->pc = 0x13dba8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 5188));
    // 0x13dbac: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13dbacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13dbb0: 0x54400025  bnel        $v0, $zero, . + 4 + (0x25 << 2)
    ctx->pc = 0x13DBB0u;
    {
        const bool branch_taken_0x13dbb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13dbb0) {
            ctx->pc = 0x13DBB4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13DBB0u;
            // 0x13dbb4: 0x3c100022  lui         $s0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13DC48u;
            goto label_13dc48;
        }
    }
    ctx->pc = 0x13DBB8u;
    // 0x13dbb8: 0x3c120022  lui         $s2, 0x22
    ctx->pc = 0x13dbb8u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)34 << 16));
    // 0x13dbbc: 0x2651143c  addiu       $s1, $s2, 0x143C
    ctx->pc = 0x13dbbcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 5180));
    // 0x13dbc0: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x13dbc0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13dbc4: 0xc046e2c  jal         func_11B8B0
    ctx->pc = 0x13DBC4u;
    SET_GPR_U32(ctx, 31, 0x13DBCCu);
    ctx->pc = 0x13DBC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DBC4u;
            // 0x13dbc8: 0x24840040  addiu       $a0, $a0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B8B0u;
    if (runtime->hasFunction(0x11B8B0u)) {
        auto targetFn = runtime->lookupFunction(0x11B8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DBCCu; }
        if (ctx->pc != 0x13DBCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B8B0_0x11b8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DBCCu; }
        if (ctx->pc != 0x13DBCCu) { return; }
    }
    ctx->pc = 0x13DBCCu;
label_13dbcc:
    // 0x13dbcc: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x13DBCCu;
    {
        const bool branch_taken_0x13dbcc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13DBD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DBCCu;
            // 0x13dbd0: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13dbcc) {
            ctx->pc = 0x13DC08u;
            goto label_13dc08;
        }
    }
    ctx->pc = 0x13DBD4u;
    // 0x13dbd4: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x13dbd4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13dbd8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13dbd8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13dbdc: 0x2484d580  addiu       $a0, $a0, -0x2A80
    ctx->pc = 0x13dbdcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294956416));
    // 0x13dbe0: 0xc045a12  jal         func_116848
    ctx->pc = 0x13DBE0u;
    SET_GPR_U32(ctx, 31, 0x13DBE8u);
    ctx->pc = 0x13DBE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DBE0u;
            // 0x13dbe4: 0x24a50040  addiu       $a1, $a1, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DBE8u; }
        if (ctx->pc != 0x13DBE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DBE8u; }
        if (ctx->pc != 0x13DBE8u) { return; }
    }
    ctx->pc = 0x13DBE8u;
label_13dbe8:
    // 0x13dbe8: 0x0  nop
    ctx->pc = 0x13dbe8u;
    // NOP
    // 0x13dbec: 0x0  nop
    ctx->pc = 0x13dbecu;
    // NOP
    // 0x13dbf0: 0x0  nop
    ctx->pc = 0x13dbf0u;
    // NOP
    // 0x13dbf4: 0x0  nop
    ctx->pc = 0x13dbf4u;
    // NOP
    // 0x13dbf8: 0x0  nop
    ctx->pc = 0x13dbf8u;
    // NOP
    // 0x13dbfc: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13DBFCu;
    {
        const bool branch_taken_0x13dbfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13dbfc) {
            ctx->pc = 0x13DBE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13dbe8;
        }
    }
    ctx->pc = 0x13DC04u;
    // 0x13dc04: 0x0  nop
    ctx->pc = 0x13dc04u;
    // NOP
label_13dc08:
    // 0x13dc08: 0x26701444  addiu       $s0, $s3, 0x1444
    ctx->pc = 0x13dc08u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 5188));
    // 0x13dc0c: 0x8e45143c  lw          $a1, 0x143C($s2)
    ctx->pc = 0x13dc0cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 5180)));
    // 0x13dc10: 0x8e060000  lw          $a2, 0x0($s0)
    ctx->pc = 0x13dc10u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13dc14: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13dc14u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13dc18: 0x2484d5c8  addiu       $a0, $a0, -0x2A38
    ctx->pc = 0x13dc18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294956488));
    // 0x13dc1c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13DC1Cu;
    SET_GPR_U32(ctx, 31, 0x13DC24u);
    ctx->pc = 0x13DC20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DC1Cu;
            // 0x13dc20: 0x24a50040  addiu       $a1, $a1, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DC24u; }
        if (ctx->pc != 0x13DC24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DC24u; }
        if (ctx->pc != 0x13DC24u) { return; }
    }
    ctx->pc = 0x13DC24u;
label_13dc24:
    // 0x13dc24: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x13dc24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13dc28: 0x2405ffc0  addiu       $a1, $zero, -0x40
    ctx->pc = 0x13dc28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x13dc2c: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13dc2cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13dc30: 0x24630040  addiu       $v1, $v1, 0x40
    ctx->pc = 0x13dc30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 64));
    // 0x13dc34: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x13dc34u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x13dc38: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x13dc38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x13dc3c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13dc3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13dc40: 0xa082144c  sb          $v0, 0x144C($a0)
    ctx->pc = 0x13dc40u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 5196), (uint8_t)GPR_U32(ctx, 2));
    // 0x13dc44: 0xae031448  sw          $v1, 0x1448($s0)
    ctx->pc = 0x13dc44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 5192), GPR_U32(ctx, 3));
label_13dc48:
    // 0x13dc48: 0x3c140022  lui         $s4, 0x22
    ctx->pc = 0x13dc48u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)34 << 16));
    // 0x13dc4c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13dc4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13dc50: 0x26841480  addiu       $a0, $s4, 0x1480
    ctx->pc = 0x13dc50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 5248));
    // 0x13dc54: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13DC54u;
    SET_GPR_U32(ctx, 31, 0x13DC5Cu);
    ctx->pc = 0x13DC58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DC54u;
            // 0x13dc58: 0x24060300  addiu       $a2, $zero, 0x300 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DC5Cu; }
        if (ctx->pc != 0x13DC5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DC5Cu; }
        if (ctx->pc != 0x13DC5Cu) { return; }
    }
    ctx->pc = 0x13DC5Cu;
label_13dc5c:
    // 0x13dc5c: 0x8e111448  lw          $s1, 0x1448($s0)
    ctx->pc = 0x13dc5cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 5192)));
    // 0x13dc60: 0x8ea21438  lw          $v0, 0x1438($s5)
    ctx->pc = 0x13dc60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 5176)));
    // 0x13dc64: 0x1840006a  blez        $v0, . + 4 + (0x6A << 2)
    ctx->pc = 0x13DC64u;
    {
        const bool branch_taken_0x13dc64 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13DC68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DC64u;
            // 0x13dc68: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13dc64) {
            ctx->pc = 0x13DE10u;
            goto label_13de10;
        }
    }
    ctx->pc = 0x13DC6Cu;
    // 0x13dc6c: 0x3c160022  lui         $s6, 0x22
    ctx->pc = 0x13dc6cu;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)34 << 16));
    // 0x13dc70: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x13dc70u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13dc74: 0x3c1e0024  lui         $fp, 0x24
    ctx->pc = 0x13dc74u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)36 << 16));
    // 0x13dc78: 0x3c170024  lui         $s7, 0x24
    ctx->pc = 0x13dc78u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)36 << 16));
    // 0x13dc7c: 0x26821480  addiu       $v0, $s4, 0x1480
    ctx->pc = 0x13dc7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 5248));
label_13dc80:
    // 0x13dc80: 0x3223003f  andi        $v1, $s1, 0x3F
    ctx->pc = 0x13dc80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)63);
    // 0x13dc84: 0x2628021  addu        $s0, $s3, $v0
    ctx->pc = 0x13dc84u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x13dc88: 0x26730018  addiu       $s3, $s3, 0x18
    ctx->pc = 0x13dc88u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 24));
    // 0x13dc8c: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x13DC8Cu;
    {
        const bool branch_taken_0x13dc8c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13DC90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DC8Cu;
            // 0x13dc90: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13dc8c) {
            ctx->pc = 0x13DCC0u;
            goto label_13dcc0;
        }
    }
    ctx->pc = 0x13DC94u;
    // 0x13dc94: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x13dc94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x13dc98: 0xc045a12  jal         func_116848
    ctx->pc = 0x13DC98u;
    SET_GPR_U32(ctx, 31, 0x13DCA0u);
    ctx->pc = 0x13DC9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DC98u;
            // 0x13dc9c: 0x2444d5f8  addiu       $a0, $v0, -0x2A08 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294956536));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DCA0u; }
        if (ctx->pc != 0x13DCA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DCA0u; }
        if (ctx->pc != 0x13DCA0u) { return; }
    }
    ctx->pc = 0x13DCA0u;
label_13dca0:
    // 0x13dca0: 0x0  nop
    ctx->pc = 0x13dca0u;
    // NOP
    // 0x13dca4: 0x0  nop
    ctx->pc = 0x13dca4u;
    // NOP
    // 0x13dca8: 0x0  nop
    ctx->pc = 0x13dca8u;
    // NOP
    // 0x13dcac: 0x0  nop
    ctx->pc = 0x13dcacu;
    // NOP
    // 0x13dcb0: 0x0  nop
    ctx->pc = 0x13dcb0u;
    // NOP
    // 0x13dcb4: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13DCB4u;
    {
        const bool branch_taken_0x13dcb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13dcb4) {
            ctx->pc = 0x13DCA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13dca0;
        }
    }
    ctx->pc = 0x13DCBCu;
    // 0x13dcbc: 0x0  nop
    ctx->pc = 0x13dcbcu;
    // NOP
label_13dcc0:
    // 0x13dcc0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x13dcc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13dcc4: 0x26310100  addiu       $s1, $s1, 0x100
    ctx->pc = 0x13dcc4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 256));
    // 0x13dcc8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x13dcc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13dccc: 0xc0502e6  jal         func_140B98
    ctx->pc = 0x13DCCCu;
    SET_GPR_U32(ctx, 31, 0x13DCD4u);
    ctx->pc = 0x13DCD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DCCCu;
            // 0x13dcd0: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140B98u;
    if (runtime->hasFunction(0x140B98u)) {
        auto targetFn = runtime->lookupFunction(0x140B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DCD4u; }
        if (ctx->pc != 0x13DCD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140B98_0x140b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DCD4u; }
        if (ctx->pc != 0x13DCD4u) { return; }
    }
    ctx->pc = 0x13DCD4u;
label_13dcd4:
    // 0x13dcd4: 0x121a00  sll         $v1, $s2, 8
    ctx->pc = 0x13dcd4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 8));
    // 0x13dcd8: 0x26c51780  addiu       $a1, $s6, 0x1780
    ctx->pc = 0x13dcd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 22), 6016));
    // 0x13dcdc: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x13dcdcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13dce0: 0x652821  addu        $a1, $v1, $a1
    ctx->pc = 0x13dce0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x13dce4: 0x3223003f  andi        $v1, $s1, 0x3F
    ctx->pc = 0x13dce4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)63);
    // 0x13dce8: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x13dce8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x13dcec: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x13dcecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x13dcf0: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13DCF0u;
    {
        const bool branch_taken_0x13dcf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13DCF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DCF0u;
            // 0x13dcf4: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13dcf0) {
            ctx->pc = 0x13DD28u;
            goto label_13dd28;
        }
    }
    ctx->pc = 0x13DCF8u;
    // 0x13dcf8: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x13dcf8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x13dcfc: 0xc045a12  jal         func_116848
    ctx->pc = 0x13DCFCu;
    SET_GPR_U32(ctx, 31, 0x13DD04u);
    ctx->pc = 0x13DD00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DCFCu;
            // 0x13dd00: 0x2444d628  addiu       $a0, $v0, -0x29D8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294956584));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DD04u; }
        if (ctx->pc != 0x13DD04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DD04u; }
        if (ctx->pc != 0x13DD04u) { return; }
    }
    ctx->pc = 0x13DD04u;
label_13dd04:
    // 0x13dd04: 0x0  nop
    ctx->pc = 0x13dd04u;
    // NOP
label_13dd08:
    // 0x13dd08: 0x0  nop
    ctx->pc = 0x13dd08u;
    // NOP
    // 0x13dd0c: 0x0  nop
    ctx->pc = 0x13dd0cu;
    // NOP
    // 0x13dd10: 0x0  nop
    ctx->pc = 0x13dd10u;
    // NOP
    // 0x13dd14: 0x0  nop
    ctx->pc = 0x13dd14u;
    // NOP
    // 0x13dd18: 0x0  nop
    ctx->pc = 0x13dd18u;
    // NOP
    // 0x13dd1c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13DD1Cu;
    {
        const bool branch_taken_0x13dd1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13dd1c) {
            ctx->pc = 0x13DD08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13dd08;
        }
    }
    ctx->pc = 0x13DD24u;
    // 0x13dd24: 0x0  nop
    ctx->pc = 0x13dd24u;
    // NOP
label_13dd28:
    // 0x13dd28: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x13DD28u;
    {
        const bool branch_taken_0x13dd28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13DD2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DD28u;
            // 0x13dd2c: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13dd28) {
            ctx->pc = 0x13DD58u;
            goto label_13dd58;
        }
    }
    ctx->pc = 0x13DD30u;
    // 0x13dd30: 0xc045a12  jal         func_116848
    ctx->pc = 0x13DD30u;
    SET_GPR_U32(ctx, 31, 0x13DD38u);
    ctx->pc = 0x13DD34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DD30u;
            // 0x13dd34: 0x2444d660  addiu       $a0, $v0, -0x29A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294956640));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DD38u; }
        if (ctx->pc != 0x13DD38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DD38u; }
        if (ctx->pc != 0x13DD38u) { return; }
    }
    ctx->pc = 0x13DD38u;
label_13dd38:
    // 0x13dd38: 0x0  nop
    ctx->pc = 0x13dd38u;
    // NOP
    // 0x13dd3c: 0x0  nop
    ctx->pc = 0x13dd3cu;
    // NOP
    // 0x13dd40: 0x0  nop
    ctx->pc = 0x13dd40u;
    // NOP
    // 0x13dd44: 0x0  nop
    ctx->pc = 0x13dd44u;
    // NOP
    // 0x13dd48: 0x0  nop
    ctx->pc = 0x13dd48u;
    // NOP
    // 0x13dd4c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13DD4Cu;
    {
        const bool branch_taken_0x13dd4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13dd4c) {
            ctx->pc = 0x13DD38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13dd38;
        }
    }
    ctx->pc = 0x13DD54u;
    // 0x13dd54: 0x0  nop
    ctx->pc = 0x13dd54u;
    // NOP
label_13dd58:
    // 0x13dd58: 0xc050030  jal         func_1400C0
    ctx->pc = 0x13DD58u;
    SET_GPR_U32(ctx, 31, 0x13DD60u);
    ctx->pc = 0x1400C0u;
    if (runtime->hasFunction(0x1400C0u)) {
        auto targetFn = runtime->lookupFunction(0x1400C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DD60u; }
        if (ctx->pc != 0x13DD60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001400C0_0x1400c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DD60u; }
        if (ctx->pc != 0x13DD60u) { return; }
    }
    ctx->pc = 0x13DD60u;
label_13dd60:
    // 0x13dd60: 0x24034000  addiu       $v1, $zero, 0x4000
    ctx->pc = 0x13dd60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x13dd64: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x13dd64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x13dd68: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13dd68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13dd6c: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x13DD6Cu;
    {
        const bool branch_taken_0x13dd6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13DD70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DD6Cu;
            // 0x13dd70: 0x26060010  addiu       $a2, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13dd6c) {
            ctx->pc = 0x13DDA0u;
            goto label_13dda0;
        }
    }
    ctx->pc = 0x13DD74u;
    // 0x13dd74: 0xc045a12  jal         func_116848
    ctx->pc = 0x13DD74u;
    SET_GPR_U32(ctx, 31, 0x13DD7Cu);
    ctx->pc = 0x13DD78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DD74u;
            // 0x13dd78: 0x27c4d690  addiu       $a0, $fp, -0x2970 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 30), 4294956688));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DD7Cu; }
        if (ctx->pc != 0x13DD7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DD7Cu; }
        if (ctx->pc != 0x13DD7Cu) { return; }
    }
    ctx->pc = 0x13DD7Cu;
label_13dd7c:
    // 0x13dd7c: 0x0  nop
    ctx->pc = 0x13dd7cu;
    // NOP
label_13dd80:
    // 0x13dd80: 0x0  nop
    ctx->pc = 0x13dd80u;
    // NOP
    // 0x13dd84: 0x0  nop
    ctx->pc = 0x13dd84u;
    // NOP
    // 0x13dd88: 0x0  nop
    ctx->pc = 0x13dd88u;
    // NOP
    // 0x13dd8c: 0x0  nop
    ctx->pc = 0x13dd8cu;
    // NOP
    // 0x13dd90: 0x0  nop
    ctx->pc = 0x13dd90u;
    // NOP
    // 0x13dd94: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13DD94u;
    {
        const bool branch_taken_0x13dd94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13dd94) {
            ctx->pc = 0x13DD80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13dd80;
        }
    }
    ctx->pc = 0x13DD9Cu;
    // 0x13dd9c: 0x0  nop
    ctx->pc = 0x13dd9cu;
    // NOP
label_13dda0:
    // 0x13dda0: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x13dda0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x13dda4: 0xae030014  sw          $v1, 0x14($s0)
    ctx->pc = 0x13dda4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x13dda8: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13dda8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ddac: 0xae110010  sw          $s1, 0x10($s0)
    ctx->pc = 0x13ddacu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 17));
    // 0x13ddb0: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x13ddb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x13ddb4: 0x40f809  jalr        $v0
    ctx->pc = 0x13DDB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13DDBCu);
        ctx->pc = 0x13DDB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DDB4u;
            // 0x13ddb8: 0x26314000  addiu       $s1, $s1, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 16384));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13DDBCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DBA0u: goto label_13dba0;
            case 0x13DBA4u: goto label_13dba4;
            case 0x13DBCCu: goto label_13dbcc;
            case 0x13DBE8u: goto label_13dbe8;
            case 0x13DC08u: goto label_13dc08;
            case 0x13DC24u: goto label_13dc24;
            case 0x13DC48u: goto label_13dc48;
            case 0x13DC5Cu: goto label_13dc5c;
            case 0x13DC80u: goto label_13dc80;
            case 0x13DCA0u: goto label_13dca0;
            case 0x13DCC0u: goto label_13dcc0;
            case 0x13DCD4u: goto label_13dcd4;
            case 0x13DD04u: goto label_13dd04;
            case 0x13DD08u: goto label_13dd08;
            case 0x13DD28u: goto label_13dd28;
            case 0x13DD38u: goto label_13dd38;
            case 0x13DD58u: goto label_13dd58;
            case 0x13DD60u: goto label_13dd60;
            case 0x13DD7Cu: goto label_13dd7c;
            case 0x13DD80u: goto label_13dd80;
            case 0x13DDA0u: goto label_13dda0;
            case 0x13DDBCu: goto label_13ddbc;
            case 0x13DDCCu: goto label_13ddcc;
            case 0x13DDDCu: goto label_13dddc;
            case 0x13DDE0u: goto label_13dde0;
            case 0x13DE00u: goto label_13de00;
            case 0x13DE10u: goto label_13de10;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13DDBCu; }
            if (ctx->pc != 0x13DDBCu) { return; }
        }
        }
    }
    ctx->pc = 0x13DDBCu;
label_13ddbc:
    // 0x13ddbc: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x13ddbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x13ddc0: 0x8e050004  lw          $a1, 0x4($s0)
    ctx->pc = 0x13ddc0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x13ddc4: 0xc050524  jal         func_141490
    ctx->pc = 0x13DDC4u;
    SET_GPR_U32(ctx, 31, 0x13DDCCu);
    ctx->pc = 0x13DDC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DDC4u;
            // 0x13ddc8: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141490u;
    if (runtime->hasFunction(0x141490u)) {
        auto targetFn = runtime->lookupFunction(0x141490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DDCCu; }
        if (ctx->pc != 0x13DDCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141490_0x141490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DDCCu; }
        if (ctx->pc != 0x13DDCCu) { return; }
    }
    ctx->pc = 0x13DDCCu;
label_13ddcc:
    // 0x13ddcc: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x13DDCCu;
    {
        const bool branch_taken_0x13ddcc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13DDD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DDCCu;
            // 0x13ddd0: 0xae02000c  sw          $v0, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ddcc) {
            ctx->pc = 0x13DE00u;
            goto label_13de00;
        }
    }
    ctx->pc = 0x13DDD4u;
    // 0x13ddd4: 0xc045a12  jal         func_116848
    ctx->pc = 0x13DDD4u;
    SET_GPR_U32(ctx, 31, 0x13DDDCu);
    ctx->pc = 0x13DDD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13DDD4u;
            // 0x13ddd8: 0x26e4d6c8  addiu       $a0, $s7, -0x2938 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 23), 4294956744));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DDDCu; }
        if (ctx->pc != 0x13DDDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13DDDCu; }
        if (ctx->pc != 0x13DDDCu) { return; }
    }
    ctx->pc = 0x13DDDCu;
label_13dddc:
    // 0x13dddc: 0x0  nop
    ctx->pc = 0x13dddcu;
    // NOP
label_13dde0:
    // 0x13dde0: 0x0  nop
    ctx->pc = 0x13dde0u;
    // NOP
    // 0x13dde4: 0x0  nop
    ctx->pc = 0x13dde4u;
    // NOP
    // 0x13dde8: 0x0  nop
    ctx->pc = 0x13dde8u;
    // NOP
    // 0x13ddec: 0x0  nop
    ctx->pc = 0x13ddecu;
    // NOP
    // 0x13ddf0: 0x0  nop
    ctx->pc = 0x13ddf0u;
    // NOP
    // 0x13ddf4: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13DDF4u;
    {
        const bool branch_taken_0x13ddf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13ddf4) {
            ctx->pc = 0x13DDE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13dde0;
        }
    }
    ctx->pc = 0x13DDFCu;
    // 0x13ddfc: 0x0  nop
    ctx->pc = 0x13ddfcu;
    // NOP
label_13de00:
    // 0x13de00: 0x8ea21438  lw          $v0, 0x1438($s5)
    ctx->pc = 0x13de00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 5176)));
    // 0x13de04: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x13de04u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13de08: 0x1440ff9d  bnez        $v0, . + 4 + (-0x63 << 2)
    ctx->pc = 0x13DE08u;
    {
        const bool branch_taken_0x13de08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13DE0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DE08u;
            // 0x13de0c: 0x26821480  addiu       $v0, $s4, 0x1480 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 5248));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13de08) {
            ctx->pc = 0x13DC80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13dc80;
        }
    }
    ctx->pc = 0x13DE10u;
label_13de10:
    // 0x13de10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13de10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13de14: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13de14u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13de18: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13de18u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13de1c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13de1cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13de20: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13de20u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13de24: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x13de24u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13de28: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x13de28u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13de2c: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x13de2cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13de30: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x13de30u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x13de34: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x13de34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x13de38: 0x3e00008  jr          $ra
    ctx->pc = 0x13DE38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13DE3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DE38u;
            // 0x13de3c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DBA0u: goto label_13dba0;
            case 0x13DBA4u: goto label_13dba4;
            case 0x13DBCCu: goto label_13dbcc;
            case 0x13DBE8u: goto label_13dbe8;
            case 0x13DC08u: goto label_13dc08;
            case 0x13DC24u: goto label_13dc24;
            case 0x13DC48u: goto label_13dc48;
            case 0x13DC5Cu: goto label_13dc5c;
            case 0x13DC80u: goto label_13dc80;
            case 0x13DCA0u: goto label_13dca0;
            case 0x13DCC0u: goto label_13dcc0;
            case 0x13DCD4u: goto label_13dcd4;
            case 0x13DD04u: goto label_13dd04;
            case 0x13DD08u: goto label_13dd08;
            case 0x13DD28u: goto label_13dd28;
            case 0x13DD38u: goto label_13dd38;
            case 0x13DD58u: goto label_13dd58;
            case 0x13DD60u: goto label_13dd60;
            case 0x13DD7Cu: goto label_13dd7c;
            case 0x13DD80u: goto label_13dd80;
            case 0x13DDA0u: goto label_13dda0;
            case 0x13DDBCu: goto label_13ddbc;
            case 0x13DDCCu: goto label_13ddcc;
            case 0x13DDDCu: goto label_13dddc;
            case 0x13DDE0u: goto label_13dde0;
            case 0x13DE00u: goto label_13de00;
            case 0x13DE10u: goto label_13de10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13DE40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
