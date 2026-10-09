#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012DB00
// Address: 0x12db00 - 0x12dd60
void sub_0012DB00_0x12db00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012DB00_0x12db00");
#endif

    switch (ctx->pc) {
        case 0x12db44u: goto label_12db44;
        case 0x12db78u: goto label_12db78;
        case 0x12dbd8u: goto label_12dbd8;
        case 0x12dc38u: goto label_12dc38;
        case 0x12dcecu: goto label_12dcec;
        case 0x12dd08u: goto label_12dd08;
        default: break;
    }

    ctx->pc = 0x12db00u;

label_12db00:
    // 0x12db00: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x12db00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x12db04: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x12db04u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12db08: 0x8c438748  lw          $v1, -0x78B8($v0)
    ctx->pc = 0x12db08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294936392)));
    // 0x12db0c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12db0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12db10: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x12db10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12db14: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12db14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12db18: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12db18u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12db1c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12db1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12db20: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x12db20u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12db24: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12db24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12db28: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x12db28u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12db2c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12db2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12db30: 0x100a02d  daddu       $s4, $t0, $zero
    ctx->pc = 0x12db30u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12db34: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12DB34u;
    {
        const bool branch_taken_0x12db34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12DB38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DB34u;
            // 0x12db38: 0xffbf0028  sd          $ra, 0x28($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12db34) {
            ctx->pc = 0x12DB44u;
            goto label_12db44;
        }
    }
    ctx->pc = 0x12DB3Cu;
    // 0x12db3c: 0xc04b6b0  jal         func_12DAC0
    ctx->pc = 0x12DB3Cu;
    SET_GPR_U32(ctx, 31, 0x12DB44u);
    ctx->pc = 0x12DAC0u;
    if (runtime->hasFunction(0x12DAC0u)) {
        auto targetFn = runtime->lookupFunction(0x12DAC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DB44u; }
        if (ctx->pc != 0x12DB44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DAC0_0x12dac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DB44u; }
        if (ctx->pc != 0x12DB44u) { return; }
    }
    ctx->pc = 0x12DB44u;
label_12db44:
    // 0x12db44: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x12db44u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x12db48: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x12db48u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x12db4c: 0x16200003  bnez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12DB4Cu;
    {
        const bool branch_taken_0x12db4c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x12DB50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DB4Cu;
            // 0x12db50: 0xa6800000  sh          $zero, 0x0($s4) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12db4c) {
            ctx->pc = 0x12DB5Cu;
            goto label_12db5c;
        }
    }
    ctx->pc = 0x12DB54u;
    // 0x12db54: 0x1a00004f  blez        $s0, . + 4 + (0x4F << 2)
    ctx->pc = 0x12DB54u;
    {
        const bool branch_taken_0x12db54 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x12DB58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DB54u;
            // 0x12db58: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12db54) {
            ctx->pc = 0x12DC94u;
            goto label_12dc94;
        }
    }
    ctx->pc = 0x12DB5Cu;
label_12db5c:
    // 0x12db5c: 0x3c0b0024  lui         $t3, 0x24
    ctx->pc = 0x12db5cu;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)36 << 16));
    // 0x12db60: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x12db60u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12db64: 0x25629360  addiu       $v0, $t3, -0x6CA0
    ctx->pc = 0x12db64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 11), 4294939488));
    // 0x12db68: 0x1a000018  blez        $s0, . + 4 + (0x18 << 2)
    ctx->pc = 0x12DB68u;
    {
        const bool branch_taken_0x12db68 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x12DB6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DB68u;
            // 0x12db6c: 0x844a0200  lh          $t2, 0x200($v0) (Delay Slot)
        SET_GPR_S32(ctx, 10, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 512)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12db68) {
            ctx->pc = 0x12DBCCu;
            goto label_12dbcc;
        }
    }
    ctx->pc = 0x12DB70u;
    // 0x12db70: 0x40402d  daddu       $t0, $v0, $zero
    ctx->pc = 0x12db70u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12db74: 0x0  nop
    ctx->pc = 0x12db74u;
    // NOP
