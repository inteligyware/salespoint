/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS inventoryitem CASCADE;

DROP TABLE IF EXISTS inventory CASCADE;

CREATE TABLE inventory (
  id BIGSERIAL NOT NULL PRIMARY KEY,
  date_started TIMESTAMP NOT NULL DEFAULT 'now()',
  date_ended TIMESTAMP NULL CHECK(date_ended > date_started),
  report TEXT NULL,
  responsable INTEGER NOT NULL);

CREATE UNIQUE INDEX responsable_date_started_i
  ON inventory (
    responsable,
    date_started);

CREATE TABLE inventoryitem (
  id BIGSERIAL NOT NULL PRIMARY KEY,
  qte_theo_gros INTEGER NOT NULL,
  qte_theo_details INTEGER NOT NULL,
  qte_phys_gros INTEGER NOT NULL,
  qte_phys_details INTEGER NOT NULL,
  qte_ajoute_gros INTEGER NOT NULL,
  qte_ajoute_details INTEGER NOT NULL,
  justification TEXT NULL,
  produit BIGINT NOT NULL,
  inventory BIGINT NOT NULL,
  CONSTRAINT inventory_fk
    FOREIGN KEY (inventory)
    REFERENCES inventory (id)
    ON DELETE CASCADE
    INITIALLY DEFERRED);

CREATE UNIQUE INDEX produit_inventory_i
  ON inventoryitem (
    produit,
    inventory);

ALTER TABLE inventory
  ADD CONSTRAINT responsable_fk
    FOREIGN KEY (responsable)
    REFERENCES personnel (id)
    ON DELETE CASCADE
    INITIALLY DEFERRED;

ALTER TABLE inventoryitem
  ADD CONSTRAINT produit_fk
    FOREIGN KEY (produit)
    REFERENCES produit (id)
    ON DELETE CASCADE
    INITIALLY DEFERRED;