label_12db78:
    // 0x12db78: 0x2271821  addu        $v1, $s1, $a3
    ctx->pc = 0x12db78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 7)));
    // 0x12db7c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x12db7cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x12db80: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x12db80u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12db84: 0xf0302a  slt         $a2, $a3, $s0
    ctx->pc = 0x12db84u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12db88: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x12db88u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x12db8c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x12db8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x12db90: 0x84430100  lh          $v1, 0x100($v0)
    ctx->pc = 0x12db90u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 256)));
    // 0x12db94: 0x1431818  mult        $v1, $t2, $v1
    ctx->pc = 0x12db94u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x12db98: 0x246503ff  addiu       $a1, $v1, 0x3FF
    ctx->pc = 0x12db98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1023));
    // 0x12db9c: 0x28640000  slti        $a0, $v1, 0x0
    ctx->pc = 0x12db9cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x12dba0: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x12dba0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dba4: 0xa4100b  movn        $v0, $a1, $a0
    ctx->pc = 0x12dba4u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x12dba8: 0x21283  sra         $v0, $v0, 10
    ctx->pc = 0x12dba8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 10));
    // 0x12dbac: 0x21280  sll         $v0, $v0, 10
    ctx->pc = 0x12dbacu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
    // 0x12dbb0: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x12dbb0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x12dbb4: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x12dbb4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x12dbb8: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x12dbb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x12dbbc: 0x14c0ffee  bnez        $a2, . + 4 + (-0x12 << 2)
    ctx->pc = 0x12DBBCu;
    {
        const bool branch_taken_0x12dbbc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x12DBC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DBBCu;
            // 0x12dbc0: 0x846a0000  lh          $t2, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 10, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12dbbc) {
            ctx->pc = 0x12DB78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12db78;
        }
    }
    ctx->pc = 0x12DBC4u;
    // 0x12dbc4: 0x25629360  addiu       $v0, $t3, -0x6CA0
    ctx->pc = 0x12dbc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 11), 4294939488));
    // 0x12dbc8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x12dbc8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_12dbcc:
    // 0x12dbcc: 0x1a000015  blez        $s0, . + 4 + (0x15 << 2)
    ctx->pc = 0x12DBCCu;
    {
        const bool branch_taken_0x12dbcc = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x12DBD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DBCCu;
            // 0x12dbd0: 0x84480400  lh          $t0, 0x400($v0) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 1024)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12dbcc) {
            ctx->pc = 0x12DC24u;
            goto label_12dc24;
        }
    }
    ctx->pc = 0x12DBD4u;
    // 0x12dbd4: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x12dbd4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_12dbd8:
    // 0x12dbd8: 0x2271821  addu        $v1, $s1, $a3
    ctx->pc = 0x12dbd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 7)));
    // 0x12dbdc: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x12dbdcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x12dbe0: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x12dbe0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12dbe4: 0xf0302a  slt         $a2, $a3, $s0
    ctx->pc = 0x12dbe4u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12dbe8: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x12dbe8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x12dbec: 0x491021  addu        $v0, $v0, $t1
    ctx->pc = 0x12dbecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x12dbf0: 0x84430100  lh          $v1, 0x100($v0)
    ctx->pc = 0x12dbf0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 256)));
    // 0x12dbf4: 0x1031818  mult        $v1, $t0, $v1
    ctx->pc = 0x12dbf4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x12dbf8: 0x246503ff  addiu       $a1, $v1, 0x3FF
    ctx->pc = 0x12dbf8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1023));
    // 0x12dbfc: 0x28640000  slti        $a0, $v1, 0x0
    ctx->pc = 0x12dbfcu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x12dc00: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x12dc00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dc04: 0xa4100b  movn        $v0, $a1, $a0
    ctx->pc = 0x12dc04u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x12dc08: 0x21283  sra         $v0, $v0, 10
    ctx->pc = 0x12dc08u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 10));
    // 0x12dc0c: 0x21280  sll         $v0, $v0, 10
    ctx->pc = 0x12dc0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
    // 0x12dc10: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x12dc10u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x12dc14: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x12dc14u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x12dc18: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x12dc18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x12dc1c: 0x14c0ffee  bnez        $a2, . + 4 + (-0x12 << 2)
    ctx->pc = 0x12DC1Cu;
    {
        const bool branch_taken_0x12dc1c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x12DC20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DC1Cu;
            // 0x12dc20: 0x84680000  lh          $t0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12dc1c) {
            ctx->pc = 0x12DBD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12dbd8;
        }
    }
    ctx->pc = 0x12DC24u;
label_12dc24:
    // 0x12dc24: 0x25629360  addiu       $v0, $t3, -0x6CA0
    ctx->pc = 0x12dc24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 11), 4294939488));
    // 0x12dc28: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x12dc28u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dc2c: 0x1a000015  blez        $s0, . + 4 + (0x15 << 2)
    ctx->pc = 0x12DC2Cu;
    {
        const bool branch_taken_0x12dc2c = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x12DC30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DC2Cu;
            // 0x12dc30: 0x84440600  lh          $a0, 0x600($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 1536)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12dc2c) {
            ctx->pc = 0x12DC84u;
            goto label_12dc84;
        }
    }
    ctx->pc = 0x12DC34u;
    // 0x12dc34: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x12dc34u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_12dc38:
    // 0x12dc38: 0x2271821  addu        $v1, $s1, $a3
    ctx->pc = 0x12dc38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 7)));
    // 0x12dc3c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x12dc3cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x12dc40: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x12dc40u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12dc44: 0xf0302a  slt         $a2, $a3, $s0
    ctx->pc = 0x12dc44u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12dc48: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x12dc48u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x12dc4c: 0x491021  addu        $v0, $v0, $t1
    ctx->pc = 0x12dc4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x12dc50: 0x84430100  lh          $v1, 0x100($v0)
    ctx->pc = 0x12dc50u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 256)));
    // 0x12dc54: 0x831818  mult        $v1, $a0, $v1
    ctx->pc = 0x12dc54u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x12dc58: 0x28640000  slti        $a0, $v1, 0x0
    ctx->pc = 0x12dc58u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x12dc5c: 0x246503ff  addiu       $a1, $v1, 0x3FF
    ctx->pc = 0x12dc5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1023));
    // 0x12dc60: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x12dc60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dc64: 0xa4100b  movn        $v0, $a1, $a0
    ctx->pc = 0x12dc64u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x12dc68: 0x21283  sra         $v0, $v0, 10
    ctx->pc = 0x12dc68u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 10));
    // 0x12dc6c: 0x21280  sll         $v0, $v0, 10
    ctx->pc = 0x12dc6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
    // 0x12dc70: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x12dc70u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x12dc74: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x12dc74u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x12dc78: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x12dc78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x12dc7c: 0x14c0ffee  bnez        $a2, . + 4 + (-0x12 << 2)
    ctx->pc = 0x12DC7Cu;
    {
        const bool branch_taken_0x12dc7c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x12DC80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DC7Cu;
            // 0x12dc80: 0x84640000  lh          $a0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12dc7c) {
            ctx->pc = 0x12DC38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12dc38;
        }
    }
    ctx->pc = 0x12DC84u;
label_12dc84:
    // 0x12dc84: 0xa64a0000  sh          $t2, 0x0($s2)
    ctx->pc = 0x12dc84u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 10));
    // 0x12dc88: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12dc88u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dc8c: 0xa6680000  sh          $t0, 0x0($s3)
    ctx->pc = 0x12dc8cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 8));
    // 0x12dc90: 0xa6840000  sh          $a0, 0x0($s4)
    ctx->pc = 0x12dc90u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 4));
label_12dc94:
    // 0x12dc94: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12dc94u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12dc98: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12dc98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12dc9c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12dc9cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12dca0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12dca0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12dca4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12dca4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12dca8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x12dca8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12dcac: 0x3e00008  jr          $ra
    ctx->pc = 0x12DCACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DCB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DCACu;
            // 0x12dcb0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DB00u: goto label_12db00;
            case 0x12DB44u: goto label_12db44;
            case 0x12DB5Cu: goto label_12db5c;
            case 0x12DB78u: goto label_12db78;
            case 0x12DBCCu: goto label_12dbcc;
            case 0x12DBD8u: goto label_12dbd8;
            case 0x12DC24u: goto label_12dc24;
            case 0x12DC38u: goto label_12dc38;
            case 0x12DC84u: goto label_12dc84;
            case 0x12DC94u: goto label_12dc94;
            case 0x12DCECu: goto label_12dcec;
            case 0x12DD08u: goto label_12dd08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DCB4u;
    // 0x12dcb4: 0x0  nop
    ctx->pc = 0x12dcb4u;
    // NOP
    // 0x12dcb8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x12dcb8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x12dcbc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12dcbcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12dcc0: 0x8c438748  lw          $v1, -0x78B8($v0)
    ctx->pc = 0x12dcc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294936392)));
    // 0x12dcc4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12dcc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12dcc8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12dcc8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dccc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12dcccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12dcd0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x12dcd0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dcd4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12dcd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12dcd8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x12dcd8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dcdc: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12DCDCu;
    {
        const bool branch_taken_0x12dcdc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12DCE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DCDCu;
            // 0x12dce0: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12dcdc) {
            ctx->pc = 0x12DCECu;
            goto label_12dcec;
        }
    }
    ctx->pc = 0x12DCE4u;
    // 0x12dce4: 0xc04b6b0  jal         func_12DAC0
    ctx->pc = 0x12DCE4u;
    SET_GPR_U32(ctx, 31, 0x12DCECu);
    ctx->pc = 0x12DAC0u;
    if (runtime->hasFunction(0x12DAC0u)) {
        auto targetFn = runtime->lookupFunction(0x12DAC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DCECu; }
        if (ctx->pc != 0x12DCECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DAC0_0x12dac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12DCECu; }
        if (ctx->pc != 0x12DCECu) { return; }
    }
    ctx->pc = 0x12DCECu;
label_12dcec:
    // 0x12dcec: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12dcecu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12dcf0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x12dcf0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dcf4: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x12dcf4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dcf8: 0x240402d  daddu       $t0, $s2, $zero
    ctx->pc = 0x12dcf8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dcfc: 0x2484ad98  addiu       $a0, $a0, -0x5268
    ctx->pc = 0x12dcfcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946200));
    // 0x12dd00: 0xc04b6c0  jal         func_12DB00
    ctx->pc = 0x12DD00u;
    SET_GPR_U32(ctx, 31, 0x12DD08u);
    ctx->pc = 0x12DD04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12DD00u;
            // 0x12dd04: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DB00u;
    goto label_12db00;
    ctx->pc = 0x12DD08u;
label_12dd08:
    // 0x12dd08: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12dd08u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dd0c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12dd0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12dd10: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12dd10u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12dd14: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12dd14u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12dd18: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12dd18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12dd1c: 0x3e00008  jr          $ra
    ctx->pc = 0x12DD1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DD20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DD1Cu;
            // 0x12dd20: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DB00u: goto label_12db00;
            case 0x12DB44u: goto label_12db44;
            case 0x12DB5Cu: goto label_12db5c;
            case 0x12DB78u: goto label_12db78;
            case 0x12DBCCu: goto label_12dbcc;
            case 0x12DBD8u: goto label_12dbd8;
            case 0x12DC24u: goto label_12dc24;
            case 0x12DC38u: goto label_12dc38;
            case 0x12DC84u: goto label_12dc84;
            case 0x12DC94u: goto label_12dc94;
            case 0x12DCECu: goto label_12dcec;
            case 0x12DD08u: goto label_12dd08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DD24u;
    // 0x12dd24: 0x0  nop
    ctx->pc = 0x12dd24u;
    // NOP
    // 0x12dd28: 0x94a70000  lhu         $a3, 0x0($a1)
    ctx->pc = 0x12dd28u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12dd2c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12dd2cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dd30: 0x94850000  lhu         $a1, 0x0($a0)
    ctx->pc = 0x12dd30u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12dd34: 0x94c30000  lhu         $v1, 0x0($a2)
    ctx->pc = 0x12dd34u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x12dd38: 0xa72818  mult        $a1, $a1, $a3
    ctx->pc = 0x12dd38u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x12dd3c: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x12dd3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x12dd40: 0x3e00008  jr          $ra
    ctx->pc = 0x12DD40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DD44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DD40u;
            // 0x12dd44: 0xa4830000  sh          $v1, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DB00u: goto label_12db00;
            case 0x12DB44u: goto label_12db44;
            case 0x12DB5Cu: goto label_12db5c;
            case 0x12DB78u: goto label_12db78;
            case 0x12DBCCu: goto label_12dbcc;
            case 0x12DBD8u: goto label_12dbd8;
            case 0x12DC24u: goto label_12dc24;
            case 0x12DC38u: goto label_12dc38;
            case 0x12DC84u: goto label_12dc84;
            case 0x12DC94u: goto label_12dc94;
            case 0x12DCECu: goto label_12dcec;
            case 0x12DD08u: goto label_12dd08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DD48u;
    // 0x12dd48: 0x3e00008  jr          $ra
    ctx->pc = 0x12DD48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DD4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DD48u;
            // 0x12dd4c: 0x24020100  addiu       $v0, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DB00u: goto label_12db00;
            case 0x12DB44u: goto label_12db44;
            case 0x12DB5Cu: goto label_12db5c;
            case 0x12DB78u: goto label_12db78;
            case 0x12DBCCu: goto label_12dbcc;
            case 0x12DBD8u: goto label_12dbd8;
            case 0x12DC24u: goto label_12dc24;
            case 0x12DC38u: goto label_12dc38;
            case 0x12DC84u: goto label_12dc84;
            case 0x12DC94u: goto label_12dc94;
            case 0x12DCECu: goto label_12dcec;
            case 0x12DD08u: goto label_12dd08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DD50u;
    // 0x12dd50: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x12dd50u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x12dd54: 0x3e00008  jr          $ra
    ctx->pc = 0x12DD54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DD58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DD54u;
            // 0x12dd58: 0x2442add8  addiu       $v0, $v0, -0x5228 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294946264));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DB00u: goto label_12db00;
            case 0x12DB44u: goto label_12db44;
            case 0x12DB5Cu: goto label_12db5c;
            case 0x12DB78u: goto label_12db78;
            case 0x12DBCCu: goto label_12dbcc;
            case 0x12DBD8u: goto label_12dbd8;
            case 0x12DC24u: goto label_12dc24;
            case 0x12DC38u: goto label_12dc38;
            case 0x12DC84u: goto label_12dc84;
            case 0x12DC94u: goto label_12dc94;
            case 0x12DCECu: goto label_12dcec;
            case 0x12DD08u: goto label_12dd08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DD5Cu;
    // 0x12dd5c: 0x0  nop
    ctx->pc = 0x12dd5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
